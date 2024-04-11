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

/**************************************************

    END OF TEMPLATE CODE

 *************************************************/


pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    const MAX: usize = 1_000_005;
    let mut prev_prime = vec![0; MAX];
    for v in 2..MAX {
        if prev_prime[v] == 0 {
            for u in (v..MAX).step_by(v) {
                prev_prime[u] = v;
            }
        }
    }
    let mut my_primes = vec![];

    let calc_primes = |mut x: usize, my_primes: &mut Vec<usize>| {
        my_primes.clear();
        while x != 1 {
            let p = prev_prime[x];
            my_primes.push(p);
            while x % p == 0 {
                x /= p;
            }
        }
    };

    let mut dsu = Dsu::new(MAX);

    let n = sc.usize();
    let q = sc.usize();
    let a = sc.vec::<usize>(n);
    for i in 0..n {
        calc_primes(a[i], &mut my_primes);
        for pr in my_primes.windows(2) {
            dsu.unite(pr[0], pr[1]);
        }
    }

    let mut edges = vec![vec![]; MAX];

    for ai in a.iter() {
        calc_primes(*ai + 1, &mut my_primes);
        let comp1 = dsu.get(prev_prime[*ai]);
        for p in my_primes.iter() {
            let comp2 = dsu.get(*p);
            edges[comp1].push(comp2);
            edges[comp2].push(comp1);
        }

        for p1 in my_primes.iter() {
            for p2 in my_primes.iter() {
                let comp2 = dsu.get(*p1);
                let comp3 = dsu.get(*p2);
                if comp2 < comp3 {
                    edges[comp3].push(comp2);
                    edges[comp2].push(comp3);
                }
            }
        }
    }

    for edges in edges.iter_mut() {
        edges.sort();
    }

    for _ in 0..q {
        let fr_ix = sc.usize() - 1;
        let to_ix = sc.usize() - 1;
        let comp_id1 = dsu.get(prev_prime[a[fr_ix]]);
        let comp_id2 = dsu.get(prev_prime[a[to_ix]]);
        let res = if comp_id1 == comp_id2 {
            0
        } else if edges[comp_id1].binary_search(&comp_id2).is_ok() {
            1
        } else {
            2
        };
        writeln!(out, "{}", res).unwrap();
    }
}