#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;
class DSU {public: int *parent; int n; int *size; DSU(int n); int root(int x); void merge(int x, int y); bool areInSame(int x, int y); int sizee(int x); ~DSU();};
DSU::DSU(int n) {this->n = n; parent = new int[n]; size = new int[n]; for (int i = 0; i < n; ++i) {parent[i] = i; size[i] = 1;}}
int DSU::root(int x) {if (parent[x] == x)	return x; return parent[x] = root(parent[x]);}
int DSU::sizee(int x) {return size[x];}
void DSU::merge(int x, int y) {x = root(x); y = root(y); if (x != y) {if (size[x] < size[y])swap(x, y); parent[y] = x; size[x] += size[y];}}
bool DSU::areInSame(int x, int y) {if (root(x) == root(y))return true; return false;}
DSU::~DSU() {delete parent; delete size; }

int xx[4] = {-1,1,0,0};
int yy[4] = {0,0,-1,1};

bool valid(int i, int j, int n, int m)
{
	return (i < n && j < m && i >= 0 && j >= 0);
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	DSU d(1004 * 1004);
	int n; cin >> n;
	int m; cin >> m;
	std::vector<string> s(n);
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (s[i][j] == '.')
			{
				for (int k = 0; k < 4; ++k)
				{
					int y = yy[k] + j;
					int x = xx[k] + i;
					if (valid(x, y, n, m) && s[x][y] == '.')
					{
						d.merge(i * 1003 + j, x * 1003 + y);
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (s[i][j] == '*')
			{
				set<int> sii;
				int si = 0;
				for (int k = 0; k < 4; ++k)
				{
					int y = yy[k] + j;
					int x = xx[k] + i;
					if (valid(x, y, n, m) && s[x][y] == '.')
					{
						int r = d.root(x * 1003 + y);
						if (sii.find(r) == sii.end())
						{
							sii.insert(r);
							si += d.size[r];
						}
					}
				}
				s[i][j] = ((si + 1)%10) + '0';
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << s[i] << "\n";
	}
}