#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<int> nums;
                nums.push_back(a[i][j]);
                nums.push_back(a[n - i - 1][j]);
                nums.push_back(a[i][m - j - 1]);
                nums.push_back(a[n - i - 1][m - j - 1]);
                sort(nums.begin(), nums.end());
                ll temp = 0;
                for (int x : nums) {
                    temp += abs(x - nums[1]);
                }
                ans += temp;
            }
        }
        cout << ans / 4 << '\n';
    }
    return 0;
}