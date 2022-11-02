#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
 
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
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

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
    inline ll readULong() {
        int c = readChar();
        ll x = 0;
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
 
ll solve(ll r, ll lcm, ll b) {
    ll x = r / lcm;
    ll ans = b * x;
    ans += min(b, r - lcm * x);
    return ans;
}
 
void solve() {
    int a = readUInt(), b = readUInt(), q = readUInt();
    if (a > b) swap(a, b);
    int lcm = a * b / __gcd(a, b);
    while (q--) {
        ll l = readULong(), r = readULong();
        ll ans = solve(r + 1, lcm, b) - solve(l, lcm, b);
        ans = (r - l + 1) - ans;
        writeInt(ans);
        writeChar(' ');
    }
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