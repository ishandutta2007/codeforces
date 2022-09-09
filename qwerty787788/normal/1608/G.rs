pub mod solution {

use crate::graph::edges::edge_with_info::EdgeWithInfo;
use crate::graph::simple_graph::SimpleGraphT;
use crate::graph::trees::calc_edge_to_parent::calc_edge_to_parent;
use crate::graph::trees::heavy_light::{GoDirection, HeavyLight};
use crate::io::input::Input;
use crate::io::output::output;
use crate::misc::binary_search::binary_search_first_true;
use crate::misc::gen_vector::gen_vec;
use crate::misc::rand::Random;
use crate::seg_trees::fenwick::Fenwick;
use crate::strings::suffix_array::SuffixArray;
use crate::strings::utils::vec2str;
use crate::{dbg, out, out_line};
use std::cmp::{max, min};
use std::ops::Range;
use std::process::exit;
use std::time::Instant;

type Edge = EdgeWithInfo<u8>;

struct Query {
    id: usize,
    fr_v: usize,
    to_v: usize,
    words_range: Range<usize>,
}

const SEPARATOR: u8 = b'$';

#[derive(Debug)]
struct Node {
    pos_in_long_string: Vec<usize>,
    rev_pos_in_long_string: Vec<usize>,
}

fn find_range_in_suf_array(
    suf_array: &SuffixArray,
    query: &Query,
    heavy_light: &HeavyLight<Node>,
) -> Range<usize> {
    let mut already_len = 0;
    let mut res = 0..suf_array.len();
    heavy_light.go_path(query.fr_v, query.to_v, |sub_path, range, dir| {
        let pos_in_long_str = match dir {
            GoDirection::RightToLeft => {
                // TODO: indexing?
                sub_path.extra.rev_pos_in_long_string[range.end - 1]
            }
            GoDirection::LeftToRight => sub_path.extra.pos_in_long_string[range.start],
        };
        let len = range.len();
        // TODO: naming???
        let search_near_pos = suf_array.get_pos_in_array(pos_in_long_str);
        let next_start = binary_search_first_true(res.clone(), |whole_str_check_pos| {
            let pos_in_string = suf_array[whole_str_check_pos];
            let pos_to_compare = (pos_in_string + already_len) % suf_array.len();
            let in_suf_array = suf_array.get_pos_in_array(pos_to_compare);
            in_suf_array >= search_near_pos || suf_array.lcp(in_suf_array, search_near_pos) >= len
        });
        let next_end = binary_search_first_true(next_start..res.end, |pos_in_suf_array| {
            let pos_in_string = suf_array[pos_in_suf_array];
            let pos_to_compare = (pos_in_string + already_len) % suf_array.len();
            let in_suf_array = suf_array.get_pos_in_array(pos_to_compare);
            suf_array.lcp(in_suf_array, search_near_pos) < len
        });
        res = next_start..next_end;
        already_len += len;
    });
    res
}

fn solve_input(
    vertices: usize,
    edges: &[(usize, usize, u8)],
    words: &[Vec<u8>],
    queries: &[Query],
) -> Vec<i64> {
    let mut graph = SimpleGraphT::<Edge>::new(vertices);
    for &(fr, to, c) in edges {
        graph.add_edge(fr, Edge::new(to, c));
        graph.add_edge(to, Edge::new(fr, c));
    }

    let mut long_string = vec![];
    let mut word_pos_in_string = vec![0; words.len()];
    for (w_id, word) in words.iter().enumerate() {
        word_pos_in_string[w_id] = long_string.len();
        long_string.append(&mut word.clone());
        long_string.push(SEPARATOR);
    }

    let edge_to_parent = calc_edge_to_parent(&graph, Edge::new(0, SEPARATOR));
    let heavy_light = HeavyLight::new(&graph, 0, |vertices| {
        let mut pos_in_long_string = vec![];
        for &v in vertices.iter().skip(1) {
            pos_in_long_string.push(long_string.len());
            long_string.push(edge_to_parent[v].info);
        }
        let mut rev_pos_in_long_string = vec![];
        for &v in vertices.iter().skip(1).rev() {
            rev_pos_in_long_string.push(long_string.len());
            long_string.push(edge_to_parent[v].info);
        }
        rev_pos_in_long_string.reverse();
        Node {
            pos_in_long_string,
            rev_pos_in_long_string,
        }
    });
    let suf_array = SuffixArray::new(long_string.clone());
    let query_ranges: Vec<_> = queries
        .iter()
        .map(|query| find_range_in_suf_array(&suf_array, query, &heavy_light))
        .collect();
    let mut res = vec![0i64; queries.len()];
    let mut change_queries = vec![vec![]; words.len() + 1];
    for query in queries.iter() {
        change_queries[query.words_range.start].push((-1, query.id));
        change_queries[query.words_range.end].push((1, query.id));
    }
    let mut fenw = Fenwick::new(long_string.len() + 1);
    for id in 0..=words.len() {
        for &(delta, query) in change_queries[id].iter() {
            res[query] += delta * fenw.get_range_sum(query_ranges[query].clone());
        }
        if id == words.len() {
            break;
        }
        let start = word_pos_in_string[id];
        for offset in 0..words[id].len() {
            fenw.add(suf_array.get_pos_in_array(start + offset), 1);
        }
    }
    res
}

fn stress() -> bool {
    let mut rnd = Random::new(787788);
    let n = 100_000;
    let alph = b'a'..b'c';
    let edges = gen_vec(n - 1, |id| {
        let p = rnd.gen_range(0..id + 1);
        (p, id, rnd.gen_range(alph.clone()))
    });
    let cnt_words = 5;
    let sum_len = 100_000;
    let words = gen_vec(cnt_words, |_| {
        let len = rnd.gen_range(sum_len / cnt_words..sum_len * 2 / cnt_words);
        rnd.gen_vec(len, alph.clone())
    });
    dbg!(words.iter().map(|s| s.len()).sum::<usize>());
    let cnt_queries = 100_000;
    let queries = gen_vec(cnt_queries, |id| {
        let x = rnd.gen_range(0..words.len());
        let y = rnd.gen_range(0..words.len());
        Query {
            id,
            fr_v: rnd.gen_range(0..n),
            to_v: rnd.gen_range(0..n),
            words_range: min(x, y)..max(x, y) + 1,
        }
    });
    solve_input(n, &edges, &words, &queries);


    true
}

fn solve(input: &mut Input, _test_case: usize) {
    let vertices = input.usize();
    let num_words = input.usize();
    let q = input.usize();
    let edges = gen_vec(vertices - 1, |_| {
        let fr = input.usize() - 1;
        let to = input.usize() - 1;
        let c: u8 = input.string_as_vec()[0];
        (fr, to, c)
    });
    let words = gen_vec(num_words, |_| input.string_as_vec());
    let queries = gen_vec(q, |id| Query {
        id,
        fr_v: input.usize() - 1,
        to_v: input.usize() - 1,
        words_range: input.usize() - 1..input.usize(),
    });
    let res = solve_input(vertices, &edges, &words, &queries);
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
use crate::misc::num_traits::Number;
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
pub mod rev_permutation {
use crate::misc::num_traits::Number;

pub fn rev_permutation<T>(a: &[T]) -> Vec<T>
where
    T: Number,
{
    let n = a.len();
    let mut res = vec![T::ZERO; n];
    for (pos, value) in a.iter().enumerate() {
        res[value.to_i32() as usize] = T::from_i32(pos as i32);
    }
    res
}
}
pub mod sparse_table_max {
use crate::collections::array_2d::Array2D;
use crate::misc::bits::index_of_highest_set_bit;
use std::fmt::Debug;
use std::ops::Range;

#[derive(Debug)]
pub struct SparseTableMax<T>
where
    T: Ord + Clone + Debug,
{
    max: Array2D<u32>,
    values: Vec<T>,
}

impl<T> SparseTableMax<T>
where
    T: Ord + Clone + Debug,
{
    fn max_by_pos(values: &[T], pos1: u32, pos2: u32) -> u32 {
        if values[pos1 as usize] > values[pos2 as usize] {
            pos1
        } else {
            pos2
        }
    }

    pub fn new(values: &[T]) -> Self {
        let n = values.len();
        let levels = index_of_highest_set_bit(n) + 1;
        let mut max = Array2D::new(0, levels, n);
        for pos in 0..n {
            max[0][pos] = pos as u32;
        }
        for lvl in 1..levels {
            for pos in 0..n {
                let from = pos + (1 << (lvl - 1));
                if from >= n {
                    max[lvl][pos] = max[lvl - 1][pos];
                } else {
                    max[lvl][pos] = Self::max_by_pos(values, max[lvl - 1][pos], max[lvl - 1][from]);
                }
            }
        }
        Self {
            values: values.iter().cloned().collect(),
            max,
        }
    }

    pub fn find_max_pos(&self, range: Range<usize>) -> usize {
        let len = range.len();
        let lvl = index_of_highest_set_bit(len);
        let from = range.end - (1 << lvl);
        debug_assert!(from >= range.start);
        let res = Self::max_by_pos(
            &self.values,
            self.max[lvl][range.start],
            self.max[lvl][from],
        ) as usize;
        debug_assert!(res >= range.start);
        debug_assert!(
            res < range.end,
            "{:?}, res = {}, values = {:?}, lvl = {}",
            range,
            res,
            self.values,
            lvl
        );
        res
    }
}
}
pub mod sparse_table_min {
use crate::collections::sparse_table_max::SparseTableMax;
use std::cmp::Reverse;
use std::fmt::Debug;
use std::ops::Range;

#[derive(Debug)]
pub struct SparseTableMin<T>(SparseTableMax<Reverse<T>>)
where
    T: Clone + Ord + Debug;

impl<T> SparseTableMin<T>
where
    T: Clone + Ord + Debug,
{
    pub fn new(values: &[T]) -> Self {
        let values_rev: Vec<_> = values.iter().cloned().map(|x| Reverse(x)).collect();
        Self(SparseTableMax::new(&values_rev))
    }

    pub fn find_min_pos(&self, range: Range<usize>) -> usize {
        self.0.find_max_pos(range)
    }
}
}
}
pub mod graph {
pub mod edges {
pub mod edge_trait {
pub trait EdgeTrait: Copy + Clone {
    fn to(&self) -> usize;
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
}

impl<E> SimpleGraphT<E>
where
    E: EdgeTrait,
{
    pub fn new(n: usize) -> Self {
        Self {
            adj: vec![vec![]; n],
        }
    }

    pub fn with_adj(adj: Vec<Vec<E>>) -> Self {
        Self { adj }
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
        Self { adj }
    }

    pub fn add_edge(&mut self, from: usize, edge: E) {
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
pub mod calc_edge_to_parent {
use crate::graph::edges::edge_trait::EdgeTrait;
use crate::graph::graph_trait::GraphTrait;
use crate::misc::rec_function::{Callable2, RecursiveFunction2};

pub fn calc_edge_to_parent<Graph, Edge>(tree: &Graph, root_edge: Edge) -> Vec<Edge>
where
    Graph: GraphTrait<Edge>,
    Edge: EdgeTrait,
{
    let n = tree.num_vertices();
    let mut res = vec![root_edge; n];
    RecursiveFunction2::new(|f, v, parent| {
        for edge in tree.adj(v) {
            if edge.to() == parent {
                continue;
            }
            f.call(edge.to(), v);
            res[edge.to()] = edge.clone();
        }
    })
    .call(root_edge.to(), root_edge.to());
    res
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

#[derive(Debug)]
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

    fn construct_path(&self, mut v_from: usize, lca: usize) -> Vec<(&SubPath<T>, Range<usize>)> {
        let mut res = vec![];
        let mut more_len = self.binary_lifting.height(v_from) - self.binary_lifting.height(lca);
        while more_len > 0 {
            let sub_path_id = self.path_of_vertex[v_from];
            let pos_in_path = self.position_inside_path[v_from];
            let use_len = min(more_len, pos_in_path);
            let range = pos_in_path - use_len..pos_in_path;
            let subpath = &self.paths[sub_path_id];
            res.push((subpath, range));
            more_len -= use_len;
            v_from = subpath.vertices[0];
        }
        res
    }

    pub fn go_path(
        &self,
        v_from: usize,
        v_to: usize,
        mut f: impl FnMut(&SubPath<T>, Range<usize>, GoDirection),
    ) {
        let lca = self.binary_lifting.lca(v_from, v_to);
        let to_lca = self.construct_path(v_from, lca);
        for (sub, range) in to_lca.into_iter() {
            f(sub, range, GoDirection::RightToLeft);
        }
        let mut from_lca = self.construct_path(v_to, lca);
        from_lca.reverse();
        for (sub, range) in from_lca.into_iter() {
            f(sub, range, GoDirection::LeftToRight);
        }
    }
}
}
}
}
pub mod io {
pub mod input {
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
    /// ```
    /// use algo_lib::io::input::Input;
    /// let mut stdin = std::io::stdin();
    /// let input = Input::new(&mut stdin);
    /// ```
    ///
    /// Using file file:
    /// ```
    /// use algo_lib::io::input::Input;
    /// let mut file = std::fs::File::open("input.txt").unwrap();
    /// let input = Input::new(&mut file);
    ///```
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

    pub fn string(&mut self) -> String {
        self.read_string()
    }

    pub fn string_as_vec(&mut self) -> Vec<u8> {
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
pub mod digits {
pub fn digits(number: i64) -> Vec<i32> {
    digits_base(number, 10)
}

pub fn digits_base(mut number: i64, base: i64) -> Vec<i32> {
    let mut res = vec![];
    while number != 0 {
        res.push((number % base) as i32);
        number /= base;
    }
    res.reverse();
    res
}

pub fn digit_from_char(c: u8) -> i32 {
    assert!(c >= b'0');
    assert!(c <= b'9');
    (c - b'0') as i32
}

pub fn char_from_digit(digit: i32) -> u8 {
    assert!(digit >= 0);
    assert!(digit <= 9);
    b'0' + digit as u8
}
}
pub mod gen_vector {
pub fn gen_vec<T>(n: usize, mut f: impl FnMut(usize) -> T) -> Vec<T> {
    (0..n).map(|id| f(id)).collect()
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
            const MAX: $t = $t::MAX;
            const MIN: $t = $t::MIN;
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
use std::ops::Neg;
use std::str::FromStr;
use std::num::ParseFloatError;

#[derive(PartialOrd, PartialEq, Copy, Clone, Default)]
pub struct OrdF64(pub f64);

impl OrdF64 {
    pub(crate) const EPS: Self = Self(1e-9);

    pub fn abs(&self) -> Self {
        Self(self.0.abs())
    }

    pub fn eq_with_eps(&self, other: &Self) -> bool {
        let abs_diff = (*self - *other).abs();
        abs_diff <= Self::EPS || abs_diff <= min(self.abs(), other.abs()) * Self::EPS
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
            | Ok(value ) => Ok(Self(value)),
            | Err(error) => Err(error),
        }
    }
}
}
pub mod rand {
use crate::misc::gen_vector::gen_vec;
use crate::misc::num_traits::Number;
use std::ops::Range;

#[allow(dead_code)]
pub struct Random {
    state: u64,
}

impl Random {
    pub fn next(&mut self) -> u64 {
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
        (from as u64 + self.next() % ((to - from) as u64)) as usize
    }

    #[allow(dead_code)]
    pub fn next_double(&mut self) -> f64 {
        (self.next() as f64) / (usize::MAX as f64)
    }

    #[allow(dead_code)]
    pub fn new(seed: u64) -> Self {
        assert_ne!(seed, 0);
        Self { state: seed }
    }

    #[allow(dead_code)]
    pub fn next_permutation(&mut self, n: usize) -> Vec<usize> {
        let mut result: Vec<_> = (0..n).collect();
        for i in 0..n {
            let idx = self.next_in_range(0, i + 1);
            result.swap(i, idx);
        }
        result
    }

    pub fn gen_range<T>(&mut self, range: Range<T>) -> T
    where
        T: Number,
    {
        let from = T::to_i32(range.start) as usize;
        let to = T::to_i32(range.end) as usize;
        T::from_i32(self.next_in_range(from, to) as i32)
    }

    pub fn gen_vec<T>(&mut self, n: usize, range: Range<T>) -> Vec<T>
    where
        T: Number,
    {
        gen_vec(n, |_| self.gen_range(range.clone()))
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
pub mod strings {
pub mod suffix_array {
use crate::collections::rev_permutation::rev_permutation;
use crate::collections::sparse_table_min::SparseTableMin;
use crate::misc::gen_vector::gen_vec;
use crate::misc::num_traits::Number;
use crate::strings::utils::vec2str;
use std::cell::{Cell, Ref, RefCell};
use std::cmp::{max, min};
use std::ops::Index;

#[derive(Debug)]
pub struct SuffixArray {
    sorted_suffixes: Vec<usize>,
    pos_in_sorted: Vec<usize>,
    lcp: Vec<u32>,
    lcp_sparse_table: RefCell<Option<SparseTableMin<u32>>>,
}

impl SuffixArray {
    pub fn get_pos_in_array(&self, pos_in_string: usize) -> usize {
        self.pos_in_sorted[pos_in_string]
    }

    pub fn len(&self) -> usize {
        self.sorted_suffixes.len()
    }

    fn lcp_sparse_table(&self) -> Ref<SparseTableMin<u32>> {
        self.lcp_sparse_table
            .borrow_mut()
            .get_or_insert_with(|| SparseTableMin::new(&self.lcp));
        Ref::map(self.lcp_sparse_table.borrow(), |m| m.as_ref().unwrap())
    }

    pub fn lcp(&self, p1: usize, p2: usize) -> usize {
        let min_pos = min(p1, p2);
        let max_pos = max(p1, p2);
        if min_pos == max_pos {
            return self.len();
        }
        let lcp_table = self.lcp_sparse_table();
        let pos = lcp_table.find_min_pos(min_pos..max_pos);
        self.lcp[pos] as usize
    }

    fn build_lcp<T>(str: &[T], sorted_suffixes: &[usize], pos_in_sorted: &[usize]) -> Vec<u32>
    where
        T: Number,
    {
        let n = str.len();
        let mut lcp = vec![0; n - 1];
        let mut k = 0;
        for i in 0..n {
            if k > 0 {
                k -= 1;
            }
            if pos_in_sorted[i] == n - 1 {
                k = 0;
                continue;
            }
            let j = sorted_suffixes[pos_in_sorted[i] + 1];
            while max(i + k, j + k) < n && str[i + k] == str[j + k] {
                k += 1;
            }
            lcp[pos_in_sorted[i]] = k as u32
        }
        lcp
    }

    pub fn debug_print_suf_array(mut str: Vec<u8>) {
        str.push(0);
        let n = str.len();
        let mut ids = gen_vec(n, |x| x);
        ids.sort_by_key(|&pos| &str[pos..]);
        for (pos, &id) in ids.iter().enumerate() {
            eprintln!("{} -> {}", pos, vec2str(&str[id..]));
        }
    }

    pub fn new<T>(mut str: Vec<T>) -> Self
    where
        T: Number,
    {
        str.push(T::ZERO);
        let n = str.len();
        let mut sorted_suffixes = gen_vec(str.len(), |x| x);
        // TODO: replace with counting sort?
        sorted_suffixes.sort_by_key(|&id| str[id as usize]);
        let mut class_eq = vec![0; n];
        for win in sorted_suffixes.windows(2) {
            if str[win[1] as usize] != str[win[0] as usize] {
                class_eq[win[1] as usize] = class_eq[win[0] as usize] + 1;
            } else {
                class_eq[win[1] as usize] = class_eq[win[0] as usize];
            }
        }
        let mut num_classes = class_eq.iter().max().unwrap() + 1;
        let mut suffixes_new = vec![0; n];
        let mut class_eq_new = vec![0; n];
        let mut cnt = vec![0; n];
        for lvl in 0.. {
            let half = 1 << lvl;
            if half >= n {
                break;
            }
            for (val_new, val) in suffixes_new.iter_mut().zip(sorted_suffixes.iter()) {
                let next = (*val as i32) - (half as i32);
                let next = if next < 0 { next + n as i32 } else { next };
                *val_new = next as usize;
            }
            for i in 0..num_classes {
                cnt[i] = 0;
            }
            for &class_id in class_eq.iter() {
                cnt[class_id] += 1;
            }
            for i in 1..num_classes {
                cnt[i] += cnt[i - 1];
            }
            for i in (0..n).rev() {
                cnt[class_eq[suffixes_new[i]]] -= 1;
                sorted_suffixes[cnt[class_eq[suffixes_new[i]]]] = suffixes_new[i];
            }
            class_eq_new[sorted_suffixes[0]] = 0;
            num_classes = 1;
            for i in 1..n {
                let mid1 = (sorted_suffixes[i] + half) % n;
                let mid2 = (sorted_suffixes[i - 1] + half) % n;
                if class_eq[sorted_suffixes[i]] != class_eq[sorted_suffixes[i - 1]]
                    || class_eq[mid1] != class_eq[mid2]
                {
                    num_classes += 1;
                }
                class_eq_new[sorted_suffixes[i]] = num_classes - 1;
            }
            for i in 0..n {
                class_eq[i] = class_eq_new[i];
            }
        }

        let pos_in_sorted = rev_permutation(&sorted_suffixes);
        let lcp = Self::build_lcp(&str, &sorted_suffixes, &pos_in_sorted);
        if cfg!(debug_assertions) {
            // too slow for debug mode?
            for (w, &lcp) in sorted_suffixes.windows(2).zip(lcp.iter()) {
                let first = &str[w[0]..];
                let second = &str[w[1]..];
                assert!(
                    first < second,
                    "[{} -> {:?}] not less than [{} -> {:?}]",
                    w[0],
                    &str[w[0]..],
                    w[1],
                    &str[w[1]..]
                );
                let lcp = lcp as usize;
                assert!(first[0..lcp] == second[0..lcp]);
                assert_ne!(first.get(lcp), second.get(lcp));
            }
        }
        Self {
            sorted_suffixes,
            pos_in_sorted,
            lcp,
            lcp_sparse_table: RefCell::new(None),
        }
    }
}

impl Index<usize> for SuffixArray {
    type Output = usize;

    fn index(&self, index: usize) -> &Self::Output {
        &self.sorted_suffixes[index]
    }
}
}
pub mod utils {
use crate::misc::digits::char_from_digit;

pub trait VecToString {
    fn to_string(self) -> String;
}

impl VecToString for Vec<u8> {
    fn to_string(self) -> String {
        String::from_utf8(self).unwrap()
    }
}

impl VecToString for Vec<i32> {
    fn to_string(self) -> String {
        self.into_iter()
            .map(char_from_digit)
            .collect::<Vec<_>>()
            .to_string()
    }
}

pub fn vec2str(v: &[u8]) -> String {
    String::from_utf8(v.to_vec()).unwrap()
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