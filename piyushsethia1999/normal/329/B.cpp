#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
int xi[] = {0, 0, 1, -1};
int yj[] = {-1, 1, 0, 0};
std::vector<string> s;
int r, c;
bool valid (int x, int y)
{
	return (x < r && y < c && x >= 0 && y >= 0);
}
void bfs(std::vector<std::vector<ll> > &grid, ll er, ll ec)
{
	queue<pair<ll, ll>> q;
	grid[er][ec] = 1;
	q.push(mp(er, ec));
	std::pair<ll, ll> p;
	while(!q.empty())
	{
		p = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int x = p.first + xi[i];
			int y = p.second + yj[i];
			if(valid(x, y))
			{
				if(!grid[x][y]){
					if(s[x][y] == 'T')
						grid[x][y] = 1000000000;
					else {
						grid[x][y] = grid[p.first][p.second]+1;
						q.push(mp(x, y));
					}
				}
			}
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
	cin>>r>>c;
	s.resize(r);
	std::vector<std::vector<ll> > grid(r,std::vector<ll> (c, 0));
	for (int i = 0; i < r; ++i)
	{
		cin >> s[i];
	}
	ll count = 0;
	ll er, ec;
	ll rr, cc;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if(s[i][j] == 'E')
			{
				er = i;
				ec = j;
			}
			else if(s[i][j] == 'S')
			{
				rr = i;
				cc = j;
			}
		}
	}
	grid[er][ec] = 1;
	bfs(grid, er, ec);
	ll mindist = grid[rr][cc];
	ll total = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if(s[i][j] <= '9' && s[i][j] >= '1' && grid[i][j] <= mindist && grid[i][j] != 0){
				total += ((ll)(s[i][j] - '0'));
			}
		}
	}
	cout<<total;
}