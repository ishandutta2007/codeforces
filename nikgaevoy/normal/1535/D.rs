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


fn upd(str: &Vec<char>, arr: &mut Vec<i32>, pos: usize) {
    arr[pos] = match str[pos] {
        '?' => arr[2 * pos] + arr[2 * pos + 1],
        '0' => arr[2 * pos + 1],
        '1' => arr[2 * pos + 0],
        _ => panic!()
    };
}


fn main() {
    let mut scan = Scanner::default();

    let k: usize = scan.next();
    let arr: String = scan.next();
    let mut str = "X".chars().chain(arr.chars().rev()).collect::<Vec<char>>();
    let q: usize = scan.next();

    assert_eq!(str.len(), 1usize << k);

    let mut arr = vec![1; 2 * str.len()];

    for i in (1..str.len()).rev() {
        upd(&str, &mut arr, i);
    }

    for _ in 0..q {
        let mut pos: usize = scan.next();
        pos = str.len() - pos;
        let c: char = scan.next();

        str[pos] = c;

        while pos > 0 {
            upd(&str, &mut arr, pos);
            pos /= 2;
        }

        println!("{}", arr[1]);
    }
}