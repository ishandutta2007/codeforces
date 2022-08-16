#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int N = 1e5 + 5;

int n, l, a[N];

pair<ld, ld> f(ld t) {
    ld t1 = 0, t2 = 0;

    int speed = 1;
    for (int i = 1; i <= n; i++) {
        if (t <= a[i]) {
            t1 += (t - a[i - 1]) / speed;
            break;
        } else if (t > a[i]) {
            t1 += ((ld)a[i] - a[i - 1]) / speed;
            speed++;
        }
    }
    if (t > a[n]) {
        t1 += (t - a[n]) / speed;
    }

    speed = 1;
    for (int i = n; i >= 1; i--) {
        if (t >= a[i]) {
            t2 += (a[i + 1] - t) / speed;
            break;
        } else {
            t2 += ((ld)a[i + 1] - a[i]) / speed;
            speed++;
        }
    }
    if (t < a[1]) {
        t2 += (a[1] - t) / speed;
    }
    return make_pair(t1, t2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    cout << fixed << setprecision(12);

    while (t--) {
        cin >> n >> l;
        a[0] = 0, a[n + 1] = l;
        for (int i = 1; i <= n; i++) cin >> a[i];

        ld lo = 0, hi = l;
        while (hi - lo > 1e-9) {
            ld mid = (lo + hi) / 2;
            auto [t1, t2] = f(mid);
            if (t1 - t2 <= 0)
                lo = mid;
            else hi = mid;
        }
        cout << f(lo).first << '\n';
    }
    return 0;
}