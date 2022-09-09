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

fn build(s: &[u8], it: &mut usize, nodes: &mut Vec<usize>, l: usize, r: usize) -> bool {
    if r - l <= 1 {
        return true;
    }
    let m = (l + r) >> 1;
    if !build(s, it, nodes, l, m) {
        return false;
    }
    if !build(s, it, nodes, m, r) {
        return false;
    }
    let mut i = l;
    let mut j = m;
    let mut b = vec![];
    while i < m && j < r {
        if *it == s.len() {
            return false;
        }
        if s[*it] == b'0' {
            b.push(nodes[i]);
            i += 1;
        } else if s[*it] == b'1' {
            b.push(nodes[j]);
            j += 1;
        } else {
            unreachable!();
        }
        *it += 1;
    }
    while i < m {
        b.push(nodes[i]);
        i += 1;
    }
    while j < r {
        b.push(nodes[j]);
        j += 1;
    }
    for (idx, &val) in b.iter().enumerate() {
        nodes[idx + l] = val;
    }
    true
}

pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let s = sc.string();
    let mut left = 0;
    let mut right = 100_005;
    while right - left > 1 {
        let n = (left + right) >> 1;

        let mut it = 0;
        let mut nodes = (0..n).collect();
        if !build(&s, &mut it, &mut nodes, 0, n) {
            right = n;
        } else {
            if it == s.len() {
                writeln!(out, "{}", n).unwrap();
                let mut res = vec![0; n];
                for (idx, node) in nodes.iter().enumerate() {
                    res[*node] = idx + 1;
                }
                for r in &res {
                    write!(out, "{} ", r).unwrap();
                }
                return;
            }
            left = n;
        }
    }
    unreachable!();
}