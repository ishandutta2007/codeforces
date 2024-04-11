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

const N: usize = 61;
const SPLIT: usize = 4;

#[derive(Copy, Clone)]
struct Segment {
    from: i32,
    value_pos: i32,
    bit_count: u8,
    pref_sum: [i32; (N + SPLIT - 1) / SPLIT],
}

struct MyStack {
    v: Vec<Segment>,
    bit_from: usize,
    bit_to: usize,
}

impl MyStack {
    fn new(n: i32, value_pos: i32, bit_from: usize, bit_to: usize) -> Self {
        let seg = Segment {
            from: n,
            value_pos,
            bit_count: 0,
            pref_sum: [0; (N + SPLIT - 1) / SPLIT],
        };
        let mut v = vec![];
        v.push(seg);
        Self {
            v,
            bit_from,
            bit_to,
        }
    }

    fn clear(&mut self) {
        while self.v.len() > 1 {
            self.v.pop();
        }
    }

    fn get_suf_cost(&self, from: i32, bit_count: usize) -> i32 {
        if bit_count < self.bit_from || bit_count >= self.bit_to {
            return 0;
        }
        // last elem <= from
        let mut left = 0;
        let mut right = self.v.len();
        while right - left > 1 {
            let mid = (left + right) / 2;
            if self.v[mid - 1].from <= from {
                right = mid;
            } else {
                left = mid;
            }
        }
        let mut ans = self.v[left].pref_sum[bit_count - self.bit_from];
        if from > self.v[left].from && bit_count == self.v[left].bit_count as usize {
            ans -= from - self.v[left].from;
        }
        ans
    }

    fn add_seg(&mut self, from: i32, value_pos: i32, bit_count: usize) {
        let next = self.v.last().unwrap();
        let mut pref_sum = next.pref_sum.clone();
        if bit_count >= self.bit_from && bit_count < self.bit_to {
            pref_sum[bit_count - self.bit_from] += next.from - from;
        }
        let seg = Segment {
            from,
            value_pos,
            bit_count: bit_count as u8,
            pref_sum,
        };
        self.v.push(seg);
    }

    fn get_cost(&self, from: i32, to: i32, bit_count: usize) -> i32 {
        self.get_suf_cost(from, bit_count) - self.get_suf_cost(to, bit_count)
    }
}

fn solve(n: usize, a: &Vec<i64>) -> i64 {
    let mut res = 0i64;

    let mut max_elem = MyStack::new(n as i32, n as i32, 0, 0);
    let mut min_elem = MyStack::new(n as i32, n as i32, 0, 0);

    let splits = [0, N / SPLIT, N * 2 / SPLIT, N * 3 / SPLIT, N];

    for window in splits.windows(2) {
        let bit_from = window[0];
        let bit_to = window[1];
        max_elem.bit_from = bit_from;
        max_elem.bit_to = bit_to;
        min_elem.bit_from = bit_from;
        min_elem.bit_to = bit_to;

        max_elem.clear();
        min_elem.clear();

        let mut cur_ok = 0;
        for left in (0..n).rev() {
            // add left
            let my_val = a[left];

            {
                while max_elem.v.last().unwrap().value_pos != n as i32
                    && a[max_elem.v.last().unwrap().value_pos as usize] < my_val
                {
                    let to_pop = max_elem.v.pop().unwrap();
                    cur_ok -= min_elem.get_cost(
                        to_pop.from,
                        max_elem.v.last().unwrap().from,
                        to_pop.bit_count as usize,
                    );
                }
                cur_ok += min_elem.get_cost(
                    left as i32,
                    max_elem.v.last().unwrap().from,
                    my_val.count_ones() as usize,
                );
                max_elem.add_seg(left as i32, left as i32, my_val.count_ones() as usize);
            }

            {
                while min_elem.v.last().unwrap().value_pos != n as i32
                    && a[min_elem.v.last().unwrap().value_pos as usize] > my_val
                {
                    let to_pop = min_elem.v.pop().unwrap();
                    cur_ok -= max_elem.get_cost(
                        to_pop.from,
                        min_elem.v.last().unwrap().from,
                        to_pop.bit_count as usize,
                    );
                }
                cur_ok += max_elem.get_cost(
                    left as i32,
                    min_elem.v.last().unwrap().from,
                    my_val.count_ones() as usize,
                );
                min_elem.add_seg(left as i32, left as i32, my_val.count_ones() as usize);
            }

            res += cur_ok as i64;
        }
    }
    res
}

#[allow(dead_code)]
struct Random {
    state: u64,
}

impl Random {
    fn next(&mut self) -> u64 {
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
        (from as u64 + self.next() % ((to - from) as u64)) as usize
    }

    #[allow(dead_code)]
    fn next_double(&mut self) -> f64 {
        (self.next() as f64) / (std::usize::MAX as f64)
    }

    #[allow(dead_code)]
    fn new(seed: u64) -> Self {
        assert_ne!(seed, 0);
        Self { state: seed }
    }
}

fn stress() -> bool {
    let n = 1_000_000;
    let mut rnd = Random::new(234234);
    let a: Vec<_> = (0..n).map(|x| rnd.next_in_range(0, 1_000_000_000_000_000_000) as i64).collect();
    let res = solve(n, &a);
    dbg!(res);
    return true;
}

pub fn main() {
    // if (stress()) {
    //     return;
    // }
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let n = sc.usize();
    let a = sc.vec::<i64>(n);

    let res = solve(n, &a);

    writeln!(out, "{}", res).unwrap();
}