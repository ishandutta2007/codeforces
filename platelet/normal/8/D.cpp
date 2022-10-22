#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using pt = complex<double>;

const double eps = 1e-12;

double t1, t2;
pt a, b, c;
vector<pt> v;

pt read() {
    int x, y;
    cin >> x >> y;
    return {x, y};
}
void calc(pt a, double ra, pt b, double rb) {
    auto d = abs(a - b);
    if(abs(d - ra - rb) < eps) return v.pb((a * rb + b * ra) / d);
    auto c = (ra * ra + d * d - rb * rb) / (ra * d * 2);
    if(abs(c) > 1) return;
    auto s = sqrt(1 - c * c);
    pt r = ra / d * pt(c, s);
    v.pb((b - a) * r + a), v.pb((b - a) * conj(r) + a);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t1 >> t2, a = read(), b = read(), c = read();
    t2 += abs(a - b), t1 += abs(a - c);
    if(auto x = abs(a - c) + abs(b - c); x <= t2) printf("%.9lf\n", min(t1 + abs(b - c), t2)), exit(0);
    double l = 0, r = 1000;
    rep(kase, 1, 30) {
        auto ra = (l + r) / 2, rb = t2 - ra, rc = t1 - ra;
        v.clear(), v.pb(a), v.pb(b), v.pb(c);
        calc(a, ra, b, rb), calc(b, rb, c, rc), calc(a, ra, c, rc);
        bool ok = 0;
        for(auto x : v) ok |= abs(x - a) <= ra + eps && abs(x - b) <= rb + eps && abs(x - c) <= rc + eps;
        ok ? l = ra : r = ra;
    }
    printf("%.9lf\n", l);
}