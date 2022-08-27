#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 2e5 + 7;
int n, m, deg[N], h[N], val[N], xsum[N];
vi e[N], xe[N];
int cnt[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m ;
	L(i, 1, n) cin >> h[i];
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		e[u].emplace_back(v);
		xe[v].emplace_back(u);
		deg[u] += 1;
	}
	queue < int > q;
	L(i, 1, n) if(!deg[i]) q.push(i);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const int &v : e[u]) cnt[val[v]] += 1;
		while(cnt[val[u]]) ++val[u];
		for(const int &v : e[u]) cnt[val[v]] -= 1;
		for(const int &v : xe[u]) {
			deg[v] -= 1;
			if(!deg[v]) q.push(v);
		}
	}
	L(i, 1, n) xsum[val[i]] ^= h[i];
	int lst = -1;
	L(i, 0, n) if(xsum[i] != 0) lst = i;
	if(lst == -1) return cout << "LOSE\n", 0;
	cout << "WIN\n";
	L(i, 1, n) if(lst == val[i] && (xsum[lst] ^ h[i]) < h[i]) {
		h[i] ^= xsum[lst], xsum[lst] = 0;
		for(const int &v : e[i]) 
			if(xsum[val[v]]) 
				h[v] ^= xsum[val[v]], xsum[val[v]] = 0;
		break ;
	}
	L(i, 1, n) cout << h[i] << ' ';
	cout << '\n';
	return 0;
}