use std::io;

fn solve() {
	let s = read_line();
	let mut sum1 = 0;
	let mut sum2 = 0;
	for (i, c) in s.chars().enumerate() {
		let d = c.to_digit(10).unwrap();
		if i < 3 {
			sum1 += d;
		} else {
			sum2 += d;
		}
	}
	println!("{}", if sum1 == sum2 { "YES" } else { "NO" });
}

fn main() {
    let t = read_int();
    for _ in 0..t {
    	solve()
    }
}


fn read_line() -> String {
	let mut line = String::new();
	match io::stdin().read_line(&mut line) {
		Ok(_) => &line,
		Err(_) => "",
	}.trim().to_string()
}

fn read_int() -> i32 {
	match read_line().parse() {
		Ok(x) => x,
		Err(_) => 0
	}
}