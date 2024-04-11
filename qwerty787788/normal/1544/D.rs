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
        let mut want = sc.vec::<usize>(n);
        for i in 0..n {
            want[i] -= 1;
        }
        let mut ans = vec![n; n];
        let mut prev = vec![n; n];
        for i in 0..n {
            let to = want[i];
            if prev[to] == n {
                ans[i] = to;
                prev[to] = i;
            }
        }
        let mut ones = vec![];
        for i in 0..n {
            if ans[i] == n && prev[i] == n {
                ones.push(i);
            }
        }
        if ones.len() == 1 {
            let v = ones[0];
            let to = want[v];
            let p = prev[to];
            assert_ne!(p, n);
            prev[to] = v;
            prev[v] = p;
            ans[p] = v;
            ans[v] = to;
        } else if ones.len() > 1 {
            for i in 0..ones.len() {
                let x = ones[i];
                let y = ones[(i + 1) % ones.len()];
                ans[x] = y;
                prev[y] = x;
            }
        }
        for i in 0..n {
            if ans[i] == n {
                let mut cur = i;
                while prev[cur] != n {
                    cur = prev[cur];
                }
                assert_ne!(cur, i);
                ans[i] = cur;
                prev[cur] = i;
            }
        }
        let mut done = 0;
        for i in 0..n {
            if ans[i] == want[i] {
                done += 1;
            }
            assert_ne!(ans[i], i);
            assert_ne!(ans[i], n);
        }
        writeln!(out, "{}", done).unwrap();
        for i in 0..n {
            write!(out, "{} ", ans[i] + 1).unwrap();
        }
        writeln!(out).unwrap();
    }
}