pub mod solution {
//{"name":"D.  ","group":"Codeforces - Codeforces Round #773 (Div. 1)","url":"https://codeforces.com/contest/1641/problem/D","interactive":false,"timeLimit":3000,"tests":[{"input":"4 2\n1 2 5\n4 3 1\n2 3 2\n4 5 3\n","output":"5\n"},{"input":"4 3\n1 2 3 5\n2 3 4 2\n3 4 5 3\n1 3 10 10\n","output":"-1\n"}],"testType":"single","input":{"type":"stdin","fileName":null,"pattern":null},"output":{"type":"stdout","fileName":null,"pattern":null},"languages":{"java":{"taskClass":"DDvaMassiva"}}}

use std::time::Instant;

use crate::algo_lib::collections::bit_set::BitSet;
use crate::algo_lib::collections::id_map::IdMap;
use crate::algo_lib::io::output::output;
use crate::algo_lib::io::task_io_settings::TaskIoType;
use crate::algo_lib::io::task_runner::run_task;
use crate::algo_lib::io::input::Input;
use crate::algo_lib::io::task_io_settings::TaskIoSettings;
use crate::algo_lib::misc::binary_search::binary_search_first_true;
use crate::algo_lib::misc::min_max::UpdateMinMax;
use crate::algo_lib::misc::rand::Random;
#[allow(unused)]
use crate::dbg;
use crate::out;
use crate::out_line;

#[derive(PartialEq, Eq, PartialOrd, Ord, Debug, Clone)]
struct Line {
    w: i32,
    a: Vec<i32>,
}

fn hash(a: &[i32]) -> i128 {
    let mult = 1234567893421i128;
    let mut res = 0i128;
    for &x in a.iter() {
        res = res.wrapping_mul(mult).wrapping_add(x as i128);
    }
    res
}

#[allow(unused)]
fn solve_test(mut lines: Vec<Line>, m: usize) -> i32 {
    lines.sort();

    let mut ids = IdMap::new();
    let mut positions = vec![];
    let mut lens: Vec<i32> = vec![];

    let mut all_check_ids = Vec::with_capacity(lines.len());

    for (line_no, line) in lines.iter().enumerate() {
        let mut check_ids = vec![];

        for mask in 1i32..(1 << m) {
            let mut cur = vec![];
            for i in 0..m {
                if ((1 << i) & mask) != 0 {
                    cur.push(line.a[i]);
                }
            }
            let cur = hash(&cur);
            let id = ids.get_or_add(&cur);
            while id >= positions.len() {
                positions.push(vec![]);
                lens.push(mask.count_ones() as i32 % 2i32);
            }
            positions[id].push(line_no as i32);

            check_ids.push(id as i32);
        }

        all_check_ids.push(check_ids);
    }
    let mut res = i32::MAX;

    // dbg!(ids.len());

    let mut counter = 0;
    let mut counter_logs = 0;
    for (it, line) in lines.iter().enumerate() {
        if line.w * 2 >= res {
            // break;
        }
        let check_ids = &all_check_ids[it];

        let first_ok_pair = binary_search_first_true(it + 1..lines.len(), |pos| -> bool {
            let mut cnt_bad = 0;

            for &id in check_ids.iter() {
                let id = id as usize;
                let sign = if lens[id] == 1 { 1 } else { -1 };
                counter += 1;
                counter_logs += positions[id].len().next_power_of_two().trailing_zeros() as i64 + 1;
                let count_bad = number_of_le_elements(&positions[id], pos as i32) as i32;
                cnt_bad += sign * count_bad;
            }

            cnt_bad < pos as i32 + 1
        });
        if first_ok_pair < lines.len() {
            res.update_min(lines[first_ok_pair].w + line.w);
        }
    }
    dbg!(counter);
    dbg!(counter_logs);
    res
}

#[derive(Debug)]
enum Positions {
    Vec(Vec<i32>),
    BitSet(BitSet),
}

fn solve_bitsets(mut lines: Vec<Line>, _m: usize) -> i32 {
    lines.sort();

    let mut ids = IdMap::new();

    let mut positions = vec![];

    for (idx, line) in lines.iter().enumerate() {
        for &value in line.a.iter() {
            let value_id = ids.get_or_add(&value);
            if value_id == positions.len() {
                positions.push(Positions::Vec(vec![]));
            }
            match &mut positions[value_id] {
                Positions::Vec(vec) => vec.push(idx as i32),
                Positions::BitSet(_) => panic!(),
            }
        }
    }

    // can use 400Mb of memory
    // 8bitsets = 1mb -> can store ~400 * 8 = 3K bitsets
    // 500K values in total, 3K-th bitset will have > 500K / 3K values = 200 elements

    const BIG_SIZE: usize = 200;

    for entry in positions.iter_mut() {
        if let Positions::Vec(vec) = entry {
            if vec.len() > BIG_SIZE {
                let mut bs = BitSet::new(lines.len());
                for &pos in vec.iter() {
                    bs.set(pos as usize, true);
                }
                *entry = Positions::BitSet(bs);
            }
        }
    }

    let mut res = i32::MAX;

    let mut bad = BitSet::new(lines.len());
    for (line_no, line) in lines.iter().enumerate() {
        bad.clear();
        for value_id in line.a.iter().map(|val| ids.get_exn(val)) {
            match &positions[value_id] {
                Positions::BitSet(bs) => {
                    bad |= bs;
                }
                Positions::Vec(vec) => {
                    for &pos in vec.iter() {
                        bad.set(pos as usize, true);
                    }
                }
            }
        }
        let first = bad.first_not_set(line_no + 1);
        if first != lines.len() {
            assert!(!bad.get(first));
            assert_ne!(first, line_no);
            for a1 in lines[first].a.iter() {
                for a2 in line.a.iter() {
                    if *a1 == *a2 {
                        dbg!(*a1);
                        dbg!(first, line_no);
                        dbg!(positions[ids.get_exn(a1)]);
                    }
                    assert_ne!(*a1, *a2);
                }
            }
            res.update_min(line.w + lines[first].w);
        }
    }

    res
}

fn solve(input: &mut Input, _test_case: usize) {
    let n = input.usize();
    let m = input.usize();
    let mut lines = vec![];
    for _ in 0..n {
        let mut a = input.vec::<i32>(m);
        let w = input.i32();
        a.sort();
        let mut ok = true;
        for w in a.windows(2) {
            if w[0] == w[1] {
                ok = false;
            }
        }
        if ok {
            lines.push(Line { w, a });
        }
    }

    let res = solve_bitsets(lines, m);

    if res == i32::MAX {
        out_line!(-1);
    } else {
        out_line!(res);
    }
}

fn number_of_le_elements(a: &[i32], val: i32) -> usize {
    binary_search_first_true(0..a.len(), |pos| a[pos] > val)
}

pub(crate) fn run(mut input: Input) -> bool {
    solve(&mut input, 1);
    output().flush();
    input.skip_whitespace();
    input.peek().is_none()
}

#[allow(unused)]
pub fn submit() -> bool {
    let io = TaskIoSettings {
        is_interactive: false,
        input: TaskIoType::Std,
        output: TaskIoType::Std,
    };

    run_task(io, run)
}

fn stress() {
    for it in 1.. {
        dbg!(it);
        let mut rnd = Random::new(787788 + it);
        let n = rnd.gen_in_range(6..200);
        let m = 5;
        let mut lines = vec![];
        let max_a = rnd.gen_in_range(6..10000);
        for _ in 0..n {
            loop {
                let mut a = rnd.gen_vec(m, 1..max_a);
                a.sort();
                let mut ok = true;
                for w in a.windows(2) {
                    if w[0] == w[1] {
                        ok = false;
                        break;
                    }
                }
                if !ok {
                    continue;
                }
                lines.push(Line {
                    w: rnd.gen_in_range(1..1_000_000_000),
                    a,
                });
                break;
            }
        }
        let res_bs = solve_bitsets(lines.clone(), m);
        let res_old = solve_test(lines, m);
        assert_eq!(res_bs, res_old);
        dbg!(res_bs);
    }
}

}
pub mod algo_lib {
pub mod collections {
pub mod array_2d {
use crate::algo_lib::io::output::Output;
use crate::algo_lib::io::output::Writable;
use crate::algo_lib::misc::num_traits::Number;
use std::io::Write;
use std::ops::Index;
use std::ops::IndexMut;
use std::ops::Mul;

// TODO: implement good Debug
#[derive(Clone, Debug)]
pub struct Array2D<T> {
    rows: usize,
    cols: usize,
    v: Vec<T>,
}

pub struct Iter<'a, T> {
    array: &'a Array2D<T>,
    row: usize,
    col: usize,
}

impl<T> Array2D<T>
where
    T: Clone,
{
    #[allow(unused)]
    pub fn new(empty: T, rows: usize, cols: usize) -> Self {
        Self {
            rows,
            cols,
            v: vec![empty; rows * cols],
        }
    }

    pub fn gen(rows: usize, cols: usize, mut f: impl FnMut(usize, usize) -> T) -> Self {
        let mut v = Vec::with_capacity(rows * cols);
        for r in 0..rows {
            for c in 0..cols {
                v.push(f(r, c));
            }
        }
        Self { rows, cols, v }
    }

    pub fn rows(&self) -> usize {
        self.rows
    }

    pub fn len(&self) -> usize {
        self.rows()
    }

    pub fn cols(&self) -> usize {
        self.cols
    }

    pub fn swap(&mut self, row1: usize, row2: usize) {
        assert!(row1 < self.rows);
        assert!(row2 < self.rows);
        if row1 != row2 {
            for col in 0..self.cols {
                self.v.swap(row1 * self.cols + col, row2 * self.cols + col);
            }
        }
    }

    pub fn transpose(&self) -> Self {
        Self::gen(self.cols, self.rows, |r, c| self[c][r].clone())
    }

    pub fn iter(&self) -> Iter<T> {
        Iter {
            array: self,
            row: 0,
            col: 0,
        }
    }
}

impl<T> Writable for Array2D<T>
where
    T: Writable,
{
    fn write(&self, output: &mut Output) {
        for r in 0..self.rows {
            self[r].write(output);
            output.write(&[b'\n']).unwrap();
        }
    }
}

impl<T> Index<usize> for Array2D<T> {
    type Output = [T];

