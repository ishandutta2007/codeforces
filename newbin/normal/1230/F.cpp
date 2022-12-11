#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 1e5 + 50;
ll out[maxn];
vector<int> g[maxn];
int n, m;
int main()
{
	cin>>n>>m;
	while(m--){
        int u, v; scanf("%d%d", &u, &v);
        if(u < v) swap(u, v);
        out[u]++; g[v].push_back(u);
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i) ans += g[i].size()*out[i];
	printf("%I64d\n", ans);
	int q; cin>>q;
	while(q--){
        int v; scanf("%d", &v);
        ans -= g[v].size()*out[v];
        for(int i = 0; i < g[v].size(); ++i){
            int u = g[v][i];
            out[u]--;
            ans -= g[u].size();
            ans += out[u];
            g[u].push_back(v);
        }
        out[v] += g[v].size();
        g[v].clear();
        printf("%I64d\n", ans);
	}
}