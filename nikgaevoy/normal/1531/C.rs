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


fn make_square(m: usize) -> Vec<Vec<char>> {
    vec![vec!['o'; m]; m]
}


fn main() {
    let mut scan = Scanner::default();
    let n: i32 = scan.next();

    if n == 2 {
        println!("-1");

        return;
    }

    let mut side = (n as f32).sqrt().ceil() as i32;

    if n + 2 == side * side {
        side += 1;
    }

    let side = side;

    let mut ans = make_square(side as usize);
    let mut cnt = side * side;

    if n != cnt {
        *ans.last_mut().unwrap().last_mut().unwrap() = '.';
        cnt -= 1;

        let mut pos = (side - 2) as usize;

        if cnt - n > 2 * side - 1 {
            ans[pos][pos] = '.';
            ans[pos - 1][pos] = '.';
            ans[pos][pos - 1] = '.';
            ans[pos - 1][pos - 1] = '.';
            cnt -= 4;
        }
        if n % 2 != cnt % 2 {
            ans[pos][pos] = '.';
            cnt -= 1;
        }

        while n < cnt {
            *ans[pos].last_mut().unwrap() = '.';
            ans.last_mut().unwrap()[pos] = '.';

            pos -= 1;
            cnt -= 2;
        }
    }

    ans.reverse();

    println!("{}", ans.len());

    for row in ans {
        println!("{}", row.iter().collect::<String>());
    }
}