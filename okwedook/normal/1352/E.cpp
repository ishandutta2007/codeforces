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

#ifdef DEBUG
    template<class T> T to_dbg(T x) { return x; }
    template<class T, class U> string to_dbg(pair<T, U> p) {
        stringstream ss;
        ss << '{' << p.f << ',' << p.s << '}';
        return ss.str();
    }
    string to_dbg(string s) { return "\"" + s + "\""; }
    template<class It> string to_dbg(It begin, It end, string d = "") {
        stringstream ss;
        ss << '{';
        if (begin != end) ss << to_dbg(*begin++);
        while (begin != end)
            ss << "," << d << to_dbg(*begin++);
        ss << '}';
        return ss.str();
    }
    template<class T> string to_dbg(vector<T> a) { return to_dbg(all(a)); }
    template<class T> string to_dbg(set<T> a) { return to_dbg(all(a)); }
    template<class T> string to_dbg(hashset<T> a) { return to_dbg(all(a)); }
    template<class T, class U> string to_dbg(map<T, U> a) { return to_dbg(all(a), "\n"); }
    template<class T, class U> string to_dbg(hashmap<T, U> a) { return to_dbg(all(a), "\n"); }
    void dbgout() { cout << endl; }
    template<class T, class... U>
    void dbgout(T t, U... u) {
        cout << to_dbg(t) << ", ";
        dbgout(u...);
    }
    #define dbg(...) cout << "[" << #__VA_ARGS__ << "] = ", dbgout(__VA_ARGS__);
#else
    #define dbg(...) 0
#endif

template<class T, class U> inline bool chmax(T &x, U y) { return x < y ? x = y, 1 : 0; }
template<class T, class U> inline bool chmin(T &x, U y) { return x > y ? x = y, 1 : 0; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }
void read() {} void print() {} void println() { cout << '\n'; }
template<class T, class ...U> void read(T &x, U& ... u) { cin >> x; read(u...); }
template<class T, class ...U> void print(const T &x, const U& ... u) { cout << x; print(u...); }
template<class T, class ...U> void println(const T &x, const U& ... u) { cout << x; println(u...); }

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

bool can[8001];
int a[8000];

void solve() {
    int n = readUInt();
    int mx = 0;
    for (int i = 0; i < n; ++i) 
        chmax(mx, a[i] = readUInt());
    for (int i = 1; i <= mx; ++i)
        can[i] = false;
    for (int l = 0; l < n; ++l) {
        int sum = a[l];
        for (int r = l + 1; r < n && (sum += a[r]) <= mx; ++r)
            can[sum] = true;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += can[a[i]];
    writeInt(ans);
    writeChar('\n');
}

signed main() {
    FAST; FIXED;
    int t = readUInt();
    while (t--) solve();
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}