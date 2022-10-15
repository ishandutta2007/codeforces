#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(),v.end());
        ll g = 0;
        for (int i = 0; i+1 < n; i++) {
            g = gcd(g,v[i+1]-v[i]);
        }
        if (abs(v[0]-k)%g == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}