#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <complex>
#include <random>
#include <cassert>
#include <chrono>
#include <functional>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) signed((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

void flush() { cout << flush; }
void flushln() { cout << endl; }
void println() { cout << '\n'; }
template<class T> void print(const T &x) { cout << x; }
template<class T> void read(T &x) { cin >> x; }
template<class T, class ...U> void read(T &x, U& ... u) { read(x); read(u...); }
template<class T, class ...U> void print(const T &x, const U& ... u) { print(x); print(u...); }
template<class T, class ...U> void println(const T &x, const U& ... u) { print(x); println(u...); }

#ifdef DEBUG
    template<class T> string pdbg(const T &x) { stringstream ss; ss << x; return ss.str(); }
    template<class T, class U> string pdbg(const pair<T, U> &p) { return "{" + pdbg(p.f) + "," + pdbg(p.s) + "}"; }
    string pdbg(const string &s) { return "\"" + s + "\""; }
    template<class It> string pdbg(It begin, It end, string d);
    template<class T> string pdbg(const vector<T> &a) { return pdbg(all(a), ""); }
    template<class T> string pdbg(const vector<vector<T>> &a) { return pdbg(all(a), "\n"); }
    template<class T> string pdbg(const vector<vector<vector<T>>> &a) { return pdbg(all(a), "\n\n"); }
    template<class T> string pdbg(const set<T> &a) { return pdbg(all(a), ""); }
    template<class T> string pdbg(const hashset<T> &a) { return pdbg(all(a), ""); }
    template<class T, class U> string pdbg(const map<T, U> &a) { return pdbg(all(a), ""); }
    template<class T, class U> string pdbg(const hashmap<T, U> &a) { return pdbg(all(a), ""); }
    template<class It> string pdbg(It begin, It end, string d) {
        string ans;
        ans += "{";
        if (begin != end) ans += pdbg(*begin++);
        while (begin != end)
            ans += "," + d + pdbg(*begin++);
        ans += "}";
        return ans;
    }
    template<class T> string dbgout(const T &x) { return pdbg(x); }
    template<class T, class... U>
    string dbgout(T const &t, const U &... u) {
        string ans = pdbg(t);
        ans += ", ";
        ans += dbgout(u...);
        return ans;
    }
    #define dbg(...) print("[", #__VA_ARGS__, "] = ", dbgout(__VA_ARGS__)), flushln()
    #define msg(...) print("[", __VA_ARGS__, "]"), flushln()
#else
    #define dbg(...) 0
    #define msg(...) 0
#endif

template<class T, class U> inline bool chmin(T &x, const U& y) { return y < x ? x = y, 1 : 0; }
template<class T, class U> inline bool chmax(T &x, const U& y) { return y > x ? x = y, 1 : 0; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
    assert((mpos += n) <= MAX_MEM);
    return (void *)(mem + mpos - n);
}
inline void operator delete ( void * ) noexcept { } // must have!

#define ull unsigned ll
 
const int P = 64;
const int msk = P - 1;
const int l = 6;
#include <popcntintrin.h>
#include <nmmintrin.h>
 
struct bit {
    vector<ull> a;
    bit() {}
    bit(int sz) {
        a.resize(sz);
    }
    inline void set(ull i) {
        a[i >> l] |= 1ull << (i & msk);
    }
};
 
inline int count(const bit &a, const bit &b) {
    int ans = 0;
    int mn = min(sz(a.a), sz(b.a));
    for (int i = 0; i < mn; ++i)
        ans += _mm_popcnt_u64(a.a[i] & b.a[i]);
    return ans;
}
 
