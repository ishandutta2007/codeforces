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

#[allow(dead_code)]
struct Random {
    state: usize
}

impl Random {
    fn next(&mut self) -> usize {
        let mut x = self.state;
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        self.state = x;
        x
    }

    #[allow(dead_code)]
    fn next_in_range(&mut self, from: usize, to: usize) -> usize {
        assert!(from < to);
        from + self.next() % (to - from)
    }

    #[allow(dead_code)]
    fn next_double(&mut self) -> f64 {
        (self.next() as f64) / (std::usize::MAX as f64)
    }

    #[allow(dead_code)]
    fn new(seed: usize) -> Self {
        assert_ne!(seed, 0);
        Self {
            state: seed,
        }
    }
}

/**************************************************

    END OF TEMPLATE CODE

 *************************************************/


pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let n = sc.usize();
    let m = sc.usize();
    let p = sc.usize();

    let mut masks = vec![];

    for _ in 0..n {
        let s = sc.string();
        let mut mask = 0;
        for j in 0..m {
            if s[j] == b'1' {
                mask |= 1u64 << j;
            }
        }
        masks.push(mask);
    }
    let mut best = 0u64;
    let mut rnd = Random::new(787788);
    let mut dp = vec![0; 1 << p];
    for _ in 0..100 {
        let id = rnd.next_in_range(0, n);
        let mut ids = vec![];
        for i in 0..m {
            if (masks[id] >> i) & 1 == 1 {
                ids.push(i);
            }
        }
        assert!(ids.len() <= p);
        for x in dp.iter_mut() {
            *x = 0;
        }
        for i in 0..n {
            let mut cur_mask = 0;
            for (pos, v) in ids.iter().enumerate() {
                if (masks[i] >> v) & 1 == 1 {
                    cur_mask |= 1 << pos;
                }
            }
            dp[cur_mask] += 1;
        }
        for bit in 0..p {
            for mask in (0..dp.len()).rev() {
                if mask & (1 << bit) != 0 {
                    dp[mask ^ (1 << bit)] += dp[mask];
                }
            }
        }
        let at_least = (n + 1) / 2;
        let mut cur_best_mask = 0usize;
        for mask in 0..dp.len() {
            if dp[mask] >= at_least && mask.count_ones() > cur_best_mask.count_ones() {
                cur_best_mask = mask;
            }
        }
        if cur_best_mask.count_ones() > best.count_ones() {
            let mut real_mask = 0;
            for i in 0..p {
                if (cur_best_mask >> i) & 1 != 0 {
                    real_mask |= 1u64 << ids[i];
                }
            }
            best = real_mask;
        }
    }
    for x in 0..m {
        if (best >> x) & 1 != 0 {
            write!(out, "1").unwrap();
        } else {
            write!(out, "0").unwrap();
        }
    }
    writeln!(out).unwrap();
}