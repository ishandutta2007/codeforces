use std::io;


fn solve() {
	let _n = read_int();
	let a = read_ints();
	let mut mn : i32 = 123456789;
	for &x in &a {
		if mn > x {
			mn = x;
		}
	}
	let mut sum : i32 = 0;
	for x in a {	
		sum += x - mn;
	}
	println!("{sum}");
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
	parse_int(&read_line())
}

fn parse_int(s: &str) -> i32 {
	match s.parse() {
		Ok(x) => x,
		Err(_) => 0
	}
}

fn read_ints() -> Vec<i32> {
	read_line()
		.split(" ")
		.map(parse_int)
		.collect::<Vec<i32>>()
}