#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1 << 20;
int twos[MAXN + 1];
int factwos[MAXN + 1];
int b[MAXN];
int ans[MAXN];
map<pair<int, int>, int> mp;

int f(int n, int k)
{
	if (n < 0)
		return 0;
	k = max(k, 0);
	if (!mp.count({n, k}))
	{
		//cout << "F " << n << " " << k << endl;
		int num = 0;
		for (int i = k; i <= n; i++)
		{
			int cnt = factwos[n] - factwos[n - i] - factwos[i];
			//cout << "cnt " << n << " " << i << " " << cnt << endl;
			if (!cnt)
				num = 1 - num;
			//num += cnt;
			//num = num & 1;
		}
		mp[{n, k}] = num;
	}
	return mp[{n, k}];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i <= MAXN; i++)
	{
		int j = i;
		while (!(j & 1))
		{
			j >>= 1;
			twos[i]++;
		}
		factwos[i] = twos[i] + factwos[i - 1];
		//if (!(i % 100))
			//cout << factwos[i] << endl;
	}
	//for (int i = 0; i <= 5; i++)
	//{
		////cout << "factwos " << i << " " << factwos[i] << endl;
		//cout << i << " " << f(5, i) << endl;
	//}
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < n; i++)
	{
		long long ind = b[i];
		int j = i;
		while (j < n)
		{
			if (j != i)
			{
				if (b[j] >= 20)
					break;
				ind *= 1 << b[j];
			}
			if (ind >= MAXN)
				break;
			int m = n - 1 - (j - i) - (j < n - 1) - (i > 0);
			int kk = k - (j < n - 1) - (i > 0);
			int par = f(m, kk);
			if (par)
				ans[ind] = 1 - ans[ind];
			j++;
		}
	}
	int ptr = MAXN - 1;
	while (ptr && !ans[ptr])
		ptr--;
	while (ptr >= 0)
	{
		cout << ans[ptr];
		ptr--;
	}
	cout << "\n";
	return 0;
}