namespace io {
    using namespace std;
    static
    const int buf_size = 4096;
    static unsigned char buf[buf_size];
    static int buf_len = 0, buf_pos = 0;
    inline bool isEof() {
        if (buf_pos == buf_len) {
            buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
            if (buf_pos == buf_len) return 1;
        }
        return 0;
    }
    inline int getChar() {
        return isEof() ? -1 : buf[buf_pos++];
    }
    inline int peekChar() {
        return isEof() ? -1 : buf[buf_pos];
    }
    inline bool seekEof() {
        int c;
        while ((c = peekChar()) != -1 && c <= 32) buf_pos++;
        return c == -1;
    }
    inline void skipBlanks() {
        while (!isEof() && buf[buf_pos] <= 32U) buf_pos++;
    }
    inline int readChar() {
        int c = getChar();
        while (c != -1 && c <= 32) c = getChar();
        return c;
    }
    inline int readUInt() {
        int c = readChar(), x = 0;
        while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
        return x;
    }
    template < class T = int > inline T readInt() {
        int s = 1, c = readChar();
        T x = 0;
        if (c == '-') s = -1, c = getChar();
        else if (c == '+') c = getChar();
        while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
        return s == 1 ? x : -x;
    }
    inline double readDouble() {
        int s = 1, c = readChar();
        double x = 0;
        if (c == '-') s = -1, c = getChar();
        while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
        if (c == '.') {
            c = getChar();
            double coef = 1;
            while ('0' <= c && c <= '9') x += (c - '0') * (coef *= 1e-1), c = getChar();
        }
        return s == 1 ? x : -x;
    }
    inline void readWord(char * s) {
        int c = readChar();
        while (c > 32) * s++ = c, c = getChar();* s = 0;
    }
    inline bool readLine(char * s) {
        int c = getChar();
        while (c != '\n' && c != -1) * s++ = c, c = getChar();* s = 0;
        return c != -1;
    }
    static int write_buf_pos = 0;
    static char write_buf[buf_size];
    inline void writeChar(int x) {
        if (write_buf_pos == buf_size) fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
        write_buf[write_buf_pos++] = x;
    }
    inline void flush() {
        if (write_buf_pos) {
            fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
            fflush(stdout);
        }
    }
    template < class T > inline void writeInt(T x, char end = 0, int output_len = -1) {
        if (x < 0) writeChar('-'), x = -x;
        char s[24];
        int n = 0;
        while (x || !n) s[n++] = '0' + x % 10, x /= 10;
        while (n < output_len) s[n++] = '0';
        while (n--) writeChar(s[n]);
        if (end) writeChar(end);
    }
    inline void writeWord(const char * s) {
        while ( * s) writeChar( * s++);
    }
    inline void writeDouble(double x, int output_len = 0) {
        if (x < 0) writeChar('-'), x = -x;
        int t = (int) x;
        writeInt(t), x -= t;
        writeChar('.');
        for (int i = output_len - 1; i > 0; i--) {
            x *= 10;
            t = std::min(9, (int) x);
            writeChar('0' + t), x -= t;
        }
        x *= 10;
        t = std::min(9, (int)(x + 0.5));
        writeChar('0' + t);
    }
    static struct buffer_flusher_t {
        ~buffer_flusher_t() {
            flush();
        }
    }
    buffer_flusher;
}; using namespace io;

const int N = 6000;
 
signed main() {
    int n = readUInt();
    vector<pii> p(n);
    for (auto &i : p) {
        i.f = readInt();
        i.s = readInt();
    }
    vector<vector<bit>> inside(4, vector<bit>(n));
    for (int i = 0; i < n; ++i)
        for (int md = 0; md < 4; ++md)
            inside[md][i] = bit((i + P - 1) / P);
    ll ans = 0;
    for (int i = 0; i < n; ++i) { 
        for (int j = 0; j < i; ++j) {
            pii v = {p[i].f - p[j].f, p[i].s - p[j].s};
            int ij = (abs(__gcd(v.f, v.s)) - 1) & 3;
            for (int ik = 1; ik < 4; ik += 2)
                ans += count(inside[ik][i], inside[(12 - ij - ik - 3) & 3][j]);
            inside[ij][i].set(j);
        }
    }
    writeInt(ans);
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}