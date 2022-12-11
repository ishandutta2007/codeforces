#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&(-x))
using namespace std;
int n, m;
vector<int> g[20];
ll ans = 0;
ll dp[1<<20][20];
int bin[1<<20];
int main()
{
    for(int i = 1; i < (1<<20); ++i){
        bin[i] = bin[i - lowbit(i)] + 1;
    }
	cin>>n>>m;
	for(int i = 1; i <= n; ++i) g[i].clear();
	while(m--){
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
	}
	for(int i = 0; i < n; ++i) dp[1<<i][i] = 1;

	for(int mask = 1; mask < (1<<n); ++mask){
        int st;
        for(int i = 0; i < n; ++i) {
            if(mask&(1<<i)){
                st = i; break;
            }
        }
        int d = bin[mask];
        for(int u = 0; u < n; ++u){
            if(!(mask&(1<<u))) continue;
            if(d > 1 && u == st) continue;
            for(int i = 0; i < g[u].size(); ++i){
                int v = g[u][i];
                if(v == st){//
                    if(d > 2)   ans += dp[mask][u];
                    continue;
                }
                else if(v < st) continue;
                else if(mask&(1<<v)) continue;
                else{
                    dp[mask|(1<<v)][v] += dp[mask][u];
                }
            }
        }
	}
	ans /= 2;
	cout<<ans<<endl;
}