#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    ll curr = 0, ans = n * (n - 1) / 2 + n, mx = (1 << k) - 1;
    unordered_map<ll, ll> st = { { 0, 1 } };
    for (auto i : arr) {
        curr ^= i;
        if (st[curr] > st[curr ^ mx]) curr ^= mx;
        ans -= st[curr];
        st[curr]++;
    }
    cout << ans;
    return 0;
}