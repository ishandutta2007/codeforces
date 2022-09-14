//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
#define int ll
const int N=500105;
const ll inf=2e18;
const ll mod=998244353;

int n,m;
ll k;
vector<int>g[N];
int a[N];
int dp[N];
bool cyc=false;
int used[N];
void dfs(int v,int x){
    dp[v]=1;
    used[v]=1;
    for (int to:g[v]){
        if (a[to]>x) continue;
        if (!used[to]){
            dfs(to,x);
            dp[v]=max(dp[v],dp[to]+1);
        } else if (used[to]==1) {
            cyc=true;
        } else {
            dp[v]=max(dp[v],dp[to]+1);
        }

    }
    used[v]=2;
}
bool ok(int x){
    cyc=false;
    for (int i=1;i<=n;i++){
        used[i]=0;
        dp[i]=0;
//        if (a[i]>x) used[i]=2;
    }

    for (int i=1;i<=n;i++){
        if (!used[i] && a[i]<=x){
            dfs(i,x);
        }
    }
    if (cyc) return true;
    for (int i=1;i<=n;i++){
        if (dp[i]>=k) return true;
    }
    return false;
}
void solve(int Case){
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }

    int L=a[1],R=a[1];
    for (int i=2;i<=n;i++){
        L=min(L,a[i]);
        R=max(R,a[i]);
    }
    while (R-L>1){
        int mid=(L+R)/2;
        if (ok(mid)) R=mid;
        else L=mid;
    }
    if (!ok(R)){
        cout<<-1<<endl;
        return;
    }
    if (!ok(L)){
        cout<<R<<endl;
    } else {
        cout<<L<<endl;
    }


}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**

**/