#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000;
int n;
ll S, tot;
vector<ar<int, 2>> adj[mxN];

inline ll cmp(ar<int, 2> x) {return 1ll*(x[1]+1)/2*x[0];} //sum subtracted if chosen edge
struct setCmp {
	bool operator()(const ar<int, 2> &a, const ar<int, 2> &b) const {return cmp(a)>cmp(b);}
};
multiset<ar<int, 2>, setCmp> e; //numLeaf, edgeWeight

int dfs(int u=0, int p=-1) {
	int cnt=(adj[u].size()==1&&adj[u][0][0]==p);
	for (ar<int, 2> v: adj[u]) if (v[0]!=p) {
		int k=dfs(v[0], u);
		e.insert({k, v[1]});
		tot+=1ll*k*v[1];
		cnt+=k;
	}
	return cnt;
}

void test_case() {
	cin >> n >> S, tot=0;
	for (int i=0; i<n; ++i) adj[i].clear();
	e.clear();
	for (int i=1; i<n; ++i) {
		int a, b, c; cin >> a >> b >> c, --a, --b;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	dfs();
	assert(e.size()==n-1);
	//for (const ar<int, 2> &x: e)
	//	cout << x[0] << ' ' << x[1] << '\n';
	int ans=0;
	while(tot>S) {
		ar<int, 2> x=*e.begin();
		e.erase(e.begin());
		tot-=cmp(x);
		x[1]/=2;
		e.insert(x);
		++ans;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		test_case();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/