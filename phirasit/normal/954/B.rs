use std::io;
use std::cmp::max;

trait Substring {
    fn substring(&self, start: i32, len: i32) -> String;
}

impl Substring for String {

    fn substring(&self, start: i32, len: i32) -> String {
        self.chars().skip(start as usize).take(len as usize).collect()
    }
}

fn main() {

    let mut n: String = String::new();
    let mut inp: String = String::new();

    io::stdin().read_line(&mut n).unwrap();
    io::stdin().read_line(&mut inp).unwrap();

    let n: i32 = n.trim().parse().unwrap();

    let mut ans: Vec<_> = (0..n/2+1).filter(|&i: &i32| -> bool {
        inp.substring(0, i) == inp.substring(i, i)
    }).collect();

    let ans: i32 = ans.pop().unwrap();
    let display: i32 = n - max(ans-1, 0); 

    println!("{}", display);
}