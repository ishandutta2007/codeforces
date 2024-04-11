#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int MOD = 1000000007;
const int MAX = 1000005;
vector<int> dp[MAX];
int a[MAX];
void add(int &a, int b)
{
	a += b;
	if (a >= MOD)
		a -= MOD;
}
int main()
{
	int n, k;
	long long l;
	scanf("%d %lld %d", &n, &l, &k);
	for (int i = 0; i < n; i++)
		dp[i].resize(k + 1);
	vector<int> vals;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		vals.push_back(a[i]);
	}
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	for (int i = 0; i < n; i++)
	{
		a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
		dp[i][1] = 1;
	}
	vector<int> cnt;
	cnt.resize(vals.size());
	for (int j = 2; j <= k; j++)
	{
		for (int i = 0; i < (int)cnt.size(); i++)
			cnt[i] = 0;
		for (int i = 0; i < n; i++)
			add(cnt[a[i]], dp[i][j - 1]);
		for (int i = 1; i < (int)cnt.size(); i++)
			add(cnt[i], cnt[i - 1]);
		for (int i = 0; i < n; i++)
			dp[i][j] = cnt[a[i]];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= k; j++)
		{
			long long b = l / n;
			if (i < l % n)
				b++;
			b = b - j + 1;
			if (b > 0)
				ans = (ans + (b % MOD) * dp[i][j]) % MOD;
		}
	printf("%d\n", ans);
	return 0;
}