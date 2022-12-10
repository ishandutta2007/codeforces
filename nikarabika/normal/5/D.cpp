//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

LD xtimeof(LD dx, LD a, LD v0) {
    // at^2 / 2 + v0t - dx = 0
    if (a == 0)
        return dx / v0;
    LD za = .5 * a;
    LD zb = v0;
    LD zc = -dx;
    LD delta = pow(zb, 2) - 4 * za * zc;
    delta = sqrt(delta);
    LD up1 = -zb + delta;
    LD up2 = -zb - delta;
    LD down = 2 * za;
    up1 /= down;
    up2 /= down;
    cerr << dx << ' ' << a << ' ' << v0 << ": " << za << ' ' << zb << ' ' << zc << ": " << delta << ' ' << up1 << ' ' << up2 << endl;
    if (up1 < 0) return up2;
    if (up2 < 0) return up1;
    return min(up1, up2);
}

LD distof(LD v1, LD v2, LD a) {
    return (pow(v2, 2) - pow(v1, 2)) / (2 * a);
}

LD get(LD dx, LD a, LD v0, LD vmax) {
    LD disl = distof(v0, vmax, a);
    if (disl <= dx) {
        cerr << "moving " << disl << "km with rising acc and "
            << dx - disl << "km with const speed" << endl;
        cerr << xtimeof(disl, a, v0) << endl
            << xtimeof(dx - disl, 0, vmax) << endl;
        return xtimeof(disl, a, v0) + xtimeof(dx - disl, 0, vmax);
    }
    return xtimeof(dx, a, v0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout.precision(10);

    LD a, v, l, d, w;
    cin >> a >> v >> l >> d >> w;
    smin(w, v);

    LD disl = distof(0, v, a);
    LD disr = distof(v, w, -a);
    LD ltime, rbegin;
    if (disl + disr < d) {
        cerr << "can reach vmax" << endl;
        cerr << "moving first " << disl << "km with positive accelration" << endl;
        cerr << "moving next " << disr << "km with negative accelration" << endl;
        ltime = xtimeof(disl, a, 0)
            + xtimeof(disr, -a, v)
            + xtimeof(d - (disl + disr), 0, v);
        rbegin = w;
    }
    else {
        cerr << "can NOT reach vmax" << endl;
        LD m;
        {
            LD hi = v;
            LD lo = 0;
            for (int i = 0; i < 1000; i++) {
                LD mid = (lo + hi) / 2;
                LD disl = distof(0, mid, a);
                LD disr = mid < w ? 0 : distof(mid, w, -a);
                if (disl + disr <= d)
                    lo = mid;
                else
                    hi = mid;
            }
            m = lo;
        }
        cerr << "reaching " << m << " as top speed" << endl;
        disl = distof(0, m, a);
        disr = m < w ? 0 : distof(m, w, -a);
        ltime = xtimeof(disl, a, 0)
            + xtimeof(disr, -a, m);
        rbegin = min(m, w);
    }
    cerr << "passed the speed limit point with speed " << rbegin << "km/h in " << ltime << "h" << endl;
    LD ans = ltime + get(l - d, a, rbegin, v);
    cout << fixed << ans << '\n';
    return 0;
}