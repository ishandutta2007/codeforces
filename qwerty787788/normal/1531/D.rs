use std::io;
use std::io::Write;
use core::fmt;
use std::fmt::Formatter;
use std::fmt::Result;

/**************************************************

    START OF TEMPLATE CODE

 *************************************************/
#[allow(unused_macros)]
macro_rules! dbg {
    ($first_val:expr, $($val:expr),+ $(,)?) => {
        eprint!("[{}:{}] {} = {:?}",
                    file!(), line!(), stringify!($first_val), &$first_val);
        ($(eprint!(", {} = {:?}", stringify!($val), &$val)),+,);
        eprintln!();
    };
    ($first_val:expr) => {
        eprintln!("[{}:{}] {} = {:?}",
                    file!(), line!(), stringify!($first_val), &$first_val);
    };
}

enum InputSource {
    Stdin,
    FromFile(Vec<String>),
}

struct Scanner {
    buffer: Vec<String>,
    input_source: InputSource,
}

impl Scanner {
    #[allow(dead_code)]
    fn new() -> Self {
        Self { buffer: vec![], input_source: InputSource::Stdin }
    }

    #[allow(dead_code)]
    fn new_file(filename: &str) -> Self {
        let file = std::fs::read_to_string(filename).unwrap();
        let mut lines: Vec<String> = file.lines().map(|line| String::from(line)).collect();
        lines.reverse();
        Self { buffer: vec![], input_source: InputSource::FromFile(lines) }
    }


    #[allow(dead_code)]
    fn i64(&mut self) -> i64 {
        self.next::<i64>()
    }

    #[allow(dead_code)]
    fn i32(&mut self) -> i32 {
        self.next::<i32>()
    }

    #[allow(dead_code)]
    fn usize(&mut self) -> usize {
        self.next::<usize>()
    }

    #[allow(dead_code)]
    fn vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.next::<T>()).collect()
    }

    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            match &mut self.input_source {
                | InputSource::Stdin => { std::io::stdin().read_line(&mut input).expect("Failed read"); }
                | InputSource::FromFile(lines) => {
                    let line = lines.pop().unwrap();
                    input = line;
                }
            }

            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }

    #[allow(dead_code)]
    fn string(&mut self) -> Vec<u8> {
        self.next::<String>().into_bytes()
    }
}

/**************************************************

    END OF TEMPLATE CODE

 *************************************************/


trait LazySegTreeNodeSpec: Clone + Default {
    fn unite(l: &Self, r: &Self) -> Self;

    fn apply_update(node: &mut Self, update: &Self::Update);
    fn join_updates(current: &mut Self::Update, add: &Self::Update);

    type Update: Clone;
}

#[allow(unused)]
struct LazySegTree<T: LazySegTreeNodeSpec> {
    n: usize,
    tree: Vec<T>,
    updates_to_push: Vec<Option<T::Update>>,
}

#[allow(unused)]
impl<T: LazySegTreeNodeSpec> LazySegTree<T> {
    fn new(init_val: &T, n: usize) -> Self {
        assert!(n > 0);
        let tree = vec![T::default(); 2 * n - 1];
        let updates_to_push = vec![None; 2 * n - 1];
        let mut res = LazySegTree {
            n,
            tree,
            updates_to_push,
        };
        res.build(0, 0, n, init_val);
        res
    }

    fn pull(&mut self, v: usize, vr: usize) {
        self.tree[v] = T::unite(&self.tree[v + 1], &self.tree[vr]);
    }

    fn build(&mut self, v: usize, l: usize, r: usize, init_val: &T) {
        if l + 1 == r {
            self.tree[v] = init_val.clone();
        } else {
            let m = (l + r) >> 1;
            let vr = v + ((m - l) << 1);
            self.build(v + 1, l, m, init_val);
            self.build(vr, m, r, init_val);
            self.pull(v, vr);
        }
    }

    fn push(&mut self, v: usize, l: usize, r: usize) {
        let update = self.updates_to_push[v].clone();
        self.updates_to_push[v] = None;
        match update {
            None => {}
            Some(update) => {
                self.apply_update(v + 1, &update);
                self.apply_update(v + ((r - l) & !1), &update);
            }
        }
    }

    fn get_(&mut self, v: usize, l: usize, r: usize, ql: usize, qr: usize) -> T {
        assert!(qr >= l);
        assert!(ql < r);
        if ql <= l && r <= qr {
            return self.tree[v].clone();
        }
        let m = (l + r) >> 1;
        let vr = v + ((m - l) << 1);
        self.push(v, l, r);
        let res = if ql >= m {
            self.get_(vr, m, r, ql, qr)
        } else {
            if qr <= m {
                self.get_(v + 1, l, m, ql, qr)
            } else {
                T::unite(
                    &self.get_(v + 1, l, m, ql, qr),
                    &self.get_(vr, m, r, ql, qr),
                )
            }
        };
        self.pull(v, vr);
        res
    }

    fn join_updates(current: &mut Option<T::Update>, add: &T::Update) {
        match current {
            None => *current = Some(add.clone()),
            Some(current) => T::join_updates(current, add),
        };
    }

    fn apply_update(&mut self, v: usize, update: &T::Update) {
        T::apply_update(&mut self.tree[v], update);
        Self::join_updates(&mut self.updates_to_push[v], update);
    }

