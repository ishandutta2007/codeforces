#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

#ifndef local
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

using namespace std;
using ll = long long;

const int N = 6000 + 5;

int n, m, q, a, b, x[N];
double p[N], y[N];

struct {
    double l, a, b;
    inline double at(double x) { return 2 * a * x + b; }
    inline double top() { return -b / (a + a); }
    inline void mov(auto rhs, double s) {
        l = rhs.l + s, a = rhs.a, b = rhs.b - 2 * a * s;
    }
} f[N << 1];
template<int cnt> void mov(int k) {
    m += cnt, k += cnt;
    per(i, m + 1, k) f[i].mov(f[i - cnt], b);
}
double ins() {
    rep(i, 1, m) {
        double sl = f[i].at(f[i].l), sr = f[i].at(f[i + 1].l);
        if(sr <= 0) continue;
        if(sl >= 0) {
            mov<1>(i), f[i].a = f[i].b = 0;
            return f[i].l;
        } else {
            mov<2>(i);
            double top = f[i].top();
            f[i + 1] = {top}, f[i + 2].l = top + b;
            return top;
        }
    }
    m++, f[m + 1].l = f[m].l + b, f[m].a = f[m].b = 0;
    return f[m].l;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q >> a >> b, b -= a;
    f[m = 1] = {-q}, f[2] = {q};
    rep(i, 1, n) {
        cin >> x[i], x[i] -= i * a, p[i] = ins();
        double l = 1 - i * a, r = q - i * a;
        rep(j, 1, m) f[j].a++, f[j].b -= 2 * x[i], f[j].l = min(max(f[j].l, l), r);
        f[m + 1].l = min(f[m + 1].l, r);
    }
    double now = ins(), ans = 0;
    per(i, n, 1) {
        y[i] = now + i * a, ans += (now - x[i]) * (now - x[i]);
        if(now >= p[i]) now = max(now - b, p[i]);
    }
    cout.setf(ios::fixed), cout.precision(10);
    rep(i, 1, n) cout << y[i] << ' ';
    cout << '\n' << ans << '\n';
}