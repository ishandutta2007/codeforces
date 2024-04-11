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

/**************************************************

    END OF TEMPLATE CODE

 *************************************************/

#[derive(Ord, PartialOrd, Eq, PartialEq, Copy, Clone, Debug)]
struct Point {
    sum: i64,
    x: i64,
    y: i64,
}

#[derive(Copy, Clone, Debug)]
struct Event {
    pos: i64,
    change: i64,
}

#[derive(Debug)]
struct Block {
    events: Vec<Event>,
    pos_shifts: i64,
    change: i64,
}

impl Block {
    fn add_point(&mut self, mut pos: i64) {
        pos -= self.pos_shifts;
        self.change += 2;
        let mut left = 0;
        let mut right = self.events.len() + 1;
        while right - left > 1 {
            let mid = (left + right) / 2;
            if self.events[mid - 1].pos >= pos {
                right = mid;
            } else {
                left = mid;
            }
        }
        let insert_pos = left;
        self.events.insert(insert_pos, Event { pos, change: 2 });
    }

    fn create(events: Vec<Event>, pos_shifts: i64) -> Self {
        let mut change = 0;
        for e in events.iter() {
            change += e.change;
        }
        Self { events, pos_shifts, change }
    }
}

#[derive(Debug)]
struct Solver {
    cost_at_zero: i64,
    coef_at_zero: i64,
    blocks: Vec<Block>,
}

impl Solver {
    fn create() -> Self {
        Self { cost_at_zero: 0, coef_at_zero: 0, blocks: vec![] }
    }

    fn advance(&mut self, len: i64) {
        if self.blocks.is_empty() {
            return;
        }
        let mut coef = self.coef_at_zero;
        let mut found = false;
        for block in self.blocks.iter_mut() {
            if found {
                block.pos_shifts += len;
                continue;
            }
            if coef + block.change < 0 {
                coef += block.change;
                continue;
            }
            let mut first_bad_event = 0;
            let mut should_split = false;
            for (idx, e) in block.events.iter().enumerate() {
                if coef + e.change > 0 {
                    first_bad_event = idx;
                    if coef < 0 {
                        should_split = true;
                    }
                    found = true;
                    break;
                }
                coef += e.change;
            }
            if found {
                if should_split {
                    let pos = block.events[first_bad_event].pos;
                    assert_eq!(block.events[first_bad_event].change, 2);
                    block.events.insert(first_bad_event, Event { pos, change: 1 });
                    block.events[first_bad_event + 1].change = 1;
                    first_bad_event += 1;
                }
                for e in block.events[first_bad_event..].iter_mut() {
                    e.pos += len;
                }
            }
        }
    }

    fn add_point(&mut self, pos: i64) {
        self.coef_at_zero -= 1;
        self.cost_at_zero += pos;
        let mut insert_pos = 0;
        while insert_pos != self.blocks.len() && self.blocks[insert_pos].events.last().unwrap().pos + self.blocks[insert_pos].pos_shifts < pos {
            insert_pos += 1;
        }
        if insert_pos == self.blocks.len() && insert_pos == 0 {
            self.blocks.push(Block { events: vec![], pos_shifts: 0, change: 0 });
        } else if insert_pos == self.blocks.len() {
            insert_pos -= 1;
        }
        self.blocks[insert_pos].add_point(pos);
    }

    fn get_ans(&self) -> i64 {
        let mut cost = self.cost_at_zero;
        let mut coef = self.coef_at_zero;
        let mut my_pos = 0;
        for block in self.blocks.iter() {
            for e in block.events.iter() {
                cost += (e.pos - my_pos + block.pos_shifts) * coef;
                coef += e.change;
                my_pos = e.pos + block.pos_shifts;
                if coef >= 0 {
                    return cost;
                }
            }
        }
        unreachable!();
    }

    const BUBEN: usize = 3000;

    fn relax(&mut self) {
        for i in 0..self.blocks.len() {
            if self.blocks[i].events.len() > Self::BUBEN {
                let first_part = self.blocks[i].events.len() / 2;
                let v2 = self.blocks[i].events[first_part..].iter().cloned().collect();
                while self.blocks[i].events.len() > first_part {
                    let change = self.blocks[i].events.pop().unwrap().change;
                    self.blocks[i].change -= change;
                }
                let pos_shifts = self.blocks[i].pos_shifts;
                self.blocks.insert(i + 1, Block::create(v2, pos_shifts));
            }
        }
    }
}

pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let n = sc.usize();
    let mut a: Vec<_> = (0..n).map(|_| {
        let x = sc.i64();
        let y = sc.i64();
        Point { sum: x + y, x, y }
    }).collect();
    a.sort();
    let mut solver = Solver::create();
    let mut cur_sum = 0;
    for p in a.iter() {
        let next_sum = p.sum;
        if next_sum > cur_sum {
            solver.advance(next_sum - cur_sum);
            cur_sum = next_sum;
        }
        solver.add_point(p.x);
        solver.relax();
    }
    writeln!(out, "{}", solver.get_ans()).unwrap();
}