#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n, m, si, sj;
vector<vector<int>> v;
map<pair<int, int>, int > mp;
int vis[2000][2000];
char a[2000][2000];
bool b = 0;
 
void dfs(int i,int j)
{
	if ( b ) return;
	int ii, jj;
	ii = i, jj = j;
 
	while (i < 0) i += n;
	while (j < 0) j += m;
	if (i >= n) i %= n;
	if (j >= m) j %= m;
 
 
	if ( vis[i][j] && mp[{ii, jj}] == 0)
	{
		b = 1;
		return;
	}
	if (vis[i][j] || a[i][j] == '#') return;
 
	//cout << ii << " " << jj << " " << i << " " << j << "  " << b << endl;
 
	vis[i][j] = 1;
	mp[{ii, jj}] = 1;
 
	dfs(ii, jj + 1);
	dfs(ii, jj - 1);
	dfs(ii + 1, jj);
	dfs(ii - 1, jj);
}
int  main()
{
	fast();
	cin >> n >> m;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'S') si = i, sj = j;
		}
	v.resize(n + 2);
	mp[{si, sj}] = 1;
	dfs(si, sj);
	if (b) cout << "Yes" << endl;
	else cout << "No" << endl;
}