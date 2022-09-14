//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=300050;
mt19937 rnd(time(NULL));
const ll mod=1000000007;
int a[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    int x=0,y=0;
    for (int i=1;i<=n;i++){
        if (a[i]==a[k]){
            if (i<=k) y++;
            x++;
        }
    }
    ll res=1ll;
    for (ll i=x-y+1;i<=x;i++){
        res*=i;
        res%=mod;
    }
    for (ll i=1;i<=y;i++){
        res*=binpow(i,mod-2);
        res%=mod;
    }
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
/*
1
4 5
3 2 1 2
2 1 2 1
*/