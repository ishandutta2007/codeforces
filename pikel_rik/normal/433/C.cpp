#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 9;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, m, a[N];
vector<int> v[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];

    m = unique(a, a + m) - a;

    if (m == 1) {
        cout << "0\n";
        return 0;
    }

    ll sum = 0;
    for (int i = 1; i < m; i++) {
        sum += abs(a[i] - a[i - 1]);
    }

    v[a[0]].push_back(a[1]);
    for (int i = 1; i < m - 1; i++) {
        v[a[i]].push_back(a[i - 1]);
        v[a[i]].push_back(a[i + 1]);
    }
    v[a[m - 1]].push_back(a[m - 2]);

    ll ans = sum;
    for (int i = 1; i <= n; i++) {
        if (!v[i].empty()) {
            sort(v[i].begin(), v[i].end());
            int median = v[i][v[i].size() / 2];

            ll cont = 0;
            for (int x : v[i]) {
                cont += abs(x - i);
            }

            ll now = 0;
            for (int x : v[i]) {
                now += abs(x - median);
            }

            ans = min(ans, sum - cont + now);
//            cout << i << ' ' << cont << ' ' << now << '\n';
        }
    }
    cout << ans << '\n';
    return 0;
}