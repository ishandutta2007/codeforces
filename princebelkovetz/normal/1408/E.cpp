#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353;

vector <int> p;

int get(int a) {
    return p[a] = p[a] == a ? a : get(p[a]);
}

bool unite(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    p[a] = b;
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int m, n; cin >> m >> n;
    vector <int> a(m), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    vector <vector <int>> e;
    p.resize(n + m);
    for (int i = 0; i < n + m; ++i)
        p[i] = i;

    for (int i = 0; i < m; ++i) {
        int k; cin >> k;
        while (k --> 0) {
            int x; cin >> x;
            e.push_back({ a[i] + b[x - 1], i, m + x - 1 });
        }
    }

    sort(e.rbegin(), e.rend());

    int ans = 0;

    for (auto& x : e) {
        if (!unite(x[1], x[2])) ans += x[0];
    }

    cout << ans << '\n';

    return 0;
}