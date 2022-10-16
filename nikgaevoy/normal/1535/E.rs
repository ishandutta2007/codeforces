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


fn buy_gold(gold: &mut Vec<(i32, i32)>, bl: &Vec<Vec<usize>>, rem: &mut i32, v: usize, mut end: usize) -> i64 {
    end = end.min(bl[v].len());

    let mut ans = 0;

    while end > 0 {
        end -= 1;

        let par = bl[v][end];

        if gold[par].0 > 0 {
            ans += buy_gold(gold, bl, rem, par, end);

            if *rem == 0 {
                break;
            }
        }
    }

    if *rem > 0 {
        let add = gold[v].0.min(*rem);

        ans += add as i64 * gold[v].1 as i64;

        gold[v].0 -= add;
        *rem -= add;
    }

    ans
}


fn main() {
    let mut scan = Scanner::default();

    let q: usize = scan.next();

    let mut gold = vec![(0, 0); q + 1];
    let mut bl = vec![vec![]; q + 1];

    let w: i32 = scan.next();
    let c: i32 = scan.next();

    gold[0] = (w, c);

    for i in 1..=q {
        let t: i32 = scan.next();

        match t {
            1 => {
                let p: usize = scan.next();
                let a: i32 = scan.next();
                let c: i32 = scan.next();

                gold[i] = (a, c);

                bl[i].push(p);

                while bl[*bl[i].last().unwrap()].len() >= bl[i].len() {
                    let add = bl[*bl[i].last().unwrap()][bl[i].len() - 1];
                    bl[i].push(add);
                }
            }
            2 => {
                let v: usize = scan.next();
                let w: i32 = scan.next();
                let mut rem = w;

                let ans = buy_gold(&mut gold, &bl, &mut rem, v, usize::MAX);

                println!("{} {}", w - rem, ans);
            }
            _ => panic!()
        }
    }
}