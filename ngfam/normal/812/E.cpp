#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, leaf;
int a[N];
vector < int > f[2];
map < int, int > cnt;
vector < int > adj[N];

void dfs(int u, int x){
	f[x].push_back(a[u]);
	if(adj[u].size() == 0){
		leaf = x;
	}
	for(int v : adj[u]){
		dfs(v, 1 - x);
	}
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}
	

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}

	for(int i = 2; i <= n; ++i){
		int p;
		scanf("%d", &p);
		adj[p].push_back(i);
	}

	dfs(1, 0);

	int sumxor = 0;

	for(int x : f[leaf]){
		sumxor ^= x;
	}


	long long ans = 0;

	cnt.clear();
	for(int x : f[1 - leaf]) ++cnt[x];

	for(int x : f[leaf]){
		ans += cnt[sumxor ^ x];
	}


	if(sumxor == 0){
		ans += (1LL * f[1 - leaf].size() * (f[1 - leaf].size() - 1)) / 2;
		ans += (1LL * f[leaf].size() * (f[leaf].size() - 1)) / 2;
	}

	cout << ans;

	return 0;
}