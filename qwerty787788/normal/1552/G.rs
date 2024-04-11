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

#[derive(Debug)]
struct State {
    pos_to_sort: Vec<u64>,
    new_here_len: Vec<usize>,
    precalc: Vec<Vec<u64>>,
    values: Vec<u64>,
}

fn is_ok(s: &mut State, lvl: usize) -> bool {
    if lvl == s.pos_to_sort.len() {
        if (s.values[lvl] + 1).count_ones() != 1 {
            return false;
        }
        return true;
    }
    s.values[lvl + 1] = s.values[lvl];
    let cnt_ones_now = (s.values[lvl] & s.pos_to_sort[lvl]).count_ones() as usize;
    for ones_here in 0..=s.new_here_len[lvl] {
        s.values[lvl + 1] &= !s.pos_to_sort[lvl];
        s.values[lvl + 1] |= s.precalc[lvl][cnt_ones_now + ones_here];
        if !is_ok(s, lvl + 1) {
            return false;
        }
    }
    true
}

pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let n = sc.usize();
    let k = sc.usize();
    let mut pos_to_sort = vec![];
    let mut new_here_len = vec![];
    let mut used = vec![false; n];
    let mut precalc = vec![];
    for _ in 0..k {
        let cnt = sc.usize();
        let mut indx = sc.vec::<usize>(cnt);
        for x in indx.iter_mut() {
            *x -= 1;
        }
        let mut new_h = vec![];
        for &x in indx.iter() {
            if !used[x] {
                used[x] = true;
                new_h.push(x);
            }
        }
        new_here_len.push(new_h.len());
        let mut pre = vec![];
        for used in 0..=cnt {
            let mut mask = 0u64;
            for i in 0..used {
                mask |= 1u64 << indx[i];
            }
            pre.push(mask);
        }
        pos_to_sort.push(*pre.last().unwrap());
        precalc.push(pre);
    }
    let mut all_used = true;
    for u in used.iter() {
        if !u {
            all_used = false;
        }
    }
    let mut state = State { pos_to_sort, new_here_len, values: vec![0; k + 1], precalc };
    if (all_used || n == 1) && is_ok(&mut state, 0) {
        writeln!(out, "ACCEPTED").unwrap();
    } else {
        writeln!(out, "REJECTED").unwrap();
    }
}