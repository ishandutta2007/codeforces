pub mod solution {

use std::collections::BTreeSet;

use crate::graph::edges::edge_trait::EdgeTrait;
use crate::graph::graph_trait::GraphTrait;
use crate::io::output::output;
use crate::misc::binary_search::binary_search_last_true;
use crate::misc::rec_function::{Callable2, RecursiveFunction2};
#[allow(unused)]
use crate::{dbg, out, out_line};
use crate::{graph::simple_graph::SimpleGraphT, seg_trees::fenwick::Fenwick};
use crate::{io::input::Input, misc::vec_apply_delta::ApplyDelta};

#[derive(Clone)]
struct Query {
    id: usize,
    at_least: usize,
    kth: usize,
}

struct DS {
    seen_number: Vec<i32>,
    count_sizes: Fenwick,
    examples: Vec<BTreeSet<usize>>,
}

impl DS {
    pub fn new(n: usize) -> Self {
        Self {
            seen_number: vec![0; n],
            count_sizes: Fenwick::new(n + 1),
            examples: vec![BTreeSet::new(); n + 1],
        }
    }

    pub fn change_num(&mut self, number: usize, delta: i32) {
        self.examples[self.seen_number[number] as usize].remove(&number);
        self.count_sizes.add(self.seen_number[number] as usize, -1);
        self.seen_number[number] += delta;
        self.count_sizes.add(self.seen_number[number] as usize, 1);
        self.examples[self.seen_number[number] as usize].insert(number);
    }

    pub fn get_random(&self, pos: usize) -> usize {
        *self.examples[pos].iter().next().unwrap()
    }
}

fn solve(input: &mut Input, _test_case: usize) {
    let n = input.usize();
    let q = input.usize();
    let values = input.read_vec::<usize>(n).sub_from_all(1);
    let mut graph = SimpleGraphT::new(n);
    for v in 1..n {
        let p = input.usize() - 1;
        graph.add_bi_edge(v, p);
    }
    let mut queries = vec![vec![]; n];
    for id in 0..q {
        let v = input.usize() - 1;
        let at_least = input.usize();
        let kth = input.usize() - 1;
        queries[v].push(Query { id, at_least, kth });
    }
    let mut ds = DS::new(n);
    let mut res = vec![0i32; q];
    RecursiveFunction2::new(|f, v: usize, p| {
        ds.change_num(values[v], 1);
        for query in queries[v].iter() {
            let cnt_at_least = ds.count_sizes.get_suffix_sum(query.at_least) as usize;
            res[query.id] = if cnt_at_least > query.kth {
                let from_end = cnt_at_least - query.kth;
                let pos = binary_search_last_true(0..n + 1, |check| {
                    ds.count_sizes.get_suffix_sum(check) >= from_end as i64
                })
                .unwrap();
                (ds.get_random(pos) + 1) as i32
            } else {
                -1
            };
        }
        for edge in graph.adj(v) {
            let to = edge.to();
            if to == p {
                continue;
            }
            f.call(to, v);
        }
        ds.change_num(values[v], -1);
    })
    .call(0, 0);
    out_line!(res);
}

pub(crate) fn run(mut input: Input) -> bool {
    let t = input.read();
    for i in 0usize..t {
        solve(&mut input, i + 1);
    }
    output().flush();
    input.skip_whitespace();
    input.peek().is_none()
}

}
pub mod collections {
pub mod array_2d {
use crate::io::output::{Output, Writable};
use crate::misc::num_traits::Number;
use std::io::Write;
use std::ops::{Index, IndexMut, Mul};

// TODO: implement good Debug
#[derive(Clone, Debug)]
pub struct Array2D<T> {
    rows: usize,
    cols: usize,
    v: Vec<T>,
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
}
}
pub mod graph {
pub mod edges {
pub mod edge_trait {
pub trait EdgeTrait: Copy + Clone {
    fn to(&self) -> usize;
    fn rev(&self, from: usize) -> Self;
}
}
pub mod simple_edge {
use crate::graph::edges::edge_trait::EdgeTrait;

#[derive(Copy, Clone, Default)]
pub struct SimpleEdge {
    to: u32,
}

impl SimpleEdge {
    pub fn new(to: usize) -> Self {
        Self { to: to as u32 }
    }
}

impl EdgeTrait for SimpleEdge {
    #[inline(always)]
    fn to(&self) -> usize {
        self.to as usize
    }

