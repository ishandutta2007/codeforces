use std::io;
use std::io::Write;
use std::cmp::Ordering;

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


#[derive(Ord, PartialOrd, Eq, PartialEq, Debug)]
struct Pos {
    x: usize,
    y: usize,
}

pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let n = sc.usize();
    let mut xx = vec![];
    let mut yy = vec![];
    for _ in 0..n {
        let x = sc.i32();
        let y = sc.i32();
        xx.push(x);
        yy.push(y);
    }
    let mut all_pos = vec![];
    for x in 0..4 {
        for y in 0..4 {
            all_pos.push(Pos { x, y });
        }
    }
    let mut res = 0i64;
    for first in 0..n {
        let mut cnt = vec![vec![0; 4]; 4];
        for second in first + 1..n {
            cnt[(((xx[second] - xx[first]) % 4 + 4) % 4) as usize][(((yy[second] - yy[first]) % 4 + 4) % 4) as usize] += 1;
        }
        for p1 in all_pos.iter() {
            for p2 in all_pos.iter() {
                if p1.cmp(&p2) == Ordering::Less {
                    continue;
                }
                let mut sum_gcd = 0;
                if p1.x != 0 || p1.y != 0 {
                    sum_gcd += 2;
                }
                if p2.x != 0 || p2.y != 0 {
                    sum_gcd += 2;
                }
                let dx = (p1.x as i32 - p2.x as i32).abs() % 4;
                let dy = (p1.y as i32 - p2.y as i32).abs() % 4;
                if dx != 0 || dy != 0 {
                    sum_gcd += 2;
                }
                if sum_gcd == 0 || sum_gcd == 4 {
                    let w1 = cnt[p1.x][p1.y];
                    let w2 = cnt[p2.x][p2.y];
                    if !p1.eq(&p2) {
                        res += w1 as i64 * w2 as i64;
                    } else {
                        let w1 = w1 as i64;
                        res += w1 * (w1 - 1) / 2;
                    }
                }
            }
        }
    }
    writeln!(out, "{}", res).unwrap();
}