    fn index(&self, index: usize) -> &Self::Output {
        &self.v[(index) * self.cols..(index + 1) * self.cols]
    }
}

impl<T> IndexMut<usize> for Array2D<T> {
    fn index_mut(&mut self, index: usize) -> &mut Self::Output {
        &mut self.v[(index) * self.cols..(index + 1) * self.cols]
    }
}

impl<T> Mul for &Array2D<T>
where
    T: Number,
{
    type Output = Array2D<T>;

    fn mul(self, rhs: Self) -> Self::Output {
        let n = self.rows;
        let m = self.cols;
        assert_eq!(m, rhs.rows);
        let k2 = rhs.cols;
        let mut res = Array2D::new(T::ZERO, n, k2);
        for i in 0..n {
            for j in 0..m {
                for k in 0..k2 {
                    res[i][k] += self[i][j] * rhs[j][k];
                }
            }
        }
        res
    }
}

impl<T> Array2D<T>
where
    T: Number,
{
    pub fn pown(&self, pw: usize) -> Self {
        assert_eq!(self.rows, self.cols);
        let n = self.rows;
        if pw == 0 {
            Self::gen(n, n, |r, c| if r == c { T::ONE } else { T::ZERO })
        } else if pw == 1 {
            self.clone()
        } else {
            let half = self.pown(pw / 2);
            let half2 = &half * &half;
            if pw & 1 == 0 {
                half2
            } else {
                &half2 * &self
            }
        }
    }
}

impl<'a, T> Iterator for Iter<'a, T> {
    type Item = &'a T;

