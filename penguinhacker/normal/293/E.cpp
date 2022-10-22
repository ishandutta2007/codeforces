#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>;

const int mxN=1e5;
int n, a, b, sz[mxN], max_d;
vector<ar<int, 2>> adj[mxN];
ll ans;
bool dead[mxN];
vector<int> oc[mxN];
Tree<ar<int, 2>> t;

int dfs1(int u, int p) {
	sz[u]=1;
	for (ar<int, 2> v : adj[u])
		if (v[0]^p&&!dead[v[0]])
			sz[u]+=dfs1(v[0], u);
	return sz[u];
}

int dfs2(int u, int p, int ts) {
	for (ar<int, 2> v : adj[u])
		if (v[0]^p&&!dead[v[0]]&&2*sz[v[0]]>ts)
			return dfs2(v[0], u, ts);
	return u;
}

void dfs4(int u, int p, int d1=0, int d2=0) {
	max_d=max(max_d, d1);
	oc[d1].push_back(d2);
	for (ar<int, 2> v : adj[u])
		if (v[0]^p&&!dead[v[0]])
			dfs4(v[0], u, d1+1, d2+v[1]);
}

void solve(int inc) {
	int cnt=0;
	ll cur=0;
	for (int i=min(max_d, a), j=0; i; --i) {
		while(j<i&&i+j<=a) {
			for (int x : oc[j])
				t.insert({x, cnt++});
			++j;
		}
		while(i<j) {
			--j;
			for (int x : oc[j])
				t.erase(t.lower_bound({x}));
		}
		for (int x : oc[i])
			cur+=t.order_of_key({b-x+1, -1});
		if (2*i<=a) {
			sort(oc[i].begin(), oc[i].end());
			for (int k=0; k<oc[i].size(); ++k) {
				int p=upper_bound(oc[i].begin(), oc[i].end(), b-oc[i][k])-oc[i].begin()-1;
				cur+=max(0, p-k);
			}
		}
	}
	ans+=cur*inc;
	//reset
	for (int i=0; i<=max_d; ++i)
		oc[i].clear();
	t.clear();
	max_d=0;
}

void dfs3(int u=0) {
	u=dfs2(u, -1, dfs1(u, -1));
	dfs4(u, -1), solve(1);
	for (ar<int, 2> v : adj[u])
		if (!dead[v[0]])
			dfs4(v[0], u, 1, v[1]), solve(-1);
	dead[u]=1;
	for (ar<int, 2> v : adj[u])
		if (!dead[v[0]])
			dfs3(v[0]);
	dead[u]=0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> a >> b;
	for (int i=1; i<n; ++i) {
		int p, w;
		cin >> p >> w, --p;
		adj[p].push_back({i, w});
		adj[i].push_back({p, w});
	}
	dfs3();
	cout << ans;
	return 0;
}