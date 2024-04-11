#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
int a[1002][1002];
int lahub1[1002][1002];
int lahubina1[1002][1002];
int lahub2[1002][1002];
int lahubina2[1002][1002];
int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
		}
	}
	for (int i = n; i >= 1 ; --i)
	{
		for (int j = m; j >= 1; --j)
		{
			lahub1[i][j] = max(lahub1[i][j+1], lahub1[i+1][j]) + a[i][j];
		}
	}
	for (int i = 1; i <= n ; ++i)
	{
		for (int j = m; j >= 1; --j)
		{
			lahubina1[i][j] = max(lahubina1[i-1][j], lahubina1[i][j+1]) + a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			lahub2[i][j] = max(lahub2[i-1][j], lahub2[i][j-1]) + a[i][j];
		}
	}
	for (int i = n; i >= 1; --i)
	{
		for (int j = 1; j <= m; ++j)
		{
			lahubina2[i][j] = max(lahubina2[i+1][j], lahubina2[i][j-1]) + a[i][j];
		}
	}
	int ma = 0;
	for (int i = 2; i <= n-1; ++i)
	{
		for (int j = 2; j <= m-1; ++j)
		{
			ma = max(ma, max(lahubina2[i][j-1]+lahubina1[i][j+1]+lahub1[i+1][j]+lahub2[i-1][j], lahubina2[i+1][j] + lahubina1[i-1][j] + lahub1[i][j+1] + lahub2[i][j-1]));
		}

	}
	cout<<ma;
}