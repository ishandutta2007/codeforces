#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
std::vector<int> A;
std::vector<std::vector<int> > adj;
void dfs(int v, int lev) {
	if(lev == 2) {
		A[v]++;
	} else {
		for (auto i : adj[v])
		{
			dfs(i, lev + 1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); 
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	ll mod = 1000000007;
	int n; cin >> n;
	int m; cin >> m;
	ll total = 0;
	ll t = 0;
	int x, y;
	adj.resize(n);
	A.resize(n);
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		x--; y--;
		adj[x].pb(y);
	}
	print(adj);
	for (int i = 0; i < n; ++i)
	{
		memset(&(A[0]), 0, n*4);
		dfs(i, 0);
		print(A);
		for (int j = 0; j < n; ++j)
		{
			if(i != j){
				total += (A[j] * ( A[j] - 1 ))/2;
			}
		}
	}
	cout << total;
}