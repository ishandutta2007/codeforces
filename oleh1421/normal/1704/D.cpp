//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define y2 y_2
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const ll inf=2e18;
const ll mod=1000000007;
const ll mod1=mod*mod;
const int N=2000100;
vector<vector<ll> >c;
ll val[N];
void solve(){
    int n,m;cin>>n>>m;
    c.resize(n);
    ll mx=-inf;
    for (int i=0;i<n;i++){
        c[i].resize(m);
        for (int j=0;j<m;j++) cin>>c[i][j];
        ll sum=0;
        for (int j=1;j<m;j++){
            c[i][j]+=c[i][j-1];
        }
        for (int j=0;j<m;j++){
            sum+=c[i][j];
        }
        val[i]=sum;
        mx=max(mx,sum);
    }
    for (int i=0;i<n;i++){
        if (val[i]<mx){
            cout<<i+1<<" "<<mx-val[i]<<'\n';
            return;
        }
    }

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}
//CRES
/**
2 3
1 2
2 1
0 0

**/