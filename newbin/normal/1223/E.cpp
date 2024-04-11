#include<bits/stdc++.h>
#define ll long long
#define P pair<int,ll>
using namespace std;
const int maxn = 5e5 + 50;
int n, k;
vector<P> g[maxn];
ll dp[maxn][2];
void init(){
    cin>>n>>k;
    for(int i = 1; i <= n; ++i) g[i].clear();
    for(int i = 1; i < n; ++i){
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(P(v, w));
        g[v].push_back(P(u, w));
    }
}
void dfs(int u, int f){
    ll ans = 0;
    int num = 0;
    vector<ll> t; t.clear();
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i].first;
        ll w = g[u][i].second;
        if(v == f) continue;
        dfs(v,u);
        ans += dp[v][1];
        //cout<<"u:"<<u<<" v:"<<v<<endl;
        t.push_back( dp[v][0] - dp[v][1] + w );
    }
    sort(t.begin(),t.end(), greater<ll>());
    num = t.size();
//    for(int i = 0; i < num; ++i){
//        cout<<"i:"<<i<<" t:"<<t[i]<<endl;
//    }
    dp[u][0] = dp[u][1] = ans;
    for(int i = 0; i < min(num,k-1); ++i){
        dp[u][0] = max(dp[u][0], dp[u][0] + t[i]);
    }
    dp[u][1] = dp[u][0];
    if(k <= num) dp[u][1] += max(t[k-1], 0LL);
    //cout<<"u:"<<u<<" dp0:"<<dp[u][0]<<" dp1:"<<dp[u][1]<<endl;
}
void sol(){
    dfs(1, 1);
    ll ans = max(dp[1][0], dp[1][1]);
    printf("%I64d\n", ans);
}
int main()
{
	int T;cin>>T;
	while(T--){
        init();
        sol();
	}
}