#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n; cin >> n;
	int m; cin >> m;
	std::vector<string> s(n);
	std::vector<std::vector<int> > grid(m+1, std::vector<int>(n, 0));
	for (int o = 0; o < n; ++o) { cin >> s[o]; }
	for (int i = m - 1; i >= 0 ; --i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(s[j][i] == '1')
				grid[i][j] = grid[i+1][j] + 1;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		sort(grid[i].begin(), grid[i].end(), [](int &a, int &b)->bool{return a > b;});
	}
	int maxarea = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(grid[i][j]*(j+1) > maxarea)
				maxarea = grid[i][j]*(j+1);
		}
	}
	cout<<maxarea;
}