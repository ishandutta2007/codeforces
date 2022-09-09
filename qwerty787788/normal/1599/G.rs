use std::io;
use std::io::Write;

/**************************************************

    START OF TEMPLATE CODE

 *************************************************/
#[allow(unused_macros)]
macro_rules! dbg {
    ($first_val:expr, $($val:expr),+ $(,)?) => {
        eprint!("[{}:{}] {} = {:?}",
                    file!(), line!(), stringify!($first_val), &$first_val);
        ($(eprint!(", {} = {:?}", stringify!($val), &$val)),+,);
        eprintln!();
    };
    ($first_val:expr) => {
        eprintln!("[{}:{}] {} = {:?}",
                    file!(), line!(), stringify!($first_val), &$first_val);
    };
}

enum InputSource {
    Stdin,
    FromFile(Vec<String>),
}

struct Scanner {
    buffer: Vec<String>,
    input_source: InputSource,
}


impl Scanner {
    #[allow(dead_code)]
    fn new() -> Self {
        Self { buffer: vec![], input_source: InputSource::Stdin }
    }

    #[allow(dead_code)]
    fn new_file(filename: &str) -> Self {
        let file = std::fs::read_to_string(filename).unwrap();
        let mut lines: Vec<String> = file.lines().map(|line| String::from(line)).collect();
        lines.reverse();
        Self { buffer: vec![], input_source: InputSource::FromFile(lines) }
    }


    #[allow(dead_code)]
    fn i64(&mut self) -> i64 {
        self.next::<i64>()
    }

    #[allow(dead_code)]
    fn i32(&mut self) -> i32 {
        self.next::<i32>()
    }

    #[allow(dead_code)]
    fn usize(&mut self) -> usize {
        self.next::<usize>()
    }

    #[allow(dead_code)]
    fn vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.next::<T>()).collect()
    }

    fn parse_next_line(&mut self) -> bool {
        let mut input = String::new();
        match &mut self.input_source {
            | InputSource::Stdin => {
                if std::io::stdin().read_line(&mut input).expect("Failed read") == 0 {
                    return false;
                }
            }
            | InputSource::FromFile(lines) => {
                match lines.pop() {
                    Some(line) => input = line,
                    None => return false,
                }
            }
        }

        self.buffer = input.split_whitespace().rev().map(String::from).collect();
        return true;
    }

    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }

            self.parse_next_line();
        }
    }

    #[allow(dead_code)]
    fn has_more_elements(&mut self) -> bool {
        loop {
            if !self.buffer.is_empty() {
                return true;
            }
            if !self.parse_next_line() {
                return false;
            }
        }
    }


    #[allow(dead_code)]
    fn string(&mut self) -> Vec<u8> {
        self.next::<String>().into_bytes()
    }
}

#[allow(dead_code)]
struct Random {
    state: usize,
}

impl Random {
    fn next(&mut self) -> usize {
        let mut x = self.state;
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        self.state = x;
        x
    }

    #[allow(dead_code)]
    fn next_in_range(&mut self, from: usize, to: usize) -> usize {
        assert!(from < to);
        from + self.next() % (to - from)
    }

    #[allow(dead_code)]
    fn next_double(&mut self) -> f64 {
        (self.next() as f64) / (std::usize::MAX as f64)
    }

    #[allow(dead_code)]
    fn new(seed: usize) -> Self {
        assert_ne!(seed, 0);
        Self {
            state: seed,
        }
    }
}

/**************************************************

    END OF TEMPLATE CODE

 *************************************************/


const MAX: f64 = 1e100;

fn vect_mul(p1: Point, p2: Point, p3: Point) -> i64 {
    (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x)
}

#[derive(Copy, Clone, Ord, PartialOrd, Eq, PartialEq, Hash, Debug)]
struct Point {
    x: i64,
    y: i64,
    id: usize,
}

fn dist2(p1: Point, p2: Point) -> i64 {
    let dx = p2.x - p1.x;
    let dy = p2.y - p1.y;
    dx * dx + dy * dy
}

fn find_path(g: Vec<Vec<f64>>, start: usize, pairs: Vec<Pair>) -> f64 {
    let real_n = g.len();
    let n = g.len() + pairs.len();
    let mut d = vec![vec![MAX; 1 << n]; real_n];
    d[start][1 << start] = 0.0;
    for mask in 0..(1 << n) {
        for last in 0..real_n {
            let cur = d[last][mask];
            if cur >= MAX {
                continue;
            }
            for next in 0..real_n {
                let next_d = cur + g[last][next];
                let mut nmask = mask | (1 << next);
                for (p_id, pair) in pairs.iter().enumerate() {
                    if (pair.first == last && pair.second == next) || (pair.first == next && pair.second == last) {
                        nmask |= 1 << (real_n + p_id);
                    }
                }
                if next_d < d[next][nmask] {
                    d[next][nmask] = next_d;
                }
            }
        }
    }
    let mut res = MAX;
    let full_mask = (1 << n) - 1;
    for last in 0..real_n {
        if d[last][full_mask] < res {
            res = d[last][full_mask];
        }
    }
    res
}

struct Pair {
    first: usize,
    second: usize,
}