    fn next(&mut self) -> Option<Self::Item> {
        if self.col == self.array.cols {
            self.col = 0;
            self.row += 1;
        }
        if self.row >= self.array.rows {
            return None;
        }
        let elem = &self.array[self.row][self.col];
        self.col += 1;
        Some(elem)
    }
}
}
pub mod bit_set {
use std::ops::BitOrAssign;
use std::ops::Not;

#[derive(Hash, Clone, Eq, PartialOrd, PartialEq, Debug)]
pub struct BitSet {
    values: Vec<u64>,
}

impl BitSet {
    #[allow(unused)]
    pub fn new(n: usize) -> Self {
        Self {
            values: vec![0u64; (n + 63) / 64],
        }
    }

    #[allow(unused)]
    pub fn get(&self, pos: usize) -> bool {
        (self.values[pos >> 6] >> (pos & 63)) & 1 == 1
    }

    #[allow(unused)]
    pub fn set(&mut self, pos: usize, val: bool) {
        if val {
            self.values[pos >> 6] |= 1u64 << (pos & 63);
        } else {
            self.values[pos >> 6] &= (1u64 << (pos & 63)).not();
        }
    }

    #[allow(unused)]
    pub fn clear(&mut self) {
        for x in self.values.iter_mut() {
            *x = 0;
        }
    }

    fn ensure_length(&mut self, bit_len: usize) {
        let i64_len = 1 + (bit_len - 1) >> 6;
        if i64_len > self.values.len() {
            self.values.resize(i64_len, 0);
        }
    }

    fn bit_len(&self) -> usize {
        self.values.len() << 6
    }

    pub fn first_not_set(&self, mut pos: usize) -> usize {
        if pos >= self.bit_len() {
            return pos;
        }
        while (pos & 63) != 0 {
            if !self.get(pos) {
                return pos;
            }
            pos += 1;
        }
        match self.values[pos >> 6..]
            .iter()
            .position(|x| *x != std::u64::MAX)
        {
            None => self.values.len() << 6,
            Some(idx) => {
                pos += idx * 64;
                while self.get(pos) {
                    pos += 1;
                }
                return pos;
            }
        }
    }
}

impl BitOrAssign<&BitSet> for BitSet {
    fn bitor_assign(&mut self, rhs: &Self) {
        self.ensure_length(rhs.bit_len());
        let len = rhs.values.len();
        for (x, y) in self.values[0..len]
            .iter_mut()
            .zip(rhs.values[0..len].iter())
        {
            *x |= *y;
        }
    }
}
}
pub mod id_map {
use std::collections::HashMap;
use std::hash::Hash;
use std::ops::Index;

pub struct IdMap<T>
where
    T: Eq + Hash + Clone,
{
    map: HashMap<T, u32>,
    values: Vec<T>,
}

impl<T> IdMap<T>
where
    T: Eq + Hash + Clone,
{
    pub fn new() -> Self {
        Self {
            map: HashMap::new(),
            values: vec![],
        }
    }

    //noinspection RsSelfConvention
    pub fn get_or_add(&mut self, key: &T) -> usize {
        if let Some(&res) = self.map.get(&key) {
            return res as usize;
        }
        let res = self.values.len() as u32;
        self.values.push(key.clone());
        self.map.insert(key.clone(), res);
        res as usize
    }

    pub fn get(&self, key: &T) -> Option<usize> {
        self.map.get(key).map(|&id| id as usize)
    }

    pub fn get_exn(&self, key: &T) -> usize {
        self.get(key).expect("Key not found")
    }

    pub fn len(&self) -> usize {
        self.values.len()
    }

    pub fn iter(&self) -> impl Iterator<Item = (usize, &T)> {
        self.values.iter().enumerate()
    }
}

impl<T> Index<usize> for IdMap<T>
where
    T: Eq + Hash + Clone,
{
    type Output = T;

    fn index(&self, index: usize) -> &Self::Output {
        &self.values[index]
    }
}
}
}
pub mod io {
pub mod input {
use crate::algo_lib::collections::array_2d::Array2D;
use crate::algo_lib::misc::ord_f64::OrdF64;
use std::fmt::Debug;
use std::io::Read;
use std::marker::PhantomData;
use std::path::Path;
use std::str::FromStr;

pub struct Input {
    input: Box<dyn Read>,
    buf: Vec<u8>,
    at: usize,
    buf_read: usize,
}

macro_rules! read_integer_fun {
    ($t:ident) => {
        #[allow(unused)]
        pub fn $t(&mut self) -> $t {
            self.read_integer()
        }
    };
}

impl Input {
    const DEFAULT_BUF_SIZE: usize = 4096;

    ///
    /// Using with stdin:
    /// ```no_run
    /// use algo_lib::io::input::Input;
    /// let stdin = std::io::stdin();
    /// let input = Input::new(Box::new(stdin));
    /// ```
    ///
    /// For read files use ``new_file`` instead.
    ///
    ///
    pub fn new(input: Box<dyn Read>) -> Self {
        Self {
            input,
            buf: vec![0; Self::DEFAULT_BUF_SIZE],
            at: 0,
            buf_read: 0,
        }
    }

