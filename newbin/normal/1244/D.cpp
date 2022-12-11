#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 1e5 + 50;
vector<int> g[maxn];
int n;
ll c[maxn][3];
int du[maxn];
ll dp[maxn][6];
int dfn[maxn];
int tot = 0;
void dfs(int u, int f){
    dfn[++tot] = u;
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(v == f) continue;
        dfs(v, u);
    }
}
int a[maxn], b[maxn];
int cc[maxn];
int main()
{
	cin>>n;
	for(int i = 1; i <= n; ++i) scanf("%I64d", &c[i][0]);
	for(int i = 1; i <= n; ++i) scanf("%I64d", &c[i][1]);
	for(int i = 1; i <= n; ++i) scanf("%I64d", &c[i][2]);
	int ok = 1;
	for(int i = 1; i < n; ++i){
            int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v); g[v].push_back(u);
        du[u]++; if(du[u] > 2) ok = 0;
        du[v]++; if(du[v] > 2) ok = 0;
	}
	if(!ok){
        printf("-1\n"); return 0;
	}
	int rt;
	for(int i = 1 ;i <= n; ++i) if(du[i] == 1) rt = i;
	dfs(rt, rt);
	ll ans = 0x3f3f3f3f3f3f3f3f;
	for(int u = 0; u < 3; ++u){
        for(int v = 0; v < 3; ++v){
            if(u == v) continue;
            a[1] = u; a[2] = v;
            ll r = c[dfn[1]][u] + c[dfn[2]][v];
            for(int i = 3; i <= n; ++i){
                int t = 1^2;
                t ^= (a[i-2]^a[i-1]);
                a[i] = t;
                r += c[dfn[i]][t];
            }
            if(r < ans){
                for(int i = 1; i <= n; ++i) b[i] = a[i];
                ans = r;
            }
        }
	}
	cout<<ans<<endl;
	for(int i = 1; i <= n; ++i) cc[dfn[i]] = b[i];
	for(int i = 1; i <= n; ++i){
        if(i > 1) printf(" ");
        //cout<<"dfn:"<<dfn[i]<<endl;
        printf("%d", cc[i]+1);
	}printf("\n");
}