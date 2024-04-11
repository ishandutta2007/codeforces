#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

ll root(ll a) {
    ll l = 0, r = a;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (m * m > a) r = m;
        else l = m;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    vector<ll> sqrtarr(n);
    vector<ll> nsqrtarr(n);
    for (ll i = 0; i < n; ++i) {
        ll temp = root(arr[i]);
        sqrtarr[i] = min(arr[i] - temp * temp, (temp + 1) * (temp + 1) - arr[i]);
        if (arr[i] == 0) nsqrtarr[i] = 2;
        else if (sqrtarr[i] == 0) nsqrtarr[i] = 1;
        else nsqrtarr[i] = 0;
    }
    ll count = 0;
    for (ll i = 0; i < n; ++i)
        count += (sqrtarr[i] == 0);
    ll ans = 0;
    if (count < n / 2) {
        sort(sqrtarr.begin(), sqrtarr.end());
        count = n / 2 - count;
        for (int i = 0; i < n && count > 0; ++i) {
            if (sqrtarr[i] == 0) continue;
            else {
                --count;
                ans += sqrtarr[i];
            }
        }
    } else if (count > n / 2) {
        sort(nsqrtarr.begin(), nsqrtarr.end());
        count = count - n / 2;
        for (int i = 0; i < n && count > 0; ++i) {
            if (nsqrtarr[i] == 0) continue;
            else {
                --count;
                ans += nsqrtarr[i];
            }
        }
    }
    cout << ans;
    //system("pause");
    return 0;
}