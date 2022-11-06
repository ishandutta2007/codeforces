#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define F first
#define S second

using namespace std;

class DSU
{
private:
	int *parent;
	int n;
	int *size;

public:
	DSU(int n);
	int root(int x);
	void merge(int x, int y);
	bool areInSame(int x, int y);
	int getsize(int i){ return size[root(i)]; }
	~DSU();
};

DSU::DSU(int n) 
{
	this->n = n;
	parent = new int[n];
	size = new int[n];
	for (int i = 0; i < n; ++i) {
		parent[i] = i;
		size[i] = 1;
	}
}

int DSU::root(int x)
{
	if(parent[x] == x)
		return x;
	return parent[x] = root(parent[x]);
}

void DSU::merge(int x, int y)
{
	x = root(x);
	y = root(y);
	if(x != y) {
		if(size[x] < size[y])
			swap(x, y);
		parent[y] = x;
		size[x] += size[y];
	}
}

bool DSU::areInSame(int x, int y)
{
	if(root(x) == root(y))
		return true;
	return false;
}

DSU::~DSU()
{
	delete parent;
	delete size;
}

double getres(std::vector<std::vector<int> >& adj, std::vector<ll>& val, int n)
{
	DSU d(n);
	std::vector<bool> vis(n, false);
	std::vector<int> so(n);
	for (int i = 0; i < n; ++i)
		so[i] = i;
	sort(so.begin(), so.end(), [&](int i, int j)->bool{return (val[i] > val[j]);});
	ll total = 0;
	for (int i = 0; i < n; ++i)
	{
		set<int> s;
		vis[so[i]] = true;
		//calc total size
		int t = 1;
		for (int v : adj[so[i]])
			if(vis[v] && (s.find(d.root(v)) == s.end())) {
				t += d.getsize(v);
				s.insert(d.root(v));
			}

		s.clear();
		//add to total
		for (int v : adj[so[i]])
			if(vis[v] && (s.find(d.root(v)) == s.end())) {
				total += (ll)((ll)d.getsize(v))*(ll)((ll)t - (ll)d.getsize(v))*(ll)(val[so[i]]);
				s.insert(d.root(v));
			}
		total += (ll)((ll)1l)*(ll)((ll)t - 1l)*(ll)(val[so[i]]);

		//merge all
		for (int v : adj[so[i]])
			if(vis[v])
				d.merge(v, so[i]);
	}
	double to = total;
	double N = n;
	double res = to/(N*(N-1));
	return res;
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
	std::vector<std::vector<int> > adj(n);
	std::vector<ll> val(n);
	for (int i = 0; i < n; ++i)
		cin >> val[i];
	int x, y;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y; x--; y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	double res = getres(adj, val, n);
	cout << res;
}