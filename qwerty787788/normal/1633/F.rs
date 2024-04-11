pub mod solution {

use crate::graph::edges::edge_trait::EdgeTrait;
use crate::graph::edges::edge_with_info::EdgeWithInfo;
use crate::graph::graph_trait::GraphTrait;
use crate::graph::simple_graph::SimpleGraphT;
use crate::graph::trees::heavy_light::{GoDirection, HeavyLight};
use crate::io::input::Input;
use crate::io::output::output;
use crate::misc::rec_function::{Callable2, RecursiveFunction2};
use crate::seg_trees::lazy_seg_tree::{LazySegTree, LazySegTreeNodeSpec};
use crate::{dbg, out, out_line};
use std::ops::{Add, Sub};

#[derive(Copy, Clone, Default)]
struct Info {
    cnt: i32,
    sum: i64,
}

impl Add for Info {
    type Output = Self;

    fn add(self, rhs: Self) -> Self::Output {
        Self {
            cnt: self.cnt + rhs.cnt,
            sum: self.sum + rhs.sum,
        }
    }
}

impl Sub for Info {
    type Output = Self;

    fn sub(self, rhs: Self) -> Self::Output {
        Self {
            cnt: self.cnt - rhs.cnt,
            sum: self.sum - rhs.sum,
        }
    }
}

#[derive(Copy, Clone, Default)]
struct SegNode {
    alive: Info,
    not_alive: Info,
}

impl LazySegTreeNodeSpec for SegNode {
    fn unite(l: &Self, r: &Self, _context: &Self::Context) -> Self {
        Self {
            alive: l.alive + r.alive,
            not_alive: l.not_alive + r.not_alive,
        }
    }

    fn apply_update(node: &mut Self, update: &Self::Update) {
        if *update {
            let tmp = node.alive;
            node.alive = node.not_alive;
            node.not_alive = tmp;
        }
    }

    fn join_updates(current: &mut Self::Update, add: &Self::Update) {
        *current ^= *add;
    }

    type Update = bool;
    type Context = ();
}

struct HeavyLightNode {
    seg_tree: LazySegTree<SegNode>,
}

fn solve(input: &mut Input, _test_case: usize) {
    let n = input.usize();
    let mut graph = SimpleGraphT::new(n);
    for id in 1..n {
        let fr = input.usize() - 1;
        let to = input.usize() - 1;
        graph.add_complex_bi_edge(fr, EdgeWithInfo::new(to, id));
    }
    let mut parent_edge_id = vec![0; n];
    RecursiveFunction2::new(|f, v, edge_id| {
        parent_edge_id[v] = edge_id;
        for edge in graph.adj(v) {
            if edge.info != edge_id {
                f.call(edge.to(), edge.info);
            }
        }
    })
    .call(0, 0);
    let mut alive_vertices = vec![false; n];
    alive_vertices[0] = true;
    let mut total_vertices = 1;
    let mut cur_info = Info { cnt: 0, sum: 0 };

    let mut heavy_light: HeavyLight<HeavyLightNode> =
        HeavyLight::new(&graph, 0, |ids: &[usize]| -> HeavyLightNode {
            let seg_tree = LazySegTree::new_f(ids.len() - 1, &|pos| {
                let v = ids[pos + 1];
                SegNode {
                    alive: Info { cnt: 0, sum: 0 },
                    not_alive: Info {
                        cnt: 1,
                        sum: parent_edge_id[v] as i64,
                    },
                }
            });
            HeavyLightNode { seg_tree }
        });

    loop {
        let query_type = input.usize();
        if query_type == 1 {
            let v = input.usize() - 1;
            alive_vertices[v] = true;
            total_vertices += 1;

            heavy_light.go_path(v, 0, |subpath, range, dir| {
                assert_eq!(dir, GoDirection::RightToLeft);
                {
                    cur_info = cur_info - subpath.extra.seg_tree.get(range.clone()).alive;
                    subpath.extra.seg_tree.update(range.clone(), true);
                    cur_info = cur_info + subpath.extra.seg_tree.get(range.clone()).alive;
                }
            });

            if cur_info.cnt * 2 == total_vertices {
                out_line!(cur_info.sum);
            } else {
                out_line!(0);
            }
        } else if query_type == 2 {
            if cur_info.cnt * 2 == total_vertices {
                let mut edges = vec![];
                RecursiveFunction2::new(|f, v: usize, p| -> usize {
                    if !alive_vertices[v] {
                        return 0;
                    }
                    let mut size = 1;
                    for e in graph.adj(v) {
                        if e.to() == p {
                            continue;
                        }
                        size ^= f.call(e.to(), v);
                    }
                    if size == 1 {
                        edges.push(parent_edge_id[v] as i64);
                    }
                    size
                })
                .call(0, 0);
                assert_eq!(cur_info.sum, edges.iter().sum());
                edges.sort();
                out_line!(edges.len());
                out_line!(edges);
            } else {
                out_line!(0);
            }
        } else {
            assert_eq!(query_type, 3);
            break;
        }
    }
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
}
pub mod graph {
pub mod edges {
pub mod edge_trait {
pub trait EdgeTrait: Copy + Clone {
    fn to(&self) -> usize;
    fn rev(&self, from: usize) -> Self;
}
}
pub mod edge_with_info {
use crate::graph::edges::edge_trait::EdgeTrait;

#[derive(Copy, Clone, Default, Debug)]
pub struct EdgeWithInfo<T>
where
    T: Clone + Copy,
{
    to: u32,
    pub info: T,
}

impl<T> EdgeWithInfo<T>
where
    T: Clone + Copy,
{
    pub fn new(to: usize, info: T) -> Self {
        Self {
            to: to as u32,
            info,
        }
    }
}

impl<T> EdgeTrait for EdgeWithInfo<T>
where
    T: Clone + Copy,
{
    #[inline(always)]
    fn to(&self) -> usize {
        self.to as usize
    }

    fn rev(&self, from: usize) -> Self {
        Self {
            to: from as u32,
            info: self.info,
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
    fn num_vertices(&self) -> usize;
    fn num_edges(&self) -> usize;

    fn adj(&self, v: usize) -> &[E];
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
pub mod trees {
pub mod binary_lifting {
use crate::collections::array_2d::Array2D;
use crate::graph::edges::edge_trait::EdgeTrait;
use crate::graph::graph_trait::GraphTrait;
use crate::misc::bits::index_of_highest_set_bit;
use crate::misc::rec_function::{Callable2, RecursiveFunction2};

pub struct BinaryLifting {
    up: Array2D<u32>,
    height: Vec<u32>,
}

impl BinaryLifting {
    pub fn new<Graph, Edge>(tree: &Graph, root: usize) -> Self
    where
        Graph: GraphTrait<Edge>,
        Edge: EdgeTrait,
    {
        let n = tree.num_vertices();
        let levels = index_of_highest_set_bit(n) + 1;
        let mut up = Array2D::new(root as u32, levels, n);
        let mut height = vec![0; n];
        RecursiveFunction2::new(|f, v, parent| {
            for edge in tree.adj(v) {
                if edge.to() == parent {
                    continue;
                }
                height[edge.to()] = height[v] + 1;
                f.call(edge.to(), v);
                up[0][edge.to()] = v as u32;
            }
        })
        .call(root, root);
        for lvl in 1..levels {
            for v in 0..n {
                up[lvl][v] = up[lvl - 1][up[lvl - 1][v] as usize];
            }
        }
        Self { up, height }
    }

    pub fn height(&self, v: usize) -> usize {
        self.height[v] as usize
    }

    pub fn up(&self, mut v: usize, len: usize) -> usize {
        for lvl in 0..self.up.rows() {
            if ((1 << lvl) & len) != 0 {
                v = self.up[lvl][v] as usize;
            }
        }
        v
    }

    pub fn lca(&self, mut v1: usize, mut v2: usize) -> usize {
        let h1 = self.height[v1];
        let h2 = self.height[v2];
        if h1 < h2 {
            v2 = self.up(v2, (h2 - h1) as usize);
        } else {
            v1 = self.up(v1, (h1 - h2) as usize);
        }
        let levels = self.up.rows();
        for lvl in (0..levels).rev() {
            if self.up[lvl][v1] != self.up[lvl][v2] {
                v1 = self.up[lvl][v1] as usize;
                v2 = self.up[lvl][v2] as usize;
            }
        }
        if v1 == v2 {
            v1
        } else {
            self.up[0][v1] as usize
        }
    }
}
}
pub mod calc_sizes {
use crate::graph::edges::edge_trait::EdgeTrait;
use crate::graph::graph_trait::GraphTrait;
use crate::misc::rec_function::{Callable2, RecursiveFunction2};

pub fn calc_subtree_sizes<Graph, Edge>(tree: &Graph, root: usize) -> Vec<usize>
where
    Graph: GraphTrait<Edge>,
    Edge: EdgeTrait,
{
    let n = tree.num_vertices();
    let mut res = vec![1; n];
    RecursiveFunction2::new(|f, v, parent| {
        for edge in tree.adj(v) {
            if edge.to() == parent {
                continue;
            }
            f.call(edge.to(), v);
            res[v] += res[edge.to()];
        }
    })
    .call(root, root);
    res
}
}
pub mod heavy_light {
use crate::graph::edges::edge_trait::EdgeTrait;
use crate::graph::graph_trait::GraphTrait;
use crate::graph::trees::binary_lifting::BinaryLifting;
use crate::graph::trees::calc_sizes::calc_subtree_sizes;
use crate::misc::rec_function::{Callable3, RecursiveFunction3};
use std::cmp::min;
use std::ops::Range;

#[derive(Debug)]
pub struct SubPath<T> {
    pub vertices: Vec<usize>,
    pub extra: T,
}

impl<T> SubPath<T> {
    pub fn new(vertices: Vec<usize>, extra: T) -> Self {
        Self { vertices, extra }
    }
}

#[derive(Debug, Eq, PartialEq)]
pub enum GoDirection {
    LeftToRight,
    RightToLeft,
}

pub struct HeavyLight<T> {
    paths: Vec<SubPath<T>>,
    path_of_vertex: Vec<usize>,
    position_inside_path: Vec<usize>,
    binary_lifting: BinaryLifting,
}

impl<T> HeavyLight<T> {
    pub fn new<Graph, Edge>(
        tree: &Graph,
        root: usize,
        mut make_node: impl FnMut(&[usize]) -> T,
    ) -> Self
    where
        Graph: GraphTrait<Edge>,
        Edge: EdgeTrait,
    {
        let sizes = calc_subtree_sizes(tree, root);
        let mut paths = vec![];
        let mut path_of_vertex = vec![0; tree.num_vertices()];
        let mut position_inside_path = vec![0; tree.num_vertices()];
        RecursiveFunction3::new(|f, v, parent, mut cur_path: Vec<usize>| {
            cur_path.push(v);
            if let Some(best_child) = tree
                .adj(v)
                .iter()
                .filter(|edge| edge.to() != parent)
                .max_by_key(|edge| sizes[edge.to()])
            {
                f.call(best_child.to(), v, cur_path);
                for edge in tree.adj(v) {
                    if edge.to() == best_child.to() || edge.to() == parent {
                        continue;
                    }
                    f.call(edge.to(), v, vec![v]);
                }
            } else {
                // first node in the path is node from the next path
                for (pos, &v) in cur_path.iter().enumerate().skip(1) {
                    path_of_vertex[v] = paths.len();
                    position_inside_path[v] = pos;
                }
                let extra = make_node(&cur_path);
                paths.push(SubPath::new(cur_path, extra));
            }
        })
        .call(root, root, vec![root]);
        Self {
            paths,
            path_of_vertex,
            position_inside_path,
            binary_lifting: BinaryLifting::new(tree, root),
        }
    }

    fn construct_path(&self, mut v_from: usize, lca: usize) -> Vec<(usize, Range<usize>)> {
        let mut res = vec![];
        let mut more_len = self.binary_lifting.height(v_from) - self.binary_lifting.height(lca);
        while more_len > 0 {
            let sub_path_id = self.path_of_vertex[v_from];
            let pos_in_path = self.position_inside_path[v_from];
            let use_len = min(more_len, pos_in_path);
            let range = pos_in_path - use_len..pos_in_path;
            res.push((sub_path_id, range));
            more_len -= use_len;
            v_from = self.paths[sub_path_id].vertices[0];
        }
        res
    }

    ///
    /// range.len() -- always number of edges in the subpath
    ///
    /// subpath[0] doesn't belong to this specific subpath,
    /// it is the "next" vertex on the parent subpath
    ///
    /// edges on the path from
    /// subpath[range.start] and subpath[range.end]
    /// should be handled inside [f]
    ///
    pub fn go_path(
        &mut self,
        v_from: usize,
        v_to: usize,
        mut f: impl FnMut(&mut SubPath<T>, Range<usize>, GoDirection),
    ) {
        let lca = self.binary_lifting.lca(v_from, v_to);
        let to_lca = self.construct_path(v_from, lca);
        for (sub_path_id, range) in to_lca.into_iter() {
            f(
                &mut self.paths[sub_path_id],
                range,
                GoDirection::RightToLeft,
            );
        }
        let mut from_lca = self.construct_path(v_to, lca);
        from_lca.reverse();
        for (sub_path_id, range) in from_lca.into_iter() {
            f(
                &mut self.paths[sub_path_id],
                range,
                GoDirection::LeftToRight,
            );
        }
    }
}
}
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
pub mod bits {
pub fn index_of_highest_set_bit(value: usize) -> usize {
    const BITS_PER_BYTE: usize = 8;
    std::mem::size_of::<usize>() * BITS_PER_BYTE - (value.leading_zeros() as usize) - 1
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
}
pub mod seg_trees {
pub mod lazy_seg_tree {
use std::ops::Range;

pub trait LazySegTreeNodeSpec: Clone + Default {
    fn unite(l: &Self, r: &Self, context: &Self::Context) -> Self;

    fn apply_update(node: &mut Self, update: &Self::Update);
    fn join_updates(current: &mut Self::Update, add: &Self::Update);

    type Update: Clone;
    type Context;
}

#[allow(unused)]
pub struct LazySegTree<T: LazySegTreeNodeSpec> {
    n: usize,
    tree: Vec<T>,
    updates_to_push: Vec<Option<T::Update>>,
    context: T::Context,
}

#[allow(unused)]
impl<T: LazySegTreeNodeSpec> LazySegTree<T> {
    pub(crate) fn new(init_val: &T, n: usize, context: T::Context) -> Self {
        assert!(n > 0);
        let tree = vec![T::default(); 2 * n - 1];
        let updates_to_push = vec![None; 2 * n - 1];
        let mut res = LazySegTree {
            n,
            tree,
            updates_to_push,
            context,
        };
        res.build(0, 0, n, init_val);
        res
    }

    fn pull(&mut self, v: usize, vr: usize) {
        self.tree[v] = T::unite(&self.tree[v + 1], &self.tree[vr], &self.context);
    }

    fn build(&mut self, v: usize, l: usize, r: usize, init_val: &T) {
        if l + 1 == r {
            self.tree[v] = init_val.clone();
        } else {
            let m = (l + r) >> 1;
            let vr = v + ((m - l) << 1);
            self.build(v + 1, l, m, init_val);
            self.build(vr, m, r, init_val);
            self.pull(v, vr);
        }
    }

    fn push(&mut self, v: usize, l: usize, r: usize) {
        let update = self.updates_to_push[v].clone();
        self.updates_to_push[v] = None;
        match update {
            None => {}
            Some(update) => {
                self.apply_update(v + 1, &update);
                self.apply_update(v + ((r - l) & !1), &update);
            }
        }
    }

    fn get_(&mut self, v: usize, l: usize, r: usize, ql: usize, qr: usize) -> T {
        assert!(qr >= l);
        assert!(ql < r);
        if ql <= l && r <= qr {
            return self.tree[v].clone();
        }
        let m = (l + r) >> 1;
        let vr = v + ((m - l) << 1);
        self.push(v, l, r);
        let res = if ql >= m {
            self.get_(vr, m, r, ql, qr)
        } else if qr <= m {
            self.get_(v + 1, l, m, ql, qr)
        } else {
            T::unite(
                &self.get_(v + 1, l, m, ql, qr),
                &self.get_(vr, m, r, ql, qr),
                &self.context,
            )
        };
        self.pull(v, vr);
        res
    }

    fn join_updates(current: &mut Option<T::Update>, add: &T::Update) {
        match current {
            None => *current = Some(add.clone()),
            Some(current) => T::join_updates(current, add),
        };
    }

    fn apply_update(&mut self, v: usize, update: &T::Update) {
        T::apply_update(&mut self.tree[v], update);
        Self::join_updates(&mut self.updates_to_push[v], update);
    }

    fn modify_(&mut self, v: usize, l: usize, r: usize, ql: usize, qr: usize, update: &T::Update) {
        assert!(qr >= l);
        assert!(ql < r);
        if ql <= l && r <= qr {
            self.apply_update(v, update);
            return;
        }
        let m = (l + r) >> 1;
        let vr = v + ((m - l) << 1);
        self.push(v, l, r);
        if ql >= m {
            self.modify_(vr, m, r, ql, qr, update);
        } else if qr <= m {
            self.modify_(v + 1, l, m, ql, qr, update);
        } else {
            self.modify_(v + 1, l, m, ql, qr, update);
            self.modify_(vr, m, r, ql, qr, update);
        };
        self.pull(v, vr);
    }

    pub fn update(&mut self, range: Range<usize>, update: T::Update) {
        if range.len() == 0 {
            return;
        }
        assert!(range.len() > 0);
        self.modify_(0, 0, self.n, range.start, range.end, &update);
    }

    pub fn get(&mut self, range: Range<usize>) -> T {
        assert!(range.len() > 0);
        self.get_(0, 0, self.n, range.start, range.end)
    }

    pub fn new_f_with_context(n: usize, f: &dyn Fn(usize) -> T, context: T::Context) -> Self {
        assert!(n > 0);
        let tree = vec![T::default(); 2 * n - 1];
        let updates_to_push = vec![None; 2 * n - 1];
        let mut res = LazySegTree {
            n,
            tree,
            updates_to_push,
            context,
        };
        res.build_f(0, 0, n, f);
        res
    }

    pub fn new_f(n: usize, f: &dyn Fn(usize) -> T) -> Self
    where
        T::Context: Default,
    {
        assert!(n > 0);
        let tree = vec![T::default(); 2 * n - 1];
        let updates_to_push = vec![None; 2 * n - 1];
        let mut res = LazySegTree {
            n,
            tree,
            updates_to_push,
            context: T::Context::default(),
        };
        res.build_f(0, 0, n, f);
        res
    }

    fn build_f(&mut self, v: usize, l: usize, r: usize, f: &dyn Fn(usize) -> T) {
        if l + 1 == r {
            self.tree[v] = f(l);
        } else {
            let m = (l + r) >> 1;
            let vr = v + ((m - l) << 1);
            self.build_f(v + 1, l, m, f);
            self.build_f(vr, m, r, f);
            self.pull(v, vr);
        }
    }

    pub fn len(&self) -> usize {
        self.n
    }
}
}
}
fn main() {
    let mut sin = std::io::stdin();
    let input = crate::io::input::Input::new_with_size(&mut sin, 1);
    unsafe {
        crate::io::output::OUTPUT = Some(crate::io::output::Output::new_with_auto_flush(Box::new(std::io::stdout())));
    }
    crate::solution::run(input);
}