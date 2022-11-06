#include <bits/stdc++.h>

using namespace std;

const int BLOCK = 300;
const int MAXN = 1E5;
const int NUM = (MAXN + BLOCK - 1) / BLOCK;
int a[MAXN];
int b[MAXN];
long long sum[NUM];
long long small[NUM];
long long large[NUM];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		b[i] = x - a[i];
	}
	for (int i = 0; i < n; i++)
	{
		sum[i / BLOCK] += b[i];
	}
	for (int i = 0; i < NUM; i++)
	{
		small[i] = large[i] = 0;
		long long pref = 0;
		for (int j = 0; j < BLOCK; j++)
		{
			int ind = i * BLOCK + j;
			if (ind >= n)
				break;
			pref += b[ind];
			small[i] = min(small[i], pref);
			large[i] = max(large[i], pref);
		}
	}
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		long long pref = 0;
		bool valid = true;
		long long ans = 0;
		while (l % BLOCK != 0 && l <= r)
		{
			pref += b[l];
			//cout << "left " << l << endl;
			//cout << "pref " << pref << endl;
			if (pref < 0)
				valid = false;
			l++;
			ans = max(ans, pref);
		}
		while (r >= l + BLOCK - 1)
		{
			int blockInd = l / BLOCK;
			long long smallPref = pref + small[blockInd];
			long long largePref = pref + large[blockInd];
			if (smallPref < 0)
				valid = false;
			ans = max(ans, largePref);
			pref += sum[blockInd];
			l += BLOCK;
		}
		while (l <= r)
		{
			pref += b[l];
			if (pref < 0)
				valid = false;
			l++;
			ans = max(ans, pref);
		}
		if (pref)
			valid = false;
		if (!valid)
			cout << "-1\n";
		else
			cout << ans << "\n";
	}
	return 0;
}