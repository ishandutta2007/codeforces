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
    let m = sc.read_integer();
    let mut edges = vec![(0, 0, 0); m];
    for i in 0..m {
        let v = sc.read_integer::<usize>() - 1;
        let u = sc.read_integer::<usize>() - 1;
        edges[i] = (v, u, 1);
    }
    let res = go(n, &edges);
    if let Some(colors) = res {
        println!("YES");
        let to_print = if !edges.iter().all(|&(v, u, _)| colors[v] == 1 || colors[u] == 1) {
            colors.into_iter().map(|x| x ^ 1).collect()
        } else {
            colors
        };
        println!("{}", to_print.into_iter().map(|x| x.to_string()).collect::<Vec<String>>().join(""));
    } else {
        println!("NO");
    }
}

fn dfs(v: usize, s: usize, c: i8, colors: &mut Vec<i8>, start: &mut Vec<usize>, adjacency: &Vec<Vec<(usize, i8)>>) -> bool {
    start[v] = s;
    colors[v] = c;
    for &(to, w) in adjacency[v].iter() {
        if colors[to] < 0 {
            if !dfs(to, s, c ^ w, colors, start, adjacency) {
                return false;
            }
        } else if colors[to] != (c ^ w) {
            return false;
        }
    }
    true
}

fn process(n: usize, to_add : &[(usize, usize, i8)], to_propagate : &[(usize, usize, i8)]) -> Option<Vec<u8>> {
    let mut colors = vec![-1i8; n];
    let mut adjacency = vec![vec![]; n];
    for &(v, u, w) in to_add {
        adjacency[v].push((u, w));
        adjacency[u].push((v, w));
    }
    let mut free = 0;
    let mut start = vec![0; n];
    for &e in to_add {
        for v in [e.0, e.1] {
            if colors[v] < 0 {
                if !dfs(v, free, 0, &mut colors, &mut start, &adjacency) {
                    return None;
                }
                free += 1;
            }
        }
    }
    for &e in to_propagate {
        for v in [e.0, e.1] {
            if colors[v] < 0 {
                colors[v] = 0;
                start[v] = free;
                free += 1;
            }
        }
    }
    let edges = to_propagate.iter().map(|&(v, u, w)| (start[v], start[u], w ^ colors[v] ^ colors[u])).collect();
    let got = go(free, &edges)?;
    Some((0..n).map(|i| got[start[i]] ^ colors[i] as u8).collect())
}

fn go(n: usize, edges: &Vec<(usize, usize, i8)>) -> Option<Vec<u8>> {
    if edges.len() == 1 {
        return if n == 1 {
            Some(vec![0])
        } else {
            Some(vec![0, edges[0].1 as u8])
        };
    }
    let mid = edges.len() >> 1;
    process(n, &edges[0..mid], &edges[mid..]).or_else(|| process(n, &edges[mid..], &edges[0..mid]))
}

mod dsu {
    struct DSU {
        p: Vec<usize>,
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