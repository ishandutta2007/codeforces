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
        Self {
            buffer: vec![],
            input_source: InputSource::Stdin,
        }
    }

    #[allow(dead_code)]
    fn new_file(filename: &str) -> Self {
        let file = std::fs::read_to_string(filename).unwrap();
        let mut lines: Vec<String> = file.lines().map(|line| String::from(line)).collect();
        lines.reverse();
        Self {
            buffer: vec![],
            input_source: InputSource::FromFile(lines),
        }
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
            InputSource::Stdin => {
                if std::io::stdin().read_line(&mut input).expect("Failed read") == 0 {
                    return false;
                }
            }
            InputSource::FromFile(lines) => match lines.pop() {
                Some(line) => input = line,
                None => return false,
            },
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

    const MAX: usize = 1_000_005;
    let mut is_prime = vec![true; MAX];
    is_prime[1] = false;
    for v in 2..MAX {
        if is_prime[v] {
            for u in (v * 2..MAX).step_by(v) {
                is_prime[u] = false;
            }
        }
    }

    let tc = sc.usize();
    for _ in 0..tc {
        let n = sc.usize();
        let delta = sc.usize();
        let mut a_primes = vec![false; n];
        let mut is_one = vec![false; n];
        let mut cnt_primes = 0;
        for i in 0..n {
            let val = sc.usize();
            a_primes[i] = is_prime[val];
            is_one[i] = val == 1;
            if a_primes[i] {
                cnt_primes += 1;
            }
        }
        let mut res = 0i64;
        for pos in 0..n {
            if !a_primes[pos] {
                continue;
            }
            let mut cnt_left = 0;
            while (1 + cnt_left) * delta <= pos
                && !a_primes[pos - (1 + cnt_left) * delta]
                && is_one[pos - (1 + cnt_left) * delta]
            {
                cnt_left += 1;
            }
            let mut cnt_right = 0;
            while pos + (1 + cnt_right) * delta < n
                && !a_primes[pos + (1 + cnt_right) * delta]
                && is_one[pos + (1 + cnt_right) * delta]
            {
                cnt_right += 1;
            }
            res += (1 + cnt_left as i64) * (1 + cnt_right as i64);
        }
        res -= cnt_primes as i64;
        writeln!(out, "{}", res).unwrap();
    }
}