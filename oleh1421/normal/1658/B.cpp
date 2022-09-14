#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const ll mod=998244353;
const int L=20;
const ll inv2=(mod+1)/2;


void solve(){
    int n;cin>>n;
    if (n%2){
        cout<<0<<endl;
        return;
    }
    ll res=1ll;
    for (int i=1;i<=n/2;i++){
        res*=i;
        res%=mod;
    }
    res*=res;
    res%=mod;
    cout<<res<<endl;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//2


//
//1 2

/**

**/