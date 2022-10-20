#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int n;
long long a[N];
vector<tuple<int, int, long long>> res;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        res.clear();
        cin >> n;
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % n) {
            cout << -1 << '\n';
            continue;
        }
        sum /= n;
        for (int i = 2; i <= n; i++) {
            int have = a[i] % i;
            if (have != 0) have = i - have;
            if (have) {
                res.push_back({1, i, have});
            }
            a[i] += have;
            res.push_back({i, 1, a[i] / i});
        }
        for (int i = 2; i <= n; i++) {
            res.push_back({1, i, sum});
        }
        cout << res.size() << '\n';
        for (auto val : res) {
            int u, v, w;
            tie(u, v, w) = val;
            cout << u << ' ' << v << ' ' << w << '\n';
        }
    }
    return 0;
}