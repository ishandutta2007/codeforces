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


fn make_move(a: &mut Vec<usize>, moves: &mut Vec<usize>, pos: usize) {
    assert_eq!(pos % 2, 0);
    if pos == 0 {
        return;
    }
    moves.push(pos);
    let mut l = 0;
    let mut r = pos;
    while l < r {
        a.swap(l, r);
        l += 1;
        r -= 1;
    }
}

pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let tc = sc.usize();
    for _ in 0..tc {
        let n = sc.usize();
        let mut a = vec![0; n];
        for i in 0..n {
            a[i] = sc.usize() - 1;
        }
        let mut can = true;
        for i in 0..n {
            if i % 2 != a[i] % 2 {
                can = false;
                break;
            }
        }
        if !can {
            writeln!(out, "-1").unwrap();
        } else {
            let mut moves = vec![];
            let mut cur_n = n;
            while cur_n != 1 {
                let mut pos_of_last = 0;
                for i in 0..cur_n {
                    if a[i] == cur_n - 1 {
                        pos_of_last = i;
                    }
                }
                make_move(&mut a, &mut moves, pos_of_last);
                let mut pos_of_last1 = 0;
                for i in 0..cur_n {
                    if a[i] == cur_n - 2 {
                        pos_of_last1 = i;
                    }
                }
                make_move(&mut a, &mut moves, pos_of_last1 - 1);
                make_move(&mut a, &mut moves, pos_of_last1 + 1);
                make_move(&mut a, &mut moves, 2);
                make_move(&mut a, &mut moves, cur_n - 1);
                assert_eq!(a[cur_n - 1], cur_n - 1);
                assert_eq!(a[cur_n - 2], cur_n - 2);
                cur_n -= 2;
            }
            for i in 0..n {
                assert_eq!(a[i], i);
            }
            assert!(moves.len() <= n * 5 / 2);
            writeln!(out, "{}", moves.len()).unwrap();
            for m in moves.iter() {
                write!(out, "{} ", m + 1).unwrap();
            }
            writeln!(out).unwrap();
        }
    }
}