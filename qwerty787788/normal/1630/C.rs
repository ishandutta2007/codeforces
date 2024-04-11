pub mod solution {

use crate::collections::last_exn::LastExn;
use crate::io::input::Input;
use crate::io::output::output;
use crate::misc::min_max::UpdateMinMax;
use crate::misc::vec_apply_delta::ApplyDelta;
use crate::seg_trees::lazy_seg_tree_max::{MaxValNode, SegTreeMax};
use crate::{dbg, out, out_line};
use std::ops::Range;

fn solve(input: &mut Input, _test_case: usize) {
    let n = input.usize();
    let a = input.read_vec::<usize>(n).sub_from_all(1);
    let mut first = vec![None; n];
    let mut dp = vec![0; n + 1];
    let mut seg_tree = SegTreeMax::new_f(
        n,
        &|pos| MaxValNode {
            pos,
            max_val: i32::MIN,
        },
        (),
    );
    for (pos, &elem) in a.iter().enumerate() {
        dp[pos + 1] = dp[pos];
        if let Some(prev) = first[elem] {
            let can = dp[prev] + (pos - prev - 1);
            dp[pos + 1].update_max(can);
            if prev + 1 < pos {
                let can = seg_tree.get(prev + 1, pos).max_val + (pos as i32) - 1;
                dp[pos + 1].update_max(can as usize);
            }
        } else {
            first[elem] = Some(pos);
        }
        seg_tree.modify(pos, pos + 1, dp[pos + 1] as i32 - (pos as i32));
    }
    out_line!(dp[n]);
}

pub(crate) fn run(mut input: Input) -> bool {
    solve(&mut input, 1);
    output().flush();
    input.skip_whitespace();
    input.peek().is_none()
}

}
pub mod collections {
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
pub mod lazy_seg_tree {
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

    pub fn modify(&mut self, ql: usize, qr: usize, update: T::Update) {
        assert!(ql < qr);
        self.modify_(0, 0, self.n, ql, qr, &update);
    }

    pub fn get(&mut self, ql: usize, qr: usize) -> T {
        assert!(ql < qr);
        self.get_(0, 0, self.n, ql, qr)
    }

    pub fn new_f(n: usize, f: &dyn Fn(usize) -> T, context: T::Context) -> Self {
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
}
}
pub mod lazy_seg_tree_max {
use crate::seg_trees::lazy_seg_tree::{LazySegTree, LazySegTreeNodeSpec};

#[derive(Clone, Default, Copy, Debug)]
pub struct MaxValNode {
    pub max_val: i32,
    pub pos: usize,
}

impl LazySegTreeNodeSpec for MaxValNode {
    #[allow(unused)]
    fn unite(l: &Self, r: &Self, context: &()) -> Self {
        if l.max_val > r.max_val {
            *l
        } else {
            *r
        }
    }

    fn apply_update(node: &mut Self, update: &Self::Update) {
        node.max_val = *update;
    }

    #[allow(unused)]
    fn join_updates(current: &mut Self::Update, add: &Self::Update) {
        unreachable!()
    }

    type Update = i32;
    type Context = ();
}

pub type SegTreeMax = LazySegTree<MaxValNode>;

#[cfg(test)]
mod tests {
use crate::seg_trees::lazy_seg_tree::{LazySegTree, LazySegTreeNodeSpec};
use crate::seg_trees::lazy_seg_tree_max::{MaxValNode, SegTreeMax};

    #[test]
    fn simple() {
        let n = 5;
        let mut seg_tree = SegTreeMax::new_f(n, &|pos| MaxValNode { max_val: 0, pos }, ());
        seg_tree.modify(2, 3, 123);
        let res = seg_tree.get(0, 5);
        assert_eq!(res.max_val, 123);
        assert_eq!(res.pos, 2);
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