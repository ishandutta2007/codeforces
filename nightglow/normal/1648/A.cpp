#include <bits/stdc++.h>

#define N 500005

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

vector<int> v[N];

int cnt[N];

long long ans, sum[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			int x; scanf("%d", &x);
			v[i].pb(x); 
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			ans += 1ll * cnt[v[i][j]] * i - sum[v[i][j]];
			cnt[v[i][j]]++; sum[v[i][j]] += i;
		}
	memset(cnt, 0, sizeof(cnt));
	memset(sum, 0, sizeof(sum));
	for (int j = 0; j < m; ++j)
		for (int i = 0; i < n; ++i)
		{
			ans += 1ll * cnt[v[i][j]] * j - sum[v[i][j]];
			cnt[v[i][j]]++; sum[v[i][j]] += j;
		}	
	cout << ans << endl;
}