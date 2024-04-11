use std::io;
use std::io::Write;
use std::cmp::{min, max};

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


#[derive(Copy, Clone, Debug, Ord, PartialOrd, Eq, PartialEq)]
struct Point {
    x: i32,
    y: i32,
}

impl Point {
    fn dist(&self, another: &Point) -> i32 {
        (self.x - another.x).abs() + (self.y - another.y).abs()
    }
}

#[derive(Copy, Clone, Debug, Ord, PartialOrd, Eq, PartialEq)]
struct Event {
    time: i32,
    p: Point,
}

pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let n = sc.usize();
    let m = sc.usize();

    let a: Vec<_> = (0..n).map(|_| {
        let x = sc.i32();
        let y = sc.i32();

        Point { x, y }
    }).collect();

    let mut b: Vec<_> = (0..m).map(|_| {
        let x = sc.i32();
        let y = sc.i32();
        let time = sc.i32();
        let p = Point { x, y };
        Event { p, time }
    }).collect();
    b.sort();

    // (mask, which one) -> score
    let mut last_quest = vec![vec![std::i32::MIN; m]; 1 << n];
    for i in 0..m {
        last_quest[0][i] = 1;
    }
    // (mask, done) -> smallest time
    let mut last_tower = vec![vec![std::i32::MAX; m + 1]; 1 << n];
    for i in 0..n {
        last_tower[1 << i][0] = 0;
    }
    for mask in 0..(1 << n) {
        for next in 0..m {
            let mut need = std::i32::MAX;
            for i in 0..n {
                if (mask >> i) & 1 != 0 {
                    need = min(need, a[i].dist(&b[next].p))
                }
            }
            for prev_quest in 0..next {
                if last_quest[mask][prev_quest] == std::i32::MIN {
                    continue;
                }
                let d = min(b[prev_quest].p.dist(&b[next].p), need);
                if b[prev_quest].time + d <= b[next].time {
                    last_quest[mask][next] = max(last_quest[mask][next], last_quest[mask][prev_quest] + 1);
                }
            }
            if need != std::i32::MAX {
                for done in 0..m {
                    if last_tower[mask][done] == std::i32::MAX {
                        continue;
                    }
                    if last_tower[mask][done] + need <= b[next].time {
                        last_quest[mask][next] = max(last_quest[mask][next], (done + 1) as i32);
                    }
                }
            }
        }
        for next_tower in 0..n {
            if (mask >> next_tower) & 1 != 0 {
                continue;
            }
            let mut need = std::i32::MAX;
            for i in 0..n {
                if (mask >> i) & 1 != 0 {
                    need = min(need, a[i].dist(&a[next_tower]));
                }
            }
            let nmask = mask | (1 << next_tower);
            if need != std::i32::MAX {
                for done in 0..=m {
                    if last_tower[mask][done] == std::i32::MAX {
                        continue;
                    }
                    last_tower[nmask][done] = min(last_tower[nmask][done], last_tower[mask][done] + need);
                }
            }
            for i in 0..m {
                if last_quest[mask][i] == std::i32::MIN {
                    continue;
                }
                let d = min(need, b[i].p.dist(&a[next_tower]));
                let done = last_quest[mask][i] as usize;
                last_tower[nmask][done] = min(last_tower[nmask][done], b[i].time + d);
            }
        }
    }
    let mut res = 0;
    for mask in 0..(1 << n) {
        for quest in 0..m {
            res = max(res, last_quest[mask][quest]);
        }
    }
    writeln!(out, "{}", res).unwrap();
}