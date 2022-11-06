#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, m, K;
	cin >> n >> m >> K;
	string s[n];
	for (int i = 0; i < n; ++i)
		cin >> s[n - 1 - i];
	std::vector<std::vector<std::vector<int> > > grid(n, std::vector<std::vector<int> > (m, std::vector<int> (K+1, -1000000)));
	std::vector<std::vector<std::vector<string> > > sg(n, std::vector<std::vector<string> > (m, std::vector<string> (K+1, "")));
	for (int i = 0; i < m; ++i)
		grid[n-1][i][(s[n-1][i] - '0')%(K+1)] = s[n-1][i] - '0';
	for (int i = n-2; i >= 0; --i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k <= K; ++k)
			{
				if(j == 0)
				{
					int p = (k + (s[i][j] - '0'))%(K+1);
					int v = grid[i+1][j+1][k] + (s[i][j] - '0');
					sg[i][j][p] = "R" + sg[i+1][j+1][k];
					grid[i][j][p] = v;
				}
				else if(j == m-1)
				{
					int p = (k + (s[i][j] - '0'))%(K+1);
					int v = grid[i+1][j-1][k] + (s[i][j] - '0');
					sg[i][j][p] = "L" + sg[i+1][j-1][k];
					grid[i][j][p] = v;
				}
				else
				{
					int p = (k + (s[i][j] - '0'))%(K+1);
					if(grid[i+1][j-1][k] > grid[i+1][j+1][k]) {
						sg[i][j][p] = "L" + sg[i+1][j-1][k];
						grid[i][j][p] = grid[i+1][j-1][k] + (s[i][j] - '0');	
					}
					else {
						sg[i][j][p] = "R" + sg[i+1][j+1][k];
						grid[i][j][p] = grid[i+1][j+1][k] + (s[i][j] - '0');	
					}
				}
			}
	int ma = -1;
	string sr;
	int y;
	for (int i = 0; i < m; ++i)
		if(grid[0][i][0] > ma)
		{
			ma = grid[0][i][0];
			y = i;
			sr = sg[0][i][0];
		}
	cout << ma << "\n";
	if(ma != -1)
		cout << y + 1 << "\n" << sr;
}