use std::collections::BTreeMap;
use std::mem::swap;

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


fn inc<T: Ord + Clone>(mp: &mut BTreeMap<T, i32>, key: &T) {
    if !mp.contains_key(key) {
        mp.insert(key.clone(), 0);
    }
    *mp.get_mut(key).unwrap() += 1;
}


fn c2(a: i32) -> i64 {
    a as i64 * (a - 1) as i64 / 2
}


fn main() {
    let mut scan = Scanner::default();
    let n: usize = scan.next();

    let mut arr: Vec<(i32, i32)> = Vec::with_capacity(n);

    for _ in 0..n {
        let mut a: i32 = scan.next();
        let mut b: i32 = scan.next();

        if b < a {
            swap(&mut a, &mut b);
        }

        arr.push((a, b));
    }

    let mut size_cnt = BTreeMap::new();

    for (a, b) in &arr {
        inc(&mut size_cnt, a);
        if a != b {
            inc(&mut size_cnt, b);
        }
    }

    let mut ans: i64 = 0;

    for (_, val) in size_cnt {
        ans += c2(val);
    }

    arr.sort();

    let mut l = 0;
    let mut r;

    while l < arr.len() {
        r = l;

        while r < arr.len() && arr[r] == arr[l] {
            r += 1;
        }

        if arr[l].0 != arr[l].1 {
            ans -= c2((r - l) as i32);
        }

        l = r;
    }

    println!("{}", ans);
}