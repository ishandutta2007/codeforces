#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001ll;
const ll mod=998244353;
using namespace std;
mt19937 rnd(time(NULL));
const int N=100010;
vector<int>g[N],G[N];
ll ans[N];
ll dp[N][2];
int CNT=0;
vector<int>order;
void dfs(int x){
    for (int v:order){
        bool Big=false;
        for (int to:g[v]){
            if (dp[to][1]){
                Big=true;
            }
        }
        if (G[v].size()>=x){
            if (Big){
                vector<int>DP(x,0);
                vector<int>nw_DP(x,0);
                DP[0]=1ll;
                ll mult=1ll;
                int cnt=g[v].size();
                CNT+=x;
                for (int to:g[v]){
                    if (dp[to][1]){
                        nw_DP[0]=(DP[x-1]*dp[to][1]+DP[0]*dp[to][0])%mod;
                        for (int i=1;i<x;i++){
                            nw_DP[i]=(DP[i-1]*dp[to][1]+DP[i]*dp[to][0])%mod;
                        }
                        for (int i=0;i<x;i++){
                            DP[i]=nw_DP[i];
                        }
                    } else {
                        mult*=dp[to][0];
                        mult%=mod;
                    }
                }
                for (int i=0;i<2;i++){
                    dp[v][i]=mult*DP[(cnt+i+x)%x]%mod;
                }
            } else {
                int cnt=g[v].size();
                for (int i=0;i<2;i++){
                    if ((cnt+i)%x==0){
                        dp[v][i]=1;
                        for (int to:g[v]){
                            dp[v][i]=(dp[v][i]*dp[to][0])%mod;
                        }
                    }
                }
            }
        } else {
            dp[v][0]=1;
            dp[v][1]=0;
            for (int to:g[v]){
                dp[v][0]=(dp[v][0]*dp[to][1])%mod;
            }
        }
    }
}
void dfs1(int v,int pr){
    for (int to:G[v]){
        if (to!=pr){
            g[v].push_back(to);
            dfs1(to,v);
        }
    }
    order.push_back(v);
}
void solve(){
    int n;cin>>n;
    order.clear();
    for (int i=1;i<=n;i++) g[i].clear(),G[i].clear();
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i=0;i<=n;i++){
        dp[i][0]=dp[i][1]=ans[i]=0;
    }
    dfs1(1,0);
    for (int x=1;x<=n-1;x++){
        if ((n-1)%x) continue;
        for (int i=0;i<=n;i++){
            dp[i][0]=dp[i][1]=0;
        }
        dfs(x);
        ans[x]=dp[1][0];
    }
    for (int i=n;i>=1;i--){
        for (int j=i*2;j<=n;j+=i){
            ans[i]=(ans[i]-ans[j]+mod)%mod;
        }
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}