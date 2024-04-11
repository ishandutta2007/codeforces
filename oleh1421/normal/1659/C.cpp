//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const int N=500010;
const int K=155;
const ll inf=1000000000000000001;
const ll mod=998244353;
ll x[N];
ll pref[N];
void solve(){
    ll n,a,b;cin>>n>>a>>b;
    for (int i=1;i<=n;i++) cin>>x[i],pref[i]=pref[i-1]+x[i];
    x[0]=0;
    ll res=inf;
    for (int i=0;i<=n;i++){
        ll cur=x[i]*(a+b);
        cur+=((pref[n]-pref[i])-x[i]*(n-i))*b;
        res=min(res,cur);
    }
    cout<<res<<endl;



}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
4 0
0 0 0 1

**/