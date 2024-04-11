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
        let s = sc.string();
        let mut cnt = vec![0; 26];
        for c in s.iter() {
            let x = c - b'a';
            let x = x as usize;
            cnt[x] += 1;
        }
        let mut exist_one = false;
        let mut one = 0;
        for i in 0..26 {
            if cnt[i] == 1 {
                exist_one = true;
                one = i;
                break;
            }
        }
        let mut res = vec![];
        if exist_one {
            cnt[one] -= 1;
            res.push(one);
            for i in 0..26 {
                while cnt[i] > 0 {
                    cnt[i] -= 1;
                    res.push(i);
                }
            }
        } else {
            let mut m1 = 0;
            while cnt[m1] == 0 {
                m1 += 1;
            }
            let max_use = 2 + (s.len() - 2) / 2;
            if max_use >= cnt[m1] {
                res.push(m1);
                res.push(m1);
                cnt[m1] -= 2;
                let mut need_another = true;
                let mut iter = m1 + 1;
                while res.len() < s.len() {
                    if need_another || cnt[m1] == 0 {
                        while cnt[iter] == 0 {
                            iter += 1;
                        }
                        res.push(iter);
                        cnt[iter] -= 1;
                        need_another = false;
                    } else {
                        need_another = true;
                        cnt[m1] -= 1;
                        res.push(m1);
                    }
                }
            } else {
                let mut m2 = m1 + 1;
                while m2 != 26 && cnt[m2] == 0 {
                    m2 += 1;
                }
                if m2 == 26 {
                    while cnt[m1] > 0 {
                        cnt[m1] -= 1;
                        res.push(m1);
                    }
                } else {
                    assert!(cnt[m2] > 1);
                    let mut m3 = m2 + 1;
                    while m3 != 26 && cnt[m3] == 0 {
                        m3 += 1;
                    }
                    if m3 == 26 {
                        res.push(m1);
                        cnt[m1] -= 1;
                        while cnt[m2] != 0 {
                            cnt[m2] -= 1;
                            res.push(m2);
                        }
                        while cnt[m1] != 0 {
                            cnt[m1] -= 1;
                            res.push(m1);
                        }
                        assert_eq!(res.len(), s.len());
                    } else {
                        res.push(m1);
                        cnt[m1] -= 1;
                        res.push(m2);
                        cnt[m2] -= 1;
                        while cnt[m1] != 0 {
                            cnt[m1] -= 1;
                            res.push(m1);
                        }
                        cnt[m3] -= 1;
                        res.push(m3);
                        while cnt[m2] != 0 {
                            cnt[m2] -= 1;
                            res.push(m2);
                        }
                        let mut iter = 0;
                        while res.len() != s.len() {
                            while cnt[iter] != 0 {
                                cnt[iter] -= 1;
                                res.push(iter);
                            }
                            iter += 1;
                        }
                    }
                }
            }
        }
        let res_c: Vec<_> = res.iter().map(|c| b'a' + (*c as u8)).collect();
        writeln!(out, "{}", String::from_utf8(res_c).unwrap()).unwrap();
    }
}