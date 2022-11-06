use std::collections::HashSet;
use std::iter::FromIterator;
use std::ops::Range;
use std::rc::Rc;
pub trait LazyParam {
    type S: Clone;
    type F: Clone;
    fn op(a: &Self::S, b: &Self::S) -> Self::S;
    fn e() -> Self::S;
    fn mapping(f: &Self::F, a: &Self::S) -> Self::S;
    fn composition(f: &Self::F, g: &Self::F) -> Self::F;
    fn id() -> Self::F;
}
#[derive(Clone, Copy, Debug)]
enum Color {
    Red,
    Black,
}
use perm::Permutation;
use Color::{Black, Red};

#[derive(Debug)]
struct Node<P: LazyParam> {
    val: P::S,
    lazy: P::F,
    color: Color,
    rank: usize,
    len: usize,
    left: Option<Rc<Node<P>>>,
    right: Option<Rc<Node<P>>>,
}
impl<P: LazyParam> Node<P> {
    fn left(&self) -> &Rc<Self> {
        self.left.as_ref().unwrap()
    }
    fn right(&self) -> &Rc<Self> {
        self.right.as_ref().unwrap()
    }
    fn is_leaf(&self) -> bool {
        self.left.is_none()
    }
    fn reflect(&self) -> P::S {
        P::mapping(&self.lazy, &self.val)
    }
    fn index(&self, index: usize) -> P::S {
        if self.is_leaf() {
            self.reflect()
        } else {
            if index < self.left().len {
                self.left().index(index)
            } else {
                self.right().index(index - self.left().len)
            }
        }
    }
    fn new_leaf(val: P::S) -> Self {
        Self {
            val,
            lazy: P::id(),
            color: Black,
            rank: 0,
            len: 1,
            left: None,
            right: None,
        }
    }
    fn new_parent(lazy: P::F, color: Color, left: Rc<Node<P>>, right: Rc<Node<P>>) -> Self {
        Self {
            val: P::op(&left.reflect(), &right.reflect()),
            lazy,
            color,
            rank: left.rank
                + match left.color {
                    Black => 1,
                    Red => 0,
                },
            len: left.len + right.len,
            left: Some(left),
            right: Some(right),
        }
    }
    fn blacken(tree: &Rc<Self>) -> Rc<Self> {
        match tree.color {
            Red => Rc::new(Self::new_parent(
                tree.lazy.clone(),
                Black,
                Rc::clone(tree.left()),
                Rc::clone(tree.right()),
            )),
            Black => Rc::clone(tree),
        }
    }
    fn propagate(tree: &Rc<Self>, f: &P::F) -> Rc<Self> {
        Rc::new(Self::new_parent(
            P::composition(f, &tree.lazy),
            tree.color,
            Rc::clone(tree.left()),
            Rc::clone(tree.right()),
        ))
    }
    fn push(tree: &Rc<Self>) -> Rc<Self> {
        Rc::new(Self::new_parent(
            P::id(),
            tree.color,
            Self::propagate(tree.left(), &tree.lazy),
            Self::propagate(tree.right(), &tree.lazy),
        ))
    }
    fn merge(left: &Rc<Self>, right: &Rc<Self>) -> Rc<Self> {
        Rc::new(if left.rank < right.rank {
            let right = &Self::push(right);
            let left = &Self::merge(left, right.left());
            match (left.color, left.left().color, right.color) {
                (Red, Red, Black) => match right.right().color {
                    Black => Self::new_parent(
                        P::id(),
                        Black,
                        Rc::clone(left.left()),
                        Rc::new(Self::new_parent(
                            P::id(),
                            Red,
                            Rc::clone(left.right()),
                            Rc::clone(right.right()),
                        )),
                    ),
                    Red => Self::new_parent(
                        P::id(),
                        Red,
                        Rc::new(Self::new_parent(
                            P::id(),
                            Black,
                            Rc::clone(left.left()),
                            Rc::clone(left.right()),
                        )),
                        Self::blacken(right.right()),
                    ),
                },
                _ => Self::new_parent(
                    P::id(),
                    right.color,
                    Rc::clone(left),
                    Rc::clone(right.right()),
                ),
            }
        } else if left.rank > right.rank {
            let left = &Self::push(left);
            let right = &Self::merge(left.right(), right);
            match (left.color, right.right().color, right.color) {
                (Black, Red, Red) => match left.left().color {
                    Black => Self::new_parent(
                        P::id(),
                        Black,
                        Rc::new(Self::new_parent(
                            P::id(),
                            Red,
                            Rc::clone(left.left()),
                            Rc::clone(right.left()),
                        )),
                        Rc::clone(right.right()),
                    ),
                    Red => Self::new_parent(
                        P::id(),
                        Red,
                        Self::blacken(left.left()),
                        Rc::new(Self::new_parent(
                            P::id(),
                            Black,
                            Rc::clone(right.left()),
                            Rc::clone(right.right()),
                        )),
                    ),
                },
                _ => Self::new_parent(
                    P::id(),
                    left.color,
                    Rc::clone(left.left()),
                    Rc::clone(right),
                ),
            }
        } else {
            Self::new_parent(P::id(), Red, Rc::clone(left), Rc::clone(right))
        })
    }
    fn split(tree: &Rc<Self>, index: usize) -> (Rc<Self>, Rc<Self>) {
        let tree = Self::push(tree);
        if index < tree.left().len {
            let (left_left, left_right) = Self::split(tree.left(), index);
            (
                left_left,
                Self::blacken(&Self::merge(&left_right, tree.right())),
            )
        } else if index > tree.left().len {
            let (right_left, right_right) = Self::split(tree.right(), index - tree.left().len);
            (
                Self::blacken(&Self::merge(tree.left(), &right_left)),
                right_right,
            )
        } else {
            (Self::blacken(tree.left()), Self::blacken(tree.right()))
        }
    }
    fn apply(tree: &Rc<Self>, range: Range<usize>, f: &P::F) -> Rc<Self> {
        if range.start >= range.end {
            return Rc::clone(tree);
        }
        if range == (0..tree.len) {
            Self::propagate(tree, f)
        } else {
            let pushed = Self::push(tree);
            Rc::new(Self::new_parent(
                P::id(),
                pushed.color,
                Self::apply(
                    pushed.left(),
                    range.start..range.end.min(pushed.left().len),
                    f,
                ),
                Self::apply(
                    pushed.right(),
                    range.start.saturating_sub(pushed.left().len)
                        ..range.end.saturating_sub(pushed.left().len),
                    f,
                ),
            ))
        }
    }
    fn fold(tree: &Rc<Self>, range: Range<usize>) -> P::S {
        if range.start >= range.end {
            return P::e();
        }
        if range == (0..tree.len) {
            tree.reflect()
        } else {
            let pushed = Self::push(tree);
            P::op(
                &Self::fold(pushed.left(), range.start..range.end.min(pushed.left().len)),
                &Self::fold(
                    pushed.right(),
                    range.start.saturating_sub(pushed.left().len)
                        ..range.end.saturating_sub(pushed.left().len),
                ),
            )
        }
    }
    fn vec(tree: &Rc<Self>, result: &mut Vec<P::S>) {
        if tree.is_leaf() {
            result.push(tree.reflect())
        } else {
            let pushed = Self::push(tree);
            Self::vec(pushed.left(), result);
            Self::vec(pushed.right(), result);
        }
    }
}

