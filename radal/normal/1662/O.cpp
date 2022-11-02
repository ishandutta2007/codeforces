#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstring>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int maxn = 8000;
const int mod = 360;

bool vis[maxn];
bool nedg[maxn][4];

void dfs(int v)
{
	if(vis[v]) return;
	vis[v] = true;
	//cerr << v << endl;
	int l = v/mod;
	int r = v%mod;
	if(!nedg[v][0])
	{
		dfs(l*mod + ((r+mod-1)%mod) );
	}
	if(!nedg[v][1])
	{
		dfs(l*mod + ((r+1)%mod) );
	}
	if(l > 0 and !nedg[v][2])
	{
		dfs( (l-1)*mod + r );
	}
	if(l < 20 and !nedg[v][3])
	{
		dfs( (l+1)*mod + r );
	}
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while(T--)
	{
		int n; cin >> n;
		memset(vis, 0, sizeof vis);
		memset(nedg, 0, sizeof nedg);
		for(int i = 0; i < n; i++)
		{
			char ch; cin >> ch;
			if(ch == 'C')
			{
				int r, t1, t2;
				cin >> r >> t1 >> t2;
				if(t1 < t2)
				{
					for(int j = t1; j < t2; j++)
					{
						nedg[r*mod+j][2] = true;
						nedg[(r-1)*mod + j][3] = true;
					}
				}
				else
				{
					for(int j = t1; j < mod; j++)
					{
						nedg[r*mod+j][2] = true;
						nedg[(r-1)*mod + j][3] = true;
					}
					for(int j = 0; j < t2; j++)
					{
						nedg[r*mod+j][2] = true;
						nedg[(r-1)*mod + j][3] = true;
					}
				}
			}
			else
			{
				int l, r, t;
				cin >> l >> r >> t;
				for(int j = l; j < r; j++)
				{
					nedg[j*mod+t][0] = true;
					nedg[j*mod+((t+mod-1)%mod)][1] = true;
				}
			}
		}
		for(int i = 0; i < mod; i++)
		{
			dfs(i);
		}
		bool pos = false;
		for(int i = 0; i < mod; i++)
		{
			pos = pos or vis[20*mod+i];
		}
		if(pos)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}