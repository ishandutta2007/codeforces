#include <bits/stdc++.h>

using namespace std;

const int N = 33;

int n, done[N];

long long calc[N], sum[N];

vector < int > adj[N], gra[N];

long long dirx[4] = {0, 1, 0, -1};
long long diry[4] = {1, 0, -1, 0};

long long ansx[N], ansy[N];

void pre_dfs(int u){
	done[u] = 1;
	for(int v : adj[u]){
		if(done[v]) continue;
		gra[u].push_back(v);
		pre_dfs(v);
	}
}
//
void dfs(int u, int f, long long x, long long y, int d){					
	int cnt = 0;
	ansx[u] = x;
	ansy[u] = y;
	for(int i = 0; i < 4; ++i){
		if(i == d) continue;
		++cnt;
		if(cnt > gra[u].size()) break;	
		int v = gra[u][cnt - 1];
		dfs(v, f - 1, x + dirx[i] * calc[f], y + diry[i] * calc[f], (i + 2) % 4);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= n; ++i){
		if(adj[i].size() > 4){
			puts("NO");
			return 0;
		}
	}
//
	calc[1] = 1;
	sum[1] = 1;
	for(int i = 2; i <= 30; ++i){
		calc[i] = sum[i - 1] + 1;
		sum[i] = sum[i - 1] + calc[i];
	}

	pre_dfs(1);
	dfs(1, 30, 0, 0, -1);

	puts("YES");
	for(int i = 1; i <= n; ++i){
		printf("%lld %lld\n", ansx[i], ansy[i]);
	}

	return 0;
}