use std::ops::Rem;

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


fn gcd<T: PartialEq<i32> + Rem<Output=T> + Copy>(a: T, b: T) -> T {
    if b == 0i32 { a } else { gcd(b, a % b) }
}


fn solve(scan: &mut Scanner) {
    let n: usize = scan.next();
    let mut arr = vec![0; n];

    for it in &mut arr {
        *it = scan.next();
    }

    arr.sort_by(|a, b| (a % 2).cmp(&(b % 2)));

    let mut ans = 0;

    for i in 0..arr.len() {
        let (le, ri) = arr.split_at(i + 1);

        for it in ri {
            if gcd(*le.last().unwrap(), 2 * *it) > 1 {
                ans += 1;
            }
        }
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