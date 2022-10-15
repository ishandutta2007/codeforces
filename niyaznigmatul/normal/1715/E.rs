pub mod solution {

use std::cmp::min;
use crate::io::input::Input;
use crate::io::output::output;
use crate::{out, out_line};
use crate::datastructures::convex_set::ConvexSet;
use crate::graphs::dijkstra::{shortest_path_sparse_dijkstra, shortest_path_sparse_dijkstra_continue};

fn solve(input: &mut Input, _test_case: usize) {
    let n = input.read();
    let m = input.read();
    let k = input.read();
    let mut edges = vec![Vec::new(); n];
    for _ in 0..m {
        let v = input.read::<usize>() - 1;
        let u = input.read::<usize>() - 1;
        let w = input.read();
        edges[v].push((u, w));
        edges[u].push((v, w));
    }
    let mut d = shortest_path_sparse_dijkstra(&edges, 0);
    for _ in 0..k {
        let mut lines = Vec::new();
        for (v, &dist) in (0..n).zip(d.iter()) {
            if dist != i64::MAX {
                let x = v as i64;
                lines.push((2 * x, -dist - x * x));
            }
        }
        let convex = ConvexSet::new(&lines);
        let mut replier = convex.monotonic_query();
        for i in 0..n {
            let x = i as i64;
            let best_line = replier.query(x);
            let value = -(best_line.0 * x + best_line.1) + x * x;
            d[i] = value;
        }
        d = shortest_path_sparse_dijkstra_continue(&edges, d);
    }
    out_line!(d);
}

pub(crate) fn run(mut input: Input) -> bool {
    solve(&mut input, 1);
    output().flush();
    input.skip_whitespace();
    !input.peek().is_some()
}


}
pub mod datastructures {
pub mod convex_set {
/// Stores ax + b. Query: given x0, maximizes a * x0 + b
pub struct ConvexSet {
    hull: Vec<(i64, i64)>,
}

/// left.0 < between.0 < right.0
fn line_not_required_between(between: &(i64, i64), left: &(i64, i64), right: &(i64, i64)) -> bool {
    (right.0 - between.0) * (left.1 - between.1) >= (between.0 - left.0) * (between.1 - right.1)
}

/// left.0 < right.0
fn point_to_the_left_of_intersection(x: i64, left: &(i64, i64), right: &(i64, i64)) -> bool {
    (right.0 - left.0) * x <= (left.1 - right.1)
}

impl ConvexSet {
    /// Elements are to be given strictly increasing by a
    pub fn new(lines: &Vec<(i64, i64)>) -> Self {
        let mut hull = Vec::new();
        for line in lines {
            while hull.len() > 1
                && line_not_required_between(&hull[hull.len() - 1], &hull[hull.len() - 2], line)
            {
                hull.pop();
            }
            hull.push(line.to_owned());
        }
        Self { hull }
    }

    pub fn query(&self, x: i64) -> (i64, i64) {
        let mut left = 0;
        let mut right = self.hull.len();
        while left + 1 < right {
            let mid = (left + right) >> 1;
            if point_to_the_left_of_intersection(x, &self.hull[mid - 1], &self.hull[mid]) {
                right = mid;
            } else {
                left = mid;
            }
        }
        self.hull[left]
    }

