#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-12;
const int N=300010;
const ll mod=998244353;
#define ADD(a,b) a+=b;if (a>=mod) a-=mod
//#define endl '\n'
vector<pair<int,int> >g[N];
int p[N];
int xr[N];
int ind[N];
void dfs(int v,int pr){
    p[v]=pr;
    for (auto cur:g[v]){
        int to=cur.first;
        if (to==pr) continue;
        ind[to]=cur.second;
        dfs(to,v);
    }
}
void solve(){
    ll hc,dc,hm,dm;cin>>hc>>dc>>hm>>dm;
    ll k,h,d;cin>>k>>d>>h;
    for (ll i=0;i<=k;i++){
        ll H=hc+h*i;
        ll D=dc+d*(k-i);
        ll needC=(hm+D-1)/D;
        ll needM=(H+dm-1)/dm;
        if (needC<=needM){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";


}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}