    pub fn new_file<P: AsRef<Path>>(path: P) -> Self {
        let file = std::fs::File::open(&path)
            .unwrap_or_else(|_| panic!("Can't open file: {:?}", path.as_ref().as_os_str()));
        Self::new(Box::new(file))
    }

    pub fn new_with_size(input: Box<dyn Read>, buf_size: usize) -> Self {
        Self {
            input,
            buf: vec![0; buf_size],
            at: 0,
            buf_read: 0,
        }
    }

    pub fn new_file_with_size<P: AsRef<Path>>(path: P, buf_size: usize) -> Self {
        let file = std::fs::File::open(&path)
            .unwrap_or_else(|_| panic!("Can't open file: {:?}", path.as_ref().as_os_str()));
        Self::new_with_size(Box::new(file), buf_size)
    }

    pub fn get(&mut self) -> Option<u8> {
        if self.refill_buffer() {
            let res = self.buf[self.at];
            self.at += 1;
            Some(res)
        } else {
            None
        }
    }

    pub fn peek(&mut self) -> Option<u8> {
        if self.refill_buffer() {
            Some(self.buf[self.at])
        } else {
            None
        }
    }

    pub fn skip_whitespace(&mut self) {
        while let Some(b) = self.peek() {
            if !char::from(b).is_whitespace() {
                return;
            }
            self.get();
        }
    }

    pub fn next_token(&mut self) -> Option<Vec<u8>> {
        self.skip_whitespace();
        let mut res = Vec::new();
        while let Some(c) = self.get() {
            if char::from(c).is_whitespace() {
                break;
            }
            res.push(c);
        }
        if res.is_empty() {
            None
        } else {
            Some(res)
        }
    }

    //noinspection RsSelfConvention
    pub fn is_exhausted(&mut self) -> bool {
        self.peek().is_none()
    }

    pub fn has_more_elements(&mut self) -> bool {
        !self.is_exhausted()
    }

    pub fn read<T: Readable>(&mut self) -> T {
        T::read(self)
    }

    pub fn vec<T: Readable>(&mut self, size: usize) -> Vec<T> {
        let mut res = Vec::with_capacity(size);
        for _ in 0usize..size {
            res.push(self.read());
        }
        res
    }

    pub fn string_vec(&mut self, size: usize) -> Vec<Vec<u8>> {
        let mut res = Vec::with_capacity(size);
        for _ in 0usize..size {
            res.push(self.string());
        }
        res
    }

    pub fn matrix<T: Readable>(&mut self, rows: usize, cols: usize) -> Array2D<T>
    where
        T: Clone,
    {
        Array2D::gen(rows, cols, |_, _| self.read())
    }

    pub fn read_line(&mut self) -> String {
        let mut res = String::new();
        while let Some(c) = self.get() {
            if c == b'\n' {
                break;
            }
            if c == b'\r' {
                if self.peek() == Some(b'\n') {
                    self.get();
                }
                break;
            }
            res.push(c.into());
        }
        res
    }

    #[allow(clippy::should_implement_trait)]
    pub fn into_iter<T: Readable>(self) -> InputIterator<T> {
        InputIterator {
            input: self,
            phantom: Default::default(),
        }
    }

    fn read_integer<T: FromStr>(&mut self) -> T
    where
        <T as FromStr>::Err: Debug,
    {
        let res = self.read_string();
        res.parse::<T>().unwrap()
    }

    fn read_string(&mut self) -> String {
        match self.next_token() {
            None => {
                panic!("Input exhausted");
            }
            Some(res) => unsafe { String::from_utf8_unchecked(res) },
        }
    }

    pub fn string_as_string(&mut self) -> String {
        self.read_string()
    }

    pub fn string(&mut self) -> Vec<u8> {
        self.read_string().into_bytes()
    }

    fn read_char(&mut self) -> char {
        self.skip_whitespace();
        self.get().unwrap().into()
    }

    fn read_float(&mut self) -> OrdF64 {
        self.read_string().parse().unwrap()
    }

    pub fn f64(&mut self) -> OrdF64 {
        self.read_float()
    }

    fn refill_buffer(&mut self) -> bool {
        if self.at == self.buf_read {
            self.at = 0;
            self.buf_read = self.input.read(&mut self.buf).unwrap();
            self.buf_read != 0
        } else {
            true
        }
    }

    read_integer_fun!(i32);
    read_integer_fun!(i64);
    read_integer_fun!(i128);
    read_integer_fun!(u32);
    read_integer_fun!(u64);
    read_integer_fun!(usize);
}

pub trait Readable {
    fn read(input: &mut Input) -> Self;
}

impl Readable for String {
    fn read(input: &mut Input) -> Self {
        input.read_string()
    }
}

impl Readable for char {
    fn read(input: &mut Input) -> Self {
        input.read_char()
    }
}

impl Readable for f64 {
    fn read(input: &mut Input) -> Self {
        input.read_string().parse().unwrap()
    }
}

impl<T: Readable> Readable for Vec<T> {
    fn read(input: &mut Input) -> Self {
        let size = input.read();
        input.vec(size)
    }
}

pub struct InputIterator<T: Readable> {
    input: Input,
    phantom: PhantomData<T>,
}

impl<T: Readable> Iterator for InputIterator<T> {
    type Item = T;

