use std::io;
use std::io::{Write, BufWriter, StdoutLock};

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

fn query(out: &mut BufWriter<StdoutLock>, sc: &mut Scanner, v: &[usize]) -> i32 {
    write!(out, "?").unwrap();
    for x in v.iter() {
        write!(out, " {}", x).unwrap();
    }
    writeln!(out).unwrap();
    out.flush().unwrap();
    sc.i32()
}

pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let n = sc.usize();
    let k = sc.usize();
    let mut best = vec![std::usize::MAX; n + 1];
    let mut last_size = vec![0; n + 1];
    best[0] = 0;
    for known in 0..n {
        if best[known] == std::usize::MAX {
            continue;
        }
        if known + k <= n {
            if best[known + k] > best[known] + 1 {
                best[known + k] = best[known] + 1;
                last_size[known + k] = k;
            }
        }
        for same in 0..k {
            let add = (k - same) * 2;
            let total = same + add;
            if total > n {
                continue;
            }
            let next = known + add;
            if next <= n && best[next] > best[known] + 2 {
                best[next] = best[known] + 2;
                last_size[next] = same;
            }
        }
    }
    if best[n] == std::usize::MAX {
        writeln!(out, "-1").unwrap();
    } else {
        let mut need = n;
        let mut res = 0;
        while need != 0 {
            let last_size = last_size[need];
            if last_size == k {
                let mut check = vec![];
                for i in 0..k {
                    check.push(need - i);
                }
                res ^= query(&mut out, &mut sc, &check);
                need -= k;
            } else {
                let same = last_size;
                let add = k - same;
                let mut v1 = vec![];
                let mut v2 = vec![];
                for i in 0..add {
                    v1.push(need - i);
                    v2.push(need - i - add);
                }
                for i in 1..=n {
                    if v1.len() == k {
                        break;
                    }
                    if i <= need && i > need - add * 2 {
                        continue;
                    }
                    v1.push(i);
                    v2.push(i);
                }
                need -= add * 2;
                res ^= query(&mut out, &mut sc, &v1);
                res ^= query(&mut out, &mut sc, &v2);
            }
        }
        writeln!(out, "! {}", res).unwrap();
    }
}