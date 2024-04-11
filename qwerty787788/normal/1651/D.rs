pub mod solution {
//{"name":"D.  ","group":"Codeforces - Educational Codeforces Round 124 (  Div. 2)","url":"http://codeforces.com/contest/1651/problem/D","interactive":false,"timeLimit":4000,"tests":[{"input":"6\n2 2\n1 2\n2 1\n3 2\n2 3\n5 5\n","output":"1 1\n1 1\n2 0\n3 1\n2 4\n5 4\n"},{"input":"8\n4 4\n2 4\n2 2\n2 3\n1 4\n4 2\n1 3\n3 3\n","output":"4 3\n2 5\n2 1\n2 5\n1 5\n4 1\n1 2\n3 2\n"}],"testType":"single","input":{"type":"stdin","fileName":null,"pattern":null},"output":{"type":"stdout","fileName":null,"pattern":null},"languages":{"java":{"taskClass":"DBlizhaishieTochki"}}}

use crate::algo_lib::collections::array_2d::Array2D;
use crate::algo_lib::collections::fx_hash_map::FxHashMap;
use crate::algo_lib::geometry::point::PointT;
use crate::algo_lib::io::output::output;
use crate::algo_lib::io::task_io_settings::TaskIoType;
use crate::algo_lib::io::task_runner::run_task;
use crate::algo_lib::io::input::Input;
use crate::algo_lib::io::task_io_settings::TaskIoSettings;
use crate::algo_lib::iters::shifts::SHIFTS_4;
use crate::algo_lib::misc::gen_vector::gen_vec;
use crate::algo_lib::misc::rec_function::Callable2;
use crate::algo_lib::misc::rec_function::RecursiveFunction2;
#[allow(unused)]
use crate::dbg;
use crate::out;
use crate::out_line;

type Point = PointT<i32>;

fn solve_a(a: &[Point]) {
    let n = a.len();
    let mut map = FxHashMap::<Point, usize>::default();
    for (id, p) in a.iter().enumerate() {
        map.insert(p.clone(), id);
    }
    let shifts = SHIFTS_4;
    let mut ans = gen_vec(n, |id| Point {
        x: a[id].x + n as i32 + 1,
        y: a[id].y,
    });
    let mut edges = vec![];
    for i in 0..n {
        for shift in shifts.iter() {
            let next_p = a[i].apply_shift(shift);
            if let Some(&next_id) = map.get(&next_p) {
                edges.push((i, next_id));
            } else {
                ans[i] = next_p;
            }
        }
    }
    loop {
        let mut changed = false;
        for &(fr, to) in edges.iter() {
            if a[fr].dist_manh(&ans[fr]) > a[fr].dist_manh(&ans[to]) {
                ans[fr] = ans[to].clone();
                changed = true;
            }
        }
        if !changed {
            break;
        }
    }
    for p in ans.iter() {
        out_line!(p.x, p.y);
    }
}

fn solve(input: &mut Input, _test_case: usize) {
    let n = input.usize();
    let a: Vec<Point> = input.vec(n);
    solve_a(&a);
}

fn stress() {
    let mut a = vec![];
    for x in 0..200 {
        for y in 0..1000 {
            a.push(Point { x, y });
        }
    }
    solve_a(&a);
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
pub mod fx_hash_map {
// It is just a little bit modified copy of https://docs.rs/rustc-hash/1.1.0/src/rustc_hash

// Copyright 2015 The Rust Project Developers. See the COPYRIGHT
// file at the top-level directory of this distribution and at
// http://rust-lang.org/COPYRIGHT.
//
// Licensed under the Apache License, Version 2.0 <LICENSE-APACHE or
// http://www.apache.org/licenses/LICENSE-2.0> or the MIT license
// <LICENSE-MIT or http://opensource.org/licenses/MIT>, at your
// option. This file may not be copied, modified, or distributed
// except according to those terms.

//! Fast, non-cryptographic hash used by rustc and Firefox.
//!
//! # Example
//!
//! ```rust
//! # #[cfg(feature = "std")]
//! # fn main() {
//! use rustc_hash::FxHashMap;
//! let mut map: FxHashMap<u32, u32> = FxHashMap::default();
//! map.insert(22, 44);
//! # }
//! # #[cfg(not(feature = "std"))]
//! # fn main() { }
//! ```

extern crate std;

use core::convert::TryInto;
use core::default::Default;
use core::hash::BuildHasherDefault;
use core::hash::Hasher;
use core::mem::size_of;
use core::ops::BitXor;
use std::collections::HashMap;
use std::collections::HashSet;

/// Type alias for a hashmap using the `fx` hash algorithm.
pub type FxHashMap<K, V> = HashMap<K, V, BuildHasherDefault<FxHasher>>;

/// Type alias for a hashmap using the `fx` hash algorithm.
pub type FxHashSet<V> = HashSet<V, BuildHasherDefault<FxHasher>>;

/// A speedy hash algorithm for use within rustc. The hashmap in liballoc
/// by default uses SipHash which isn't quite as speedy as we want. In the
/// compiler we're not really worried about DOS attempts, so we use a fast
/// non-cryptographic hash.
///
/// This is the same as the algorithm used by Firefox -- which is a homespun
/// one not based on any widely-known algorithm -- though modified to produce
/// 64-bit hash values instead of 32-bit hash values. It consistently
/// out-performs an FNV-based hash within rustc itself -- the collision rate is
/// similar or slightly worse than FNV, but the speed of the hash function
/// itself is much higher because it works on up to 8 bytes at a time.
pub struct FxHasher {
    hash: usize,
}

#[cfg(target_pointer_width = "32")]
const K: usize = 0x9e3779b9;
#[cfg(target_pointer_width = "64")]
const K: usize = 0x517cc1b727220a95;

impl Default for FxHasher {
    #[inline]
    fn default() -> FxHasher {
        FxHasher { hash: 0 }
    }
}

impl FxHasher {
    #[inline]
    fn add_to_hash(&mut self, i: usize) {
        self.hash = self.hash.rotate_left(5).bitxor(i).wrapping_mul(K);
    }
}

impl Hasher for FxHasher {
    #[inline]
    fn write(&mut self, mut bytes: &[u8]) {
        #[cfg(target_pointer_width = "32")]
        let read_usize = |bytes: &[u8]| u32::from_ne_bytes(bytes[..4].try_into().unwrap());
        #[cfg(target_pointer_width = "64")]
        let read_usize = |bytes: &[u8]| u64::from_ne_bytes(bytes[..8].try_into().unwrap());

        let mut hash = FxHasher { hash: self.hash };
        assert!(size_of::<usize>() <= 8);
        while bytes.len() >= size_of::<usize>() {
            hash.add_to_hash(read_usize(bytes) as usize);
            bytes = &bytes[size_of::<usize>()..];
        }
        if (size_of::<usize>() > 4) && (bytes.len() >= 4) {
            hash.add_to_hash(u32::from_ne_bytes(bytes[..4].try_into().unwrap()) as usize);
            bytes = &bytes[4..];
        }
        if (size_of::<usize>() > 2) && bytes.len() >= 2 {
            hash.add_to_hash(u16::from_ne_bytes(bytes[..2].try_into().unwrap()) as usize);
            bytes = &bytes[2..];
        }
        if (size_of::<usize>() > 1) && bytes.len() >= 1 {
            hash.add_to_hash(bytes[0] as usize);
        }
        self.hash = hash.hash;
    }

    #[inline]
    fn write_u8(&mut self, i: u8) {
        self.add_to_hash(i as usize);
    }

    #[inline]
    fn write_u16(&mut self, i: u16) {
        self.add_to_hash(i as usize);
    }

    #[inline]
    fn write_u32(&mut self, i: u32) {
        self.add_to_hash(i as usize);
    }

    #[cfg(target_pointer_width = "32")]
    #[inline]
    fn write_u64(&mut self, i: u64) {
        self.add_to_hash(i as usize);
        self.add_to_hash((i >> 32) as usize);
    }

    #[cfg(target_pointer_width = "64")]
    #[inline]
    fn write_u64(&mut self, i: u64) {
        self.add_to_hash(i as usize);
    }

    #[inline]
    fn write_usize(&mut self, i: usize) {
        self.add_to_hash(i);
    }

    #[inline]
    fn finish(&self) -> u64 {
        self.hash as u64
    }
}
}
}
pub mod geometry {
pub mod point {
use crate::algo_lib::io::input::Input;
use crate::algo_lib::io::input::Readable;
use crate::algo_lib::iters::shifts::Shift;
use crate::algo_lib::misc::num_traits::Number;
use crate::algo_lib::misc::ord_f64::OrdF64;
use std::ops::Add;
use std::ops::AddAssign;
use std::ops::Sub;
use std::ops::SubAssign;

#[derive(Copy, Clone, Ord, PartialOrd, Eq, PartialEq, Hash, Debug)]
pub struct PointT<T: Number> {
    pub x: T,
    pub y: T,
}

impl<T: Number> PointT<T> {
    pub fn new(x: T, y: T) -> Self {
        Self { x, y }
    }

    pub fn dist2(&self, p2: &PointT<T>) -> T {
        let dx = self.x - p2.x;
        let dy = self.y - p2.y;
        dx * dx + dy * dy
    }

    pub fn dist_manh(&self, p2: &PointT<T>) -> T {
        let dx = self.x - p2.x;
        let dy = self.y - p2.y;
        let dx_abs = if dx < T::ZERO { T::ZERO - dx } else { dx };
        let dy_abs = if dy < T::ZERO { T::ZERO - dy } else { dy };
        dx_abs + dy_abs
    }

    pub fn angle_to(&self, other: &PointT<T>) -> OrdF64
    where
        f64: From<T>,
    {
        let dy = other.y - self.y;
        let dx = other.x - self.x;
        OrdF64(f64::atan2(dy.try_into().unwrap(), dx.try_into().unwrap()))
    }

    pub fn swap_x_y(&self) -> Self {
        Self::new(self.y, self.x)
    }

    pub fn vect_mul(p1: &PointT<T>, p2: &PointT<T>, p3: &PointT<T>) -> T {
        (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x)
    }

    pub fn scal_mul(p1: &PointT<T>, p2: &PointT<T>, p3: &PointT<T>) -> T {
        Self::scal_mul2(&(*p2 - *p1), &(*p3 - *p1))
    }

    pub fn scal_mul2(p1: &PointT<T>, p2: &PointT<T>) -> T {
        p1.x * p2.x + p1.y * p2.y
    }

    pub fn vect_mul2(p1: &PointT<T>, p2: &PointT<T>) -> T {
        p1.x * p2.y - p1.y * p2.x
    }

    pub fn apply_shift(&self, shift: &Shift) -> Self {
        Self {
            x: self.x + T::from_i32(shift.dx),
            y: self.y + T::from_i32(shift.dy),
        }
    }

    pub fn shift(&self, dx: T, dy: T) -> Self {
        Self {
            x: self.x + dx,
            y: self.y + dy,
        }
    }

    pub fn scale(&self, coef: T) -> Self {
        Self {
            x: self.x * coef,
            y: self.y * coef,
        }
    }

    pub fn index_vec2d<'a, Elem>(&self, arr: &'a [Vec<Elem>]) -> Option<&'a Elem> {
        if self.x >= T::ZERO
            && self.x < T::from_i32(arr.len() as i32)
            && self.y >= T::ZERO
            && self.y < T::from_i32(arr[T::to_i32(self.x) as usize].len() as i32)
        {
            let x = T::to_i32(self.x) as usize;
            let y = T::to_i32(self.y) as usize;
            Some(&arr[x][y])
        } else {
            None
        }
    }

    pub fn rotate_ccw(&self) -> Self {
        Self::new(T::ZERO - self.y, self.x)
    }

    pub const ZERO: PointT<T> = PointT {
        x: T::ZERO,
        y: T::ZERO,
    };
}

impl<T> Add for PointT<T>
where
    T: Number,
{
    type Output = Self;

    fn add(self, rhs: Self) -> Self::Output {
        Self::new(self.x + rhs.x, self.y + rhs.y)
    }
}

impl<T> AddAssign for PointT<T>
where
    T: Number,
{
    fn add_assign(&mut self, rhs: Self) {
        self.x += rhs.x;
        self.y += rhs.y;
    }
}

impl<T> Sub for PointT<T>
where
    T: Number,
{
    type Output = Self;

    fn sub(self, rhs: Self) -> Self::Output {
        Self::new(self.x - rhs.x, self.y - rhs.y)
    }
}

impl<T> SubAssign for PointT<T>
where
    T: Number,
{
    fn sub_assign(&mut self, rhs: Self) {
        self.x -= rhs.x;
        self.y -= rhs.y;
    }
}

impl<T> Readable for PointT<T>
where
    T: Number + Readable,
{
    fn read(input: &mut Input) -> Self {
        let x = input.read();
        let y = input.read();
        Self { x, y }
    }
}

#[derive(Copy, Clone, Ord, PartialOrd, Eq, PartialEq, Hash)]
pub struct PointWithIdT<T: Number> {
    pub p: PointT<T>,
    id: u32,
}

impl<T> PointWithIdT<T>
where
    T: Number,
{
    pub fn new(p: PointT<T>, id: usize) -> Self {
        Self { p, id: id as u32 }
    }

    pub fn id(&self) -> usize {
        self.id as usize
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
pub mod iters {
pub mod shifts {
#[derive(Copy, Clone, Hash, Ord, PartialOrd, Eq, PartialEq)]
pub struct Shift {
    pub dx: i32,
    pub dy: i32,
}

// x goes down
// y goes right
pub const SHIFT_DOWN: Shift = Shift { dx: 1, dy: 0 };
pub const SHIFT_UP: Shift = Shift { dx: -1, dy: 0 };
pub const SHIFT_RIGHT: Shift = Shift { dx: 0, dy: 1 };
pub const SHIFT_LEFT: Shift = Shift { dx: 0, dy: -1 };

pub const SHIFTS_4: [Shift; 4] = [SHIFT_DOWN, SHIFT_LEFT, SHIFT_UP, SHIFT_RIGHT];
pub const SHIFTS_8: [Shift; 8] = [
    SHIFT_DOWN,
    SHIFT_LEFT,
    SHIFT_UP,
    SHIFT_RIGHT,
    Shift { dx: -1, dy: -1 },
    Shift { dx: -1, dy: 1 },
    Shift { dx: 1, dy: -1 },
    Shift { dx: 1, dy: 1 },
];

pub const SHIFTS_9: [Shift; 9] = [
    SHIFT_DOWN,
    SHIFT_LEFT,
    SHIFT_UP,
    SHIFT_RIGHT,
    Shift { dx: -1, dy: -1 },
    Shift { dx: -1, dy: 1 },
    Shift { dx: 1, dy: -1 },
    Shift { dx: 1, dy: 1 },
    Shift { dx: 0, dy: 0 },
];

pub fn shift_by_nswe(c: u8) -> Shift {
    match c {
        b'S' | b's' => SHIFT_DOWN,
        b'N' | b'n' => SHIFT_UP,
        b'E' | b'e' => SHIFT_RIGHT,
        b'W' | b'w' => SHIFT_LEFT,
        _ => panic!("Unexpected direction!"),
    }
}

pub fn shift_by_uldr(c: u8) -> Shift {
    match c {
        b'D' | b'd' => SHIFT_DOWN,
        b'U' | b'u' => SHIFT_UP,
        b'R' | b'r' => SHIFT_RIGHT,
        b'L' | b'l' => SHIFT_LEFT,
        _ => panic!("Unexpected direction!"),
    }
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
                    file!(), line!(), stringify!($first_val), &$first_val)
    };
}
}
pub mod gen_vector {
pub fn gen_vec<T>(n: usize, mut f: impl FnMut(usize) -> T) -> Vec<T> {
    (0..n).map(|id| f(id)).collect()
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

impl From<i64> for OrdF64 {
    fn from(x: i64) -> Self {
        f!(x as f64)
    }
}

impl From<f64> for OrdF64 {
    fn from(x: f64) -> Self {
        f!(x)
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
}
fn main() {
    crate::solution::submit();
}