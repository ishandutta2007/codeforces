#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<ll, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

ll f(ll x, ll y){
    return max(0ll, x - y);
}

int main(){
    fastIO;
    ll p[3], d;
    cin >> p[0] >> p[1] >> p[2] >> d;
    sort(p, p + 3);
    ll res = f(p[0], p[1] - d) + f(p[1] + d, p[2]);
    res = min(res, f(p[0] + d, p[1]) + f(max(p[0] + d, p[1]) + d, p[2]));
    res = min(res, f(p[1], p[2] - d) + f(p[0], min(p[1], p[2] - d) - d));
    cout << res << "\n";
    return 0;
}