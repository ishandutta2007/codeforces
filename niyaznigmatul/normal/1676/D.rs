use crate::reader::Reader;

fn main() {
    let mut sc = Reader::new();
    let tests : u32 = sc.read_integer();
    for _ in 0..tests {
        solve(&mut sc);
    }
}

fn solve(sc: &mut Reader) {
    let n = sc.read_integer();
    let m = sc.read_integer();
    let mut a = vec![vec![0; m]; n];
    for i in 0..n {
        for j in 0..m {
            a[i][j] = sc.read_integer();
        }
    }
    let mut ans = 0;
    for i in 0..n {
        for j in 0..m {
            let mut sum = 0;
            for row in 0..n {
                for col in [i + j + n - row, n + j - i + row] {
                    if col < n || col >= n + m {
                        continue
                    }
                    sum += a[row][col - n];
                }
            }
            sum -= a[i][j];
            ans = ans.max(sum);
        }
    }
    println!("{}", ans);
}

mod reader {
    use std::fmt::Debug;
    use std::io;
    use std::str::FromStr;
    use std::vec::IntoIter;

    pub struct Reader {
        tokens: IntoIter<String>
    }

    impl Reader {
        pub fn new() -> Self {
            Self {
                tokens: Vec::new().into_iter()
            }
        }

        fn read_token_safe(&mut self) -> Option<String> {
            loop {
                let token = self.tokens.next();
                if let None = token {
                    let mut str = String::new();
                    let r = io::stdin().read_line(&mut str);
                    if let Err(_) = r {
                        break;
                    }
                    self.tokens = str.trim().split(" ").map(|s| s.to_string()).collect::<Vec<String>>().into_iter();
                } else {
                    return token;
                }
            }
            None
        }

        pub fn read_integer<T: FromStr>(&mut self) -> T
        where <T as FromStr>::Err : Debug,
        {
            match self.read_token_safe() {
                Some(str) => str.parse::<T>().unwrap(),
                None => "0".to_string().parse::<T>().unwrap()
            }
        }

        pub fn read_token(&mut self) -> String {
            self.read_token_safe().unwrap()
        }
    }
}