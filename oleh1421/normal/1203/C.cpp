#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
ll a[500001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll g=a[1];
    for (int i=2;i<=n;i++) g=__gcd(g,a[i]);
    int res=0;
    for (ll i=1;i*i<=g;i++){
        if (g%i) continue;
        res++;
        if (i*i<g) res++;
    }
    cout<<res;
    return 0;
}