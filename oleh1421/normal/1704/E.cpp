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
const ll mod=998244353;
const ll mod1=mod*mod;
const int N=2010;
vector<int>g[N];
ll a[N];
bool go[N];
ll dp[N];
bool used[N];
void dfs(int v){
    used[v]=true;
    if (g[v].empty()){
        dp[v]=1;
        return;
    }
    for (int to:g[v]){
        if (!used[to]) dfs(to);
        dp[v]+=dp[to];
        dp[v]%=mod;
    }
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        used[i]=false;
        dp[i]=0;
        g[i].clear();
    }
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }
    ll res=0ll;
    for (int it=1;;it++){
        for (int i=1;i<=n;i++){
            go[i]=(a[i]>0);
        }
        bool ok=true;
        for (int i=1;i<=n;i++){
            for (int j:g[i]){
                if (go[i] && !go[j]){
                    ok=false;
                }
            }
        }
        if (ok) break;
        for (int i=1;i<=n;i++){
            if (go[i]){
                a[i]--;
                for (int j:g[i]){
                    a[j]++;
                }
            }
        }
        res++;

    }
    for (int i=1;i<=n;i++){
        if (!used[i]) dfs(i);
        res+=a[i]*dp[i];
        res%=mod;
    }
    cout<<res<<'\n';




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
1
3 2
1 1 1
1 2
2 3

**/