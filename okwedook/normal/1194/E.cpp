#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")
 
#include <stdio.h>
#include <vector>
 
using namespace std;
 
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define f first
#define s second
#define sz(a) signed(a.size())
 
inline bool check(int x, pii a) {
    return a.f <= x && x <= a.s;
}

#define ull unsigned ll
 
const int p = 64;
const int msk = p - 1;
const int l = 6;
int sz;
#include <popcntintrin.h>
#include <nmmintrin.h>
 
struct bit {
    ull *a;
    bit() {
        a = new ull[sz];
        for (ull i = 0; i < sz; ++i) a[i] = 0;
    }
    inline void set(ull i) {
        a[i >> l] |= 1ull << (i & msk);
    }
};
 
inline ull count(const bit &a, const bit &b) {
    ull ans = 0;
    for (ull i = 0; i < sz; ++i)
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
 
signed main() {
    int n = readUInt();
    vector<pair<int, pii>> vert;
    vector<pair<int, pii>> hor;
    while (n--) {
        int x1, y1, x2, y2;
        x1 = readInt();
        y1 = readInt();
        x2 = readInt();
        y2 = readInt();
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        if (x1 == x2) vert.pb({x1, {y1, y2}});
        else hor.pb({y1, {x1, x2}});
    }
    if (sz(hor) < sz(vert)) swap(hor, vert);
    sz = (sz(hor) + p - 1) / p;
    vector<bit> inter(sz(vert));
    for (ull i = 0; i < sz(vert); ++i)
        for (ull j = 0; j < sz(hor); ++j)
            if (check(hor[j].f, vert[i].s) && check(vert[i].f, hor[j].s))
                inter[i].set(j);
    ull ans = 0;
    for (ull i = 0; i < sz(vert); ++i)
        for (ull j = i + 1; j < sz(vert); ++j) {
            ull cnt = count(inter[i], inter[j]);
            ans += cnt * (cnt - 1) / 2;
        }
    writeInt(ans);
    return 0;
}