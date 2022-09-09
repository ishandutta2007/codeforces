use std::io;
use std::io::Write;
use std::collections::BTreeMap;

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

#[derive(Ord, PartialOrd, Eq, PartialEq, Copy, Clone)]
struct Monitor {
    h: usize,
    w: usize,
}

impl Monitor {
    fn is_square(&self) -> bool {
        self.h == self.w
    }
}

pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let n = sc.usize();
    let monitors: Vec<_> = (0..n).map(|_| {
        let h = sc.usize();
        let w = sc.usize();
        Monitor { h, w }
    }).collect();
    let mut seen_numbers: BTreeMap<usize, i64> = BTreeMap::new();
    let mut seen_monitors: BTreeMap<Monitor, i64> = BTreeMap::new();
    let mut res = 0i64;
    for monitor in &monitors {
        res += seen_numbers.get(&monitor.h).unwrap_or(&0);
        if !monitor.is_square() {
            res += seen_numbers.get(&monitor.w).unwrap_or(&0);
        }
        if !monitor.is_square() {
            res -= seen_monitors.get(&monitor).unwrap_or(&0);
            res -= seen_monitors.get(&Monitor { h: monitor.w, w: monitor.h }).unwrap_or(&0);
        }
        *seen_numbers.entry(monitor.h).or_default() += 1;
        if !monitor.is_square() {
            *seen_numbers.entry(monitor.w).or_default() += 1;
        }
        *seen_monitors.entry(monitor.clone()).or_default() += 1;
    }
    writeln!(out, "{}", res).unwrap();
}