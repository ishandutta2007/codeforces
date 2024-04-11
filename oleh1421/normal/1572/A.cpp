//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define int ll
#define endl '\n'
const int N=1000100;
const ll mod=998244353;
const ll inf=1000000000000000000;
int dp[N];
vector<int>g[N];
int used[N];
bool CYC=false;
void dfs(int v){
    used[v]=1;
    dp[v]=1;
    for (int to:g[v]){
        if (used[to]==1){
            CYC=true;
        } else {
            if (!used[to]) dfs(to);
            dp[v]=max(dp[v],dp[to]+(v<to));
        }
    }
    used[v]=2;
}
void solve(){
    CYC=false;
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        g[i].clear();
        dp[i]=0;
        used[i]=0;
        int k;cin>>k;
        for (int j=0;j<k;j++){
            int x;cin>>x;
            g[i].push_back(x);
        }
    }
    for (int i=1;i<=n;i++){
        if (!used[i]) dfs(i);
    }
    if (CYC) cout<<-1<<endl;
    else {

        int res=0;
        for (int i=1;i<=n;i++) res=max(res,dp[i]);
        cout<<res<<endl;
    }
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
//1 3 3 4
//0 1 2 3