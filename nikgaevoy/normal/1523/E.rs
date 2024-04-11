#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}

impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            std::io::stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}


const MOD: u32 = 1e9 as u32 + 7;


fn multmod(x: u32, y: u32) -> u32 {
    (((x as u64) * (y as u64)) % MOD as u64) as u32
}


fn sqrmod(x: u32) -> u32 {
    multmod(x, x)
}


fn powmod(x: u32, y: u32) -> u32 {
    if y > 0 {
        if y % 2 == 0 {
            sqrmod(powmod(x, y / 2))
        } else {
            multmod(x, powmod(x, y - 1))
        }
    } else {
        1
    }
}


fn invmod(x: u32) -> u32 {
    powmod(x, MOD - 2)
}


fn divmod(x: u32, y: u32) -> u32 {
    multmod(x, invmod(y))
}


fn addmod(x: u32, y: u32) -> u32 {
    let mut x = x;
    x += y;

    if x >= MOD {
        x -= MOD;
    }

    x
}


#[derive(Default)]
struct Ccomp {
    dpf: Vec<u32>,
    dpif: Vec<u32>,
}


impl Ccomp {
    pub fn fact(&mut self, n: usize) -> u32 {
        if self.dpf.is_empty() {
            self.dpf = vec![1u32; 2];
        }

        while n >= self.dpf.len() {
            self.dpf.push(multmod(*self.dpf.last().unwrap(), self.dpf.len() as u32));
        }

        self.dpf[n]
    }


    pub fn ifact(&mut self, n: usize) -> u32 {
        while n >= self.dpif.len() {
            let val = invmod(self.fact(self.dpif.len()));

            self.dpif.push(val);
        }

        self.dpif[n]
    }


    fn c(&mut self, n: usize, k: usize) -> u32 {
        if k > n {
            return 0;
        }

        let a = self.fact(k);
        let b = self.ifact(n - k);

        multmod(self.fact(n), multmod(a, b))
    }
}


fn solve(scan: &mut Scanner) {
    let n: usize = scan.next();
    let k: usize = scan.next();

    let mut ccomp = Ccomp::default();
    let mut ans = 0;

    for i in 0..n {
        let sub = if i == 0 { 0 } else { (i - 1) * (k - 1) };

        if sub > n {
            break;
        }
        let num = ccomp.c(n - sub, i);
        let den = ccomp.c(n, i);

        ans = addmod(ans, divmod(num, den));
    }

    println!("{}", ans);
}


fn main() {
    let mut scan = Scanner::default();
    let t: usize = scan.next();

    for _ in 0..t {
        solve(&mut scan);
    }
}