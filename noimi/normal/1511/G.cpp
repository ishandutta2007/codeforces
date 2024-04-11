#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("O3", "unroll-loops", "omit-frame-pointer", "inline", "tree-vectorize", "openmp", "predictive-commoning")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper", "D_GLIBCXX_PARALLEL", "openmp")

#include <bits/stdc++.h>
#pragma region my_template

struct Rep {
    struct I {
        int i;
        void operator++() { ++i; }
        int operator*() const { return i; }
        bool operator!=(I o) const { return i < *o; }
    };
    const int l_, r_;
    Rep(int l, int r) : l_(l), r_(r) {}
    Rep(int n) : Rep(0, n) {}
    I begin() const { return {l_}; }
    I end() const { return {r_}; }
};
struct Per {
    struct I {
        int i;
        void operator++() { --i; }
        int operator*() const { return i; }
        bool operator!=(I o) const { return i > *o; }
    };
    const int l_, r_;
    Per(int l, int r) : l_(l), r_(r) {}
    Per(int n) : Per(0, n) {}
    I begin() const { return {r_ - 1}; }
    I end() const { return {l_ - 1}; }
};

template <class F> struct Fix : private F {
    Fix(F f) : F(f) {}
    template <class... Args> decltype(auto) operator()(Args &&...args) const { return F::operator()(*this, std::forward<Args>(args)...); }
};

template <class T = int> T scan() {
    T res;
    std::cin >> res;
    return res;
}

template <class T, class U = T> bool chmin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T> bool chmax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

#ifndef LOCAL
#define DUMP(...) void(0)
template <int OnlineJudge, int Local> constexpr int OjLocal = OnlineJudge;
#endif

using namespace std;

#define ALL(c) begin(c), end(c)

#pragma endregion

template <typename T = long long, const int sz = 5 * 10000000> struct IO {
    char reader[sz], writer[sz];
    char *now, *now2 = writer;
    IO() {
        reader[fread(reader, sizeof(char), sizeof(char) * sz, stdin)];
        now = reader;
    }
    inline T read() {
        while(*now && *now <= 32) now++;
        if(*now == '-') {
            now++;
            T res = 0;
            while('0' <= *now and *now <= '9') { res = res * 10 + *now++ - '0'; }
            return -res;
        } else {
            T res = 0;
            while('0' <= *now and *now <= '9') { res = res * 10 + *now++ - '0'; }
            return res;
        }
    }
    inline void read(T &res) {
        while(*now && *now <= 32) now++;
        if(*now == '-') {
            now++;
            res = 0;
            while('0' <= *now and *now <= '9') { res = res * 10 + *now++ - '0'; }
            res = -res;
        } else {
            res = 0;
            while('0' <= *now and *now <= '9') { res = res * 10 + *now++ - '0'; }
        }
    }
    inline string read_str() {
        string res;
        while(*now and *now != '\n' and *now != ' ') res += *now++;
        now++;
        return res;
    }
    inline void write(T x, char margin = ' ') {
        if(x == 0) {
            putchar('0');
            putchar(margin);
            return;
        }
        if(x < 0) {
            putchar('-');
            x = -x;
        }
        while(x) {
            *now2 = '0' + x % 10;
            now2++;
            x /= 10;
        }
        do {
            now2--;
            putchar(*now2);
        } while(now2 != writer);
        putchar(margin);
    }
    inline void write_str(string s, char margin = ' ') {
        for(auto c : s) putchar(c);
        putchar(margin);
    }
};
IO<int> io;
inline int read() { return io.read(); }
inline void write(int x) { io.write(x); }

int main() {
    int n = read(), m = read();
    vector<int> a(n);
    for(auto &&e : a) e = read() - 1;
    sort(ALL(a));
    string ans;
    for(int q = read(); q--;) {
        int lo = read() - 1;
        int hi = read() - 1;
        int l = lower_bound(ALL(a), lo) - begin(a);
        int r = upper_bound(ALL(a), hi) - begin(a);
        int x = 0;
        for(int i : Rep(l, r)) x ^= a[i] - lo;
        ans.push_back("AB"[x == 0]);
    }
    io.write_str(ans, '\n');
}