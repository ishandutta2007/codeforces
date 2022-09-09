use std::io;
use std::io::{Write, StdoutLock, BufWriter};
use std::collections::BTreeSet;

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

fn query(out: &mut BufWriter<StdoutLock>, sc: &mut Scanner, v: usize, n: usize) -> Vec<usize> {
    writeln!(out, "? {}", v + 1).unwrap();
    out.flush().unwrap();
    sc.vec::<usize>(n)
}

#[derive(Copy, Clone, Ord, PartialOrd, Eq, PartialEq)]
struct Edge {
    fr: usize,
    to: usize,
}

fn add_all_edges(graph: &mut BTreeSet<Edge>, v: usize, response: &Vec<usize>) {
    for i in 0..response.len() {
        if response[i] == 1 {
            graph.insert(Edge { fr: i, to: v });
            graph.insert(Edge { fr: v, to: i });
        }
    }
}

pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let n = sc.usize();
    let start = query(&mut out, &mut sc, 0, n);
    let mut graph: BTreeSet<Edge> = BTreeSet::new();
    add_all_edges(&mut graph, 0, &start);
    let mut odd = vec![];
    let mut even = vec![];
    for i in 1..n {
        if start[i] % 2 == 0 {
            even.push(i);
        } else {
            odd.push(i);
        }
    }
    let check = if even.len() < odd.len() { even } else { odd };
    for &v in check.iter() {
        let response = query(&mut out, &mut sc, v, n);
        add_all_edges(&mut graph, v, &response);
    }
    writeln!(out, "!").unwrap();
    let mut sum = 0;
    for e in graph.iter() {
        if e.fr < e.to {
            sum += 1;
            writeln!(out, "{} {}", e.fr + 1, e.to + 1).unwrap();
        }
    }
    assert_eq!(sum + 1, n);
}