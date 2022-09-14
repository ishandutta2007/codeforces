//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC opitmize ("trapv")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=100010;
const int L=20;
int a[N];
ll cnt[N][L+3];
ll dp[N];
ll sz[N];
vector<int>g[N];
void dfs(int v,int pr){
    sz[v]=1;
    dp[v]=a[v];
    for (int i=0;i<=L;i++){
        if (a[v]&(1<<i)) cnt[v][i]++;
    }
    for (auto to:g[v]){
        if (to==pr) continue;
        dfs(to,v);
        dp[v]+=dp[to];
        for (int i=0;i<=L;i++){
            dp[v]+=((cnt[v][i]*(sz[to]-cnt[to][i])+(sz[v]-cnt[v][i])*cnt[to][i]))*(1ll<<i);
        }
        sz[v]+=sz[to];

        for (int i=0;i<=L;i++) {
            if (a[v]&(1<<i)) cnt[v][i]+=(sz[to]-cnt[to][i]);
            else cnt[v][i]+=cnt[to][i];
        }
    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    cout<<dp[1];
    return 0;
}