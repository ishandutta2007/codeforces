#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=500055;
const ll mod=1000000007;
const ll inf=1e18;
void solve(){
    ll n,x,t;cin>>n>>x>>t;
    ll mn=min(t/x,n);

    ll res=(n-mn)*1ll*(mn*1ll);
    res+=mn*(mn-1ll)/2ll;
    cout<<res<<endl;
}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
1
6 6
0 0 0 0 0 0
1 1 1 1 1 1
1 2
2 3
1 3
4 5
5 6
4 6
**/
//k*d-d=2
//d*(k-2)=2
//k>1
//d=2