    fn rev(&self, from: usize) -> Self {
        Self { to: from as u32 }
    }
}
}
pub mod weighted_edge {
use crate::graph::edges::edge_trait::EdgeTrait;
use crate::misc::num_traits::Number;

#[derive(Copy, Clone, Default)]
pub struct WeightedEdge<T>
where
    T: Number,
{
    to: u32,
    pub cost: T,
}

impl<T> WeightedEdge<T>
where
    T: Number,
{
    pub fn new(to: usize, cost: T) -> Self {
        Self {
            to: to as u32,
            cost,
        }
    }
}

impl<T> EdgeTrait for WeightedEdge<T>
where
    T: Number,
{
    #[inline(always)]
    fn to(&self) -> usize {
        self.to as usize
    }

    fn rev(&self, from: usize) -> Self {
        Self {
            to: from as u32,
            cost: self.cost,
        }
    }
}
}
}
pub mod graph_trait {
use crate::graph::edges::edge_trait::EdgeTrait;

pub trait GraphTrait<E>
where
    E: EdgeTrait,
{
    // alias for [num_vertices]
    fn len(&self) -> usize;
    fn num_vertices(&self) -> usize;
    fn num_edges(&self) -> usize;

    fn adj(&self, v: usize) -> &[E];
}
}
pub mod simple_graph {
use crate::graph::edges::edge_trait::EdgeTrait;
use crate::graph::graph_trait::GraphTrait;
use crate::misc::num_traits::Number;

use crate::graph::edges::simple_edge::SimpleEdge;
use crate::graph::edges::weighted_edge::WeightedEdge;
use crate::graph::weighted_graph::WeightedGraph;

pub struct SimpleGraphT<E>
where
    E: EdgeTrait,
{
    adj: Vec<Vec<E>>,
    num_edges: usize,
}

impl<E> SimpleGraphT<E>
where
    E: EdgeTrait,
{
    pub fn new(n: usize) -> Self {
        Self {
            adj: vec![vec![]; n],
            num_edges: 0,
        }
    }

    pub fn with_adj(adj: Vec<Vec<E>>) -> Self {
        let num_edges = adj.iter().map(|v| v.len()).sum();
        Self { adj, num_edges }
    }

    pub fn with_edges(n: usize, edges: &[(usize, E)]) -> Self {
        let mut cnt_adj = vec![0u32; n];
        for (fr, _) in edges.iter() {
            cnt_adj[*fr] += 1;
        }
        let mut adj: Vec<_> = (0..n)
            .map(|id| Vec::with_capacity(cnt_adj[id] as usize))
            .collect();
        for (fr, edge) in edges.iter() {
            adj[*fr].push(edge.clone());
        }
        Self {
            adj,
            num_edges: edges.len(),
        }
    }

    pub fn add_complex_edge(&mut self, from: usize, edge: E) {
        self.adj[from].push(edge);
    }

    pub fn add_complex_bi_edge(&mut self, from: usize, edge: E) {
        self.adj[from].push(edge);
        let rev_edge = edge.rev(from);
        self.adj[edge.to()].push(rev_edge);
    }

    fn ensure_vertex_exist(&mut self, v: usize) {
        if v >= self.adj.len() {
            self.adj.resize(v + 1, vec![]);
        }
    }

    pub fn add_edge_maybe_new_vertices(&mut self, from: usize, edge: E) {
        self.ensure_vertex_exist(from);
        self.ensure_vertex_exist(edge.to());
        self.adj[from].push(edge);
    }
}

impl<E> GraphTrait<E> for SimpleGraphT<E>
where
    E: EdgeTrait,
{
    fn len(&self) -> usize {
        self.num_vertices()
    }

    fn num_vertices(&self) -> usize {
        self.adj.len()
    }

    fn num_edges(&self) -> usize {
        self.num_edges
    }

    fn adj(&self, v: usize) -> &[E] {
        &self.adj[v]
    }
}

impl<E> SimpleGraphT<E>
where
    E: EdgeTrait,
{
    pub fn all_edges(&self) -> impl Iterator<Item = (usize, &E)> + '_ {
        (0..self.num_vertices()).flat_map(move |v| self.adj[v].iter().map(move |e| (v, e)))
    }
}

impl SimpleGraphT<SimpleEdge> {
    pub fn add_edge(&mut self, fr: usize, to: usize) {
        self.add_complex_edge(fr, SimpleEdge::new(to));
    }

