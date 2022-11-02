#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<pair<ll, ll>, ll> pp;

int main() { 
    ll t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll n;
        cin >> n;
        ll currtime = 0;
        vector<ll> ans(n);
        for (int j = 0; j < n; ++j) {
            ll l, r;
            cin >> l >> r;
            currtime = max(currtime, l);
            if (currtime > r) continue;
            ans[j] = currtime;
            ++currtime;
        }
        for (auto j : ans) cout << j << ' ';
        cout << '\n';
    }
    //system("pause");
    return 0; 
}