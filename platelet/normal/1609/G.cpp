#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

ll read() {
    const int M = 1e6;
    static streambuf* in = cin.rdbuf();
    #define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
    static char buf[M], *p1, *p2;
    int c = gc; ll r = 0;
    while(c < 48) c = gc;
    while(c > 47) r = r * 10 + (c & 15), c = gc;
    return r;
}
void wrt(ll x) {
    static streambuf* out = cout.rdbuf();
    #define pc out -> sputc
    static char c[20]; int sz = 0;
    do c[++sz] = x % 10, x /= 10; while(x);
    while(sz) pc(c[sz--] + 48);
    pc(10);
}

const int N = (1 << 17) + 5;

int n, m, q;
ll a[105], c[N], C[N], sum;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    rep(i, 1, n) a[i] = read();
    rep(i, 1, m) c[i] = read();
    per(i, n, 2) a[i] -= a[i - 1], sum += a[i] * (n - i + 1);
    per(i, m, 2) c[i] -= c[i - 1], sum += c[i] * (m - i + 1);
    ll A = a[1], B = c[1];
    a[1] = c[1] = 0, sum += (A + B) * (n + m - 1);
    per(i, m, 1) c[i] -= c[i - 1], C[i] = i * c[i];
    For(i, 1, 1 << 17) {
        c[i + (i & -i)] += c[i];
        C[i + (i & -i)] += C[i];
    }
    int t, k, d;
    while(q--) {
        t = read(), k = read(), d = read();
        if(k == (t == 1 ? n : m)) (t == 1 ? A : B) += d, sum += d * (n + m - 1), k--;
        sum += k * (k + 1LL) / 2 * d;
        if(t == 1) rep(i, n - k + 1, n) a[i] += d;
        else {
            k = m - k + 1;
            for(int i = k; i < 1 << 17; i += i & -i)
                c[i] += d, C[i] += (ll)k * d;
        }
        ll ans = sum, tmp[101] = {};
        int k[101] = {};
        for(int j = 1 << 16; j; j >>= 1) rep(i, 1, n)
        if(a[i] > c[k[i] | j] + tmp[i]) k[i] |= j, tmp[i] += c[k[i]], ans -= C[k[i]];
        rep(i, 1, n) k[i] = min(k[i], m), ans += (k[i] + 1) * tmp[i] + a[i] * (m - k[i]);
        wrt(ans);
    }
}