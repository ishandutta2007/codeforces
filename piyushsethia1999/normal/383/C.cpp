#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

std::vector<int> orderev;
std::vector<int> orderod;
std::vector<pair<int, int> > evlim;
std::vector<pair<int, int> > odlim;
std::vector<int> lev;
std::vector<int> sodd;
std::vector<int> seve;
void dfs(std::vector<std::vector<int> >& adj, int u, int p, int l)
{
	lev[u] = l;
	int oddstart, evstart;
	if(l & 1)
		orderod.pb(u), oddstart = orderod.size() - 1, evstart = orderev.size();
	else
		orderev.pb(u), evstart = orderev.size() - 1, oddstart = orderod.size();
	for(int v : adj[u])
		if(v != p)
			dfs(adj, v, u, l + 1);
	if(l & 1)
		orderev.pb(p), odlim[u] = {oddstart, orderod.size() - 1}, evlim[u] = {evstart, (int)(orderev.size()) - 2};
	else
		orderod.pb(p), evlim[u] = {evstart, orderev.size() - 1}, odlim[u] = {oddstart, (int)(orderod.size()) - 2};
}

void updateo(int node, int s, int e, int l, int r, int val)
{
	if(s > r || e < l)
		return;
	else if(s >= l && e <= r) {
		sodd[node] += val;
		return;
	}
	int mid = (s+e)/2;
	updateo(2 * node, s, mid, l, r, val);
	updateo(2 * node + 1, mid + 1, e, l, r, val);
}
void updatee(int node, int s, int e, int l, int r, int val)
{
	if(s > r || e < l)
		return;
	else if(s >= l && e <= r) {
		seve[node] += val;
		return;
	}
	int mid = (s+e)/2;
	updatee(2 * node, s, mid, l, r, val);
	updatee(2 * node + 1, mid + 1, e, l, r, val);
}

int queryo(int node, int s, int e, int in)
{
	if(s == e)
		return sodd[node];
	int mid = (s+e)/2;
	if(in <= mid)
		return sodd[node] + queryo(2*node, s, mid, in);
	return sodd[node] + queryo(2*node + 1, mid + 1, e, in); 
}

int querye(int node, int s, int e, int in)
{
	if(s == e)
		return seve[node];
	int mid = (s+e)/2;
	if(in <= mid)
		return seve[node] + querye(2*node, s, mid, in);
	return seve[node] + querye(2*node + 1, mid + 1, e, in); 
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, m;
	cin >> n >> m; 
	odlim.resize(n);
	evlim.resize(n);
	lev.resize(n);
	seve.resize(4*n);
	sodd.resize(4*n);
	std::vector<std::vector<int> > adj(n);
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n-1; ++i)
	{
		int x, y;
		cin >> x >> y;x--,y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(adj, 0, -1, 0);
	for (int i = 0; i < m; ++i)
	{
		int q;
		cin >> q;
		if(q == 1)
		{
			int x, y;
			cin >> x >> y; x--;
			if(lev[x] & 1) {
				updateo(1, 0, n-1, odlim[x].first, odlim[x].second, y);
				updatee(1, 0, n-1, evlim[x].first, evlim[x].second, -y);
			}
			else {
				updatee(1, 0, n-1, evlim[x].first, evlim[x].second, y);
				updateo(1, 0, n-1, odlim[x].first, odlim[x].second, -y);
			}
		}
		else
		{
			int x;
			cin >> x; x--;
			if(lev[x] & 1)
				cout << queryo(1, 0, n-1, odlim[x].first) + a[x] << "\n";
			else
				cout << querye(1, 0, n-1, evlim[x].first) + a[x] << "\n";
		}
		// cout << "Update: \n";
		// for (int x = 0; x < n; ++x)
		// {
		// 	if(lev[x] & 1)
		// 		cout << queryo(1, 0, n-1, odlim[x].first) + a[x] << "\n";
		// 	else
		// 		cout << querye(1, 0, n-1, evlim[x].first) + a[x] << "\n";
		// }
	}
}