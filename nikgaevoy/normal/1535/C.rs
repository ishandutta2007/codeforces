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


fn solve(scan: &mut Scanner) {
    let str: String = scan.next();

    let mut ans = 0i64;
    let mut sz = [0, 0];
    let mut one = false;
    let mut first = true;

    for it in str.chars() {
        sz[0] += 1;
        sz[1] += 1;

        if it == '0' {
            if !first && one {
                sz[1] = sz[0];
            }
            sz[0] = 0;
            first = false;
            one = false;
        } else if it == '1' {
            if !first && !one {
                sz[1] = sz[0];
            }
            sz[0] = 0;
            first = false;
            one = true;
        }

        one = !one;
        ans += sz[1];
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