use crate::reader::Reader;

fn main() {
    let mut sc = Reader::new();
    let tests = sc.read_integer();
    for _ in 0..tests {
        solve(&mut sc);
    }
}

fn solve(sc: &mut Reader) {
    let n = sc.read_integer();
    let mut a = vec![0; n];
    for i in 0..n {
        a[i] = sc.read_integer();
    }
    let mut b = vec![0; n];
    let ans = calc_inversions(&mut a, &mut b, 0, n);
    println!("{}", ans);
}

fn calc_inversions(a: &mut Vec<usize>, b: &mut Vec<usize>, left: usize, right: usize) -> u64 {
    if left + 1 == right {
        return 0;
    }
    let mid = (left + right) >> 1;
    let mut answer = calc_inversions(a, b, left, mid) + calc_inversions(a, b, mid, right);
    let mut i = left;
    let mut j = mid;
    let mut k = 0;
    while i < mid || j < right {
        if j >= right || (i < mid && a[i] < a[j]) {
            b[k] = a[i];
            i += 1;
        } else {
            b[k] = a[j];
            j += 1;
            answer += (mid - i) as u64;
        }
        k += 1
    }
    for i in 0..k {
        a[i + left] = b[i];
    }
    answer
}

mod reader {
    use std::fmt::Debug;
    use std::io;
    use std::io::{Read, Stdin};
    use std::iter::{Peekable, Iterator};
    use std::str::FromStr;
    use std::vec::IntoIter;

    pub struct Reader {
        input: Stdin,
        buf: Peekable<IntoIter<u8>>,
    }

    impl Reader {
        pub fn new() -> Self {
            Self {
                input: io::stdin(),
                buf: Vec::new().into_iter().peekable(),
            }
        }

        fn refill_buffer(&mut self) {
            while self.buf.peek().is_none() {
                let mut buf = vec![0; 65536];
                let read_bytes = self.input.read(&mut buf).unwrap();
                if read_bytes == 0 {
                    return;
                }
                self.buf = buf.into_iter().peekable();
            }
        }

        fn peek(&mut self) -> Option<u8> {
            self.refill_buffer();
            self.buf.peek().map(|x| *x)
        }

        fn get(&mut self) -> Option<u8> {
            self.refill_buffer();
            self.buf.next()
        }

        fn read_line_safe(&mut self) -> Option<String> {
            let mut str = String::new();
            while let Some(ch) = self.get() {
                if ch == b'\n' {
                    break;
                }
                if ch == b'\r' {
                    if self.peek() == Some(b'\n') {
                        self.get();
                    }
                    break;
                }
                str.push(ch as char);
            }
            if str.is_empty() {
                None
            } else {
                Some(str)
            }
        }

        fn read_token_safe(&mut self) -> Option<String> {
            while (self.peek()? as char).is_whitespace() {
                self.get();
            }
            let mut str = String::new();
            while let Some(ch) = self.get() {
                if (ch as char).is_whitespace() {
                    break;
                }
                str.push(ch as char);
            }
            if str.is_empty() {
                None
            } else {
                Some(str)
            }
        }

        pub fn read_integer<T: FromStr>(&mut self) -> T
            where <T as FromStr>::Err: Debug,
        {
            self.read_token_safe().unwrap().parse::<T>().unwrap()
        }

        pub fn read_token(&mut self) -> String {
            self.read_token_safe().unwrap()
        }
    }
}