#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, g, b;
        ll ans;
        cin >> n >> g >> b;
        ll needed = (n+1)/2;
        if ((n/(g+b))*g+min(g,(n%(g+b)))>=needed) {
            ans = n;
        }
        else {
            if (needed%g == 0) {
                ans = needed/g - 1;
                ans *= b+g;
                ans += g;
            }
            else {
                ans = (needed/g)*(g+b) + needed%g;
            }
        }
        cout << ans << endl;
    }

    return 0;
}