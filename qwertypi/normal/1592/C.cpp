#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G(100001);
int w[100001];
int s[100001];
void dfs(int u = 0, int p = -1){
	for(auto v : G[u]){
		if(v != p){
			dfs(v, u);
			s[u] ^= s[v];
		}
	}
	s[u] ^= w[u];
}

int ans = 0;
int ttl = 0;
bool dfs2(int u = 0, int p = -1){
	int ok = 0;
	for(auto v : G[u]){
		if(v != p){
			ok += dfs2(v, u);
		}
	}
	if(ok && s[u] == 0){
		ans = 2;
	}
	ans = max(ans, ok);
	ok += s[u] == ttl;
	return ok;
}

void solve(){
	ans = 0;
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) G[i].clear();
	ttl = 0;
	for(int i = 0; i < n; i++) cin >> w[i], ttl ^= w[i], s[i] = 0;
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(ttl == 0){
		cout << "YES" << endl;
	}else{
		if(k == 2){
			cout << "NO" << endl;
		}else{
			dfs();
			dfs2();
			cout << (ans >= 2 ? "YES" : "NO") << endl;
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--) solve();
}