#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    vector<ll> minarr = arr;
    ll maxx = 1;
    for (ll i = 0; i < n; ++i) {
        maxx = max(maxx, arr[i] + 1);
        minarr[i] = maxx;
    }
    maxx = minarr[n - 1];
    for (ll i = n - 2; i >= 0; --i) {
        --maxx;
        if (minarr[i] < maxx) minarr[i] = maxx;
        maxx = max(minarr[i], maxx);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += max(0ll, minarr[i] - arr[i] - 1);
    }
    cout << ans;
    return 0;
}