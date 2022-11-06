#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

ll ans = 1e17;

ll gcd(ll a, ll b)
{
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
	return (a*b)/(gcd(a,b));
}

void dfs(std::vector<std::vector<int> >& adj, std::vector<ll>& m, std::vector<ll>& c, int u, int p)
{
	for (int v : adj[u])
		if(v != p){
			dfs(adj, m, c, v, u);
			c[u]++;
			m[u] = lcm(m[u], m[v]);
		}
	if(c[u])
		m[u] *= c[u];
}

void dfs2(std::vector<std::vector<int> >& adj, std::vector<ll>& a, std::vector<ll>& m, std::vector<ll>& c, int u, int p)
{
	for (int v : adj[u])
		if(v != p) {
			m[v] = max(m[v], m[u]/c[u]);
			dfs2(adj, a, m, c, v, u);
		}
	if(!c[u])
		if( (a[u]/m[u]) < ans)
			ans = a[u]/m[u];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n;
	cin >> n;
	std::vector<ll> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	std::vector<std::vector<int> > adj(n);
	int x, y;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> x >> y; x--; y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	std::vector<ll> m(n, 1);
	std::vector<ll> c(n, 0);
	dfs(adj, m, c, 0, -1);
	print(m);
	dfs2(adj, a, m, c, 0, -1);
	ll rem = 0;
	for (int i = 0; i < n; ++i)
		rem += (c[i]?(0):(a[i] - (ans*m[i])));
	cout << rem;
}