pub struct PersistentLazyRBTree<P: LazyParam> {
    root: Option<Rc<Node<P>>>,
}
impl<P: LazyParam> PersistentLazyRBTree<P> {
    fn of(root: Rc<Node<P>>) -> Self {
        Self { root: Some(root) }
    }
    pub fn new() -> Self {
        Self { root: None }
    }
    pub fn len(&self) -> usize {
        self.root.as_ref().map_or(0, |root| root.len)
    }
    pub fn merge(left: &Self, right: &Self) -> Self {
        match (&left.root, &right.root) {
            (None, _) => right.clone(),
            (_, None) => left.clone(),
            (Some(left_node), Some(right_node)) => {
                Self::of(Node::blacken(&Node::merge(left_node, right_node)))
            }
        }
    }
    pub fn split(&self, index: usize) -> (Self, Self) {
        assert!(index <= self.len());
        if index == 0 {
            (Self::new(), self.clone())
        } else if index == self.len() {
            (self.clone(), Self::new())
        } else {
            let (left, right) = Node::split(self.root.as_ref().unwrap(), index);
            (Self::of(left), Self::of(right))
        }
    }
    pub fn insert(&self, index: usize, val: P::S) -> Self {
        assert!(index <= self.len());
        let (ref left, ref right) = self.split(index);
        Self::merge(
            &Self::merge(left, &Self::of(Rc::new(Node::new_leaf(val)))),
            right,
        )
    }
    pub fn erase(&self, index: usize) -> Self {
        assert!(index < self.len());
        let (ref left, ref right) = self.split(index);
        let (_, ref right) = right.split(1);
        Self::merge(left, right)
    }
    pub fn index(&self, index: usize) -> P::S {
        assert!(index < self.len());
        self.root.as_ref().unwrap().index(index)
    }
    pub fn fold(&self, range: Range<usize>) -> P::S {
        assert!(range.end <= self.len());
        assert!(range.end <= self.len());
        self.root
            .as_ref()
            .map_or(P::e(), |root| Node::fold(root, range))
    }
    pub fn apply(&self, range: Range<usize>, f: &P::F) -> Self {
        assert!(range.end <= self.len());
        self.root
            .as_ref()
            .map_or(self.clone(), |root| Self::of(Node::apply(root, range, f)))
    }
    pub fn iter(&self) -> std::vec::IntoIter<P::S> {
        let mut result = Vec::with_capacity(self.len());
        self.root.as_ref().map(|root| Node::vec(root, &mut result));
        result.into_iter()
    }
}
impl<P: LazyParam> Clone for PersistentLazyRBTree<P> {
    fn clone(&self) -> Self {
        Self {
            root: self.root.clone(),
        }
    }
}
impl<P: LazyParam> FromIterator<P::S> for PersistentLazyRBTree<P> {
    fn from_iter<I: IntoIterator<Item = P::S>>(iter: I) -> Self {
        let mut res: Vec<Self> = vec![];
        for item in iter {
            let mut cur = Self::new().insert(0, item);
            while let Some(last) = res.last() {
                if last.len() != cur.len() {
                    break;
                }
                cur = Self::merge(last, &cur);
                res.pop();
            }
            res.push(cur);
        }
        while res.len() >= 2 {
            let right = res.pop().unwrap();
            let left = res.pop().unwrap();
            res.push(Self::merge(&left, &right));
        }
        res.remove(0)
    }
}

