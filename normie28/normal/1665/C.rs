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
        let mut arr = read_arr();
        arr.push(0);
        let mut mp : HashMap<i32,i32> = HashMap::new();
        for g in arr {
            let cnt = mp.entry(g).or_insert(0);
            *cnt+=1;
        }
        let mut cnts = Vec::new();
        for (id,cnt) in mp {
            cnts.push(cnt);
        }
        cnts.sort();
        cnts.reverse();

        let mut m=0;
        for g in &cnts {
            m+=1;
        }
        let mut l=m;
        let mut r=n;
        let mut mid=0;
        while l<r {
            mid=(l+r)/2;
            let mut residue=0;
            let mut pt=mid;
            for g in &cnts {
                if g>&pt {
                    residue+=g-&pt;
                }
                pt-=1;
            }
            if residue>mid-m {l=mid+1;} else {r=mid;}
        }
        println!("{}",l);
    }
}