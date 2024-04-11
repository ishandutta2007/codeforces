#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll s1 = 0;
    ll s2 = 0;
    int r = n;
    ll res = 0;
    for (int l = 0; l < n; l++) {
        s1 += a[l];
        while (s2 < s1) {
            r--;
            s2 += a[r];
        }
        if (s1 == s2 && r > l) {
            res = max(res, s1);
        }
    }
    cout << res << "\n";

}