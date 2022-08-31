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

        vector<int> a(n);
        for (int& i : a) cin >> i;

        vector<int> cnt(30);
        for (int i = 0; i < n; i++) {
            cnt[32 - __builtin_clz(a[i]) - 1]++;
        }

        ll ans = 0;
        for (int i = 0; i < 30; i++) {
            ans += ((ll)cnt[i] * cnt[i] - cnt[i]) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}