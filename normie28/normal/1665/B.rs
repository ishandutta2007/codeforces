use std::io;
use std::collections::HashMap;
fn read_int() -> i32 {
    let mut t = String::new();
    io::stdin()
    .read_line(&mut t)
    .expect("sus");
    let t : i32 = t.trim().parse().expect("a");
    t
}
fn read_arr() -> Vec<i32> {
    let mut t = String::new();
    io::stdin()
    .read_line(&mut t)
    .expect("sus");
    t.split_ascii_whitespace().map(|x| -> i32 {
        let y : i32 = x.trim().parse().expect("a");
        y
    }).collect()
}
fn main() {
    let t = read_int();
    for t1 in 0..t {
        let n = read_int();
        let arr = read_arr();
        let mut mp : HashMap<i32,i32> = HashMap::new();
        for g in arr {
            let cnt = mp.entry(g).or_insert(0);
            *cnt+=1;
        }
        let mut mx = 0;
        for (id,cnt) in mp {
            if mx<cnt {
                mx = cnt;
            }
        }
        let mut res=n-mx;
        while mx<n {
            mx*=2;
            res+=1;
        }
        println!("{}",res);
    }
}