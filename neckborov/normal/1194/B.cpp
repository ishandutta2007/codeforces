//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int Q;
    cin >> Q;
    while (Q--) {
        int n, m;
        cin >> n >> m;
        vector<char> a(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i * m + j];
            }
        }
        vector<int> q(n);
        int ans = n + m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                q[i] += a[i * m + j] == '.';
            }
        }
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += a[i * m + j] == '.';
            }
            for (int i = 0; i < n; i++) {
                ans = min(ans, cnt + q[i] - (a[i * m + j] == '.'));
            }

        }
        cout << ans << endl;
    }
    return 0;
}