    fn modify_(&mut self, v: usize, l: usize, r: usize, ql: usize, qr: usize, update: &T::Update) {
        assert!(qr >= l);
        assert!(ql < r);
        if ql <= l && r <= qr {
            self.apply_update(v, update);
            return;
        }
        let m = (l + r) >> 1;
        let vr = v + ((m - l) << 1);
        self.push(v, l, r);
        if ql >= m {
            self.modify_(vr, m, r, ql, qr, update);
        } else {
            if qr <= m {
                self.modify_(v + 1, l, m, ql, qr, update);
            } else {
                self.modify_(v + 1, l, m, ql, qr, update);
                self.modify_(vr, m, r, ql, qr, update);
            }
        };
        self.pull(v, vr);
    }

    pub fn modify(&mut self, ql: usize, qr: usize, update: T::Update) {
        self.modify_(0, 0, self.n, ql, qr, &update);
    }

    pub fn get(&mut self, ql: usize, qr: usize) -> T {
        self.get_(0, 0, self.n, ql, qr)
    }

    fn new_f(n: usize, f: &dyn Fn(usize) -> T) -> Self {
        assert!(n > 0);
        let tree = vec![T::default(); 2 * n - 1];
        let updates_to_push = vec![None; 2 * n - 1];
        let mut res = LazySegTree {
            n,
            tree,
            updates_to_push,
        };
        res.build_f(0, 0, n, f);
        res
    }

    fn build_f(&mut self, v: usize, l: usize, r: usize, f: &dyn Fn(usize) -> T) {
        if l + 1 == r {
            self.tree[v] = f(l);
        } else {
            let m = (l + r) >> 1;
            let vr = v + ((m - l) << 1);
            self.build_f(v + 1, l, m, f);
            self.build_f(vr, m, r, f);
            self.pull(v, vr);
        }
    }
}

#[derive(Copy, Clone)]
enum Color {
    Red,
    Orange,
    Yellow,
    Green,
    Blue,
    Indigo,
    Violet,
}

impl Color {
    fn from_string(s: &str) -> Self {
        match s {
            "red" => Color::Red,
            "orange" => Color::Orange,
            "yellow" => Color::Yellow,
            "green" => Color::Green,
            "blue" => Color::Blue,
            "indigo" => Color::Indigo,
            "violet" => Color::Violet,
            _ => unreachable!(),
        }
    }
}

impl fmt::Display for Color {
    fn fmt(&self, f: &mut Formatter<'_>) -> Result {
        match self {
            Color::Red => write!(f, "red"),
            Color::Orange => write!(f, "orange"),
            Color::Yellow => write!(f, "yellow"),
            Color::Green => write!(f, "green"),
            Color::Blue => write!(f, "blue"),
            Color::Indigo => write!(f, "indigo"),
            Color::Violet => write!(f, "violet"),
        }
    }
}

#[derive(Clone, Default)]
struct What {
    color: Option<Color>,
    is_locked: bool,
}

#[derive(Clone, Default)]
struct Node {
    if_locked: What,
    if_not_locked: What,
}

impl Node {
    fn result(&self) -> Color {
        let what = &self.if_not_locked;
        match what.color {
            Some(color) => color,
            None => Color::Blue,
        }
    }

    fn from_command(cmd: &Command) -> Self {
        match cmd {
            Command::Lock => Self { if_locked: What { color: None, is_locked: true }, if_not_locked: What { color: None, is_locked: true } },
            Command::Unlock => Self { if_locked: What { color: None, is_locked: false }, if_not_locked: What { color: None, is_locked: false } },
            Command::SetColor(c) => Self { if_locked: What { color: None, is_locked: true }, if_not_locked: What { color: Some(*c), is_locked: false } },
        }
    }
}

impl LazySegTreeNodeSpec for Node {
    fn unite(l: &Self, r: &Self) -> Self {
        let if_locked = {
            let state = &l.if_locked;
            let next_state = if state.is_locked { &r.if_locked } else { &r.if_not_locked };
            let color = if let Some(col) = next_state.color {
                Some(col)
            } else {
                state.color
            };
            What { color, is_locked: next_state.is_locked }
        };
        let if_not_locked = {
            let state = &l.if_not_locked;
            let next_state = if state.is_locked { &r.if_locked } else { &r.if_not_locked };
            let color = if let Some(col) = next_state.color {
                Some(col)
            } else {
                state.color
            };
            What { color, is_locked: next_state.is_locked }
        };
        Self { if_locked, if_not_locked }
    }

    fn apply_update(node: &mut Self, update: &Self::Update) {
        *node = Node::from_command(update);
    }

    fn join_updates(current: &mut Self::Update, add: &Self::Update) {

    }

    type Update = Command;
}

#[derive(Clone)]
enum Command {
    Lock,
    Unlock,
    SetColor(Color),
}

impl Command {
    fn from_string(s: &str) -> Self {
        match s {
            "lock" => Command::Lock,
            "unlock" => Command::Unlock,
            _ => Command::SetColor(Color::from_string(s))
        }
    }
}

pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let n = sc.usize();
    let commands: Vec<_> = (0..n).map(|_| {
        let s: String = sc.next();
        Command::from_string(&s)
    }).collect();
    let mut st = LazySegTree::new_f(n, &|i| Node::from_command(&commands[i]));
    let node = st.get(0, n);
    writeln!(out, "{}", node.result()).unwrap();
    let updates = sc.usize();
    for _ in 0..updates {
        let pos = sc.usize() - 1;
        let s: String = sc.next();
        let cmd = Command::from_string(&s);
        st.modify(pos, pos + 1, cmd);
        let node = st.get(0, n);
        writeln!(out, "{}", node.result()).unwrap();
    }
}