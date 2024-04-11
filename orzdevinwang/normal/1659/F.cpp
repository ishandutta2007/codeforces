#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 1e6 + 7;
int n, x, p[N], xpp[N], deg[N];
vi e[N];
bool vis[N];
int dis[N], cnt[N];
void Main() {
	cin >> n >> x;
	L(i, 1, n) e[i].clear();
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	L(i, 1, n) cin >> xpp[i], p[xpp[i]] = i;
	int mx = 1;
	L(i, 1, n) if(sz(e[i]) > sz(e[mx])) mx = i;
	if(sz(e[mx]) < n - 1) return cout << "Alice\n", void();
	L(i, 1, n) dis[i] = 1e9;
	dis[x] = 0;
	L(t, 1, 4) L(i, 1, n) for(const int &v : e[i]) dis[v] = min(dis[v], dis[i] + 1);
	L(i, 0, 4) cnt[i] = 0;
	L(i, 1, n) cnt[dis[i]] += 1;
	L(i, 1, n) vis[i] = false;
	L(i, 1, n) if(!vis[i]) {
		int tr = i, mx = 0;
		while(!vis[tr]) vis[tr] = true, mx = max(mx, dis[tr]), tr = p[tr];
		cnt[mx] -= 1;
	}
	L(i, 1, 4) cnt[i] += cnt[i - 1];
	bool OK = true;
	L(i, 0, 4) if(cnt[i] > i) OK = false;
	if(OK) return cout << "Alice\n", void();
	L(i, 1, n) vis[i] = false;
	int cyc = 0;
	L(i, 1, n) if(!vis[i]) {
		int tr = i, cnt = 0;
		while(!vis[tr]) vis[tr] = true, tr = p[tr], cnt += 1;
		if(cnt % 2 == 0) cyc ^= 1;
	}
	if(sz(e[mx]) == n - 1) {
		if(p[mx] != mx && (x == mx || p[x] == mx)) 
			return cout << "Bob\n", void();
		if((x == mx) ^ cyc) {
			cout << "Bob\n";
		} else {
			cout << "Alice\n";
		}
		return ;
	} 
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main(); 
	return 0;
}