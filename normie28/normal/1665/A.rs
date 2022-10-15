use std::io;


fn main() {
    let mut t = String::new();
    io::stdin()
        .read_line(&mut t)
        .expect("sus");
    let t : u32 = t.trim().parse().expect("a");

    for t1 in 0..t {
        let mut n = String::new();
        io::stdin()
            .read_line(&mut n)
            .expect("sus");
        let n : u32 = n.trim().parse().expect("a");
        print!("{} ",n-3);
        print!("{} ",1);
        print!("{} ",1);
        println!("{}",1);
    }
}