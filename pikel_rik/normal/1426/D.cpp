#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll sum = 0;
    int cur = 0, ans = 0;

    map<ll, int> mp;
    mp[0] = 0;

    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (mp.count(sum) and cur <= mp[sum] + 1) {
            ans++;
            cur = i;
        }
        mp[sum] = i;
    }
    cout << ans << '\n';
    return 0;
}