#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;

int dfs(std::vector<bool>& vis, int a, std::vector<int>& p)
{
	if(vis[a])
		return (a + 1);
	vis[a] = true;
	return dfs(vis, p[a], p);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	int n; cin >> n;
	vector<int> p(n); for (int o = 0; o < n; ++o) { cin >> p[o]; p[o]--; }
	for (int i = 0; i < n; ++i)
	{
		std::vector<bool> vis(n, false);
		cout << dfs(vis, i, p) << " ";
	}
}