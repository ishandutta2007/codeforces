#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

vector<array<int, 3>> a(8);

ll dist(array<int, 3> x, array<int, 3> y) {
    return (ll)(x[0] - y[0]) * (x[0] - y[0]) + (ll)(x[1] - y[1]) * (x[1] - y[1]) + (ll)(x[2] - y[2]) * (x[2] - y[2]);
}

void recurse(int i) {
    if (i == 8) {
        ll side = LLONG_MAX;

        for (int j = 0; j < 8; j++) {
            for (int k = j + 1; k < 8; k++) {
                side = min(side, dist(a[j], a[k]));
            }
        }

        if (side == 0) {
            return;
        }

        for (int j = 0; j < 8; j++) {
            int c1 = 0, c2 = 0, c3 = 0;
            for (int k = 0; k < 8; k++) {
                if (dist(a[j], a[k]) == side)
                    c1++;
                else if (dist(a[j], a[k]) == 2 * side)
                    c2++;
                else if (dist(a[j], a[k]) == 3 * side)
                    c3++;
            }

            if (c1 != 3 or c2 != 3 or c3 != 1) {
                return;
            }
        }

        cout << "YES\n";
        for (int j = 0; j < 8; j++) {
            cout << a[j][0] << ' ' << a[j][1] << ' ' << a[j][2] << '\n';
        }
        exit(0);
    }
    do {
        recurse(i + 1);
    } while (next_permutation(a[i].begin(), a[i].end()));
    sort(a[i].begin(), a[i].end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (auto& p : a) {
        cin >> p[0] >> p[1] >> p[2];
        sort(p.begin(), p.end());
    }

    recurse(0);
    cout << "NO\n";
    return 0;
}