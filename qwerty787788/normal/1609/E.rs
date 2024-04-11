use std::cmp::min;
use std::io;
use std::io::Write;

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
        Self {
            buffer: vec![],
            input_source: InputSource::Stdin,
        }
    }

    #[allow(dead_code)]
    fn new_file(filename: &str) -> Self {
        let file = std::fs::read_to_string(filename).unwrap();
        let mut lines: Vec<String> = file.lines().map(|line| String::from(line)).collect();
        lines.reverse();
        Self {
            buffer: vec![],
            input_source: InputSource::FromFile(lines),
        }
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

    fn parse_next_line(&mut self) -> bool {
        let mut input = String::new();
        match &mut self.input_source {
            InputSource::Stdin => {
                if std::io::stdin().read_line(&mut input).expect("Failed read") == 0 {
                    return false;
                }
            }
            InputSource::FromFile(lines) => match lines.pop() {
                Some(line) => input = line,
                None => return false,
            },
        }

        self.buffer = input.split_whitespace().rev().map(String::from).collect();
        return true;
    }

    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }

            self.parse_next_line();
        }
    }

    #[allow(dead_code)]
    fn has_more_elements(&mut self) -> bool {
        loop {
            if !self.buffer.is_empty() {
                return true;
            }
            if !self.parse_next_line() {
                return false;
            }
        }
    }

    #[allow(dead_code)]
    fn string(&mut self) -> Vec<u8> {
        self.next::<String>().into_bytes()
    }
}

trait LazySegTreeNodeSpec: Clone + Default {
    fn unite(l: &Self, r: &Self, go: &[Vec<usize>]) -> Self;

    fn apply_update(node: &mut Self, update: &Self::Update);
    fn join_updates(current: &mut Self::Update, add: &Self::Update);

    type Update: Clone;
}

#[allow(unused)]
struct LazySegTree<T: LazySegTreeNodeSpec> {
    n: usize,
    tree: Vec<T>,
    updates_to_push: Vec<Option<T::Update>>,
    go: Vec<Vec<usize>>,
}

#[allow(unused)]
impl<T: LazySegTreeNodeSpec> LazySegTree<T> {
    fn new(init_val: &T, n: usize, go: Vec<Vec<usize>>) -> Self {
        assert!(n > 0);
        let tree = vec![T::default(); 2 * n - 1];
        let updates_to_push = vec![None; 2 * n - 1];
        let mut res = LazySegTree {
            n,
            tree,
            updates_to_push,
            go,
        };
        res.build(0, 0, n, init_val);
        res
    }

    fn pull(&mut self, v: usize, vr: usize) {
        self.tree[v] = T::unite(&self.tree[v + 1], &self.tree[vr], &self.go);
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
                    &self.go,
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

/**************************************************

   END OF TEMPLATE CODE

*************************************************/

const N: usize = 18;

#[derive(Clone, Default)]
struct Node {
    cost: [i32; N + 1],
}

const INIT_STATE: [usize; 3] = [6, 2, 1];

impl LazySegTreeNodeSpec for Node {
    type Update = usize;

    fn unite(l: &Self, r: &Self, go: &[Vec<usize>]) -> Self {
        let mut cost = [i32::MAX / 2; N + 1];
        for i in 0..N {
            for j in 0..N {
                let next_id = go[i][j];
                cost[next_id] = min(cost[next_id], l.cost[i] + r.cost[j]);
            }
        }
        Self { cost }
    }

    fn apply_update(node: &mut Self, update: &Self::Update) {
        for x in node.cost.iter_mut() {
            *x = i32::MAX / 2;
        }
        for &ini in INIT_STATE.iter() {
            node.cost[ini] = 1;
        }
        node.cost[*update] = 0;
    }

    fn join_updates(current: &mut Self::Update, add: &Self::Update) {}
}

#[derive(Ord, PartialOrd, Eq, PartialEq, Debug)]
struct State {
    go: Vec<usize>,
}

pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let mut states = vec![];
    for g0 in 0..=2 {
        for g1 in 1..=3 {
            for g2 in 2..=3 {
                states.push(State {
                    go: vec![g0, g1, g2],
                });
            }
        }
    }
    // for s in states.iter() {
    //     dbg!(s);
    // }
    assert_eq!(states.len(), N);
    let mut go = vec![vec![0; N]; N];
    for id1 in 0..N {
        for id2 in 0..N {
            let mut expect_go = vec![0; 3];
            for from in 0..3 {
                for mid in from..=3 {
                    for to in mid..=3 {
                        if states[id1].go[from] >= mid && (mid == 3 || states[id2].go[mid] >= to) {
                            expect_go[from] = to;
                        }
                    }
                }
            }
            let next_state = State { go: expect_go };
            if next_state.go[0] == 3 {
                go[id1][id2] = N;
            } else {
                while states[go[id1][id2]] != next_state {
                    go[id1][id2] += 1;
                }
            }
        }
    }
    let mut init_state = vec![0; 3];
    for v in 0..3 {
        let mut go = vec![0, 1, 2];
        go[v] = v + 1;
        let next_state = State { go };
        // dbg!(next_state);
        while states[init_state[v]] != next_state {
            init_state[v] += 1;
        }
    }
    // dbg!(init_state);

    let n = sc.usize();
    let q = sc.usize();
    let s = sc.string();
    let mut seg_tree = LazySegTree::new(&Node { cost: [0; N + 1] }, n, go);

    let init_state_by_char = |c: u8| -> usize {
        if c == b'a' {
            init_state[0]
        } else if c == b'b' {
            init_state[1]
        } else if c == b'c' {
            init_state[2]
        } else {
            unreachable!();
        }
    };
    for pos in 0..n {
        seg_tree.modify(pos, pos + 1, init_state_by_char(s[pos]));
    }
    for _ in 0..q {
        let pos = sc.usize() - 1;
        let c = sc.string()[0];
        seg_tree.modify(pos, pos + 1, init_state_by_char(c));
        let res = seg_tree.get(0, n);
        let mut min_cost = i32::MAX;
        for i in 0..N {
            min_cost = min(min_cost, res.cost[i]);
        }
        writeln!(out, "{}", min_cost).unwrap();
    }
}