use std::error;
use std::fmt;
use std::str::FromStr;

#[non_exhaustive]
#[derive(Debug, PartialEq)]
pub enum Error {
    MissingMatch,
    MissingClosingBrace,
    UnexpectedValue(u8, Option<u8>),
    InvalidUtf8(Vec<u8>),
    PartialUtf8(usize, Vec<u8>),
    Parse(String, &'static str),
}

impl error::Error for Error {}

impl fmt::Display for Error {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        use crate::Error::*;
        use std::str::from_utf8;

        match *self {
            InvalidUtf8(ref raw) => write!(f, "input was not valid utf8: {:?}", raw),
            Parse(ref s, arg) => write!(f, "could not parse {} as target type of {}", s, arg),
            UnexpectedValue(exp, act) => write!(
                f,
                "found value {:?} not matching the pattern value {}",
                act.map(|b| b as char),
                exp as char
            ),
            PartialUtf8(n, ref raw) => write!(
                f,
                "input was only partially valid utf8: \"{}\" followed by {:?}",
                from_utf8(&raw[..n]).unwrap(),
                &raw[n..]
            ),
            MissingMatch => write!(f, "Bad read! format string: did not contain {{}}"),
            MissingClosingBrace => write!(
                f,
                "found single open curly brace at the end of the format string"
            ),
        }
    }
}