fn solve(mut on_line: Vec<Point>, strange: Point, start: usize, pts: &Vec<Point>, use_all: bool) -> f64 {
    let n = pts.len();
    on_line.sort();
    let mut is_interesting = vec![use_all; n];
    is_interesting[strange.id] = true;
    is_interesting[on_line.first().unwrap().id] = true;
    is_interesting[on_line.last().unwrap().id] = true;
    let mut closest_pos = 0;
    for (pos, &p) in on_line.iter().enumerate() {
        let cur_d2 = dist2(p, strange);
        let prev_d2 = dist2(on_line[closest_pos], strange);
        if cur_d2 < prev_d2 {
            closest_pos = pos;
        }
    }
    let mut start_real = 0;
    while start_real != on_line.len() && on_line[start_real].id != start {
        start_real += 1;
    }
    let mut to_check = vec![closest_pos];
    if start_real != on_line.len() {
        to_check.push(start_real);
    }
    for &check_pos in to_check.iter() {
        for delta in (-1..2).step_by(2) {
            let mut now_id = check_pos;
            let mut seen = on_line[check_pos];
            let mut cnt = 0;
            while (now_id as i32) + delta >= 0 && (now_id as i32 + delta < on_line.len() as i32) {
                now_id = (now_id as i32 + delta) as usize;
                if dist2(on_line[now_id], seen) != 0 {
                    let prev = now_id as i32 - delta;
                    is_interesting[on_line[prev as usize].id] = true;
                    is_interesting[on_line[now_id].id] = true;
                    seen = on_line[now_id];
                    cnt += 1;
                    if cnt >= 3 {
                        break;
                    }
                }
            }
        }
    }
    is_interesting[start] = true;

    let mut interesting_ids = vec![];
    for (id, &is_int) in is_interesting.iter().enumerate() {
        if is_int {
            interesting_ids.push(id);
        }
    }
    let new_n = interesting_ids.len();
    let mut g = vec![vec![MAX; new_n]; new_n];
    for i in 0..new_n {
        for j in 0..new_n {
            let real_i = interesting_ids[i];
            let real_j = interesting_ids[j];
            g[i][j] = (dist2(pts[real_i], pts[real_j]) as f64).sqrt();
        }
    }
    let mut pairs = vec![];
    for i in 0..on_line.len() {
        if is_interesting[on_line[i].id] && i + 1 < on_line.len() && !is_interesting[on_line[i + 1].id] {
            let mut j = i + 1;
            while !is_interesting[on_line[j].id] {
                j += 1;
            }
            let mut real_i = 0;
            while interesting_ids[real_i] != on_line[i].id {
                real_i += 1;
            }
            let mut real_j = 0;
            while interesting_ids[real_j] != on_line[j].id {
                real_j += 1;
            }
            pairs.push(Pair { first: real_i, second: real_j });
        }
    }
    let mut real_start = 0;
    while interesting_ids[real_start] != start {
        real_start += 1;
    }
    find_path(g, real_start, pairs)
}

fn solve_test(pts: Vec<Point>, start: usize, use_all: bool) -> f64 {
    let mut rnd = Random::new(7877881);

    for _ in 0.. {
        let from = rnd.next_in_range(0, pts.len());
        let to = rnd.next_in_range(0, pts.len());
        if pts[from] == pts[to] {
            continue;
        }
        let mut cnt_on_line = 0;
        for &p in pts.iter() {
            if vect_mul(pts[from], pts[to], p) == 0 {
                cnt_on_line += 1;
            }
        }
        if cnt_on_line == pts.len() - 1 {
            let mut on_line = vec![];
            let mut strange = Point { x: 0, y: 0, id: pts.len() };
            for &p in pts.iter() {
                if vect_mul(pts[from], pts[to], p) == 0 {
                    on_line.push(p);
                } else {
                    assert_eq!(strange.id, pts.len());
                    strange = p;
                }
            }
            assert_ne!(strange.id, pts.len());
            let res = solve(on_line, strange, start, &pts, use_all);
            return res;
        }
    }
    unreachable!();
}

fn stress() {
    for test in 7.. {
        dbg!(test);
        let mut rnd = Random::new(test);
        const MAX: usize = 20;
        let n = 3 + rnd.next_in_range(0, MAX);
        let mut next_point = || -> Point {
            let x = rnd.next_in_range(0, MAX) as i64;
            let y = rnd.next_in_range(0, MAX) as i64;
            Point { x, y, id: 0 }
        };
        let first = next_point();
        let second = next_point();
        if first == second {
            continue;
        }
        let mut pts = vec![first, second];
        loop {
            let check = next_point();
            if vect_mul(first, second, check) == 0 {
                continue;
            }
            pts.push(check);
            break;
        }
        while pts.len() < n {
            let check = next_point();
            if vect_mul(first, second, check) == 0 {
                pts.push(check);
            }
        }
        let start = rnd.next_in_range(0, n);
        // TODO: random shuffle
        for (id, p) in pts.iter_mut().enumerate() {
            p.id = id;
        }
        let my_ans = solve_test(pts.clone(), start, false);
        let slow_ans = solve_test(pts.clone(), start, true);
        if (my_ans - slow_ans).abs() > 1e-5 {
            dbg!(my_ans, slow_ans);
            dbg!(pts);
            dbg!(start);
            assert!(false);
        }
    }
}

pub fn main() {
    // stress();
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let first_n = sc.usize();
    let start = sc.usize() - 1;
    let pts: Vec<_> = (0..first_n).map(|id| {
        let x = sc.i64();
        let y = sc.i64();
        Point { x, y, id }
    }).collect();

    let res = solve_test(pts, start, false);
    writeln!(out, "{}", res).unwrap();
    return;
}