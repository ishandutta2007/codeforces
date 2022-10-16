#line 2 "/home/nok0/documents/programming/library/template/header.hpp"
#include <bits/stdc++.h>
#line 3 "/home/nok0/documents/programming/library/template/def_name.hpp"

#define pb        push_back
#define eb        emplace_back
#define SZ(x)     ((int)(x).size())
#define all(x)    (x).begin(), (x).end()
#define rall(x)   (x).rbegin(), (x).rend()
#define popcnt(x) __builtin_popcountll(x)
template<class T = int>
using V = std::vector<T>;
template<class T = int>
using VV = std::vector<std::vector<T>>;
template<class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using int128 = __int128_t;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
#line 3 "/home/nok0/documents/programming/library/template/input.hpp"

template<class T, class U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}
template<class T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
    for (T &i : v) is >> i;
    return is;
}
std::istream &operator>>(std::istream &is, __int128_t &a) {
    std::string s;
    is >> s;
    __int128_t ret = 0;
    for (int i = 0; i < (int)s.length(); i++)
        if ('0' <= s[i] and s[i] <= '9')
            ret = 10 * ret + s[i] - '0';
    a = ret * (s[0] == '-' ? -1 : 1);
    return is;
}
namespace scanner {
void scan(int &a) { std::cin >> a; }
void scan(long long &a) { std::cin >> a; }
void scan(std::string &a) { std::cin >> a; }
void scan(char &a) { std::cin >> a; }
void scan(char a[]) { std::scanf("%s", a); }
void scan(double &a) { std::cin >> a; }
void scan(long double &a) { std::cin >> a; }
template<class T, class U>
void scan(std::pair<T, U> &p) { std::cin >> p; }
template<class T>
void scan(std::vector<T> &a) { std::cin >> a; }
void INPUT() {}
template<class Head, class... Tail>
void INPUT(Head &head, Tail &...tail) {
    scan(head);
    INPUT(tail...);
}
}  // namespace scanner
#define VEC(type, name, size)     \
    std::vector<type> name(size); \
    scanner::INPUT(name)
#define VVEC(type, name, h, w)                                    \
    std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
    scanner::INPUT(name)
#define INT(...)     \
    int __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define LL(...)            \
    long long __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define STR(...)             \
    std::string __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define CHAR(...)     \
    char __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define DOUBLE(...)     \
    double __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define LD(...)              \
    long double __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#line 3 "/home/nok0/documents/programming/library/template/output.hpp"


template<class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
    os << p.first << " " << p.second;
    return os;
}
template<class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &a) {
    for (int i = 0; i < int(a.size()); ++i) {
        if (i) os << " ";
        os << a[i];
    }
    return os;
}
std::ostream &operator<<(std::ostream &dest, __int128_t &value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}
template<class T>
void print(const T a) { std::cout << a << '\n'; }
template<class Head, class... Tail>
void print(Head H, Tail... T) {
    std::cout << H << ' ';
    print(T...);
}
template<class T>
void printel(const T a) { std::cout << a << '\n'; }
template<class T>
void printel(const std::vector<T> &a) {
    for (const auto &v : a)
        std::cout << v << '\n';
}
template<class Head, class... Tail>
void printel(Head H, Tail... T) {
    std::cout << H << '\n';
    printel(T...);
}
void Yes(const bool b = true) { std::cout << (b ? "Yes\n" : "No\n"); }
void No() { std::cout << "No\n"; }
void YES(const bool b = true) { std::cout << (b ? "YES\n" : "NO\n"); }
void NO() { std::cout << "NO\n"; }
#line 2 "/home/nok0/documents/programming/library/template/rep.hpp"

#define foa(v, a)                   for (auto &v : a)
#define repname(a, b, c, d, e, ...) e
#define rep(...)                    repname(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define rep0(x)                     for (int rep_counter = 0; rep_counter < (x); ++rep_counter)
#define rep1(i, x)                  for (int i = 0; i < (x); ++i)
#define rep2(i, l, r)               for (int i = (l); i < (r); ++i)
#define rep3(i, l, r, c)            for (int i = (l); i < (r); i += (c))

#define repsname(a, b, c, ...) c
#define reps(...)              repsname(__VA_ARGS__, reps1, reps0)(__VA_ARGS__)
#define reps0(x)               for (int reps_counter = 1; reps_counter <= (x); ++reps_counter)
#define reps1(i, x)            for (int i = 1; i <= (x); ++i)

#define rrepname(a, b, c, ...) c
#define rrep(...)              rrepname(__VA_ARGS__, rrep1, rrep0)(__VA_ARGS__)
#define rrep0(x)               for (int rrep_counter = (x)-1; rrep_counter >= 0; --rrep_counter)
#define rrep1(i, x)            for (int i = (x)-1; i >= 0; --i)
#line 6 "/home/nok0/documents/programming/library/template/all"
using namespace std;
#line 2 "a.cpp"

int main() {
	INT(n);
	VEC(int, a, n);
	sort(all(a));
	multiset<int> st;
	foa(v, a) st.insert(v);
	int res = 0;
	foa(v, a) {
		while(SZ(st) and *st.begin() <= v) st.erase(st.begin());
		if(SZ(st)) {
			res++;
			st.erase(st.begin());
		}
	}
	print(res);
}