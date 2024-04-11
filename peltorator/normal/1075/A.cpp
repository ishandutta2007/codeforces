#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >>n;
    ll x, y;
    cin >> x >> y;
    ll val = x + y - 2 - (n - x) - (n - y);
    cout << (val <= 0 ? "White\n" : "Black\n");
}