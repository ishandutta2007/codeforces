#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int long long
using namespace std;
ll x[200001];
vector<int>g[200001];
ll sum[200001];
ll val[200001];
ll cnt[200001];
ll add(ll a,ll b){
    return (a+b)%1000000007ll;
}
ll mult(ll a,ll b) {return (a*b)%1000000007ll;}
void dfs(int v,int pr){
     sum[v]=val[v];
     cnt[v]=(x[v]==0);
     for (auto to:g[v]){
        if (to!=pr){
            dfs(to,v);
            sum[v]=add(sum[v],sum[to]);
            if (x[to]==0) cnt[v]=add(cnt[v],cnt[to]);
        }
     }
}
ll gcd(ll a,ll b){
   if (a==0) return b;
   if (b==0) return a;
   return __gcd(a,b)*1ll;
}
ll res=0ll;
ll res1=0ll;
ll val1[200001];
ll dp[200001];
void dfs1(int v,int pr,ll cur){
     /*if (x[v]==0) res1=add(cur%1000000007ll,res1);
     else */
        res1=add(mult(cur,val[v]),res1);
     val[v]=val1[v];
     sum[v]=val[v];

     for (auto to:g[v]){
        if (to==pr) continue;
        ll g=gcd(x[to],cur);
        if (g==1ll) res1=add(res1,sum[to]),sum[v]=add(sum[v],sum[to]);
        else {
            if (g){
            x[to]/=g;
            val1[to]=mult(val1[to],(g%1000000007ll));
            }
            dfs1(to,v,g);
            sum[v]=add(sum[to],sum[v]);
        }
     }
}
void dfs2(int v,int pr){
    if (x[v]){
    res1=0;
    dfs1(v,pr,x[v]*1ll);
    dp[v]=res1;
    res=add(res,res1);
    }
    for (auto to:g[v]){
        if (to!=pr){
            dfs2(to,v);
        }
    }
    if (!x[v]){
        for (auto to:g[v]){
            if (to!=pr) dp[v]+=dp[to];
        }
        res=add(res,dp[v]);

    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i],val[i]=1ll,val1[i]=1ll;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    dfs2(1,0);
    cout<<res;
    return 0;
}