pub fn match_next(expected: u8, iter: &mut dyn Iterator<Item = u8>) -> Result<(), Error> {
    let next = iter.next();
    if next != Some(expected) {
        return Err(Error::UnexpectedValue(expected, next));
    }
    Ok(())
}

pub fn parse_capture<T>(
    name: &'static str,
    next: Option<u8>,
    iter: &mut dyn Iterator<Item = u8>,
) -> Result<T, Error>
where
    T: FromStr,
    <T as FromStr>::Err: ::std::fmt::Debug,
{
    static WHITESPACES: &[u8] = b"\t\r\n ";
    let raw: Vec<u8> = match next {
        Some(c) => iter.take_while(|&ch| ch != c).collect(),
        None => iter
            .skip_while(|ch| WHITESPACES.contains(ch))
            .take_while(|ch| !WHITESPACES.contains(ch))
            .collect(),
    };
    match String::from_utf8(raw) {
        Ok(s) => FromStr::from_str(&s).map_err(|_| Error::Parse(s, name)),
        Err(e) => {
            let n = e.utf8_error().valid_up_to();
            let raw = e.into_bytes();
            if n == 0 {
                Err(Error::InvalidUtf8(raw))
            } else {
                Err(Error::PartialUtf8(n, raw))
            }
        }
    }
}

/// ```rust,no_run
/// use text_io::try_read;
///
/// let i: i32 = try_read!("The answer: {}!").unwrap();
/// let i: Result<i32, _> = try_read!("The {}{{}}!", "The answer is 42!".bytes());
/// assert!(i.is_err());
/// ```
///
/// ```rust
/// use text_io::try_read;
///
/// let i: Result<i32, _> = try_read!("The answer is {}!", "The answer is 42!".bytes());
/// assert!(i.is_ok());
///
/// let i: Result<i32, _> = try_read!("The {}{{}}!", "The answer is 42!".bytes());
/// assert!(i.is_err());
/// ```
#[macro_export]
macro_rules! try_read(
    () => { $crate::try_read!("{}") };
    ($text:expr) => {{
        (|| -> std::result::Result<_, $crate::Error> {
            use std::io::Write;
            std::io::stdout().flush().unwrap();
            let __try_read_var__;
            $crate::try_scan!($text, __try_read_var__);
            Ok(__try_read_var__)
        })()
    }};
    ($text:expr, $input:expr) => {{
        (|| -> std::result::Result<_, $crate::Error> {
            use std::io::Write;
            std::io::stdout().flush().unwrap();
            let __try_read_var__;
            $crate::try_scan!($input => $text, __try_read_var__);
            Ok(__try_read_var__)
        })()
    }};
);

/// ```rust,no_run
/// use text_io::try_scan;
///
/// fn parser() -> Result<i32, Box<dyn std::error::Error>> {
///     let i: i32;
///     let text = "The answer is 42!";
///
///     try_scan!(text.bytes() => "The answer is {}!", i);
///
///     assert_eq!(i, 1);
///     Ok(i)
/// }
/// ```
#[macro_export]
macro_rules! try_scan(
    ($pattern:expr, $($arg:expr),*) => {
        use ::std::io::Read;
        $crate::try_scan!(::std::io::stdin().bytes().map(std::result::Result::unwrap) => $pattern, $($arg),*);
    };
    ($input:expr => $pattern:expr, $($arg:expr),*) => {{
        $crate::try_scan!(@impl question_mark; $input => $pattern, $($arg),*)
    }};
    (@question_mark: $($e:tt)+) => {{
        ($($e)+)?
    }};
    (@unwrap: $($e:tt)+) => {{
        ($($e)+).unwrap()
    }};
    (@impl $action:tt; $input:expr => $pattern:expr, $($arg:expr),*) => {{
        #![allow(clippy::try_err)]
        use $crate::{Error, match_next, parse_capture};

        // typesafe macros :)
        let pattern: &'static str = $pattern;
        let stdin: &mut dyn Iterator<Item = u8> = &mut ($input);

        let mut pattern = pattern.bytes();

        $(
            $arg = loop {
                match $crate::try_scan!(@$action: pattern.next().ok_or(Error::MissingMatch)) {
                    b'{' => match $crate::try_scan!(@$action: pattern.next().ok_or(Error::MissingClosingBrace)) {
                        b'{' => $crate::try_scan!(@$action: match_next(b'{', stdin)),
                        b'}' => break $crate::try_scan!(@$action: parse_capture(stringify!($arg), pattern.next(), stdin)),
                        _ => return $crate::try_scan!(@$action: Err(Error::MissingClosingBrace)),
                    },
                    c => $crate::try_scan!(@$action: match_next(c, stdin)),
                }
            };
        )*

        for c in pattern {
            $crate::try_scan!(@$action: match_next(c, stdin))
        }

        format_args!($pattern, $($arg),*);
    }};
);

