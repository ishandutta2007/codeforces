#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() { 
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    ll m = arr[0];
    for (auto &i : arr) {
        m = min(m, i);
    }
    ll p = -100000000;
    ll ans = 100000000;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != m) continue;
        if (p < 0) p = i;
        else {
            ans = min(ans, i - p);
            p = i;
        }
    }
    cout << ans;
    //system("pause");     
    return 0; 
}