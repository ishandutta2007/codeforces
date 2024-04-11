//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///use char if you want a naive algorithm to pass
#include <bits/stdc++.h>
//#include <vector>
#define endl '\n'
typedef long long ll;
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll x;cin>>x;
    ll a=1ll;
    for (ll i=2ll;i*i<x;i++){
        if (x%i) continue;
        if (__gcd(i,x/i)==1ll) a=i;
    }
    cout<<a<<" "<<x/a;

    return 0;
}