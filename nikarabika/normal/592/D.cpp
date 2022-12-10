//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef long long int LL;

#define PB push_back
#define smax(x, y) (x) = max((x), (y))

const int maxn = 2e5 + 85 - 69;
vector<int> adj[maxn];
bool mark[maxn], bad[maxn], intree[maxn];
int max_down[maxn], max_down2[maxn], max_up[maxn], ans[maxn], par[maxn], child_cnt[maxn], cnt[maxn], bad_child[maxn];
int n, m;
int Max, root, treev;

void dfs(int v, int p = -1){
	cnt[v] = bad[v];
	for(auto u : adj[v]){
		if(u != p){
			dfs(u, v);
			cnt[v] += cnt[u];
			if(cnt[u])
				bad_child[v]++;
		}
	}
	return;
}

void dfs2(int v){
	for(auto u : adj[v])
		if(u != par[v] and intree[u]){
			child_cnt[v]++;
			par[u] = v;
			dfs2(u);
			if(max_down[u] + 1 >= max_down[v])
				max_down2[v] = max_down[v], max_down[v] = max_down[u] + 1;
			else if(max_down[u] + 1 >= max_down2[v])
				max_down2[v] = max_down[u] + 1;
		}
}

void dfs3(int v){
	mark[v] = true;
	if(v == root){
		ans[v] = max_down[v] + max_down2[v];
		return;
	}
	if(!mark[par[v]])
		dfs3(par[v]);
	max_up[v] = max_up[par[v]] + 1;
	if(child_cnt[par[v]] > 1){
		if(max_down[par[v]] == max_down[v] + 1)
			smax(max_up[v], max_down2[par[v]] + 1);
		else
			smax(max_up[v], max_down[par[v]] + 1);
	}
	ans[v] = max_down[v] + max(max_up[v], max_down2[v]);
	smax(Max, ans[v]);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 1; i <= m; i++){
		int x;
		cin >> x;
		bad[x] = true;
	}
	dfs(1);
	for(int i = 1; i <= n; i++)
		if(!(cnt[i] == 0 or (cnt[i] == m and !bad[i] and bad_child[i] <= 1)))
			intree[i] = true, root = i, treev++;
	dfs2(root);
	for(int i = 1; i <= n; i++)
		if(intree[i] and !mark[i])
			dfs3(i);
	for(int i = 1; i <= n; i++){
		if(intree[i] and ans[i] == Max and (child_cnt[i] == 0 or (par[i] == 0 and child_cnt[i] == 1))){
			cout << i << endl
				<< 2 * (treev - 1) - Max << endl;
			return 0;
		}
	}
	return 0;
}