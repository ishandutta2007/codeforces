#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
tuple<int, int, int, int> a[MAXN];
int par[MAXN];
int sz[MAXN];
int explode[MAXN];

int getRoot(int x)
{
	if (par[x] != x)
		par[x] = getRoot(par[x]);
	return par[x];
}

bool mge(int x, int y)
{
	x = getRoot(x);
	y = getRoot(y);
	if (x == y)
		return false;
	if (sz[x] > sz[y])
		swap(x, y);
	par[x] = y;
	sz[y] += sz[x];
	explode[y] = min(explode[y], explode[x]);
	return true;
}

bool check(int n, int target)
{
	int extra = 0;
	for (int i = 0; i < n; i++)
	{
		if (par[i] != i)
			continue;
		extra += explode[i] > target;
	}
	return target + 1 >= extra;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			int x, y, timer;
			cin >> x >> y >> timer;
			a[i] = {x, y, timer, i};
			par[i] = i;
			sz[i] = 1;
			explode[i] = timer;
		}
		for (int i = 0; i < 2; i++)
		{
			sort(a, a + n);
			int ptr = 0;
			while (ptr < n)
			{
				int x = get<0>(a[ptr]);
				ptr++;
				while (ptr < n && get<0>(a[ptr]) == x)
				{
					if (get<1>(a[ptr]) - get<1>(a[ptr - 1]) <= k)
					{
						mge(get<3>(a[ptr]), get<3>(a[ptr - 1]));
						//cout << "merged " << get<3>(a[ptr]) << " " << get<3>(a[ptr - 1]) << endl;
					}
					ptr++;
				}
			}
			for (int j = 0; j < n; j++)
			{
				swap(get<0>(a[j]), get<1>(a[j]));
			}
		}
		int ans = -1;
		for (int jump = 1E9; jump; jump >>= 1)
		{
			while (ans + jump <= 1E9 && !check(n, ans + jump))
				ans += jump;
		}
		cout << ans + 1 << "\n";
	}
	return 0;
}