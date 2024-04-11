#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 3e5 + 77;
int qpow(int x, int y) {
    int res = 1;
    for(; y; x *= x, y >>= 1) if(y & 1) res *= x;
    return res;
}
inline char gc() {
    static char buf[1048576], *p1, *p2;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1048576, stdin),
    p1 == p2) ? EOF : *p1++;
}
inline int read() {
    char ch = gc(); int r = 0, w = 1;
    for (; ch < '0' || ch > '9'; ch = gc()) if (ch == '-') w = -1;
    for (; '0' <= ch && ch <= '9'; ch = gc()) r = r * 10 + (ch - '0');
    return r * w;
}
int n, mx, a[N], vis[N], g;
int mu[N], p[N >> 3], tot;
bool Prime[N];
void xxs(int x) {
    mu[1] = 1;
    L(i, 2, x) {
        if(!Prime[i]) p[++tot] = i, mu[i] = -1;
        for(int j = 1; p[j] * i <= x && j <= tot; ++j) {
            Prime[p[j] * i] = true;
            if(i % p[j] == 0) {
                mu[p[j] * i] = 0;
                break ;
            }
            mu[p[j] * i] = -mu[i];
        }
    }
}
int pw[N][3], cur[N], cnt;
int check(int o) {
    int ret = 0;
    L(i, 1, mx) if(mu[i]) ret += mu[i] * pw[i][o] * cur[i];
    return ret;
}
int main () {
    n = read();
    L(i, 1, n) {
        a[i] = read();
        g = __gcd(g, a[i]);
        if(a[i] == 1) ++cnt;
        vis[a[i]] = true;
        mx = max(mx, a[i]);
    }
    if(g > 1) {
        cout << -1 << '\n';
        return 0;
    }
    if(cnt) {
    	cout << 1 << '\n';
    	return 0;
	}
    xxs(mx);
    L(i, 1, tot)
        R(j, mx / p[i], 1)
            vis[j] += vis[j * p[i]];
    L(i, 1, mx) {
        pw[i][0] = vis[i], cur[i] = 1;
        L(j, 1, 2) pw[i][j] = pw[i][j - 1] * pw[i][j - 1];
    }
    int ns = 0;
    R(i, 2, 0)
        if(!check(i)) {
            ns |= 1 << i;
            L(j, 1, mx) cur[j] *= pw[j][i];
        }
    ns += 1;
    cout << ns << '\n';
    return 0;
}