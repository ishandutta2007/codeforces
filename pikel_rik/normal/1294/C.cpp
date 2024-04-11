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

        vector<int> div;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                div.push_back(i);
                if (i != n / i)
                    div.push_back(n / i);
            }
        }

        vector<int> ans;
        for (int i = 0; i < div.size(); i++) {
            for (int j = i + 1; j < div.size(); j++) {
                if (div[i] * (ll)div[j] >= n) continue;
                if (n % (div[i] * div[j]) != 0) continue;
                int num = n / (div[i] * div[j]);
                if (num == 1 or num == div[i] or num == div[j]) continue;
                ans = {div[i], div[j], num};
            }
        }

        if (!ans.empty()) {
            cout << "YES\n"; for (int i : ans) cout << i << " "; cout << "\n";
        } else cout << "NO\n";
    }
    return 0;
}