    pub fn add_bi_edge(&mut self, fr: usize, to: usize) {
        self.add_complex_edge(fr, SimpleEdge::new(to));
        self.add_complex_edge(to, SimpleEdge::new(fr));
    }
}

impl<T: Number> WeightedGraph<T> {
    pub fn add_weighted_edge(&mut self, fr: usize, to: usize, cost: T) {
        self.add_complex_edge(fr, WeightedEdge::new(to, cost));
    }

    pub fn add_bi_weighted_edge(&mut self, fr: usize, to: usize, cost: T) {
        self.add_complex_edge(fr, WeightedEdge::new(to, cost));
        self.add_complex_edge(to, WeightedEdge::new(fr, cost));
    }
}
}
pub mod weighted_graph {
use crate::graph::edges::weighted_edge::WeightedEdge;
use crate::graph::simple_graph::SimpleGraphT;

pub type WeightedGraph<T> = SimpleGraphT<WeightedEdge<T>>;
}
}
pub mod io {
pub mod input {
use crate::collections::array_2d::Array2D;
use crate::misc::ord_f64::OrdF64;
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

macro_rules! read_integer_fun {
    ($t:ident) => {
        #[allow(unused)]
        pub fn $t(&mut self) -> $t {
            self.read_integer()
        }
    };
}

impl<'s> Input<'s> {
    const DEFAULT_BUF_SIZE: usize = 4096;

    ///
    /// Using with stdin:
    /// ``
    /// use algo_lib::io::input::Input;
    /// let mut stdin = std::io::stdin();
    /// let input = Input::new(&mut stdin);
    /// ``
    ///
    /// Using file file:
    /// ``
    /// use algo_lib::io::input::Input;
    /// let mut file = std::fs::File::open("input.txt").unwrap();
    /// let input = Input::new(&mut file);
    ///``
    ///
    ///
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

