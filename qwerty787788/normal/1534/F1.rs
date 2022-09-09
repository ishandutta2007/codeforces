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


fn dfs1(v: usize, used: &mut [bool], graph: &Vec<Vec<usize>>, order: &mut Vec<usize>) {
    used[v] = true;
    for &to in &graph[v] {
        if !used[to] {
            dfs1(to, used, graph, order);
        }
    }
    order.push(v);
}

fn dfs2(v: usize, used: &mut [bool], graph_rev: &Vec<Vec<usize>>, comp_ids: &mut [usize], comp_id: usize) {
    comp_ids[v] = comp_id;
    used[v] = true;
    for &to in &graph_rev[v] {
        if !used[to] {
            dfs2(to, used, graph_rev, comp_ids, comp_id);
        }
    }
}

pub fn main() {
    let stdout = io::stdout();
    let mut out = std::io::BufWriter::new(stdout.lock());
    let mut sc = Scanner::new();

    let n = sc.usize();
    let m = sc.usize();
    let mut s = vec![];
    for _ in 0..n {
        s.push(sc.string());
    }
    let mut ids = 0;
    let mut go_id = vec![vec![std::usize::MAX; m]; n];
    let mut real_id = vec![vec![std::usize::MAX; m]; n];
    for col in 0..m {
        let mut seen = false;
        for row in 0..n {
            if s[row][col] == b'#' {
                real_id[row][col] = ids;
                ids += 1;
                seen = true;
            }
            if seen {
                go_id[row][col] = ids;
                ids += 1;
            }
        }
    }
    let mut graph = vec![vec![]; ids];
    for col in 0..m {
        for row in 0..n {
            if s[row][col] == b'#' {
                graph[real_id[row][col]].push(go_id[row][col]);
                graph[go_id[row][col]].push(real_id[row][col]);
            }
            if go_id[row][col] != std::usize::MAX {
                if col > 0 && s[row][col - 1] == b'#' {
                    graph[go_id[row][col]].push(real_id[row][col - 1]);
                }
                if col + 1 < m && s[row][col + 1] == b'#' {
                    graph[go_id[row][col]].push(real_id[row][col + 1]);
                }
                if row > 0 && s[row - 1][col] == b'#' {
                    graph[go_id[row][col]].push(real_id[row - 1][col]);
                }
                if row + 1 < n {
                    graph[go_id[row][col]].push(go_id[row + 1][col]);
                }
            }
        }
    }
    let mut graph_rev = vec![vec![]; ids];
    for x in 0..ids {
        for &y in &graph[x] {
            graph_rev[y].push(x);
        }
    }
    let mut used = vec![false; ids];
    let mut order = vec![];
    for i in 0..ids {
        if !used[i] {
            dfs1(i, &mut used, &graph, &mut order);
        }
    }
    order.reverse();
    let mut used = vec![false; ids];
    let mut comps = 0;
    let mut comp_id = vec![0; ids];
    for &v in order.iter() {
        if !used[v] {
            dfs2(v, &mut used, &graph_rev, &mut comp_id, comps);
            comps += 1;
        }
    }
    let mut sink = vec![true; comps];
    for v in 0..ids {
        for &to in &graph[v] {
            let comp = comp_id[to];
            if comp_id[v] == comp {
                continue;
            }
            sink[comp] = false;
        }
    }
    let mut res = 0;
    for v in sink {
        if v {
            res += 1;
        }
    }
    writeln!(out, "{}", res).unwrap();
}