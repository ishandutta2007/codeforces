#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        int sum = accumulate(a.begin(), a.end(), 0);

        if (sum % n != 0) {
            cout << "-1\n";
            continue;
        }

        int target = sum / n;
        vector<pair<pair<int, int>, int>> ans;

        for (int i = 2; i <= n; i++) {
            if (a[i] % i != 0) {
                ans.emplace_back(make_pair(1, i), i - a[i] % i);
                a[i] += i - a[i] % i;
            }
            ans.emplace_back(make_pair(i, 1), a[i] / i);
        }

        for (int i = 2; i <= n; i++) {
            ans.emplace_back(make_pair(1, i), target);
        }

        cout << ans.size() << '\n';
        for (auto& p : ans) {
            cout << p.first.first << ' ' << p.first.second << ' ' << p.second << '\n';
        }
    }
    return 0;
}