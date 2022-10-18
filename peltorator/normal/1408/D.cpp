#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    const int N = 1e6 + 239;
    vector<int> maxvals(N, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i] >> d[i];
    }
    vector<int> x(n, 0), y(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] <= c[j] && b[i] <= d[j]) {
                maxvals[c[j] - a[i]] = max(maxvals[c[j] - a[i]], d[j] - b[i] + 1);
            }
        }
    }
    for (int i = N - 2; i >= 0; i--) {
        maxvals[i] = max(maxvals[i + 1], maxvals[i]);
    }
    int ans = 1e9;
    for (int i = 0; i < N; i++) {
        ans = min(ans, i + maxvals[i]);
    }
    cout << ans << endl;
}