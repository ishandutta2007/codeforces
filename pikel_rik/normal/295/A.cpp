#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

ll n, m, k, a[N], q[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, pair<int, int>>> c(m);

    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d; --l; --r;
        c[i] = {l, {r, d}};
    }

    while (k--) {
        int x, y;
        cin >> x >> y; --x; --y;
        q[x] += 1;
        q[y+1] -= 1;
    }

    for (int i = 1; i < m; i++) {
        q[i] += q[i - 1];
    }

    for (int i = 0; i < m; i++) {
        b[c[i].first] += q[i] * c[i].second.second;
        b[c[i].second.first + 1] -= q[i] * c[i].second.second;
    }

    for (int i = 1; i < n; i++)
        b[i] += b[i-1];

    for (int i = 0; i < n; i++) {
        cout << a[i] + b[i] << " ";
    }
    return 0;
}