    fn next(&mut self) -> Option<Self::Item> {
        self.input.skip_whitespace();
        self.input.peek().map(|_| self.input.read())
    }
}

macro_rules! read_integer {
    ($t:ident) => {
        impl Readable for $t {
            fn read(input: &mut Input) -> Self {
                input.read_integer()
            }
        }
    };
}

read_integer!(i8);
read_integer!(i16);
read_integer!(i32);
read_integer!(i64);
read_integer!(i128);
read_integer!(isize);
read_integer!(u8);
read_integer!(u16);
read_integer!(u32);
read_integer!(u64);
read_integer!(u128);
read_integer!(usize);

macro_rules! tuple_readable {
    ( $( $name:ident )+ ) => {
        impl<$($name: Readable), +> Readable for ($($name,)+) {
            fn read(input: &mut Input) -> Self {
                ($($name::read(input),)+)
            }
        }
    }
}

tuple_readable! {T}
tuple_readable! {T U}
tuple_readable! {T U V}
tuple_readable! {T U V X}
tuple_readable! {T U V X Y}
tuple_readable! {T U V X Y Z}
tuple_readable! {T U V X Y Z A}
tuple_readable! {T U V X Y Z A B}
tuple_readable! {T U V X Y Z A B C}
tuple_readable! {T U V X Y Z A B C D}
tuple_readable! {T U V X Y Z A B C D E}
tuple_readable! {T U V X Y Z A B C D E F}
}
pub mod output {
use std::io::Write;

pub struct Output {
    output: Box<dyn Write>,
    buf: Vec<u8>,
    at: usize,
    auto_flush: bool,
}

impl Output {
    const DEFAULT_BUF_SIZE: usize = 4096;

    pub fn new(output: Box<dyn Write>) -> Self {
        Self {
            output,
            buf: vec![0; Self::DEFAULT_BUF_SIZE],
            at: 0,
            auto_flush: false,
        }
    }

    pub fn new_with_auto_flush(output: Box<dyn Write>) -> Self {
        Self {
            output,
            buf: vec![0; Self::DEFAULT_BUF_SIZE],
            at: 0,
            auto_flush: true,
        }
    }

    pub fn flush(&mut self) {
        if self.at != 0 {
            self.output.write_all(&self.buf[..self.at]).unwrap();
            self.at = 0;
            self.output.flush().expect("Couldn't flush output");
        }
    }

    pub fn print<T: Writable>(&mut self, s: &T) {
        s.write(self);
    }

    pub fn put(&mut self, b: u8) {
        self.buf[self.at] = b;
        self.at += 1;
        if self.at == self.buf.len() {
            self.flush();
        }
    }

    pub fn maybe_flush(&mut self) {
        if self.auto_flush {
            self.flush();
        }
    }

    pub fn print_per_line<T: Writable>(&mut self, arg: &[T]) {
        for i in arg {
            i.write(self);
            self.put(b'\n');
        }
    }

    pub fn print_iter<T: Writable, I: Iterator<Item = T>>(&mut self, iter: I) {
        let mut first = true;
        for e in iter {
            if first {
                first = false;
            } else {
                self.put(b' ');
            }
            e.write(self);
        }
    }

    pub fn print_iter_ref<'a, T: 'a + Writable, I: Iterator<Item = &'a T>>(&mut self, iter: I) {
        let mut first = true;
        for e in iter {
            if first {
                first = false;
            } else {
                self.put(b' ');
            }
            e.write(self);
        }
    }
}

impl Write for Output {
    fn write(&mut self, buf: &[u8]) -> std::io::Result<usize> {
        let mut start = 0usize;
        let mut rem = buf.len();
        while rem > 0 {
            let len = (self.buf.len() - self.at).min(rem);
            self.buf[self.at..self.at + len].copy_from_slice(&buf[start..start + len]);
            self.at += len;
            if self.at == self.buf.len() {
                self.flush();
            }
            start += len;
            rem -= len;
        }
        if self.auto_flush {
            self.flush();
        }
        Ok(buf.len())
    }

    fn flush(&mut self) -> std::io::Result<()> {
        self.flush();
        Ok(())
    }
}

pub trait Writable {
    fn write(&self, output: &mut Output);
}

impl Writable for &str {
    fn write(&self, output: &mut Output) {
        output.write_all(self.as_bytes()).unwrap();
    }
}

impl Writable for String {
    fn write(&self, output: &mut Output) {
        output.write_all(self.as_bytes()).unwrap();
    }
}

impl Writable for char {
    fn write(&self, output: &mut Output) {
        output.put(*self as u8);
    }
}

impl<T: Writable> Writable for [T] {
    fn write(&self, output: &mut Output) {
        output.print_iter_ref(self.iter());
    }
}

impl<T: Writable> Writable for Vec<T> {
    fn write(&self, output: &mut Output) {
        self[..].write(output);
    }
}

macro_rules! write_to_string {
    ($t:ident) => {
        impl Writable for $t {
            fn write(&self, output: &mut Output) {
                self.to_string().write(output);
            }
        }
    };
}

write_to_string!(u8);
write_to_string!(u16);
write_to_string!(u32);
write_to_string!(u64);
write_to_string!(u128);
write_to_string!(usize);
write_to_string!(i8);
write_to_string!(i16);
write_to_string!(i32);
write_to_string!(i64);
write_to_string!(i128);
write_to_string!(isize);
write_to_string!(f32);
write_to_string!(f64);

impl<T: Writable, U: Writable> Writable for (T, U) {
    fn write(&self, output: &mut Output) {
        self.0.write(output);
        output.put(b' ');
        self.1.write(output);
    }
}

impl<T: Writable, U: Writable, V: Writable> Writable for (T, U, V) {
    fn write(&self, output: &mut Output) {
        self.0.write(output);
        output.put(b' ');
        self.1.write(output);
        output.put(b' ');
        self.2.write(output);
    }
}

pub static mut OUTPUT: Option<Output> = None;

pub fn set_global_output_to_stdout() {
    unsafe {
        OUTPUT = Some(Output::new(Box::new(std::io::stdout())));
    }
}

pub fn set_global_output_to_file(path: &str) {
    unsafe {
        let out_file = std::fs::File::create(path).expect(&format!("Can't create file {}", path));
        OUTPUT = Some(Output::new(Box::new(out_file)));
    }
}

pub fn set_global_output_to_none() {
    unsafe {
        match &mut OUTPUT {
            None => {}
            Some(output) => output.flush(),
        }
        OUTPUT = None;
    }
}

pub fn output() -> &'static mut Output {
    unsafe {
        match &mut OUTPUT {
            None => {
                panic!("Global output wasn't initialized");
            }
            Some(output) => output,
        }
    }
}

