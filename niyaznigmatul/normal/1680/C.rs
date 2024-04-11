use crate::reader::Reader;

fn main() {
    let mut sc = Reader::new();
    let tests = sc.read_integer();
    for _ in 0..tests {
        solve(&mut sc);
    }
}

fn solve(sc: &mut Reader) {
    let blocks = build_blocks(sc.read_token().into_bytes());
    if can_solve(&blocks, 0) {
        println!("0");
        return;
    }
    let mut left = 0;
    let mut right = blocks.len();
    while left + 1 < right {
        let mid = (left + right) >> 1;
        if can_solve(&blocks, mid) {
            right = mid;
        } else {
            left = mid;
        }
    }
    println!("{}", right);
}

fn can_solve(blocks: &Vec<usize>, k: usize) -> bool {
    if k >= blocks.len() {
        return true;
    }
    let leave = blocks.len() - k;
    let mut sum = 0;
    for i in 0..leave {
        sum += blocks[i];
    }
    let mut best_sum = sum;
    for i in leave..blocks.len() {
        sum += blocks[i];
        sum -= blocks[i - leave];
        best_sum = best_sum.min(sum);
    }
    best_sum <= k
}

fn build_blocks(s: Vec<u8>) -> Vec<usize> {
    let mut blocks = Vec::new();
    let mut i = 0;
    while i < s.len() && s[i] == b'0' {
        i += 1;
    }
    if i < s.len() && s[i] == b'1' {
        i += 1;
    }
    while i < s.len() {
        let mut count = 0usize;
        while i < s.len() && s[i] == b'0' {
            count += 1;
            i += 1;
        }
        if i < s.len() {
            blocks.push(count);
            i += 1;
        }
    }
    blocks
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