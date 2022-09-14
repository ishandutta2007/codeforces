//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=301010;
const int L=20;
const ll mod=1000000007;
const int inf=1e9;
vector<int>g[N];
int dp[N];
void dfs(int v,int pr){
    int mn=inf;
    int cnt=0;
    for (int to:g[v]){
        if (to==pr) continue;
        dfs(to,v);
        mn=min(mn,dp[to]);
        cnt++;
    }
    if (cnt==0) dp[v]=1;
    else if (cnt==1)dp[v]=2;
    else dp[v]=mn+2;
}
void solve(int Case){
    int n;cin>>n;
    for (int i=1;i<=n;i++) g[i].clear();
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    cout<<n-dp[1]<<endl;

}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
0 1
1 0 1 0 1 0 1 0 1 0 0 0
9 2 1 4 3 6 5 8 7 10 11 12

C(n-1,(n-1)/2)
 1 1 2 3 6 10 20 35 70 12
dp[i] = (i%2==1 ? dp[i-1]*2 : (dp[i-1]/4)*3);
**/