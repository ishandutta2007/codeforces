#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int a[MAXN + 1];

long long cost(int dist, int comps)
{
	int j = dist / comps;
	int numBig = dist % comps;
	int numSmall = comps - numBig;
	return (long long) j * j * numSmall + (long long) (j + 1) * (j + 1) * numBig;
}

pair<long long, int> check(int n, long long x)
{
	pair<long long, int> ans;
	for (int i = 1; i <= n; i++)
	{
		int dist = a[i] - a[i - 1];
		//cout << "dist " << dist << endl;
		if (dist == 1 || cost(dist, 1) - cost(dist, 2) < x)
			continue;
		int lo = 1;
		int hi = a[i] - a[i - 1] - 1;
		while (lo < hi)
		{
			int mid = (lo + hi + 1) / 2;
			if (cost(dist, mid) - cost(dist, mid + 1) >= x)
				lo = mid;
			else
				hi = mid - 1;
		}
		//cout << "loooo " << i << " " << lo << endl;
		ans.first += cost(dist, 1) - cost(dist, lo + 1);
		ans.second += lo;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout << cost(5, 1) << " " << cost(5, 5) << endl;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	long long m;
	cin >> m;
	for (int i = 1; i <= n; i++)
	{
		m -= (long long) (a[i] - a[i - 1]) * (a[i] - a[i - 1]);
	}
	m = -m;
	if (m <= 0)
	{
		cout << "0\n";
		return 0;
	}
	long long lo = 1;
	long long hi = 1E18;
	while (lo < hi)
	{
		long long mid = (lo + hi) / 2;
		//cout << "mid " << mid << " " << check(n, mid).first << " " << check(n, mid).second << endl;
		if (check(n, mid).first < m)
			hi = mid;
		else
			lo = mid + 1;
	}
	//cout << "lo " << lo << endl;
	//cout << "START" << endl;
	pair<long long, int> pr = check(n, lo);
	m -= pr.first;
	//cout << "first " << pr.first << endl;
	//cout << "second " << pr.second << endl;
	//cout << "m " << m << endl;
	int ans = pr.second;
	if (lo > 1)
		ans += (m + lo - 2) / (lo - 1);
	cout << ans << "\n";
	return 0;
}