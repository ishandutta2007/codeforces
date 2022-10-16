use std::ops::Mul;

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


struct SegTree<T: Mul<Output=T> + Default + Clone> {
    arr: Vec<T>,
}


fn up(n: usize) -> usize
{
    (usize::MAX >> n.leading_zeros()) + 1
}


impl<T: Mul<T, Output=T> + Default + Clone> SegTree<T> {
    fn new(n: usize) -> SegTree<T> {
        SegTree { arr: vec![T::default(); 2 * up(n)] }
    }


    fn set(&mut self, wh: usize, x: T) {
        let mut wh = wh + self.arr.len() / 2;

        self.arr[wh] = x;
        wh /= 2;

        while wh > 0 {
            self.arr[wh] = self.arr[2 * wh].clone() * self.arr[2 * wh + 1].clone();

            wh /= 2;
        }
    }


    fn allmul(&self) -> T {
        self.arr[1].clone()
    }
}


type Color = Option<&'static str>;


#[derive(Clone)]
struct Op
{
    op: [(bool, Color); 2],
}

static STRINGS: [&str; 7] = ["red", "orange", "yellow", "green", "blue", "indigo", "violet"];

impl Op {
    fn new(str: String) -> Op {
        if str == "lock" {
            return Op { op: [(true, None), (true, None)] };
        }
        if str == "unlock" {
            return Op { op: [(false, None), (false, None)] };
        }

        Op { op: [(false, Some(STRINGS.iter().find(|x| *x == &str).unwrap())), (true, None)] }
    }
}


impl Default for Op {
    fn default() -> Self {
        Op { op: [(false, None), (true, None)] }
    }
}


fn merge(a: &Color, b: &Color) -> Color {
    match b {
        None => a,
        Some(_) => b,
    }.clone()
}


impl Mul for Op {
    type Output = Op;

    fn mul(self, rhs: Self) -> Self::Output {
        let mut ans = Op::default();

        for i in 0..=1 {
            let l = &self.op[i];
            let r = &rhs.op[if l.0 { 1 } else { 0 }];

            ans.op[i] = (r.0, merge(&l.1, &r.1));
        }

        ans
    }
}


fn ask(st: &SegTree<Op>) -> &str {
    st.allmul().op[0].1.clone().unwrap()
}


fn main() {
    let mut scan = Scanner::default();
    let n: usize = scan.next();

    let mut st = SegTree::<Op>::new(n + 1);

    st.set(0, Op::new("blue".parse().unwrap()));

    for i in 0..n {
        let str: String = scan.next();

        st.set(i + 1, Op::new(str));
    }

    println!("{}", ask(&st));

    let q: usize = scan.next();

    for _ in 0..q {
        let wh: usize = scan.next();
        let str: String = scan.next();

        st.set(wh, Op::new(str));

        println!("{}", ask(&st));
    }
}

#[cfg(test)]
mod tests {
    use rand::Rng;
    use super::*;
    use rand::rngs::ThreadRng;
    use std::time::Instant;


    fn rand_op(rng: &mut ThreadRng) -> String {
        static OPS: [&str; 9] = ["lock", "unlock", "red", "orange", "yellow", "green", "blue", "indigo", "violet"];

        OPS[rng.gen_range(0..OPS.len())].parse().unwrap()
    }


    #[test]
    fn maxtest() {
        let now = Instant::now();

        let mut rng = rand::thread_rng();

        let n = 1e5 as usize;

        let mut st = SegTree::<Op>::new(n + 1);

        for i in 0..n {
            st.set(i + 1, Op::new(rand_op(&mut rng)))
        }

        st.allmul().op[0].1.clone().unwrap();

        let q = 1e5 as usize;

        for _ in 0..q {
            st.set(rng.gen_range(1..=n), Op::new(rand_op(&mut rng)))
        }

        println!("{}", now.elapsed().as_secs_f32());
    }
}