#[macro_export]
macro_rules! out {
    ($first: expr $(,$args:expr )*) => {
        output().print(&$first);
        $(output().put(b' ');
        output().print(&$args);
        )*
        output().maybe_flush();
    }
}

#[macro_export]
macro_rules! out_line {
    ($first: expr $(, $args:expr )* ) => {
        {
            out!($first $(,$args)*);
            output().put(b'\n');
            output().maybe_flush();
        }
    };
    () => {
        {
            output().put(b'\n');
            output().maybe_flush();
        }
    };
}
}
pub mod task_io_settings {
pub enum TaskIoType {
    Std,
    File(String),
}

pub struct TaskIoSettings {
    pub is_interactive: bool,
    pub input: TaskIoType,
    pub output: TaskIoType,
}
}
pub mod task_runner {
use std::io::Write;

use super::input::Input;
use super::output::Output;
use super::output::OUTPUT;
use super::task_io_settings::TaskIoSettings;
use super::task_io_settings::TaskIoType;

pub fn run_task<Res>(io: TaskIoSettings, run: impl FnOnce(Input) -> Res) -> Res {
    let output: Box<dyn Write> = match io.output {
        TaskIoType::Std => Box::new(std::io::stdout()),
        TaskIoType::File(file) => {
            let out_file = std::fs::File::create(file).unwrap();
            Box::new(out_file)
        }
    };

    unsafe {
        if io.is_interactive {
            OUTPUT = Some(Output::new_with_auto_flush(output));
        } else {
            OUTPUT = Some(Output::new(output));
        }
    }

    let input = match io.input {
        TaskIoType::Std => {
            let sin = std::io::stdin();
            if io.is_interactive {
                Input::new_with_size(Box::new(sin), 1)
            } else {
                Input::new(Box::new(sin))
            }
        }
        TaskIoType::File(file) => {
            if io.is_interactive {
                Input::new_file_with_size(file, 1)
            } else {
                Input::new_file(file)
            }
        }
    };

    run(input)
}
}
}
pub mod misc {
pub mod binary_search {
use crate::algo_lib::misc::num_traits::Number;
use std::ops::Range;

pub fn binary_search_first_true<T>(range: Range<T>, mut f: impl FnMut(T) -> bool) -> T
where
    T: Number,
{
    // we can't store [range.start - 1] into [left], because it could overflow
    let mut left_plus_one = range.start;
    let mut right = range.end;
    while right > left_plus_one {
        let mid = left_plus_one + (right - left_plus_one) / T::TWO;
        if f(mid) {
            right = mid;
        } else {
            left_plus_one = mid + T::ONE;
        }
    }
    right
}

pub fn binary_search_last_true<T>(range: Range<T>, mut f: impl FnMut(T) -> bool) -> Option<T>
where
    T: Number,
{
    let first_false = binary_search_first_true(range.clone(), |x| !f(x));
    if first_false == range.start {
        None
    } else {
        Some(first_false - T::ONE)
    }
}

#[test]
fn simple_stress() {
    const N: usize = 50;
    for n in 1..N {
        for cnt_false in 0..=n {
            let mut a = vec![false; cnt_false];
            a.resize(n, true);
            let mut max_f_calls = ((n + 1) as f64).log2().ceil() as i32;
            let f_is_true = |id: usize| -> bool {
                max_f_calls -= 1;
                assert!(max_f_calls >= 0);
                a[id]
            };
            let result = binary_search_first_true(0..n, f_is_true);
            assert_eq!(result, cnt_false);
        }
    }
}
}
pub mod dbg_macro {
#[macro_export]
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
                    file!(), line!(), stringify!($first_val), &$first_val)
    };
}
}
pub mod gen_vector {
pub fn gen_vec<T>(n: usize, mut f: impl FnMut(usize) -> T) -> Vec<T> {
    (0..n).map(|id| f(id)).collect()
}
}
pub mod min_max {
pub trait UpdateMinMax: PartialOrd + Sized {
    fn update_min(&mut self, other: Self) -> bool {
        if other < *self {
            *self = other;
            true
        } else {
            false
        }
    }

    fn update_max(&mut self, other: Self) -> bool {
        if other > *self {
            *self = other;
            true
        } else {
            false
        }
    }
}

impl<T: PartialOrd + Sized> UpdateMinMax for T {}

pub trait FindMinMaxPos {
    fn index_of_min(&self) -> usize;
    fn index_of_max(&self) -> usize;
}

impl<T: PartialOrd> FindMinMaxPos for [T] {
    fn index_of_min(&self) -> usize {
        let mut pos_of_best = 0;
        for (idx, val) in self.iter().enumerate().skip(1) {
            if val < &self[pos_of_best] {
                pos_of_best = idx;
            }
        }
        pos_of_best
    }

