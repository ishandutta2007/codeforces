#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n;
vector<int> a[N];
int res[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            a[i].clear();
            res[i] = n + 1;
        }
        for (int i = 1; i <= n; i++) {
            int u;
            cin >> u;
            a[u].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            if (a[i].empty()) continue;
            int now = 1;
            int last = 0;
            for (int u : a[i]) {
                now = max(now, u - last);
                last = u;
            }
            now = max(now, n + 1 - last);
            res[now] = min(res[now], i);
        }
        for (int i = 1; i <= n; i++) {
            if (i > 1) res[i] = min(res[i], res[i - 1]);
            if (res[i] > n) cout << -1 << ' ';
            else cout << res[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}