pub mod solution {

use crate::geometry::point::PointT;
use crate::graph::dsu::Dsu;
use crate::io::input::Input;
use crate::io::output::output;
use crate::misc::binary_search::binary_search_first_true;
use crate::misc::min_max::UpdateMinMax;
use crate::{dbg, out, out_line};

type Point = PointT<i32>;

#[derive(Copy, Clone)]
struct Bomb {
    p: Point,
    timer: i32,
    id: usize,
}

fn solve(input: &mut Input, _test_case: usize) {
    let n = input.usize();
    let k = input.i32();

    let mut a: Vec<_> = (0..n)
        .map(|id| {
            let x = input.i32();
            let y = input.i32();
            let timer = input.i32();
            Bomb {
                p: Point::new(x, y),
                timer,
                id,
            }
        })
        .collect();

    let mut dsu = Dsu::new(n);

    let near = |b1: &Bomb, b2: &Bomb| -> bool {
        if b1.p.x == b2.p.x && (b1.p.y - b2.p.y).abs() <= k {
            return true;
        }
        b1.p.y == b2.p.y && (b1.p.x - b2.p.x).abs() <= k
    };

    for key in [|b: &Bomb| (b.p.x, b.p.y), |b: &Bomb| (b.p.y, b.p.x)] {
        a.sort_by_key(key);
        for w in a.windows(2) {
            if near(&w[0], &w[1]) {
                dsu.unite(w[0].id, w[1].id);
            }
        }
    }

    a.sort_by_key(|b| b.id);

    let mut smallest_time = vec![i32::MAX; n];
    for id in 0..n {
        let group = dsu.get(id);
        smallest_time[group].update_min(a[id].timer);
    }
    let timers: Vec<_> = (0..n)
        .filter_map(|id| {
            if dsu.is_root(id) {
                Some(smallest_time[id])
            } else {
                None
            }
        })
        .collect();
    let enough_time = binary_search_first_true(0..n + 1, |time| {
        timers
            .iter()
            .filter(|&will_end| *will_end > (time as i32))
            .count()
            <= time + 1
    });
    out_line!(enough_time);
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
pub mod geometry {
pub mod point {
use crate::misc::num_traits::Number;

#[derive(Copy, Clone)]
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

    pub fn vect_mul(p1: &PointT<T>, p2: &PointT<T>, p3: &PointT<T>) -> T {
        (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x)
    }

    pub fn scal_mul(p1: &PointT<T>, p2: &PointT<T>, p3: &PointT<T>) -> T {
        (p2.x - p1.x) * (p3.x - p1.x) + (p2.y - p1.y) * (p3.y - p1.y)
    }
}
}
}
pub mod graph {
pub mod dsu {
pub struct Dsu {
    p: Vec<u32>,
    size: Vec<u32>,
}

impl Dsu {
    pub fn clear(&mut self) {
        for (idx, val) in self.p.iter_mut().enumerate() {
            *val = idx as u32;
        }
        for val in self.size.iter_mut() {
            *val = 1;
        }
    }

    pub fn new(n: usize) -> Self {
        let mut res = Self {
            p: vec![0; n],
            size: vec![0; n],
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

    fn read_float(&mut self) -> f64 {
        self.read_string().parse().unwrap()
    }

    pub fn f64(&mut self) -> f64 {
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
    fn position_of_min(&self) -> usize;
    fn position_of_max(&self) -> usize;
}

impl<T: PartialOrd> FindMinMaxPos for [T] {
    fn position_of_min(&self) -> usize {
        let mut pos_of_best = 0;
        for (idx, val) in self.iter().enumerate().skip(1) {
            if val < &self[pos_of_best] {
                pos_of_best = idx;
            }
        }
        pos_of_best
    }

    fn position_of_max(&self) -> usize {
        let mut pos_of_best = 0;
        for (idx, val) in self.iter().enumerate().skip(1) {
            if val > &self[pos_of_best] {
                pos_of_best = idx;
            }
        }
        pos_of_best
    }
}

pub fn position_of_min_by<T, F>(n: usize, f: F) -> usize
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

pub fn position_of_max_by<T, F>(n: usize, f: F) -> usize
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
use std::convert::TryFrom;
use std::fmt::Debug;
use std::ops::{Add, AddAssign, Div, DivAssign, Mul, MulAssign, Sub, SubAssign};

pub trait HasConstants<T> {
    const MAX: T;
    const MIN: T;
    const ZERO: T;
    const ONE: T;
    const TWO: T;
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
    + TryFrom<i32>
    + Debug
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
            + TryFrom<i32>
            + Debug,
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
    };
}

has_constants_impl!(i32);
has_constants_impl!(i64);
has_constants_impl!(i128);
has_constants_impl!(u32);
has_constants_impl!(u64);
has_constants_impl!(u128);
has_constants_impl!(usize);
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