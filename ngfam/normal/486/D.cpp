#include <bits/stdc++.h>

using namespace std;

const long long N = 2222, mod = 1e9 + 7;

long long f[N], ans;
int n, d, a[N], done[N], fix[N], dead[N][N], root;
vector < int > adj[N];

void dfs(int u, int fr, int to){
  fix[u] = 1;
  f[u] = 1;
  for(auto v : adj[u]){
    if(fix[v]) continue;
    if(a[v] > to || a[v] < fr){
      continue;
    }
    if(dead[root][v]) continue;
    if(a[v] == fr){
      dead[root][v] = 1;
      dead[v][root] = 1;
    }
    dfs(v, fr, to);
    f[u] = f[u] + f[u] * f[v];
    f[u] %= mod;
  }
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("1.out", "w", stdout);
	#endif
	scanf("%d%d", &d, &n);
	for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
	}
	for(int i = 1; i < n; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i){
    root = i;
    memset(fix, 0, sizeof fix);
    memset(f, 0, sizeof f);
    dfs(i, a[i], a[i] + d);
    ans += f[i];
    ans %= mod;
    //cout << i << " " << f[i] << endl;
	}
	cout << ans;
	return 0;
}