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

mod modulo {
    const MODULO: u32 = 31607;

    #[derive(Copy, Clone, Eq, PartialEq)]
    pub struct Mod(u32);

    impl Mod {
        #[allow(unused)]
        pub const ZERO: Self = Self(0);

        #[allow(unused)]
        pub const ONE: Self = Self(1);

        fn rev_rec(a: u32, m: u32) -> u32 {
            if a == 1 {
                return a;
            }
            return ((1 - Self::rev_rec(m % a, a) as i64 * m as i64) / a as i64 + m as i64) as u32;
        }

        #[allow(dead_code)]
        fn inv(self) -> Mod {
            Mod(Self::rev_rec(self.0, MODULO))
        }

        #[allow(dead_code)]
        pub fn new(mut x: u32) -> Self {
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
            if self.0 <= MAX as u32 {
                write!(f, "{}", self.0)
            } else if self.0 >= MODULO - MAX as u32 {
                write!(f, "-{}", MODULO - self.0)
            } else {
                for denum in 1..MAX {
                    for num in 1..MAX {
                        if Mod(num as u32) / Mod(denum as u32) == *self {
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
            let res = self.0 as i32 - rhs.0 as i32;
            if res < 0 {
                Mod((res + MODULO as i32) as u32)
            } else {
                Mod(res as u32)
            }
        }
    }

    impl std::ops::SubAssign for Mod {
        fn sub_assign(&mut self, rhs: Self) {
            let x = *self - rhs;
            *self = x;
        }
    }

    impl std::ops::Mul for Mod {
        type Output = Mod;

        fn mul(self, rhs: Self) -> Self::Output {
            let res = (self.0) * rhs.0 % (MODULO);
            Mod(res as u32)
        }
    }

    impl std::ops::MulAssign for Mod {
        fn mul_assign(&mut self, rhs: Self) {
            self.0 = ((self.0) * (rhs.0) % (MODULO));
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

/**************************************************

    END OF TEMPLATE CODE

 *************************************************/


pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let n = sc.usize();
    let ten4 = Mod::ONE / Mod::new(10000);
    let mut a = vec![vec![Mod::ZERO; n]; n];
    for i in 0..n {
        for j in 0..n {
            a[i][j] = Mod::new(sc.i32() as u32) * ten4;
        }
    }
    let mut mask_prob = vec![vec![Mod::ZERO; 1 << n]; n];
    for j in 0..n {
        mask_prob[j][0] = Mod::ONE;
        for mask in 1..(1 << n) {
            let mut set_bit = 0;
            while ((1 << set_bit) & mask) == 0 {
                set_bit += 1;
            }
            mask_prob[j][mask] = mask_prob[j][mask ^ (1 << set_bit)] * a[set_bit][j];
        }
    }
    let mut diag_mask_prob = vec![vec![Mod::ZERO; 1 << n]; 2];
    for d in 0..2 {
        diag_mask_prob[d][0] = Mod::ONE;
        for mask in 1..(1 << n) {
            let mut set_bit = 0;
            while ((1 << set_bit) & mask) == 0 {
                set_bit += 1;
            }
            let col = if d == 0 {
                set_bit
            } else {
                n - set_bit - 1
            };
            diag_mask_prob[d][mask] = diag_mask_prob[d][mask ^ (1 << set_bit)] * a[set_bit][col];
        }
    }
    let mut full_row_prob = vec![Mod::ONE; n];
    for i in 0..n {
        for j in 0..n {
            full_row_prob[i] *= a[i][j];
        }
    }
    let mut res = Mod::ZERO;
    // (parity, at least one)
    let mut dp = vec![Mod::ZERO; 4];
    let mut ndp = vec![Mod::ZERO; 4];

    let center = if n % 2 == 1 {
        a[n / 2][n / 2]
    } else {
        Mod::ONE
    };
    let center_inv = Mod::ONE / center;

    for rows_mask in 0..(1 << (n + 2)) {
        let mut cur_pr = Mod::ONE;
        for row in 0..n {
            if ((1 << row) & rows_mask) != 0 {
                cur_pr *= full_row_prob[row];
            }
        }
        let only_rows_mask = rows_mask & ((1 << n) - 1);
        let diag_need_mask = ((1 << n) - 1) ^ only_rows_mask;
        let has_main_diag = ((1 << n) & rows_mask) != 0;
        let has_another_diag = ((1 << (n + 1)) & rows_mask) != 0;
        if ((1 << n) & rows_mask) != 0 {
            cur_pr *= diag_mask_prob[0][diag_need_mask];
        }
        if ((1 << (1 + n)) & rows_mask) != 0 {
            cur_pr *= diag_mask_prob[1][diag_need_mask];
        }
        if has_main_diag && has_another_diag && ((1 << (n / 2)) & rows_mask) == 0 {
            cur_pr *= center_inv;
        }
        for i in 0..4 {
            dp[i] = Mod::ZERO;
        }
        let cur_parity = (rows_mask.count_ones() % 2) as usize;
        let cur_at_least_one = (rows_mask != 0) as usize;
        let state = (cur_parity << 1) | cur_at_least_one;
        dp[state] = cur_pr;
        for col in 0..n {
            for i in 0..4 {
                ndp[i] = Mod::ZERO;
            }
            let mut has_mask = only_rows_mask;
            if has_main_diag {
                has_mask |= 1 << col;
            }
            if has_another_diag {
                has_mask |= 1 << (n - 1 - col);
            }
            let need_mask = ((1 << n) - 1) ^ has_mask;
            let pr_ok = mask_prob[col][need_mask];
            let pr_not_ok = Mod::ONE;
            for parity in 0..2 {
                for at_least in 0..2 {
                    let cur = dp[(parity << 1) | at_least];
                    if cur == Mod::ZERO {
                        continue;
                    }
                    for ok in 0..2 {
                        let next_parity = (parity + ok) & 1;
                        let next_at_lest = at_least | ok;
                        let next_prob = if ok == 0 {
                            cur * pr_not_ok
                        } else {
                            cur * pr_ok
                        };
                        ndp[(next_parity << 1) | next_at_lest] += next_prob;
                    }
                }
            }
            for i in 0..4 {
                dp[i] = ndp[i];
            }
        }
        for parity in 0..2 {
            let cur = dp[(parity << 1) | 1];
            if parity == 1 {
                res += cur;
            } else {
                res -= cur;
            }
        }
    }
    writeln!(out, "{}", res).unwrap();
}