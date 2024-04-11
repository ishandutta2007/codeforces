use std::io;
use std::io::Write;
use std::collections::BTreeSet;
use std::cmp::max;

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

    fn parse_next_line(&mut self) -> bool {
        let mut input = String::new();
        match &mut self.input_source {
            | InputSource::Stdin => {
                if std::io::stdin().read_line(&mut input).expect("Failed read") == 0 {
                    return false;
                }
            }
            | InputSource::FromFile(lines) => {
                match lines.pop() {
                    Some(line) => input = line,
                    None => return false,
                }
            }
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

/**************************************************

    END OF TEMPLATE CODE

 *************************************************/

struct Graph {
    g1: Vec<Vec<usize>>,
    g2: Vec<Vec<usize>>,
}

#[derive(Ord, PartialOrd, Eq, PartialEq, Copy, Clone)]
struct Node {
    tin: usize,
    v: usize,
}

struct State {
    tin: Vec<usize>,
    tout: Vec<usize>,
    cur_time: usize,
    res: usize,
    nodes: BTreeSet<Node>,
}


fn calc_times(s: &mut State, g: &Graph, v: usize) {
    s.tin[v] = s.cur_time;
    s.cur_time += 1;
    for &to in g.g2[v].iter() {
        calc_times(s, g, to);
    }
    s.tout[v] = s.cur_time;
}

fn dfs1(s: &mut State, g: &Graph, v: usize) {
    let cur_node = Node { tin: s.tin[v], v };
    let child = match s.nodes.range(cur_node..).next() {
        | None => None,
        | Some(node) => if s.tout[v] >= s.tout[node.v] {
            Some(node.v)
        } else {
            None
        }
    };
    let mut parent = None;
    if child.is_none() {
        parent = match s.nodes.range(..cur_node).next_back() {
            | None => None,
            | Some(node) => if s.tout[node.v] >= s.tout[v] {
                Some(node.clone())
            } else {
                None
            }
        };

        s.nodes.insert(cur_node);
        if let Some(parent) = parent {
            s.nodes.remove(&parent);
        }
    }
    s.res = max(s.res, s.nodes.len());
    for &to in g.g1[v].iter() {
        dfs1(s, g, to);
    }

    if child.is_none() {
        s.nodes.remove(&cur_node);
        if let Some(parent) = parent {
            s.nodes.insert(parent);
        }
    }
}

pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let tc = sc.usize();
    for _ in 0..tc {
        let n = sc.usize();
        let mut g1 = vec![vec![]; n];
        let mut g2 = vec![vec![]; n];
        for i in 1..n {
            g1[sc.usize() - 1].push(i);
        }
        for i in 1..n {
            g2[sc.usize() - 1].push(i);
        }
        let tin = vec![0; n];
        let tout = vec![0; n];
        let g = Graph { g1, g2 };
        let mut s = State { tin, tout, cur_time: 0, res: 0, nodes: BTreeSet::new() };
        calc_times(&mut s, &g, 0);
        dfs1(&mut s, &g, 0);
        writeln!(out, "{}", s.res).unwrap();
    }
}