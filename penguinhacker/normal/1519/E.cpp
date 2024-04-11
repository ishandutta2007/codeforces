#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=400005;
int n, t, tin[2*mxN];
ar<int, 2> e[mxN];
ar<ll, 2> nxt[mxN][2];
vector<ar<int, 2>> ans;
vector<ar<ll, 2>> di;
vector<int> adj[2*mxN], ex[2*mxN];
 
void reduce(ll& a, ll& b) {
	ll g=__gcd(a, b);
	a/=g, b/=g;
}
 
ar<ll, 2> make(ll a, ll b, ll c, ll d) {
	reduce(a, b), reduce(c, d);
	ll x=b*c, y=a*d;
	reduce(x, y);
	return {x, y};
}
 
void dfs(int u, int p=-1) {
	tin[u]=++t;
	if (p^-1)
		ex[u].push_back(p);
	for (int x : adj[u]) {
		if (x==p)
			continue;
		int v=u^e[x][0]^e[x][1];
		if (!tin[v]) {
			dfs(v, x);
		} else if (tin[v]<tin[u]) {
			ex[u].push_back(x);
		}
	}
	while(ex[u].size()>=2) {
		int a=ex[u].back();
		ex[u].pop_back();
		int b=ex[u].back();
		ex[u].pop_back();
		ans.push_back({a+1, b+1});
	}
	if (ex[u].size()==1)
		ex[u^e[p][0]^e[p][1]].push_back(p);
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		ll a, b, c, d; // (a/b, c/d)
		cin >> a >> b >> c >> d;
		ar<ll, 2> x=make(a+b, b, c, d);
		ar<ll, 2> y=make(a, b, c+d, d);
		nxt[i][0]=x, nxt[i][1]=y;
		di.push_back(x), di.push_back(y);
	}
	sort(di.begin(), di.end());
	di.resize(unique(di.begin(), di.end())-di.begin());
	for (int i=0; i<n; ++i) {
		int u=lower_bound(di.begin(), di.end(), nxt[i][0])-di.begin();
		int v=lower_bound(di.begin(), di.end(), nxt[i][1])-di.begin();
		adj[u].push_back(i);
		adj[v].push_back(i);
		e[i]={u, v};
	}
	for (int i=0; i<di.size(); ++i)
		if (!tin[i])
			dfs(i);
	cout << ans.size() << "\n";
	for (ar<int, 2> a : ans)
		cout << a[0] << " " << a[1] << "\n";
	return 0;
}