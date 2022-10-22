#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

int q, a[500005], buc[305][305];

int read() {
    const int M = 1e6;
    static streambuf* in = cin.rdbuf();
    #define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
    static char buf[M], *p1, *p2;
    int c = gc, r = 0, f = 1;
    for(; c < 48; c = gc) if(c == 45) f = -1;
    while(c > 47) r = r * 10 + (c & 15), c = gc;
    return r * f;
}
void wrt(int x) {
    static streambuf* out = cout.rdbuf();
    #define pc out -> sputc
    static char c[11]; int sz = 0;
    if(x < 0) pc(45), x = -x;
    do c[++sz] = x % 10, x /= 10; while(x);
    while(sz) pc(c[sz--] + 48);
    pc(10);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> q;
    while(q--) {
        int t = read(), x = read(), y = read();
        if(t == 1) {
            a[x] += y;
            rep(i, 1, 300) buc[i][x % i] += y;
        } else if(x <= 300) wrt(buc[x][y]);
        else {
            int ans = 0;
            for(int i = y; i <= 500000; i += x) ans += a[i];
            wrt(ans);
        }
    }
}