    pub fn monotonic_query(&self) -> MonotonicQuery {
        MonotonicQuery {
            conv_set: self,
            pos: 0,
        }
    }
}

pub struct MonotonicQuery<'a> {
    conv_set: &'a ConvexSet,
    pos: usize,
}

impl<'a> MonotonicQuery<'a> {
    pub fn query(&mut self, x: i64) -> (i64, i64) {
        let hull = &self.conv_set.hull;
        while self.pos + 1 < hull.len()
            && !point_to_the_left_of_intersection(x, &hull[self.pos], &hull[self.pos + 1])
        {
            self.pos += 1;
        }
        hull[self.pos]
    }
}
}
}
pub mod graphs {
pub mod dijkstra {
use std::cmp::{min, Reverse};
use std::collections::BinaryHeap;

pub fn shortest_path_dijkstra_by<T, F>(vertices: &[T], source: usize, mut f: F) -> Vec<i64>
where
    F: FnMut(&T, &T) -> Option<i64>,
{
    let n = vertices.len();
    let mut d = vec![i64::MAX; n];
    let mut used = vec![false; n];
    d[source] = 0;
    while let Some(found) = (0..n)
        .filter(|v| !used[*v] && d[*v] != i64::MAX)
        .min_by_key(|v| d[*v])
    {
        used[found] = true;
        for to in 0..n {
            if let Some(weight) = f(&vertices[found], &vertices[to]) {
                d[to] = min(d[to], d[found] + weight);
            }
        }
    }
    d
}

pub fn shortest_path_sparse_dijkstra_continue(
    edges: &[Vec<(usize, i64)>],
    mut d: Vec<i64>,
) -> Vec<i64> {
    let n = edges.len();
    let mut q = BinaryHeap::from_iter(
        (0..n)
            .filter(|v| d[*v] != i64::MAX)
            .map(|v| Reverse((d[v], v))),
    );
    // q.reserve(edges.iter().map(|x| x.len()).sum::<usize>());
    while let Some(Reverse((distance, v))) = q.pop() {
        if d[v] != distance {
            continue;
        }
        for &(to, weight) in &edges[v] {
            if d[to] > distance + weight {
                d[to] = distance + weight;
                q.push(Reverse((d[to], to)));
            }
        }
    }
    d
}

pub fn shortest_path_sparse_dijkstra(edges: &[Vec<(usize, i64)>], source: usize) -> Vec<i64> {
    let mut d = vec![i64::MAX; edges.len()];
    d[source] = 0;
    shortest_path_sparse_dijkstra_continue(edges, d)
}
}
}
pub mod io {
pub mod input {
use std::fmt::Debug;
use std::io::Read;
use std::marker::PhantomData;
use std::str::FromStr;

pub struct Input<'s> {
    input: &'s mut dyn Read,
    buf: Vec<u8>,
    at: usize,
    buf_read: usize,
}

impl<'s> Input<'s> {
    const DEFAULT_BUF_SIZE: usize = 4096;

    pub fn new(input: &'s mut dyn Read) -> Self {
        Self {
            input,
            buf: vec![0; Self::DEFAULT_BUF_SIZE],
            at: 0,
            buf_read: 0,
        }
    }

    pub fn new_with_size(input: &'s mut dyn Read, buf_size: usize) -> Self {
        Self {
            input,
            buf: vec![0; buf_size],
            at: 0,
            buf_read: 0,
        }
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

    pub fn read<T: Readable>(&mut self) -> T {
        T::read(self)
    }

    pub fn read_vec<T: Readable>(&mut self, size: usize) -> Vec<T> {
        let mut res = Vec::with_capacity(size);
        for _ in 0usize..size {
            res.push(self.read());
        }
        res
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
    pub fn into_iter<T: Readable>(self) -> InputIterator<'s, T> {
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

    fn read_char(&mut self) -> char {
        self.skip_whitespace();
        self.get().unwrap().into()
    }

    fn read_float(&mut self) -> f64 {
        self.read_string().parse().unwrap()
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
        input.read_float()
    }
}

impl<T: Readable> Readable for Vec<T> {
    fn read(input: &mut Input) -> Self {
        let size = input.read();
        input.read_vec(size)
    }
}

pub struct InputIterator<'s, T: Readable> {
    input: Input<'s>,
    phantom: PhantomData<T>,
}

impl<'s, T: Readable> Iterator for InputIterator<'s, T> {
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

pub fn output() -> &'static mut Output {
    unsafe {
        match &mut OUTPUT {
            None => {
                panic!("Panic");
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
    }
}

#[macro_export]
macro_rules! out_line {
    ($first: expr $(, $args:expr )* ) => {
        out!($first $(,$args)*);
        output().put(b'\n');
    };
    () => {
        output().put(b'\n');
    };
}
}
}
fn main() {
    let mut sin = std::io::stdin();
    let input = crate::io::input::Input::new(&mut sin);
    unsafe {
        crate::io::output::OUTPUT = Some(crate::io::output::Output::new(Box::new(std::io::stdout())));
    }
    crate::solution::run(input);
}