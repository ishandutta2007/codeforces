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
    let mut a = vec![vec![]; 2];
    a[0] = sc.read_token().into_bytes();
    a[1] = sc.read_token().into_bytes();
    let mut dp = vec![usize::MAX; 4];
    dp[0] = 0;
    let mut has_asterisk = false;
    for col in 0..n {
        let mut ndp = vec![usize::MAX; 4];
        let f_mask: usize = if a[0][col] == b'*' { 1 } else { 0 } + if a[1][col] == b'*' { 2 } else {0};
        for mask in 0..4 {
            if (f_mask & mask) != f_mask { continue }
            let add = mask.count_ones() as usize;
            let mut value = usize::MAX;
            if !has_asterisk {
                value = value.min(add);
            }
            for p_mask in 0..4 {
                if p_mask == 0 && mask != 0 { continue }
                if mask != 0 && p_mask != 0 && (mask & p_mask) == 0 { continue }
                let p_value = dp[p_mask];
                if p_value == usize::MAX { continue }
                value = value.min(p_value + add);
            }
            ndp[mask] = value;
        }
        if f_mask > 0 {
            has_asterisk = true;
        }
        dp = ndp;
    }
    let mut ans = *dp.iter().min().unwrap();
    if ans > 0 {
        ans -= 1;
    }
    println!("{}", ans);
}

mod dsu {
    struct DSU {
        p: Vec<usize>
    }

    impl DSU {
        #[allow(dead_code)]
        pub fn new(n: usize) -> Self {
            Self {
                p: (0..n).collect()
            }
        }

        #[allow(dead_code)]
        pub fn get(&mut self, x: usize) -> usize {
            if x != self.p[x] {
                self.p[x] = self.get(self.p[x]);
            }
            self.p[x]
        }

        #[allow(dead_code)]
        pub fn join(&mut self, x: usize, y: usize) -> bool {
            let a = self.get(x);
            let b = self.get(y);
            self.p[a] = b;
            a != b
        }
    }
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

        #[allow(dead_code)]
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

        #[allow(dead_code)]
        pub fn read_integer<T: FromStr>(&mut self) -> T
            where <T as FromStr>::Err: Debug,
        {
            self.read_token_safe().unwrap().parse::<T>().unwrap()
        }

        #[allow(dead_code)]
        pub fn read_token(&mut self) -> String {
            self.read_token_safe().unwrap()
        }
    }
}