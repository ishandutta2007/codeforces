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


struct Dsu {
    p: Vec<usize>,
}

impl Dsu {
    fn new(n: usize) -> Self {
        let p = (0..n).collect();
        Self { p }
    }

    fn get(&mut self, v: usize) -> usize {
        if self.p[v] == v {
            return v;
        } else {
            self.p[v] = self.get(self.p[v]);
            return self.p[v];
        }
    }

    fn unite(&mut self, mut x: usize, mut y: usize) {
        x = self.get(x);
        y = self.get(y);
        self.p[x] = y;
    }
}

fn dfs(v: usize, g: &[Vec<usize>], p: usize, parents: &mut Vec<usize>) {
    parents[v] = p;
    for &to in g[v].iter() {
        if to == p {
            continue;
        }
        dfs(to, g, v, parents);
    }
}

pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let n = sc.usize();
    let m = sc.usize();

    let mut g = vec![vec![]; n];

    let mut dsu = Dsu::new(n);
    for _ in 0..m {
        let fr = sc.usize() - 1;
        let to = sc.usize() - 1;
        if dsu.get(fr) == dsu.get(to) {
            continue;
        }
        dsu.unite(fr, to);
        g[fr].push(to);
        g[to].push(fr);
    }

    let mut used = vec![false; n];


    let tc = sc.usize();
    
    let mut q_fr = vec![0; tc];
    let mut q_to = vec![0; tc];

    for it in 0..tc {
        q_fr[it] = sc.usize() - 1;
        q_to[it] = sc.usize() - 1;
        used[q_fr[it]] = !used[q_fr[it]];
        used[q_to[it]] = !used[q_to[it]];
    }

    let mut cnt_used = 0;
    for i in 0..n {
        if used[i] {
            cnt_used += 1;
        }
    }
    if cnt_used == 0 {
        writeln!(out, "YES").unwrap();
        let mut parents = vec![0; n];
        dfs(0, &g, 0, &mut parents);
        for it in 0..tc {
            let mut fr = q_fr[it];
            let mut to = q_to[it];
            let mut from_fr = vec![fr];
            let mut from_to = vec![to];
            while fr != 0 {
                fr = parents[fr];
                from_fr.push(fr);
            }
            while to != 0 {
                to = parents[to];
                from_to.push(to);
            }
            let mut last_common = 0;
            while !from_fr.is_empty() && !from_to.is_empty() && from_fr.last().unwrap() == from_to.last().unwrap() {
                last_common = *from_to.last().unwrap();
                from_to.pop();
                from_fr.pop();
            }
            from_to.reverse();
            from_fr.push(last_common);
            from_fr.append(&mut from_to);
            writeln!(out, "{}", from_fr.len()).unwrap();
            for v in from_fr.iter() {
                write!(out, "{} ", v + 1).unwrap();
            }
            writeln!(out).unwrap();
        }
    } else {
        assert_eq!(cnt_used % 2, 0);
        writeln!(out, "NO").unwrap();
        writeln!(out, "{}", cnt_used / 2).unwrap();
    }
}