/// All text input is handled through this macro
#[macro_export]
macro_rules! read(
    ($($arg:tt)*) => {
        $crate::try_read!($($arg)*).unwrap()
    };
);

/// This macro allows to pass several variables so multiple values can be read
#[macro_export]
macro_rules! scan(
    ($text:expr, $($arg:expr),*) => {
        {
            use ::std::io::Read;
            $crate::scan!(::std::io::stdin().bytes().map(std::result::Result::unwrap) => $text, $($arg),*);
        }
    };
    ($input:expr => $pattern:expr, $($arg:expr),*) => {{
        $crate::try_scan!(@impl unwrap; $input => $pattern, $($arg),*)
    }};
);

mod perm {
    pub struct PermutationIterator<T: Ord + Clone> {
        li: Vec<T>,
        is_finished: bool,
    }

    impl<T: Ord + Clone> PermutationIterator<T> {
        pub fn new(mut li: Vec<T>) -> PermutationIterator<T> {
            let is_finished = li.is_empty();
            li.sort();
            PermutationIterator { li, is_finished }
        }
    }

    impl<T: Ord + Clone> Iterator for PermutationIterator<T> {
        type Item = Vec<T>;

        // C++  next_permutation 
        // ref. https://cpprefjp.github.io/reference/algorithm/next_permutation.html
        fn next(&mut self) -> Option<Self::Item> {
            if self.is_finished {
                return None;
            }

            if self.li.len() == 1 {
                self.is_finished = true;
                return Some(self.li.clone());
            }

            let mut i = self.li.len() - 1;
            let res = self.li.clone();

            loop {
                let ii = i;
                i -= 1;
                if self.li[i] < self.li[ii] {
                    let mut j = self.li.len() - 1;
                    while self.li[i] >= self.li[j] {
                        j -= 1;
                    }

                    self.li.swap(i, j);
                    self.li[ii..].reverse();
                    return Some(res);
                }
                if i == 0 {
                    self.li.reverse();
                    self.is_finished = true;
                    return Some(res);
                }
            }
        }
    }

    pub trait Permutation<T: Ord + Clone> {
        fn permutation(self) -> PermutationIterator<T>;
    }

    // Vec<T> 
    // impl <T: Ord + Clone> Permutation<T> for Vec<T> {
    //     fn permutation(self) -> PermutationIterator<T> {
    //         PermutationIterator::new(self)
    //     }
    // }

    // IntoIterator  Permutation 
    impl<T: Ord + Clone, I: IntoIterator<Item = T>> Permutation<T> for I {
        fn permutation(self) -> PermutationIterator<T> {
            PermutationIterator::new(self.into_iter().collect())
        }
    }
}

fn is_prime(n: usize) -> bool {
    let mut i = 2;
    while i * i <= n {
        if n % i == 0 {
            return false;
        }
        i += 1;
    }
    return true;
}
fn main() {
    let t: usize = read!();
    for _ in 0..t {
        let n: i64 = read!();
        println!("{}", (n - 6) / 3);
    }
}