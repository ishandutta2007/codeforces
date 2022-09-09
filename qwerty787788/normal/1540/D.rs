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

#[allow(dead_code)]
pub struct Fenwick {
    values: Vec<i32>
}

impl Fenwick {
    #[allow(dead_code)]
    fn get_sum(&self, mut pos: usize) -> i32 {
        let mut res = 0i32;
        loop {
            res += self.values[pos] as i32;
            pos = pos & (pos + 1);
            if pos == 0 {
                return res;
            }
            pos -= 1;
        }
    }

    #[allow(dead_code)]
    fn add(&mut self, mut pos: usize, change: i32) {
        while pos < self.values.len() {
            self.values[pos] += change;
            pos |= pos + 1;
        }
    }

    #[allow(dead_code)]
    pub(crate) fn new(n: usize) -> Self {
        let values = vec![0; n];
        Fenwick { values }
    }
}


/**************************************************

    END OF TEMPLATE CODE

 *************************************************/


#[derive(Copy, Clone)]
struct SetValue {
    val: usize,
    time: usize,
}

#[derive(Copy, Clone)]
struct Query {
    val: usize,
    time: usize,
}

pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let n = sc.usize();
    let mut b = sc.vec::<usize>(n);
    let mut set_events = vec![vec![]; n];
    for i in 0..n {
        set_events[i].push(SetValue { time: 0, val: b[i] });
    }
    let mut queries = vec![vec![]; n];
    let q = sc.usize();
    let mut time = 0;
    let mut answers = vec![0; q];
    for _ in 0..q {
        let q_type = sc.usize();
        let pos = sc.usize() - 1;
        if q_type == 1 {
            let val = sc.usize();
            set_events[pos].push(SetValue { time, val });
            b[pos] = val;
        } else {
            queries[pos].push(Query { val: b[pos], time });
            time += 1;
        }
    }
    for pos in 0..n {
        set_events[pos].push(SetValue { time, val: 0 });
        for evs in set_events[pos].windows(2) {
            update_ans(&mut answers, evs)
        }
        for q in queries[pos].iter() {
            answers[q.time] = q.val;
        }
    }
    for t in 0..time {
        writeln!(out, "{}", n - answers[t]).unwrap();
    }
}

#[inline(never)]
fn update_ans(answers: &mut Vec<usize>, evs: &[SetValue]) {
    for cur_ans in answers[evs[0].time..evs[1].time].iter_mut() {
        *cur_ans += (*cur_ans >= evs[0].val) as usize;
    }
}