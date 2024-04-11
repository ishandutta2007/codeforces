// ./e-four-points.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

struct pt {
    int x, y;
};
istream& operator>>(istream &in, pt &o) {
    return in >> o.x >> o.y;
}

pt pts[4];

ll calcsingle(int pos[4]) {
    sort(pos, pos + 4);
    ll res = 0, mid = pos[2];
    for (auto i = 0; i < 4; i++)
        res += abs(mid - pos[i]);
    return res;
}

int P[4], xs[4], ys[4];
ll calc(int s) {
    iota(P, P+4, 0);
    ll ans = LLINF;
    do {
        for (auto i = 0; i < 4; i++) {
            xs[i] = pts[P[i]].x;
            ys[i] = pts[P[i]].y;
        }
        xs[1] -= s; xs[3] -= s;
        ys[2] -= s; ys[3] -= s;
        ans = min(ans, calcsingle(xs) + calcsingle(ys));
    } while (next_permutation(P, P+4));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        for (auto i = 0; i < 4; i++)
            cin >> pts[i];

        ll l = 0, r = 1e9+1;
        while (l+1 < r) {
            ll mid = (l+r) / 2;
            if (calc(mid) > calc(mid+1)) l = mid;
            else r = mid;
        }
        // printf("l=%lld cl=%lld cl+1=%lld\n", l,calc(l),calc(l+1));
        cout << min(calc(l), calc(l+1)) << '\n';
    }

    return 0;
}