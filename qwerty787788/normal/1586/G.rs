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

mod modulo {
    const MODULO: i32 = 1_000_000_007;

    #[derive(Copy, Clone, Eq, PartialEq)]
    pub struct Mod(i32);

    impl Mod {
        #[allow(unused)]
        pub const ZERO: Self = Self(0);

        #[allow(unused)]
        pub const ONE: Self = Self(1);

        fn rev_rec(a: i32, m: i32) -> i32 {
            if a == 1 {
                return a;
            }
            return ((1 - Self::rev_rec(m % a, a) as i64 * m as i64) / a as i64 + m as i64) as i32;
        }

        #[allow(dead_code)]
        fn inv(self) -> Mod {
            Mod(Self::rev_rec(self.0, MODULO))
        }

        #[allow(dead_code)]
        pub fn new(mut x: i32) -> Self {
            if x < 0 {
                x += MODULO;
            } else if x >= MODULO {
                x -= MODULO;
            }
            assert!(0 <= x && x < MODULO);
            Self(x)
        }
    }

    impl std::fmt::Display for Mod {
        fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
            write!(f, "{}", self.0)
        }
    }

    impl std::fmt::Debug for Mod {
        fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
            const MAX: usize = 100;
            if self.0 <= MAX as i32 {
                write!(f, "{}", self.0)
            } else if self.0 >= MODULO - MAX as i32 {
                write!(f, "-{}", MODULO - self.0)
            } else {
                for denum in 1..MAX {
                    for num in 1..MAX {
                        if Mod(num as i32) / Mod(denum as i32) == *self {
                            return write!(f, "{}/{}", num, denum);
                        }
                    }
                }
                write!(f, "(?? {} ??)", self.0)
            }
        }
    }

    impl std::ops::Add for Mod {
        type Output = Mod;

        fn add(self, rhs: Self) -> Self::Output {
            let res = self.0 + rhs.0;
            if res >= MODULO {
                Mod(res - MODULO)
            } else {
                Mod(res)
            }
        }
    }

    impl std::ops::AddAssign for Mod {
        fn add_assign(&mut self, rhs: Self) {
            self.0 += rhs.0;
            if self.0 >= MODULO {
                self.0 -= MODULO;
            }
        }
    }

    impl std::ops::Sub for Mod {
        type Output = Mod;

        fn sub(self, rhs: Self) -> Self::Output {
            let res = self.0 - rhs.0;
            if res < 0 {
                Mod(res + MODULO)
            } else {
                Mod(res)
            }
        }
    }

    impl std::ops::SubAssign for Mod {
        fn sub_assign(&mut self, rhs: Self) {
            self.0 -= rhs.0;
            if self.0 < 0 {
                self.0 += MODULO;
            }
        }
    }

    impl std::ops::Mul for Mod {
        type Output = Mod;

        fn mul(self, rhs: Self) -> Self::Output {
            let res = (self.0 as i64) * (rhs.0 as i64) % (MODULO as i64);
            Mod(res as i32)
        }
    }

    impl std::ops::MulAssign for Mod {
        fn mul_assign(&mut self, rhs: Self) {
            self.0 = ((self.0 as i64) * (rhs.0 as i64) % (MODULO as i64)) as i32;
        }
    }

    impl std::ops::Div for Mod {
        type Output = Mod;

        fn div(self, rhs: Self) -> Self::Output {
            let rhs_inv = rhs.inv();
            self * rhs_inv
        }
    }

    impl std::ops::DivAssign for Mod {
        fn div_assign(&mut self, rhs: Self) {
            *self *= rhs.inv();
        }
    }
}

use modulo::*;

#[allow(dead_code)]
pub struct Fenwick {
    values: Vec<Mod>,
}

impl Fenwick {
    #[allow(dead_code)]
    fn get_sum(&self, mut pos: usize) -> Mod {
        let mut res = Mod::ZERO;
        loop {
            res += self.values[pos];
            pos = pos & (pos + 1);
            if pos == 0 {
                return res;
            }
            pos -= 1;
        }
    }

    #[allow(dead_code)]
    fn add(&mut self, mut pos: usize, change: Mod) {
        while pos < self.values.len() {
            self.values[pos] += change;
            pos |= pos + 1;
        }
    }

    #[allow(dead_code)]
    pub(crate) fn new(n: usize) -> Self {
        let values = vec![Mod::ZERO; n];
        Fenwick { values }
    }
}


pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let n = sc.usize();
    let mut left = vec![0; n];
    let mut right = vec![0; n];

    let mut right_end_of = vec![n; 2 * n];

    for i in 0..n {
        left[i] = sc.usize() - 1;
        right[i] = sc.usize() - 1;

        right_end_of[right[i]] = i;
    }

    let mut required_times = vec![];
    let size = sc.usize();
    for _ in 0..size {
        let id = sc.usize() - 1;
        required_times.push(right[id]);
    }
    required_times.sort();

    let max_time = 2 * n;

    let mut to_ask = vec![vec![]; max_time];

    let mut iter = required_times.len() - 1;

    let last_required_time = required_times[iter];

    loop {
        let last = required_times[iter];
        let last_task_id = right_end_of[last];
        assert_ne!(n, last_task_id);
        let all_done_before = left[last_task_id];
        let mut found = false;
        loop {
            if iter == 0 {
                // not found
                break;
            }
            iter -= 1;
            let task_id = right_end_of[required_times[iter]];
            if left[task_id] < all_done_before {
                continue;
            }
            found = true;
            break;
        }
        if !found {
            break;
        }
        to_ask[required_times[iter]].push(all_done_before);
    }


    let mut fenw_cycles = Fenwick::new(max_time);
    let mut cycle = vec![Mod::ZERO; n];

    // single jump from [last_required_time]
    let mut res = Mod::ONE;

    for time in 0..max_time {
        let task_id = right_end_of[time];
        if task_id == n {
            continue;
        }
        cycle[task_id] = Mod::ONE;
        cycle[task_id] += fenw_cycles.get_sum(time) - fenw_cycles.get_sum(left[task_id]);

        for &query in to_ask[time].iter() {
            res += fenw_cycles.get_sum(time) - fenw_cycles.get_sum(query);
            res += Mod::ONE;
        }

        fenw_cycles.add(left[task_id], cycle[task_id]);

        if time < last_required_time {
            res += cycle[task_id];
        }
    }
    writeln!(out, "{}", res).unwrap();
}