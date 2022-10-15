use std::io;
fn read_int() -> i64 {
    let mut t = String::new();
    io::stdin()
    .read_line(&mut t)
    .expect("sus");
    let t : i64 = t.trim().parse().expect("a");
    t
}
fn main() {
    let mut t=0;
    t=read_int();
    for t1 in 0..t {
        let mut u : i64 = 1;
        let mut res : i64 = 0;
        for i in 0..30 {
            u*=2;
            println!("? {} {}",res+1,res+u+1);
            let mut ans : i64 = read_int();
            if ans!=u {
                res+=u/2;
            }   
        }
        println!("! {}",u-res-1);
    }
}