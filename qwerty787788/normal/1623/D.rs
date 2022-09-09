pub mod solution {

use crate::io::input::Input;
use crate::io::output::output;
use crate::math::modulo::Mod7;
use crate::{dbg, out, out_line};

type Mod = Mod7;

struct RobotRow {
    cur: i32,
    delta: i32,
    max: i32,
}

impl RobotRow {
    fn make_move(&mut self) {
        if self.cur + self.delta > self.max || self.cur + self.delta < 1 {
            self.delta *= -1;
        }
        self.cur += self.delta;
    }
}

fn solve(input: &mut Input, _test_case: usize) {
    let n = input.i32();
    let m = input.i32();
    let x1 = input.i32();
    let y1 = input.i32();
    let x2 = input.i32();
    let y2 = input.i32();
    let p = Mod::new(input.i32()) / Mod::new(100);
    let mut r1 = RobotRow {
        cur: x1,
        delta: 1,
        max: n,
    };
    let mut r2 = RobotRow {
        cur: y1,
        delta: 1,
        max: m,
    };
    let cycle_len = (n - 1) * (m - 1) * 2;
    let mut prob_alive = Mod::ONE;
    let mut ev = Mod::ZERO;
    for move_id in 0..cycle_len {
        if r1.cur == x2 || r2.cur == y2 {
            ev += p * prob_alive * Mod::new(move_id);
            prob_alive *= Mod::ONE - p;
        }
        r1.make_move();
        r2.make_move();
    }
    let ans = (ev + prob_alive * Mod::new(cycle_len)) / (Mod::ONE - prob_alive);
    out_line!(ans.to_string());
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
pub mod math {
pub mod modulo {
use std::marker::PhantomData;

pub trait Value {
    fn val() -> i32;
}

#[derive(Copy, Clone, Eq, PartialEq, Default)]
pub struct ModWithValue<M>(i32, PhantomData<M>)
where
    M: Value;

impl<M> ModWithValue<M>
where
    M: Value,
{
    #[allow(unused)]
    pub const ZERO: Self = Self(0, PhantomData);

    #[allow(unused)]
    pub const ONE: Self = Self(1, PhantomData);

    fn rev_rec(a: i32, m: i32) -> i32 {
        if a == 1 {
            return a;
        }
        return ((1 - Self::rev_rec(m % a, a) as i64 * m as i64) / a as i64 + m as i64) as i32;
    }

    #[allow(dead_code)]
    fn inv(self) -> Self {
        ModWithValue(Self::rev_rec(self.0, M::val()), PhantomData)
    }

    #[allow(dead_code)]
    pub fn new(mut x: i32) -> Self {
        if x < 0 {
            x += M::val();
        } else if x >= M::val() {
            x -= M::val();
        }
        assert!(0 <= x && x < M::val());
        Self(x, PhantomData)
    }
}

impl<M> std::fmt::Display for ModWithValue<M>
where
    M: Value,
{
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        write!(f, "{}", self.0)
    }
}

impl<M> std::fmt::Debug for ModWithValue<M>
where
    M: Value + Copy + Eq,
{
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        const MAX: usize = 100;
        if self.0 <= MAX as i32 {
            write!(f, "{}", self.0)
        } else if self.0 >= M::val() - MAX as i32 {
            write!(f, "-{}", M::val() - self.0)
        } else {
            for denum in 1..MAX {
                for num in 1..MAX {
                    if Self(num as i32, PhantomData) / Self(denum as i32, PhantomData) == *self {
                        return write!(f, "{}/{}", num, denum);
                    }
                }
            }
            write!(f, "(?? {} ??)", self.0)
        }
    }
}

impl<M> std::ops::Add for ModWithValue<M>
where
    M: Value,
{
    type Output = Self;

    fn add(self, rhs: Self) -> Self::Output {
        let res = self.0 + rhs.0;
        if res >= M::val() {
            ModWithValue(res - M::val(), PhantomData)
        } else {
            ModWithValue(res, PhantomData)
        }
    }
}

impl<M> std::ops::AddAssign for ModWithValue<M>
where
    M: Value,
{
    fn add_assign(&mut self, rhs: Self) {
        self.0 += rhs.0;
        if self.0 >= M::val() {
            self.0 -= M::val();
        }
    }
}

impl<M> std::ops::Sub for ModWithValue<M>
where
    M: Value,
{
    type Output = Self;

    fn sub(self, rhs: Self) -> Self::Output {
        let res = self.0 - rhs.0;
        if res < 0 {
            ModWithValue(res + M::val(), PhantomData)
        } else {
            ModWithValue(res, PhantomData)
        }
    }
}

impl<M> std::ops::SubAssign for ModWithValue<M>
where
    M: Value,
{
    fn sub_assign(&mut self, rhs: Self) {
        self.0 -= rhs.0;
        if self.0 < 0 {
            self.0 += M::val();
        }
    }
}

impl<M> std::ops::Mul for ModWithValue<M>
where
    M: Value,
{
    type Output = Self;

    fn mul(self, rhs: Self) -> Self::Output {
        let res = (self.0 as i64) * (rhs.0 as i64) % (M::val() as i64);
        ModWithValue(res as i32, PhantomData)
    }
}

impl<M> std::ops::MulAssign for ModWithValue<M>
where
    M: Value,
{
    fn mul_assign(&mut self, rhs: Self) {
        self.0 = ((self.0 as i64) * (rhs.0 as i64) % (M::val() as i64)) as i32;
    }
}

impl<M> std::ops::Div for ModWithValue<M>
where
    M: Value,
{
    type Output = Self;

    fn div(self, rhs: Self) -> Self::Output {
        let rhs_inv = rhs.inv();
        self * rhs_inv
    }
}

impl<M> std::ops::DivAssign for ModWithValue<M>
where
    M: Value,
{
    fn div_assign(&mut self, rhs: Self) {
        *self *= rhs.inv();
    }
}

pub trait ConstValue: Value {
    const VAL: i32;
}

impl<V: ConstValue> Value for V {
    fn val() -> i32 {
        Self::VAL
    }
}

#[derive(Copy, Clone, Eq, PartialEq, Default)]
pub struct Value7();
impl ConstValue for Value7 {
    const VAL: i32 = 1_000_000_007;
}
pub type Mod7 = ModWithValue<Value7>;

#[derive(Copy, Clone, Eq, PartialEq, Default)]
pub struct Value9();
impl ConstValue for Value9 {
    const VAL: i32 = 1_000_000_009;
}
pub type Mod9 = ModWithValue<Value9>;

#[derive(Copy, Clone, Eq, PartialEq, Default)]
#[allow(non_camel_case_types)]
pub struct Value_998_244_353();
impl ConstValue for Value_998_244_353 {
    const VAL: i32 = 998_244_353;
}
#[allow(non_camel_case_types)]
pub type Mod_998_244_353 = ModWithValue<Value_998_244_353>;

#[cfg(test)]
mod tests {
    use crate::math::modulo::*;

    type Mod = Mod7;

    #[test]
    fn add() {
        let x = Mod::new(1);
        let y = Mod::new(2);
        assert_eq!(format!("{}", x + y), "3");
    }

    #[test]
    fn sub() {
        let x = Mod::new(1);
        let y = Mod::new(2);
        assert_eq!(format!("{}", x - y), "1000000006");
        assert_eq!(format!("{:?}", x - y), "-1");
    }

    #[test]
    fn mul() {
        let x = Mod::new(3);
        let y = Mod::new(5);
        assert_eq!(format!("{}", x * y), "15");
    }

    #[test]
    fn div() {
        let x = Mod::new(3);
        let y = Mod::new(5);
        assert_eq!(format!("{}", x / y), "200000002");
        assert_eq!(format!("{:?}", x / y), "3/5");
    }

    #[test]
    fn div_assign() {
        let mut x = Mod::new(3);
        let y = Mod::new(5);
        x /= y;
        assert_eq!(format!("{}", x), "200000002");
        assert_eq!(format!("{:?}", x), "3/5");
    }

    #[test]
    fn dbg_format() {
        let x = Mod::new(1) / Mod::new(2);
        let y = Mod::new(1) / Mod::new(3);
        assert_eq!(format!("{}", x + y), "833333340");
        assert_eq!(format!("{:?}", x + y), "5/6");
    }

    #[test]
    fn dbg_format_big() {
        let x = Mod::new(123) / Mod::new(457);
        assert_eq!(format!("{:?}", x), "(?? 262582059 ??)");
    }

    #[test]
    fn dbg_format_more() {
        assert_eq!(format!("{:?}", Mod::new(1)), "1");
        assert_eq!(format!("{:?}", Mod::new(3)), "3");
        assert_eq!(format!("{:?}", Mod::new(-5)), "-5");
    }

    #[test]
    fn consts() {
        let one = Mod::ONE - Mod::ZERO;
        assert_eq!(format!("{:?}", one), "1");
    }
}
}
}
pub mod misc {
pub mod misc {
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
}
fn main() {
    let mut sin = std::io::stdin();
    let input = crate::io::input::Input::new(&mut sin);
    unsafe {
        crate::io::output::OUTPUT = Some(crate::io::output::Output::new(Box::new(std::io::stdout())));
    }
    crate::solution::run(input);
}