use std::io;
use std::io::{Write, BufWriter, StdoutLock};
use std::cmp::min;

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

fn query(sc: &mut Scanner, out: &mut BufWriter<StdoutLock>, n: usize, pref_add: usize, suff_add: usize) -> usize {
    write!(out, "?").unwrap();
    for v in 0..n {
        let val = if v == n - 1 {
            suff_add
        } else {
            pref_add
        };
        write!(out, " {}", val).unwrap();
    }
    writeln!(out).unwrap();
    out.flush().unwrap();
    sc.usize()
}

pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();
    let n = sc.usize();
    let mut delta = vec![0; n];
    for first in 2..=n {
        let pos = query(&mut sc, &mut out, n, first, 1);
        if pos != 0 {
            delta[pos - 1] = ((first - 1) as i32) * -1;
        }
    }
    for last in 2..=n {
        let pos = query(&mut sc, &mut out, n, 1, last);
        if pos != 0 {
            delta[pos - 1] = (last - 1) as i32;
        }
    }
    for i in 0..(n - 1) {
        assert_ne!(delta[i], 0);
    }
    let mut smallest = 0;
    for &val in delta.iter() {
        smallest = min(smallest, val);
    }
    for val in delta.iter_mut() {
        *val -= smallest;
    }
    write!(out, "!").unwrap();
    for val in delta.iter() {
        write!(out, " {}", val + 1).unwrap();
    }
    writeln!(out).unwrap();
}