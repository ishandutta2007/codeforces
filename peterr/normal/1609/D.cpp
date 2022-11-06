#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E3;
int par[MAXN + 1];
int sz[MAXN + 1];

int getroot(int x)
{
	if (par[x] != x)
		par[x] = getroot(par[x]);
	return par[x];
}

bool mge(int x, int y)
{
	x = getroot(x);
	y = getroot(y);
	if (x == y)
		return false;
	if (sz[x] > sz[y])
		swap(x, y);
	par[x] = y;
	sz[y] += sz[x];
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i <= MAXN; i++)
	{
		par[i] = i;
		sz[i] = 1;
	}
	int n, d;
	cin >> n >> d;
	int useless = 0;
	for (int i = 0; i < d; i++)
	{
		int x, y;
		cin >> x >> y;
		if (!mge(x, y))
			useless++;
		//cout << "useless " << i << " " << useless << "\n";
		vector<int> vec;
		for (int j = 1; j <= n; j++)
		{
			if (par[j] == j)
				vec.push_back(sz[j]);
		}
		sort(vec.rbegin(), vec.rend());
		int ans = 0;
		for (int j = 0; j < useless + 1; j++)
		{
			if (j >= (int) vec.size())
				break;
			ans += vec[j];
		}
		cout << ans - 1 << "\n";
	}
	return 0;
}