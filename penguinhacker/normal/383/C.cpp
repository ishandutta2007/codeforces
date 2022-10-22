#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define debug(x) cerr << "[" << #x << "] = [" << (x) << "]\n"
#define ps() cerr << "\n"

const int mxN=200000;
struct BIT {
	int n=mxN+1;
	vector<int> bit;
	BIT() {bit.assign(n, 0);}
	void upd(int i, int val) {for (++i; i<n; i+=i&-i) bit[i]+=val;}
	void upd(int l, int r, int val) {upd(l, val); upd(r+1, -val);}
	int qry(int i) {int res=0; for (++i; i>0; i-=i&-i) res+=bit[i]; return res;}
} b[2];

int n, m, a[mxN], pari[mxN];
int sub[mxN][2], pos[mxN][2], posInd[2];
vector<int> adj[mxN];

void dfs(int u=0, int p=-1) {
	int x=pari[u];
	pos[u][x]=posInd[x]++;
	pos[u][x^1]=posInd[x^1];
	++sub[u][x];
	b[x].upd(pos[u][x], pos[u][x], a[u]);
	for (int v: adj[u]) if (v!=p) {
		pari[v]=x^1;
		dfs(v, u);
		sub[u][0]+=sub[v][0];
		sub[u][1]+=sub[v][1];
	}
	/*debug(u);
	debug(pos[u][0]); debug(sub[u][0]);
	debug(pos[u][1]); debug(sub[u][1]);
	ps();*/
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
	}
	for (int i=1; i<n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	for (int i=0; i<m; ++i) {
		int type, u; cin >> type >> u, --u;
		int x=pari[u];
		if (type==1) {
			int val; cin >> val;
			b[x].upd(pos[u][x], pos[u][x]+sub[u][x]-1, val);
			b[x^1].upd(pos[u][x^1], pos[u][x^1]+sub[u][x^1]-1, -val);
		}
		if (type==2) {
			int ans=b[x].qry(pos[u][x]);
			cout << ans << "\n";
		}
	}
	return 0;
}