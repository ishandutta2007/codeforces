pub mod solution {
//{"name":"E.  ","group":"Codeforces - Codeforces Round #783 (Div. 1)","url":"https://codeforces.com/contest/1667/problem/E","interactive":false,"timeLimit":3000,"tests":[{"input":"3\n","output":"1 1 0\n"},{"input":"5\n","output":"10 10 4 0 0\n"},{"input":"7\n","output":"276 276 132 36 0 0 0\n"}],"testType":"single","input":{"type":"stdin","fileName":null,"pattern":null},"output":{"type":"stdout","fileName":null,"pattern":null},"languages":{"java":{"taskClass":"ETsentroidnieVeroyatnosti"}}}

use std::cmp::max;

use crate::algo_lib::io::output::output;
use crate::algo_lib::io::task_io_settings::TaskIoType;
use crate::algo_lib::io::task_runner::run_task;
use crate::algo_lib::io::input::Input;
use crate::algo_lib::io::task_io_settings::TaskIoSettings;
use crate::algo_lib::math::combinations::Combinations;
use crate::algo_lib::math::combinations::CombinationsFact;
use crate::algo_lib::math::modulo::Mod_998_244_353;
use crate::algo_lib::math::ntt::NTT;
#[allow(unused)]
use crate::dbg;
use crate::out;
use crate::out_line;

type Mod = Mod_998_244_353;

fn solve(input: &mut Input, _test_case: usize) {
    let n = input.usize();
    let big_size = (n + 1) / 2;
    let mut ways_big_root = vec![Mod::ZERO; n];

    let comb = CombinationsFact::<Mod>::new(n + 1);

    let mut f = vec![Mod::ZERO; n + 1];
    for subtree_size in big_size - 1..n {
        let mut ways = comb.fact(subtree_size);

        let left_vertices = n - subtree_size - 1;
        if left_vertices > 0 {
            ways *= comb.fact(left_vertices - 1);
        }
        f[subtree_size] += ways;
        f[subtree_size] /= comb.fact(subtree_size);
    }

    let mut g = vec![Mod::ZERO; n + 1];
    for i in 0..g.len() {
        g[i] = Mod::ONE / comb.fact(i);
    }

    // let mut fg = vec![Mod::ZERO; 2 * n + 2];
    // for i in 0..=n {
    //     for j in 0..=n {
    //         fg[i + j] += f[i] * g[j];
    //     }
    // }

    let fg = NTT::new().multiply(f, g);

    for root_pos in (1..n).rev() {
        let max_subtree_size = n - root_pos - 1;
        // for subtree_size in 0..=max_subtree_size {
        //     ways_big_root[root_pos] += f[subtree_size] / comb.fact(max_subtree_size - subtree_size);
        // }
        // assert_eq!(ways_big_root[root_pos], fg[max_subtree_size]);
        ways_big_root[root_pos] =
            fg[max_subtree_size] * Mod::new(root_pos) * comb.fact(max_subtree_size);
    }
    for root_pos in (0..1).rev() {
        let max_subtree_size = n - root_pos - 1;
        for subtree_size in big_size - 1..=max_subtree_size {
            let mut ways = comb.fact(subtree_size);

            let left_vertices = n - subtree_size - 1;
            if left_vertices > 0 {
                if root_pos == 0 {
                    continue;
                }
                ways *= comb.fact(left_vertices - 1);
            }
            ways *= comb.c(max_subtree_size, subtree_size);
            ways_big_root[root_pos] += ways;
        }
        if root_pos != 0 {
            ways_big_root[root_pos] *= Mod::new(root_pos);
        }
    }
    let mut pref_sum = Mod::ZERO;
    for i in (0..n).rev() {
        let next_sum = pref_sum + ways_big_root[i] / Mod::new(max(1, i));
        ways_big_root[i] -= pref_sum;
        pref_sum = next_sum;
    }

    out_line!(ways_big_root);
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

    pub fn new_f(rows: usize, cols: usize, mut f: impl FnMut(usize, usize) -> T) -> Self {
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
        Self::new_f(self.cols, self.rows, |r, c| self[c][r].clone())
    }

    pub fn iter(&self) -> Iter<T> {
        Iter {
            array: self,
            row: 0,
            col: 0,
        }
    }

    pub fn pref_sum(&self) -> Self
    where
        T: Number,
    {
        let mut res = Self::new(T::ZERO, self.rows + 1, self.cols + 1);
        for i in 0..self.rows {
            for j in 0..self.cols {
                let value = self[i][j] + res[i][j + 1] + res[i + 1][j] - res[i][j];
                res[i + 1][j + 1] = value;
            }
        }
        res
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
            Self::new_f(n, n, |r, c| if r == c { T::ONE } else { T::ZERO })
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
pub mod last_exn {
use std::collections::BTreeSet;

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

impl<T> LastExn<T> for BTreeSet<T> {
    fn last_exn(&self) -> &T {
        self.iter().next_back().unwrap()
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
        Array2D::new_f(rows, cols, |_, _| self.read())
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
pub mod math {
pub mod combinations {
use crate::algo_lib::math::factorials::gen_facts;
use crate::algo_lib::misc::num_traits::Number;

pub trait Combinations<T> {
    fn c(&self, n: usize, k: usize) -> T;
}

pub struct CombinationsFact<T> {
    fact: Vec<T>,
    fact_inv: Vec<T>,
}

impl<T> CombinationsFact<T>
where
    T: Number,
{
    #[allow(unused)]
    pub fn new(n: usize) -> Self {
        let fact = gen_facts(n);
        let mut fact_inv = fact.clone();
        assert_eq!(fact_inv.len(), n + 1);
        fact_inv[n] = T::ONE / fact_inv[n];
        for i in (1..n).rev() {
            fact_inv[i] = fact_inv[i + 1] * T::from_i32((i + 1) as i32);
        }
        Self { fact, fact_inv }
    }

    pub fn fact(&self, n: usize) -> T {
        self.fact[n]
    }
}

impl<T> Combinations<T> for CombinationsFact<T>
where
    T: Number,
{
    fn c(&self, n: usize, k: usize) -> T {
        if k > n {
            return T::ZERO;
        }
        self.fact[n] * self.fact_inv[k] * self.fact_inv[n - k]
    }
}
}
pub mod factorials {
use crate::algo_lib::misc::num_traits::Number;

///
/// Generate factorials of all numbers up to `n`
///
pub fn gen_facts<T>(n: usize) -> Vec<T>
where
    T: Number,
{
    let mut res = Vec::with_capacity(n);
    res.push(T::ONE);
    for x in 1..=n {
        let num = T::from_i32(x as i32);
        res.push(*res.last().unwrap() * num);
    }
    res
}
}
pub mod modulo {
use crate::algo_lib::collections::last_exn::LastExn;
use crate::algo_lib::io::input::Input;
use crate::algo_lib::io::input::Readable;
use crate::algo_lib::io::output::Output;
use crate::algo_lib::io::output::Writable;
use crate::algo_lib::misc::num_traits::ConvI32;
use crate::algo_lib::misc::num_traits::HasConstants;
use crate::algo_lib::misc::num_traits::Number;
use std::io::Write;
use std::marker::PhantomData;

pub trait Value: Clone + Copy + Eq + Default + Ord {
    fn val() -> i32;
}

#[derive(Copy, Clone, Eq, PartialEq, Default, Ord, PartialOrd)]
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

    #[allow(unused)]
    pub const TWO: Self = Self(2, PhantomData);

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
    pub fn new<T: Number>(x: T) -> Self {
        let mut x = x.to_i32();
        if x < 0 {
            x += M::val();
            if x < 0 {
                x %= M::val();
                x += M::val();
            }
        } else if x >= M::val() {
            x -= M::val();
            if x >= M::val() {
                x %= M::val();
            }
        }
        assert!(0 <= x && x < M::val());
        Self(x, PhantomData)
    }

    pub fn pown(self, pw: usize) -> Self {
        if pw == 0 {
            Self::ONE
        } else if pw == 1 {
            self
        } else {
            let half = self.pown(pw / 2);
            let res = half * half;
            if pw % 2 == 0 {
                res
            } else {
                res * self
            }
        }
    }

    pub fn gen_powers(base: Self, n: usize) -> Vec<Self> {
        let mut res = Vec::with_capacity(n);
        res.push(Self::ONE);
        for _ in 1..n {
            res.push(*res.last_exn() * base);
        }
        res
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

impl<M> Writable for ModWithValue<M>
where
    M: Value,
{
    fn write(&self, output: &mut Output) {
        output.write_fmt(format_args!("{}", self.0)).unwrap();
    }
}

impl<M> Readable for ModWithValue<M>
where
    M: Value,
{
    fn read(input: &mut Input) -> Self {
        let i32 = input.i32();
        Self::new(i32)
    }
}

impl<M> HasConstants<ModWithValue<M>> for ModWithValue<M>
where
    M: Value,
{
    // This doesn't make much sense, but hope we never use
    const MAX: ModWithValue<M> = ModWithValue::ZERO;
    const MIN: ModWithValue<M> = ModWithValue::ZERO;
    const ZERO: ModWithValue<M> = ModWithValue::ZERO;
    const ONE: ModWithValue<M> = ModWithValue::ONE;
    const TWO: ModWithValue<M> = ModWithValue::TWO;
}

impl<M> ConvI32<ModWithValue<M>> for ModWithValue<M>
where
    M: Value,
{
    fn from_i32(val: i32) -> ModWithValue<M> {
        ModWithValue::new(val)
    }

    fn to_i32(self) -> i32 {
        self.0
    }
}

pub trait ConstValue: Value + Copy {
    const VAL: i32;
}

impl<V: ConstValue> Value for V {
    fn val() -> i32 {
        Self::VAL
    }
}

#[derive(Copy, Clone, Eq, PartialEq, Default, Ord, PartialOrd)]
pub struct Value7();
impl ConstValue for Value7 {
    const VAL: i32 = 1_000_000_007;
}
pub type Mod7 = ModWithValue<Value7>;

#[derive(Copy, Clone, Eq, PartialEq, Default, Ord, PartialOrd)]
pub struct Value9();
impl ConstValue for Value9 {
    const VAL: i32 = 1_000_000_009;
}
pub type Mod9 = ModWithValue<Value9>;

#[derive(Copy, Clone, Eq, PartialEq, Default, Ord, PartialOrd)]
#[allow(non_camel_case_types)]
pub struct Value_998_244_353();
impl ConstValue for Value_998_244_353 {
    const VAL: i32 = 998_244_353;
}
#[allow(non_camel_case_types)]
pub type Mod_998_244_353 = ModWithValue<Value_998_244_353>;

pub trait ModuloTrait: Number {
    fn mod_value() -> i32;
    fn pown(self, n: usize) -> Self;
}

impl<V: Value> ModuloTrait for ModWithValue<V> {
    fn mod_value() -> i32 {
        V::val()
    }

    fn pown(self, n: usize) -> Self {
        self.pown(n)
    }
}
}
pub mod ntt {
// partially copied from https://github.com/EgorKulikov/rust_algo/blob/master/algo_lib/src/numbers/prime_fft.rs
// article: https://cp-algorithms.com/algebra/fft.html#:~:text=and%20their%20powers.-,Number%20theoretic%20transform,-Now%20we%20switch

use crate::algo_lib::math::modulo::ModuloTrait;

pub struct NTT<M>
where
    M: ModuloTrait,
{
    root: M,
    root_power: usize,
}

impl<M> NTT<M>
where
    M: ModuloTrait,
{
    pub fn new() -> Self {
        let root_power = 1 << (M::mod_value() - 1).trailing_zeros();

        let root = (2..)
            .map(M::from_i32)
            .filter(|&root| -> bool {
                root.pown(root_power - 1) != M::ONE && root.pown(root_power) == M::ONE
            })
            .next()
            .unwrap();

        Self { root, root_power }
    }

    pub fn multiply(&self, mut a: Vec<M>, mut b: Vec<M>) -> Vec<M> {
        let result_size = a.len() + b.len() - 1;
        let expected_size = (result_size).next_power_of_two();
        a.resize(expected_size, M::ZERO);
        b.resize(expected_size, M::ZERO);
        self.fft(&mut a, false);
        self.fft(&mut b, false);
        for (x, &y) in a.iter_mut().zip(b.iter()) {
            *x *= y;
        }
        self.fft(&mut a, true);
        a.truncate(result_size);
        a
    }

    fn multiply_all_ref(&self, polynomials: &mut [Vec<M>]) -> Vec<M> {
        if polynomials.len() == 1 {
            polynomials[0].to_vec()
        } else {
            let mid = polynomials.len() / 2;
            let (lhs, rhs) = polynomials.split_at_mut(mid);
            let lhs = self.multiply_all_ref(lhs);
            let rhs = self.multiply_all_ref(rhs);
            self.multiply(lhs, rhs)
        }
    }

    pub fn multiply_all(&self, mut polynomials: Vec<Vec<M>>) -> Vec<M> {
        self.multiply_all_ref(&mut polynomials)
    }

    fn fft(&self, a: &mut [M], invert: bool) {
        assert!(a.len().is_power_of_two());
        let mut j = 0usize;
        for i in 1..a.len() {
            let mut bit = a.len() >> 1;
            while j >= bit {
                j -= bit;
                bit >>= 1;
            }
            j += bit;
            if i < j {
                a.swap(i, j);
            }
        }

        let mut len = 2;
        while len <= a.len() {
            let mut w_len = if invert {
                M::ONE / self.root
            } else {
                self.root
            };
            let mut i = len;
            while i < self.root_power {
                w_len *= w_len;
                i += i;
            }
            let half = len >> 1;
            for i in (0..a.len()).step_by(len) {
                let mut w = M::ONE;
                for j in 0..half {
                    let u = a[i + j];
                    let v = a[i + j + half] * w;
                    a[i + j] = u + v;
                    a[i + j + half] = u - v;
                    w *= w_len;
                }
            }
            len <<= 1;
        }
        if invert {
            let inv_size = M::ONE / M::from_i32(a.len() as i32);
            for i in a {
                *i *= inv_size;
            }
        }
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
}
}
fn main() {
    crate::solution::submit();
}