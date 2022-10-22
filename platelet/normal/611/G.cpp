#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

int read() {
    const int M = 1e6;
    static streambuf* in = cin.rdbuf();
    #define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
    static char buf[M], *p1, *p2;
    int c, r = 0, f = 1;
    while((c = gc) < 48) if(c == 45) f = -1;
    while(c > 47) r = r * 10 + (c & 15), c = gc;
    return r * f;
}

const int N = 5e5 + 5, P = 1e9 + 7;

int n;
struct pt {
    int x, y;
    ll operator*(const pt& b)const { return (ll)x * b.y - (ll)y * b.x; }
    __int128 cross(ll bx, ll by) {
        return (__int128)y * bx - (__int128)x * by;
    }
} a[N];
inline int nxt(int i) { return ++i == n ? 0 : i; }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    rep(i, 1, n) a[n - i].x = read(), a[n - i].y = read();
    ll area = 0;
    For(i, 0, n) area += a[i] * a[nxt(i)];
    int j = 0;
    ll x = 0, y = 0, S = 0;
    __int128 sum = 0, ans = 0;
    For(i, 0, n) {
        while(S + a[j] * a[i] <= area >> 1) {
            x += a[j].x, y += a[j].y, sum += S + a[j] * a[i];
            S += a[j] * a[nxt(j)], j = nxt(j);
        }
        ll cnt = j - i - 1;
        if(cnt < 0) cnt += n;
        ans += __int128(cnt - 1) * area - sum * 2;
        x -= a[i].x, y -= a[i].y;
        ll t = a[i] * a[i + 1];
        S -= t, sum -= t * (__int128)cnt;
        sum += a[i + 1].cross(x, y) - a[i].cross(x, y);
    }
    cout << int(ans % P);
}