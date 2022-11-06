#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
int n, m;

bool valid(int i, int j)
{
	return(i < n && j < m && j >= 0 && i >= 0);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	cin >> n >> m;
	string s;
	std::vector<std::vector<bool> > grid(n, std::vector<bool> (m, true));
	std::vector<std::vector<int> > lef(n, std::vector<int> (m, 0));
	std::vector<std::vector<int> > dow(n, std::vector<int> (m, 0));
	std::vector<std::vector<int> > rig(n, std::vector<int> (m, 0));
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		for (int j = 0; j < m; ++j)
			if(s[j] == '1')
				grid[i][j] = false;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 1; j < m; ++j) {
			if(grid[i][j-1])
				lef[i][j] = lef[i][j-1] + 1;
			if(grid[i][m-j])
				rig[i][m-j-1] = rig[i][m-j] + 1;
		}
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if(grid[i-1][j])
				dow[i][j] = dow[i-1][j] + 1;
	std::vector<std::vector<ll> > g(n, std::vector<ll> (m, 0));
	ll f = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if(!grid[i][j])
				continue;
			int o = 1;
			while(valid(i+o, j+o) && grid[i+o][j+o] && grid[i+o][j]) {
				if(lef[i+o][j+o] >= o)
					g[i][j]++;
				o++;
			}
			o = 1;
			while(valid(i+o, j+o) && grid[i+o][j+o] && grid[i][j+o]) {
				if(dow[i+o][j+o] >= (o))
					g[i][j]++;
				o++;
			}
			o = 1;
			while(valid(i+o, j-o) && grid[i+o][j-o] && grid[i+o][j]) {
				if(rig[i+o][j-o] >= o)
					g[i][j]++;
				o++;
			}
			o = 1;
			while(valid(i+o, j-o) && grid[i+o][j-o] && grid[i][j-o]) {
				if(dow[i+o][j-o] >= (o))
					g[i][j]++;
				o++;
			}
			o = 1;
			while(valid(i+o, j+o) && grid[i+o][j+o] && valid(i+o, j-o) && grid[i+o][j-o]) {
				if(lef[i+o][j+o] >= (2*o))
					g[i][j]++;
				o++;
			}
			o = 1;
			while(valid(i+o, j+o) && grid[i+o][j+o] && valid(i-o, j+o) && grid[i-o][j+o]) {
				if(dow[i+o][j+o] >= (2*o))
					g[i][j]++;
				o++;
			}
			o = 1;
			while(valid(i-o, j+o) && grid[i-o][j+o] && valid(i-o, j-o) && grid[i-o][j-o]) {
				if(lef[i-o][j+o] >= (2*o))
					g[i][j]++;
				o++;
			}
			o = 1;
			while(valid(i+o, j-o) && grid[i+o][j-o] && valid(i-o, j-o) && grid[i-o][j-o]) {
				if(dow[i+o][j-o] >= (2*o))
					g[i][j]++;
				o++;
			}
			f += g[i][j];
		}
	cout << f;
}