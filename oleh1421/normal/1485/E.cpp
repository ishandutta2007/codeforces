//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const ll mod=1000000007ll;
vector<int>g[N];
int a[N];
vector<int>plast[N];
int d[N];
int p[N];
void dfs(int v,int pr){
    plast[d[v]].push_back(v);
    p[v]=pr;
    for (int to:g[v]){
        if (to!=pr){
            d[to]=d[v]+1;
            dfs(to,v);
        }
    }
}
ll dp[N];
void solve(){
    int n;cin>>n;
    for (int i=0;i<=n;i++){
        p[i]=d[i]=dp[i]=0;
        plast[i].clear();
        g[i].clear();
    }
    for (int i=2;i<=n;i++){
        int pr;cin>>pr;
        g[pr].push_back(i);
        g[i].push_back(pr);
    }
    for (int i=2;i<=n;i++) cin>>a[i];
    d[1]=0;
    dfs(1,0);
    int mx=0;
    for (int i=1;i<=n;i++) mx=max(mx,d[i]);
    dp[1]=0;

    for (int i=1;i<=mx;i++){
        int mx=-1000000001;
        int mn=-mx;
        for (int v:plast[i]){
            mn=min(mn,a[v]);
            mx=max(mx,a[v]);
        }
        for (int v:plast[i]){
            dp[v]=max(dp[v],dp[p[v]]+max(a[v]-mn,mx-a[v]));
        }
        vector<pair<int,int> >u;
        for (int v:plast[i]){
            u.push_back({a[v],v});
        }
        sort(u.begin(),u.end());
        ll MX=-100000000001ll;
        for (auto cur:u){
            int v=cur.second;
            dp[v]=max(dp[v],MX+a[v]);
            MX=max(MX,dp[p[v]]-a[v]);
        }
        MX=0;
        reverse(u.begin(),u.end());
        for (auto cur:u){
            int v=cur.second;
            dp[v]=max(dp[v],MX-a[v]);
            MX=max(MX,dp[p[v]]+a[v]);
        }
//        for (int v:plast[i]){
//            for (int u:plast[i]){
////                if (p[v]!=p[u]){
//                    dp[v]=max(dp[v],dp[p[u]]+abs(a[v]-a[u]));
////                }
//            }
////            cout<<i<<" "<<v<<" "<<dp[v]<<endl;
//        }

    }
    ll res=0;
    for (int i=1;i<=n;i++) res=max(res,dp[i]);
    cout<<res<<endl;

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
/*
1
14
1 1 1 2 3 4 4 5 5 6 7 8 8
2 3 7 7 6 9 5 9 7 3 6 6 5
*/