    pub fn has_more_elements(&mut self) -> bool {
        !self.is_exhausted()
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

    pub fn read_string_vec(&mut self, size: usize) -> Vec<Vec<u8>> {
        let mut res = Vec::with_capacity(size);
        for _ in 0usize..size {
            res.push(self.string());
        }
        res
    }

    pub fn read_matrix<T: Readable>(&mut self, rows: usize, cols: usize) -> Array2D<T>
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
        out!($first $(,$args)*);
        output().put(b'\n');
        output().maybe_flush();
    };
    () => {
        output().put(b'\n');
        output().maybe_flush();
    };
}
}
}
pub mod misc {
pub mod binary_search {
use crate::misc::num_traits::Number;
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
                    file!(), line!(), stringify!($first_val), &$first_val);
    };
}
}
pub mod num_traits {
use std::fmt::Debug;
use std::ops::{Add, AddAssign, Div, DivAssign, Mul, MulAssign, Sub, SubAssign};

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
use crate::io::input::{Input, Readable};
use crate::io::output::{Output, Writable};
use crate::misc::num_traits::{ConvI32, HasConstants};
use std::cmp::{min, Ordering};
use std::fmt::{Debug, Display, Formatter};
use std::io::Write;
use std::num::ParseFloatError;
use std::ops::Neg;
use std::str::FromStr;

#[derive(PartialOrd, PartialEq, Copy, Clone, Default)]
pub struct OrdF64(pub f64);

impl OrdF64 {
    pub(crate) const EPS: Self = Self(1e-9);
    pub const SMALL_EPS: Self = Self(1e-4);

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
}
pub mod rec_function {
// Copied from https://github.com/EgorKulikov/rust_algo/blob/master/algo_lib/src/misc/recursive_function.rs

use std::marker::PhantomData;

macro_rules! recursive_function {
    ($name: ident, $trait: ident, ($($type: ident $arg: ident,)*)) => {
        pub trait $trait<$($type, )*Output> {
            fn call(&mut self, $($arg: $type,)*) -> Output;
        }

        pub struct $name<F, $($type, )*Output>
        where
            F: FnMut(&mut dyn $trait<$($type, )*Output>, $($type, )*) -> Output,
        {
            f: F,
            $($arg: PhantomData<$type>,
            )*
            phantom_output: PhantomData<Output>,
        }

        impl<F, $($type, )*Output> $name<F, $($type, )*Output>
        where
            F: FnMut(&mut dyn $trait<$($type, )*Output>, $($type, )*) -> Output,
        {
            pub fn new(f: F) -> Self {
                Self {
                    f,
                    $($arg: Default::default(),
                    )*
                    phantom_output: Default::default(),
                }
            }
        }

        impl<F, $($type, )*Output> $trait<$($type, )*Output> for $name<F, $($type, )*Output>
        where
            F: FnMut(&mut dyn $trait<$($type, )*Output>, $($type, )*) -> Output,
        {
            fn call(&mut self, $($arg: $type,)*) -> Output {
                let const_ptr = &self.f as *const F;
                let mut_ptr = const_ptr as *mut F;
                unsafe { (&mut *mut_ptr)(self, $($arg, )*) }
            }
        }
    }
}

recursive_function!(RecursiveFunction0, Callable0, ());
recursive_function!(RecursiveFunction, Callable, (Arg arg,));
recursive_function!(RecursiveFunction2, Callable2, (Arg1 arg1, Arg2 arg2,));
recursive_function!(RecursiveFunction3, Callable3, (Arg1 arg1, Arg2 arg2, Arg3 arg3,));
recursive_function!(RecursiveFunction4, Callable4, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4,));
recursive_function!(RecursiveFunction5, Callable5, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5,));
recursive_function!(RecursiveFunction6, Callable6, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6,));
recursive_function!(RecursiveFunction7, Callable7, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6, Arg7 arg7,));
recursive_function!(RecursiveFunction8, Callable8, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6, Arg7 arg7, Arg8 arg8,));
recursive_function!(RecursiveFunction9, Callable9, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6, Arg7 arg7, Arg8 arg8, Arg9 arg9,));
}
pub mod vec_apply_delta {
use crate::misc::num_traits::Number;

pub trait ApplyDelta<T> {
    fn add_to_all(self, delta: T) -> Self;
    fn sub_from_all(self, sub: T) -> Self;
}

impl<T> ApplyDelta<T> for Vec<T>
where
    T: Number,
{
    fn add_to_all(mut self, delta: T) -> Self {
        self.iter_mut().for_each(|val| *val += delta);
        self
    }

    fn sub_from_all(mut self, sub: T) -> Self {
        self.iter_mut().for_each(|val| *val -= sub);
        self
    }
}

impl<T> ApplyDelta<T> for Vec<(T, T)>
where
    T: Number,
{
    fn add_to_all(mut self, delta: T) -> Self {
        self.iter_mut().for_each(|(val1, val2)| {
            *val1 += delta;
            *val2 += delta
        });
        self
    }

    fn sub_from_all(mut self, sub: T) -> Self {
        self.iter_mut().for_each(|(val1, val2)| {
            *val1 -= sub;
            *val2 -= sub;
        });
        self
    }
}

pub trait ApplyDelta2<T> {
    fn add_to_all(&mut self, delta: T);
    fn sub_from_all(&mut self, sub: T);
}

impl<T> ApplyDelta2<T> for [T]
where
    T: Number,
    T: Sized,
{
    fn add_to_all(self: &mut [T], delta: T) {
        self.iter_mut().for_each(|x| *x += delta);
    }

    fn sub_from_all(&mut self, sub: T) {
        self.iter_mut().for_each(|x| *x -= sub);
    }
}
}
}
pub mod seg_trees {
pub mod fenwick {
use std::ops::Range;

#[allow(dead_code)]
pub struct Fenwick {
    values: Vec<i64>,
}

impl Fenwick {
    #[allow(dead_code)]
    pub fn get_sum(&self, mut pos: usize) -> i64 {
        let mut res = 0i64;
        loop {
            res += self.values[pos] as i64;
            pos = pos & (pos + 1);
            if pos == 0 {
                return res;
            }
            pos -= 1;
        }
    }

    pub fn get_range_sum(&self, range: Range<usize>) -> i64 {
        if range.end == 0 {
            return 0;
        }
        let res = self.get_sum(range.end - 1);
        if range.start == 0 {
            res
        } else {
            res - self.get_sum(range.start - 1)
        }
    }

    pub fn get_suffix_sum(&self, pos: usize) -> i64 {
        let total = self.get_sum(self.values.len() - 1);
        let before = if pos == 0 { 0 } else { self.get_sum(pos - 1) };
        total - before
    }

    #[allow(dead_code)]
    pub fn add(&mut self, mut pos: usize, change: i64) {
        while pos < self.values.len() {
            self.values[pos] += change;
            pos |= pos + 1;
        }
    }

    #[allow(dead_code)]
    pub fn new(n: usize) -> Self {
        let values = vec![0; n];
        Fenwick { values }
    }

    pub fn new_pow2(n: usize) -> Self {
        Self::new(n.next_power_of_two())
    }
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