    fn index_of_max(&self) -> usize {
        let mut pos_of_best = 0;
        for (idx, val) in self.iter().enumerate().skip(1) {
            if val > &self[pos_of_best] {
                pos_of_best = idx;
            }
        }
        pos_of_best
    }
}

pub fn index_of_min_by<T, F>(n: usize, f: F) -> usize
where
    T: PartialOrd,
    F: Fn(usize) -> T,
{
    assert!(n > 0);
    let mut best_idx = 0;
    let mut best_val = f(0);
    for idx in 1..n {
        let cur_val = f(idx);
        if cur_val < best_val {
            best_val = cur_val;
            best_idx = idx;
        }
    }
    best_idx
}

pub fn index_of_max_by<T, F>(n: usize, f: F) -> usize
where
    T: PartialOrd,
    F: Fn(usize) -> T,
{
    assert!(n > 0);
    let mut best_idx = 0;
    let mut best_val = f(0);
    for idx in 1..n {
        let cur_val = f(idx);
        if cur_val > best_val {
            best_val = cur_val;
            best_idx = idx;
        }
    }
    best_idx
}
}
pub mod num_traits {
use std::fmt::Debug;
use std::ops::Add;
use std::ops::AddAssign;
use std::ops::Div;
use std::ops::DivAssign;
use std::ops::Mul;
use std::ops::MulAssign;
use std::ops::Sub;
use std::ops::SubAssign;

pub trait HasConstants<T> {
    const MAX: T;
    const MIN: T;
    const ZERO: T;
    const ONE: T;
    const TWO: T;
}

pub trait ConvI32<T> {
    fn from_i32(val: i32) -> T;
    fn to_i32(self) -> i32;
}

pub trait Number:
    Copy
    + Add<Output = Self>
    + AddAssign
    + Sub<Output = Self>
    + SubAssign
    + Mul<Output = Self>
    + MulAssign
    + Div<Output = Self>
    + DivAssign
    + Ord
    + PartialOrd
    + Eq
    + PartialEq
    + HasConstants<Self>
    + Default
    + Debug
    + Sized
    + ConvI32<Self>
{
}

impl<
        T: Copy
            + Add<Output = Self>
            + AddAssign
            + Sub<Output = Self>
            + SubAssign
            + Mul<Output = Self>
            + MulAssign
            + Div<Output = Self>
            + DivAssign
            + Ord
            + PartialOrd
            + Eq
            + PartialEq
            + HasConstants<Self>
            + Default
            + Debug
            + Sized
            + ConvI32<Self>,
    > Number for T
{
}

macro_rules! has_constants_impl {
    ($t: ident) => {
        impl HasConstants<$t> for $t {
            // TODO: remove `std` for new rust version..
            const MAX: $t = std::$t::MAX;
            const MIN: $t = std::$t::MIN;
            const ZERO: $t = 0;
            const ONE: $t = 1;
            const TWO: $t = 2;
        }

        impl ConvI32<$t> for $t {
            fn from_i32(val: i32) -> $t {
                val as $t
            }

            fn to_i32(self) -> i32 {
                self as i32
            }
        }
    };
}

has_constants_impl!(i32);
has_constants_impl!(i64);
has_constants_impl!(i128);
has_constants_impl!(u32);
has_constants_impl!(u64);
has_constants_impl!(u128);
has_constants_impl!(usize);
has_constants_impl!(u8);

impl ConvI32<Self> for f64 {
    fn from_i32(val: i32) -> Self {
        val as f64
    }

    fn to_i32(self) -> i32 {
        self as i32
    }
}

impl HasConstants<Self> for f64 {
    const MAX: Self = Self::MAX;
    const MIN: Self = -Self::MAX;
    const ZERO: Self = 0.0;
    const ONE: Self = 1.0;
    const TWO: Self = 2.0;
}
}
pub mod ord_f64 {
use crate::algo_lib::io::input::Input;
use crate::algo_lib::io::input::Readable;
use crate::algo_lib::io::output::Output;
use crate::algo_lib::io::output::Writable;
use crate::algo_lib::misc::num_traits::ConvI32;
use crate::algo_lib::misc::num_traits::HasConstants;
use std::cmp::min;
use std::cmp::Ordering;
use std::f64::consts::PI;
use std::fmt::Debug;
use std::fmt::Display;
use std::fmt::Formatter;
use std::io::Write;
use std::num::ParseFloatError;
use std::ops::Neg;
use std::ops::Rem;
use std::str::FromStr;

#[derive(PartialOrd, PartialEq, Copy, Clone, Default)]
pub struct OrdF64(pub f64);

impl OrdF64 {
    pub const EPS: Self = Self(1e-9);
    pub const SMALL_EPS: Self = Self(1e-4);
    pub const PI: Self = Self(PI);

    pub fn abs(&self) -> Self {
        Self(self.0.abs())
    }

    pub fn eq_with_eps(&self, other: &Self, eps: Self) -> bool {
        let abs_diff = (*self - *other).abs();
        abs_diff <= eps || abs_diff <= min(self.abs(), other.abs()) * eps
    }

    pub fn eq_with_default_eps(&self, other: &Self) -> bool {
        self.eq_with_eps(other, Self::EPS)
    }

    pub fn sqrt(&self) -> Self {
        Self(self.0.sqrt())
    }

    pub fn powf(&self, n: f64) -> Self {
        Self(self.0.powf(n))
    }
}

impl Eq for OrdF64 {}

impl Ord for OrdF64 {
    fn cmp(&self, other: &Self) -> Ordering {
        self.partial_cmp(other).unwrap()
    }
}

impl std::ops::Add for OrdF64 {
    type Output = Self;

    fn add(self, rhs: Self) -> Self::Output {
        Self(self.0 + rhs.0)
    }
}

impl std::ops::AddAssign for OrdF64 {
    fn add_assign(&mut self, rhs: Self) {
        self.0 += rhs.0;
    }
}

impl std::ops::Sub for OrdF64 {
    type Output = Self;

