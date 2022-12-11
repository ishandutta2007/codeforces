use std::io;

fn main() {

    let mut n: String = String::new();
    let mut seq: String = String::new();

    io::stdin().read_line(&mut n);
    io::stdin().read_line(&mut seq);

    let n: i32 = n.trim().parse::<i32>().unwrap();
    let seq = seq.trim().chars().collect::<Vec<_>>();

    let mut ans: i32 = n;
    let mut last: char = 'D';
    for c in seq {
        if c != last && last != 'D' {
            ans = ans - 1;
            last = 'D';
        } else {
            last = c;
        }
    }

    println!("{}", ans);
}