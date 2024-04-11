#include <bits/stdc++.h>

using namespace std;

int n, a[100005], b[100005], c[100005];

vector<tuple<int,int,int>> vecs;

void work(int l, int r, int d)
{
	vecs.emplace_back(l, r, d);
	for (int i = l; i <= r; ++i)
		b[i - l] = a[i];
	for (int i = 0; i <= r - l; ++i)
		c[i] = b[(i + d) % (r - l + 1)];
	for (int i = l; i <= r; ++i)
		a[i] = c[i - l];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		vecs.clear();
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		for (int i = 1; i < n; ++i)
		{
			int minp = i;
			for (int j = i; j <= n; ++j)
				if (a[j] < a[minp])
					minp = j;
			if (minp != i)
			{
				work(i, n, minp - i);
			}
		}
		printf("%d\n", vecs.size());
		for (auto [i,j,k]:vecs)printf("%d %d %d\n",i,j,k);
	}
}