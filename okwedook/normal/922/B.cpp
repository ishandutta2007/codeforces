#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll a = 1; a <= n; ++a) 
        for (ll b = a; b <= n; ++b) {
            ll c = a xor b;
            if (c > b && c <= n && a + c > b && a + b > c && b + c > a) ++ans;
        }
    cout << ans;
    //system("pause");
    return 0;
}