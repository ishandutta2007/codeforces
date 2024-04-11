#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
#define int ll
const int N=500010;
const int L=20;
int a[N][2];
vector<int>g[N];
int dp[N][2];
void dfs(int v,int pr){
    for (int to:g[v]){
        if (to!=pr){
            dfs(to,v);
        }
    }
    for (int i=0;i<2;i++){
        dp[v][i]=0;
        for (int to:g[v]){
            if (to==pr) continue;
            dp[v][i]+=max(dp[to][0]+abs(a[v][i]-a[to][0]),dp[to][1]+abs(a[v][i]-a[to][1]));
        }
    }
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1],g[i].clear();
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    cout<<max(dp[1][0],dp[1][1])<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
4 4 4
1010
1111
0101
1111
**/