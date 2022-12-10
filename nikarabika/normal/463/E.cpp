//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e5, maxval = 2000 * 1000;
vector<int> adj[maxn];
int fact[maxval + 1];
vector<int> vert[maxval + 1];
int ans[maxn], h[maxn], val[maxn];
int n, q;

void dfs(int v, int p = -1){
	int tmp = val[v];
	while(tmp > 1){
		if(sz(vert[fact[tmp]])){
			if(ans[v] == -1 or h[ans[v]] < h[vert[fact[tmp]].back()])
				ans[v] = vert[fact[tmp]].back();
		}
		vert[fact[tmp]].PB(v);
		int tmp2 = tmp;
		while(tmp % fact[tmp2] == 0)
			tmp /= fact[tmp2];
	}
	for(auto u : adj[v])
		if(u != p){
			h[u] = h[v] + 1;
			dfs(u, v);
		}
	tmp = val[v];
	while(tmp > 1){
		vert[fact[tmp]].pop_back();
		int tmp2 = tmp;
		while(tmp % fact[tmp2] == 0)
			tmp /= fact[tmp2];
	}
	return;
}

int main(){
	for(LL i = 2; i <= (LL)maxval; i++){
		if(fact[i] == 0){
			fact[i] = i;
			for(LL j = i * i; j <= (LL)maxval; j += i)
				if(fact[j] == 0)
					fact[j] = i;
		}
	}
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++)
		scanf("%d", val + i);
	for(int i = 1; i < n; i++){
		int fi, se;
		scanf("%d%d", &fi, &se);
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	memset(ans, -1, sizeof ans);
	dfs(0);
	while(q--){
		int ty;
		scanf("%d", &ty);
		if(ty == 1){
			int v;
			scanf("%d", &v);
			printf("%d\n", (ans[v - 1] == -1 ? -1 : ans[v - 1] + 1));
		}
		else{
			int v, w;
			scanf("%d%d", &v, &w);
			val[v - 1] = w;
			memset(ans, -1, sizeof ans);
			dfs(0);
		}
	}
	return 0;
}