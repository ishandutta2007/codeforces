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
    let mut arr = [0; 4];

    for it in &mut arr {
        *it = scan.next();
    }

    let arr = arr;

    if arr[0].min(arr[1]) > arr[2].max(arr[3]) ||
        arr[2].min(arr[3]) > arr[0].max(arr[1]) {
        println!("NO");
    } else {
        println!("YES");
    }
}


fn main() {
    let mut scan = Scanner::default();

    let t: u32 = scan.next();

    for _ in 0..t {
        solve(&mut scan);
    }
}