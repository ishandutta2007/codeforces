#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000, BLOCK=400;
int n, m, c[mxN], cnt[mxN], ans[mxN], res[mxN+1];
int pos[mxN], a[mxN], sub[mxN];
vector<int> adj[mxN];
struct QRY {
	int l, r, k, ind; //typo below :/ in submission before this
	bool operator<(const QRY &o) {return l/BLOCK==o.l/BLOCK?r<o.r:l/BLOCK<o.l/BLOCK;}
} q[mxN];
int posInd=0;
void dfs(int u=0, int p=-1) {
	a[posInd]=c[u];
	pos[u]=posInd++;
	for (int v : adj[u]) if (v!=p) {
		dfs(v, u);
		sub[pos[u]]+=sub[pos[v]]+1;
	}
}

inline void add(int i) {int k=++cnt[a[i]]; if (k>0) ++res[k];}
inline void remove(int i) {int k=cnt[a[i]]--; if (k>0) --res[k];}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> c[i], --c[i];
	for (int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	for (int i=0; i<m; ++i) {
		cin >> q[i].l >> q[i].k; q[i].l=pos[q[i].l-1];
		q[i].r=sub[q[i].l]+q[i].l, q[i].ind=i;
	}
	sort(q, q+m);
	for (int i=0, lb=0, rb=0; i<m; ++i) {
		int l=q[i].l, r=q[i].r;
		while(lb<l) remove(lb++);
		while(lb>l) add(--lb);
		while(rb<=r+1) add(rb++);
		while(rb>r+1) remove(--rb);
		ans[q[i].ind]=res[q[i].k];
	}
	for (int i=0; i<m; ++i) cout << ans[i] << '\n';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/