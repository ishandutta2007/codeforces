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
    let mut parent = vec![0; n];
    for i in 1..n {
        parent[i] = sc.read_integer::<usize>() - 1;
    }
    let colors = sc.read_token()
        .into_bytes()
        .into_iter()
        .map(|x| x == b'B')
        .collect::<Vec<_>>();
    let mut count_white = vec![0; n];
    let mut count_black = vec![0; n];
    let mut ans = 0;
    for i in (0..n).rev() {
        if colors[i] {
            count_black[i] += 1;
        } else {
            count_white[i] += 1;
        }
        if i > 0 {
            count_black[parent[i]] += count_black[i];
            count_white[parent[i]] += count_white[i];
        }
        if count_white[i] == count_black[i] {
            ans += 1;
        }
    }
    println!("{}", ans);
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