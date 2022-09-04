#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100, inf = 1e9 + 100;

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    ll a, b, c, d, e;
    cin >> a >> b >> c >> d;
    ll x = min(a, min(c, d));
    ll ans = x * 256;
    a -= x;
    c -= x;
    d -= x;
    ans += min(a, b) * 32;
    cout << ans;
}