    fn sub(self, rhs: Self) -> Self::Output {
        Self(self.0 - rhs.0)
    }
}

impl std::ops::SubAssign for OrdF64 {
    fn sub_assign(&mut self, rhs: Self) {
        self.0 -= rhs.0;
    }
}

impl std::ops::Mul for OrdF64 {
    type Output = Self;

    fn mul(self, rhs: Self) -> Self::Output {
        Self(self.0 * rhs.0)
    }
}

impl std::ops::MulAssign for OrdF64 {
    fn mul_assign(&mut self, rhs: Self) {
        self.0 *= rhs.0;
    }
}

impl std::ops::Div for OrdF64 {
    type Output = Self;

    fn div(self, rhs: Self) -> Self::Output {
        Self(self.0 / rhs.0)
    }
}

impl std::ops::DivAssign for OrdF64 {
    fn div_assign(&mut self, rhs: Self) {
        self.0 /= rhs.0;
    }
}

impl Neg for OrdF64 {
    type Output = Self;

    fn neg(self) -> Self::Output {
        Self(-self.0)
    }
}

impl Display for OrdF64 {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        Display::fmt(&self.0, f)
    }
}

impl Debug for OrdF64 {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        Debug::fmt(&self.0, f)
    }
}

impl Writable for OrdF64 {
    fn write(&self, output: &mut Output) {
        output.write_fmt(format_args!("{}", self.0)).unwrap();
    }
}

impl Readable for OrdF64 {
    fn read(input: &mut Input) -> Self {
        Self(input.read::<f64>())
    }
}

impl HasConstants<Self> for OrdF64 {
    const MAX: Self = Self(f64::MAX);
    const MIN: Self = Self(-f64::MAX);
    const ZERO: Self = Self(0.0);
    const ONE: Self = Self(1.0);
    const TWO: Self = Self(2.0);
}

impl ConvI32<Self> for OrdF64 {
    fn from_i32(val: i32) -> Self {
        Self(val as f64)
    }

    fn to_i32(self) -> i32 {
        self.0 as i32
    }
}

impl FromStr for OrdF64 {
    type Err = ParseFloatError;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        match s.parse::<f64>() {
            Ok(value) => Ok(Self(value)),
            Err(error) => Err(error),
        }
    }
}

impl From<OrdF64> for f64 {
    fn from(x: OrdF64) -> Self {
        x.0
    }
}

impl Rem for OrdF64 {
    type Output = Self;

    fn rem(self, rhs: Self) -> Self::Output {
        Self(self.0 % rhs.0)
    }
}

#[macro_export]
macro_rules! f {
    ($a:expr) => {
        OrdF64($a)
    };
}

impl From<usize> for OrdF64 {
    fn from(x: usize) -> Self {
        f!(x as f64)
    }
}

impl From<i32> for OrdF64 {
    fn from(x: i32) -> Self {
        f!(x as f64)
    }
}

impl From<f64> for OrdF64 {
    fn from(x: f64) -> Self {
        f!(x)
    }
}
}
pub mod rand {
use crate::algo_lib::misc::gen_vector::gen_vec;
use crate::algo_lib::misc::num_traits::Number;
use std::ops::Range;
use std::time::SystemTime;
use std::time::UNIX_EPOCH;

#[allow(dead_code)]
pub struct Random {
    state: u64,
}

impl Random {
    pub fn gen_u64(&mut self) -> u64 {
        let mut x = self.state;
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        self.state = x;
        x
    }

    #[allow(dead_code)]
    pub fn next_in_range(&mut self, from: usize, to: usize) -> usize {
        assert!(from < to);
        (from as u64 + self.gen_u64() % ((to - from) as u64)) as usize
    }

    pub fn gen_index<T>(&mut self, a: &[T]) -> usize {
        self.gen_in_range(0..a.len())
    }

    #[allow(dead_code)]
    pub fn gen_double(&mut self) -> f64 {
        (self.gen_u64() as f64) / (usize::MAX as f64)
    }

    #[allow(dead_code)]
    pub fn new(seed: u64) -> Self {
        let state = if seed == 0 { 787788 } else { seed };
        Self { state }
    }

    pub fn new_time_seed() -> Self {
        let time = SystemTime::now();
        let seed = (time.duration_since(UNIX_EPOCH).unwrap().as_nanos() % 1_000_000_000) as u64;
        if seed == 0 {
            Self::new(787788)
        } else {
            Self::new(seed)
        }
    }

    #[allow(dead_code)]
    pub fn gen_permutation(&mut self, n: usize) -> Vec<usize> {
        let mut result: Vec<_> = (0..n).collect();
        for i in 0..n {
            let idx = self.next_in_range(0, i + 1);
            result.swap(i, idx);
        }
        result
    }

    pub fn gen_in_range<T>(&mut self, range: Range<T>) -> T
    where
        T: Number,
    {
        let from = T::to_i32(range.start);
        let to = T::to_i32(range.end);
        let len = (to - from) as usize;
        T::from_i32(self.next_in_range(0, len) as i32 + from)
    }

    pub fn gen_vec<T>(&mut self, n: usize, range: Range<T>) -> Vec<T>
    where
        T: Number,
    {
        gen_vec(n, |_| self.gen_in_range(range.clone()))
    }

    pub fn gen_nonempty_range(&mut self, n: usize) -> Range<usize> {
        let x = self.gen_in_range(0..n);
        let y = self.gen_in_range(0..n);
        if x <= y {
            x..y + 1
        } else {
            y..x + 1
        }
    }

    pub fn gen_bool(&mut self) -> bool {
        self.gen_in_range(0..2) == 0
    }
}
}
}
}
fn main() {
    crate::solution::submit();
}