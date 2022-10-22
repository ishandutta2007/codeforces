#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000;
int n;
ll S, tot1, tot2;
vector<ar<int, 3>> adj[mxN];

inline ll cmp(ar<int, 2> x) {return 1ll*(x[1]+1)/2*x[0];} //sum subtracted if chosen edge
struct setCmp {
	bool operator()(const ar<int, 2> &a, const ar<int, 2> &b) const {return cmp(a)>cmp(b);}
};
multiset<ar<int, 2>, setCmp> e1, e2; //numLeaf, edgeWeight

int dfs(int u=0, int p=-1) {
	int cnt=(adj[u].size()==1&&adj[u][0][0]==p);
	for (ar<int, 3> v: adj[u]) if (v[0]!=p) {
		int k=dfs(v[0], u);
		if (v[2]==1) {
			e1.insert({k, v[1]});
			tot1+=1ll*k*v[1];
		}
		else {
			e2.insert({k, v[1]});
			tot2+=1ll*k*v[1];
		}
		cnt+=k;
	}
	return cnt;
}

vector<ll> solve(multiset<ar<int, 2>, setCmp> &e, ll &tot) {
	vector<ll> c={tot};
	while(tot>0) {
		ar<int, 2> x=*e.begin();
		e.erase(e.begin());
		tot-=cmp(x);
		x[1]/=2;
		if (x[1]>0) e.insert(x);
		c.push_back(tot);
	}
	return c;
}

void test_case() {
	cin >> n >> S, tot1=0, tot2=0;
	for (int i=0; i<n; ++i) adj[i].clear();
	assert(e1.empty()&&e2.empty());
	for (int i=1; i<n; ++i) {
		int a, b, c, d; cin >> a >> b >> c >> d, --a, --b;
		adj[a].push_back({b, c, d});
		adj[b].push_back({a, c, d});
	}
	dfs();
	/*for (auto x: e1)
		cout << x[0] << ' ' << x[1] << '\n';
	cout << '\n';
	for (auto x: e2)
		cout << x[0] << ' ' << x[1] << '\n';*/
	vector<ll> v1=solve(e1, tot1), v2=solve(e2, tot2);
	/*for (ll i: v1) cout << i << ' ';
	cout << '\n';
	for (ll i: v2) cout << i << ' ';*/
	int ans=INT_MAX;
	int s1=v1.size(), s2=v2.size();
	for (int p1=0, p2=s2-1; p1<s1; ++p1) {
		if (v1[p1]>S) continue;
		while(p2>0&&v1[p1]+v2[p2-1]<=S) --p2;
		ans=min(ans, p1+2*p2);
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