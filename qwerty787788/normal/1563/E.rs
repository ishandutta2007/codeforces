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


pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let tc = sc.usize();
    for _ in 0..tc {
        let n = sc.usize();
        let m = sc.usize();
        let mut more_than = vec![-1; n];
        for i in 1..n {
            more_than[i] = sc.i64();
        }
        let mut add = vec![0; n];
        for i in 1..n {
            add[i] = sc.i64();
        }
        let mut g = vec![vec![]; n];
        for _ in 0..m {
            let fr = sc.usize() - 1;
            let to = sc.usize() - 1;
            g[fr].push(to);
            g[to].push(fr);
        }
        let mut left = -1;
        let mut right = 1e10 as i64;

        while right - left > 1 {
            let start_power = (left + right) >> 1;

            let mut seen = vec![false; n];
            seen[0] = true;
            let mut all_seen;
            let mut now_power = start_power;
            let mut cur_power = vec![0; n];

            loop {
                let mut prev: Vec<_> = (0..n).collect();
                let mut queue = vec![];
                all_seen = true;
                for i in 0..n {
                    if !seen[i] {
                        all_seen = false;
                    } else {
                        queue.push(i);
                        cur_power[i] = now_power;
                    }
                }
                if all_seen {
                    break;
                }
                let mut v1 = n;
                let mut v2 = n;
                while let Some(v) = queue.pop() {
                    if v1 != n {
                        break;
                    }
                    for &to in g[v].iter() {
                        if to == prev[v] {
                            continue;
                        }
                        if seen[to] {
                            if seen[v] {
                                continue;
                            } else {
                                v1 = v;
                                v2 = v;
                                break;
                            }
                        }
                        assert!(!seen[to]);
                        if prev[to] == to {
                            if cur_power[v] <= more_than[to] {
                                continue;
                            }
                            cur_power[to] = cur_power[v] + add[to];
                            prev[to] = v;
                            queue.push(to);
                        } else {
                            v1 = v;
                            v2 = to;
                            break;
                        }
                    }
                }
                if v1 == n {
                    break;
                }
                assert!(!seen[v2]);
                while !seen[v1] {
                    seen[v1] = true;
                    now_power += add[v1];
                    v1 = prev[v1];
                }
                while !seen[v2] {
                    seen[v2] = true;
                    now_power += add[v2];
                    v2 = prev[v2];
                }
            }
            if all_seen {
                right = start_power;
            } else {
                left = start_power;
            }
        }
        writeln!(out, "{}", right).unwrap();
    }
}