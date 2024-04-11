pub mod solution {

use crate::collections::last_exn::LastExn;
use crate::graph::edges::edge_trait::EdgeTrait;
use crate::graph::graph_readers::config::{Directional, Indexation};
use crate::graph::graph_readers::weighted::read_weighted_graph;
use crate::graph::graph_trait::GraphTrait;
use crate::graph::minimal_spanning_tree::minimal_spanning_tree;
use crate::graph::simple_graph::SimpleGraphT;
use crate::io::input::Input;
use crate::io::output::output;
use crate::misc::num_traits_tuple::number_pair;
use crate::misc::vec_binary_search::VecBinarySearch;
use crate::{dbg, out, out_line};

fn solve(input: &mut Input, _test_case: usize) {
    let n = input.usize();
    let m = input.usize();
    let graph =
        read_weighted_graph::<i64>(input, n, m, Directional::Undirected, Indexation::FromOne);
    let queries = {
        let p = input.usize();
        let k = input.usize();
        let a = input.i64();
        let b = input.i64();
        let c = input.i64();
        let mut qs = input.read_vec::<i64>(p);
        qs.reserve(k - p);
        for _ in 0..k - p {
            let next = (*qs.last_exn() * a + b) % c;
            qs.push(next);
        }
        qs
    };
    let mut split = vec![0];
    for (_, e1) in graph.all_edges() {
        split.push(e1.cost + 1);
        for (_, e2) in graph.all_edges() {
            split.push((e1.cost + e2.cost) / 2 + 1);
        }
    }
    split.sort();
    split.dedup();
    let functions: Vec<_> = split
        .into_iter()
        .map(|x| {
            let mut new_graph = SimpleGraphT::new(n);
            for (fr, edge) in graph.all_edges() {
                let w = edge.cost;
                new_graph.add_weighted_edge(fr, edge.to(), number_pair((w - x).abs(), w));
            }
            let tree = minimal_spanning_tree(&new_graph);
            assert_eq!(tree.num_edges() + 1, n);
            let mut k = 0;
            let mut b = 0;
            // k * x + b
            for (_, edge) in tree.all_edges() {
                let real_w = edge.cost.second;
                if real_w >= x {
                    k -= 1;
                    b += real_w;
                } else {
                    k += 1;
                    b -= real_w;
                }
            }
            (x, k, b)
        })
        .collect();
    let mut res = 0;

    for query in queries.into_iter() {
        let (_, k, b) = functions.lower(&(query, i64::MAX, i64::MAX)).unwrap();
        let cur_ans = k * query + b;
        assert!(cur_ans >= 0);
        res ^= cur_ans;
    }
    out_line!(res);
}

pub(crate) fn run(mut input: Input) -> bool {
    solve(&mut input, 1);
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
pub mod last_exn {
pub trait LastExn<T> {
    fn last_exn(&self) -> &T;
}

impl<T> LastExn<T> for &[T] {
    fn last_exn(&self) -> &T {
        self.last().unwrap()
    }
}

impl<T> LastExn<T> for Vec<T> {
    fn last_exn(&self) -> &T {
        self.last().unwrap()
    }
}
}
}
pub mod graph {
pub mod compressed_graph {
use crate::graph::edges::edge_trait::EdgeTrait;
use crate::graph::graph_trait::GraphTrait;

pub struct CompressedGraph<E>
where
    E: EdgeTrait,
{
    num_vertices: usize,
    edges: Vec<E>,
    start_of_edges: Vec<u32>,
}

impl<E> CompressedGraph<E>
where
    E: EdgeTrait,
    E: Default,
{
    pub fn with_edge_iter<Iter>(num_vertices: usize, edge_iter: Iter) -> Self
    where
        Iter: Iterator<Item = (usize, E)> + Clone,
    {
        let mut num_of_edges: Vec<u32> = vec![0u32; num_vertices + 1];
        for (fr, _edge) in edge_iter.clone() {
            num_of_edges[fr] += 1;
        }
        let mut start_of_edges = num_of_edges;
        for i in 1..=num_vertices {
            start_of_edges[i] += start_of_edges[i - 1];
        }
        let mut edges = vec![E::default(); start_of_edges[num_vertices] as usize];
        for (fr, edge) in edge_iter {
            start_of_edges[fr] -= 1;
            edges[start_of_edges[fr] as usize] = edge;
        }
        Self {
            num_vertices,
            edges,
            start_of_edges,
        }
    }
}

impl<E> GraphTrait<E> for CompressedGraph<E>
where
    E: EdgeTrait,
{
    fn num_vertices(&self) -> usize {
        self.num_vertices
    }

    fn num_edges(&self) -> usize {
        self.edges.len()
    }

    #[inline(always)]
    fn adj(&self, v: usize) -> &[E] {
        let from = self.start_of_edges[v] as usize;
        let to = self.start_of_edges[v + 1] as usize;
        &self.edges[from..to]
    }
}

impl<E> CompressedGraph<E>
where
    E: EdgeTrait,
{
    pub fn all_edges(&self) -> impl Iterator<Item = (usize, &E)> + '_ {
        (0..self.num_vertices()).flat_map(move |v| self.adj(v).iter().map(move |e| (v, e)))
    }
}
}
pub mod dsu {
pub struct Dsu {
    p: Vec<u32>,
    size: Vec<u32>,
    num_comps: u32,
}

impl Dsu {
    pub fn clear(&mut self) {
        for (idx, val) in self.p.iter_mut().enumerate() {
            *val = idx as u32;
        }
        for val in self.size.iter_mut() {
            *val = 1;
        }
        self.num_comps = self.p.len() as u32;
    }

    pub fn new(n: usize) -> Self {
        let mut res = Self {
            p: vec![0; n],
            size: vec![0; n],
            num_comps: n as u32,
        };
        res.clear();
        res
    }

    pub fn get(&mut self, v: usize) -> usize {
        if self.p[v] as usize != v {
            self.p[v] = self.get(self.p[v] as usize) as u32;
        }
        self.p[v] as usize
    }

    pub fn unite(&mut self, v1: usize, v2: usize) -> bool {
        let v1 = self.get(v1);
        let v2 = self.get(v2);
        if v1 == v2 {
            false
        } else {
            self.p[v1 as usize] = v2 as u32;
            self.size[v2 as usize] += self.size[v1 as usize];
            self.num_comps -= 1;
            true
        }
    }

    pub fn calc_size(&mut self, mut v: usize) -> usize {
        v = self.get(v);
        self.size[v as usize] as usize
    }

    pub fn is_root(&self, v: usize) -> bool {
        self.p[v] as usize == v
    }

    pub fn calc_components(&mut self) -> Vec<Vec<usize>> {
        let n = self.p.len();
        let mut res = vec![vec![]; n];
        for v in 0..n {
            res[self.get(v) as usize].push(v);
        }
        res.into_iter().filter(|vec| !vec.is_empty()).collect()
    }

    pub fn num_components(&self) -> usize {
        self.num_comps as usize
    }
}
}
pub mod edges {
pub mod edge_trait {
pub trait EdgeTrait: Copy + Clone {
    fn to(&self) -> usize;
    fn rev(&self, from: usize) -> Self;
}
}
pub mod weighted_edge {
use crate::graph::edges::edge_trait::EdgeTrait;
use crate::misc::num_traits::Number;
use crate::graph::weighted_graph::WeightedGraph;

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

impl<T: Number> WeightedGraph<T> {
    pub fn add_weighted_edge(&mut self, fr: usize, to: usize, cost: T) {
        self.add_edge(fr, WeightedEdge::new(to, cost));
    }
}
}
}
pub mod graph_builder {
use crate::graph::compressed_graph::CompressedGraph;
use crate::graph::edges::edge_trait::EdgeTrait;

pub struct GraphBuilder<E>
where
    E: EdgeTrait,
{
    num_vertices: usize,
    edges: Vec<(u32, E)>,
}

impl<E> GraphBuilder<E>
where
    E: EdgeTrait,
    E: Default,
{
    pub fn new(num_vertices: usize) -> Self {
        Self {
            num_vertices,
            edges: vec![],
        }
    }

    pub fn add_vertex(&mut self) {
        self.num_vertices += 1;
    }

    pub fn add_edge(&mut self, from: usize, edge: E) {
        self.edges.push((from as u32, edge));
    }

    pub fn build(self) -> CompressedGraph<E> {
        CompressedGraph::with_edge_iter(
            self.num_vertices,
            self.edges.iter().map(|(fr, edge)| (*fr as usize, *edge)),
        )
    }
}
}
pub mod graph_readers {
pub mod config {
pub enum Directional {
    Directed,
    Undirected,
}

pub enum Indexation {
    FromZero,
    FromOne,
}
}
pub mod weighted {
use crate::graph::compressed_graph::CompressedGraph;
use crate::graph::edges::edge_trait::EdgeTrait;
use crate::graph::edges::weighted_edge::WeightedEdge;
use crate::graph::graph_readers::config::*;
use crate::io::input::{Input, Readable};
use crate::misc::num_traits::Number;

fn read_directed_edges<T>(
    input: &mut Input,
    num_edges: usize,
    indexation: Indexation,
) -> Vec<(usize, WeightedEdge<T>)>
where
    T: Number + Readable,
{
    (0..num_edges)
        .map(|_| {
            let mut read_v = || -> usize {
                match indexation {
                    Indexation::FromZero => input.usize(),
                    Indexation::FromOne => input.usize() - 1,
                }
            };
            let fr = read_v();
            let to = read_v();
            let cost: T = input.read();
            (fr, WeightedEdge::new(to, cost))
        })
        .collect()
}

pub fn read_weighted_graph<T>(
    input: &mut Input,
    num_vertices: usize,
    num_edges: usize,
    directional: Directional,
    indexation: Indexation,
) -> CompressedGraph<WeightedEdge<T>>
where
    T: Number + Readable,
{
    let mut edges = read_directed_edges(input, num_edges, indexation);
    match directional {
        Directional::Directed => (),
        Directional::Undirected => {
            let mut rev_edges: Vec<_> = edges
                .iter()
                .map(|(fr, edge)| (edge.to(), WeightedEdge::new(*fr, edge.cost)))
                .collect();
            edges.append(&mut rev_edges);
        }
    };
    CompressedGraph::with_edge_iter(num_vertices, edges.iter().map(|(fr, edge)| (*fr, *edge)))
}
}
}
pub mod graph_trait {
use crate::graph::edges::edge_trait::EdgeTrait;

pub trait GraphTrait<E>
where
    E: EdgeTrait,
{
    fn num_vertices(&self) -> usize;
    fn num_edges(&self) -> usize;

    fn adj(&self, v: usize) -> &[E];
}
}
pub mod minimal_spanning_tree {
use crate::graph::compressed_graph::CompressedGraph;
use crate::graph::dsu::Dsu;
use crate::graph::edges::edge_trait::EdgeTrait;
use crate::graph::edges::weighted_edge::WeightedEdge;
use crate::graph::graph_builder::GraphBuilder;
use crate::graph::graph_trait::GraphTrait;
use crate::misc::num_traits::Number;

pub fn minimal_spanning_tree<G, T: Number>(graph: &G) -> CompressedGraph<WeightedEdge<T>>
where
    G: GraphTrait<WeightedEdge<T>>,
{
    let n = graph.num_vertices();
    let mut all_edges = Vec::with_capacity(graph.num_edges() / 2);
    for v in 0..n {
        for edge in graph.adj(v) {
            if edge.to() > v {
                all_edges.push((v, edge.clone()));
            }
        }
    }
    all_edges.sort_by_key(|(_fr, edge)| edge.cost);
    let mut dsu = Dsu::new(n);
    let mut builder = GraphBuilder::new(n);
    for (fr, edge) in all_edges.into_iter() {
        if dsu.get(fr) != dsu.get(edge.to()) {
            dsu.unite(fr, edge.to());
            builder.add_edge(fr, edge);
        }
    }
    builder.build()
}
}
pub mod simple_graph {
use crate::graph::edges::edge_trait::EdgeTrait;
use crate::graph::graph_trait::GraphTrait;

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

    pub fn add_edge(&mut self, from: usize, edge: E) {
        self.adj[from].push(edge);
    }

    pub fn add_bi_edge(&mut self, from: usize, edge: E) {
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
pub mod misc {
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
pub mod num_traits_tuple {
use crate::misc::num_traits::{ConvI32, HasConstants, Number};
use std::cmp::Ordering;
use std::fmt::{Debug, Formatter};
use std::ops::{Add, AddAssign, Div, DivAssign, Mul, MulAssign, Sub, SubAssign};

pub struct NumberPair<T1: Number, T2: Number> {
    pub first: T1,
    pub second: T2,
}

impl<T1: Number, T2: Number> NumberPair<T1, T2> {
    pub fn new(first: T1, second: T2) -> Self {
        Self { first, second }
    }

    pub fn to_tuple(&self) -> (T1, T2) {
        (self.first, self.second)
    }
}

impl<T1: Number, T2: Number> Copy for NumberPair<T1, T2> {}

impl<T1: Number, T2: Number> Clone for NumberPair<T1, T2> {
    fn clone(&self) -> Self {
        Self::new(self.first.clone(), self.second.clone())
    }
}

impl<T1, T2> Add for NumberPair<T1, T2>
where
    T1: Number,
    T2: Number,
{
    type Output = Self;

    fn add(self, rhs: Self) -> Self::Output {
        Self::new(self.first + rhs.first, self.second + rhs.second)
    }
}

impl<T1: Number, T2: Number> AddAssign for NumberPair<T1, T2> {
    fn add_assign(&mut self, rhs: Self) {
        self.first += rhs.first;
        self.second += rhs.second;
    }
}

impl<T1: Number, T2: Number> Sub for NumberPair<T1, T2> {
    type Output = Self;

    fn sub(self, rhs: Self) -> Self::Output {
        Self::new(self.first - rhs.first, self.second - rhs.second)
    }
}

impl<T1: Number, T2: Number> SubAssign for NumberPair<T1, T2> {
    fn sub_assign(&mut self, rhs: Self) {
        self.first -= rhs.first;
        self.second -= rhs.second;
    }
}

impl<T1: Number, T2: Number> Mul for NumberPair<T1, T2> {
    type Output = Self;

    fn mul(self, rhs: Self) -> Self::Output {
        Self::new(self.first * rhs.first, self.second * rhs.second)
    }
}

impl<T1: Number, T2: Number> MulAssign for NumberPair<T1, T2> {
    fn mul_assign(&mut self, rhs: Self) {
        self.first *= rhs.first;
        self.second *= rhs.second;
    }
}

impl<T1: Number, T2: Number> Div for NumberPair<T1, T2> {
    type Output = Self;

    fn div(self, rhs: Self) -> Self::Output {
        Self::new(self.first / rhs.first, self.second / rhs.second)
    }
}

impl<T1: Number, T2: Number> DivAssign for NumberPair<T1, T2> {
    fn div_assign(&mut self, rhs: Self) {
        self.first /= rhs.first;
        self.second /= rhs.second;
    }
}

impl<T1: Number, T2: Number> PartialEq<Self> for NumberPair<T1, T2> {
    fn eq(&self, other: &Self) -> bool {
        self.to_tuple().eq(&other.to_tuple())
    }
}

impl<T1: Number, T2: Number> PartialOrd<Self> for NumberPair<T1, T2> {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        self.to_tuple().partial_cmp(&other.to_tuple())
    }
}

impl<T1: Number, T2: Number> Ord for NumberPair<T1, T2> {
    fn cmp(&self, other: &Self) -> Ordering {
        self.to_tuple().cmp(&other.to_tuple())
    }
}

impl<T1: Number, T2: Number> Eq for NumberPair<T1, T2> {}

impl<T1: Number, T2: Number> HasConstants<Self> for NumberPair<T1, T2> {
    const MAX: Self = NumberPair {
        first: T1::MAX,
        second: T2::MAX,
    };
    const MIN: Self = NumberPair {
        first: T1::MIN,
        second: T2::MIN,
    };
    const ZERO: Self = NumberPair {
        first: T1::ZERO,
        second: T2::ZERO,
    };
    const ONE: Self = NumberPair {
        first: T1::ONE,
        second: T2::ONE,
    };
    const TWO: Self = NumberPair {
        first: T1::TWO,
        second: T2::TWO,
    };
}

impl<T1: Number, T2: Number> Default for NumberPair<T1, T2> {
    fn default() -> Self {
        Self::new(T1::default(), T2::default())
    }
}

impl<T1: Number, T2: Number> Debug for NumberPair<T1, T2> {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        f.write_str(&"(")?;
        self.first.fmt(f)?;
        f.write_str(&", ")?;
        self.second.fmt(f)?;
        f.write_str(&")")
    }
}

impl<T1: Number, T2: Number> ConvI32<Self> for NumberPair<T1, T2> {
    fn from_i32(val: i32) -> Self {
        Self::new(T1::from_i32(val), T2::from_i32(val))
    }

    fn to_i32(self) -> i32 {
        panic!("Can't convert pair to i32");
    }
}

pub fn number_pair<T1: Number, T2: Number>(first: T1, second: T2) -> NumberPair<T1, T2> {
    NumberPair::new(first, second)
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
pub mod vec_binary_search {
pub trait VecBinarySearch<T> {
    fn higher_or_equal(&self, val: &T) -> Option<T>
    where
        T: Ord + Clone;
    fn lower(&self, val: &T) -> Option<T>
    where
        T: Ord + Clone;
}

impl<T> VecBinarySearch<T> for Vec<T>
where
    T: Ord + Clone,
{
    fn higher_or_equal(&self, val: &T) -> Option<T>
    where
        T: Ord + Clone,
    {
        match self.binary_search(val) {
            Ok(pos) => Some(self[pos].clone()),
            Err(pos) => {
                if pos == self.len() {
                    None
                } else {
                    Some(self[pos].clone())
                }
            }
        }
    }

    fn lower(&self, val: &T) -> Option<T>
    where
        T: Ord + Clone,
    {
        match self.binary_search(&val) {
            Ok(pos) | Err(pos) => {
                if pos == 0 {
                    None
                } else {
                    Some(self[pos - 1].clone())
                }
            }
        }
    }
}

impl<T> VecBinarySearch<T> for &[T]
where
    T: Ord + Clone,
{
    fn higher_or_equal(&self, val: &T) -> Option<T>
    where
        T: Ord + Clone,
    {
        match self.binary_search(val) {
            Ok(pos) => Some(self[pos].clone()),
            Err(pos) => {
                if pos == self.len() {
                    None
                } else {
                    Some(self[pos].clone())
                }
            }
        }
    }

    fn lower(&self, val: &T) -> Option<T>
    where
        T: Ord + Clone,
    {
        match self.binary_search(&val) {
            Ok(pos) | Err(pos) => {
                if pos == 0 {
                    None
                } else {
                    Some(self[pos - 1].clone())
                }
            }
        }
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