#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXK = 3E5;
const int MAXN = 1E6;
tuple<int, int, int> a[MAXK];
int cnt[MAXN + 1];
map<int, int> mp[MAXN + 1];
int twopow[MAXN + 1];
int res[MAXK];
bool isBad[MAXN + 1];
int bal[MAXN + 1][2];
bool empty_[MAXK];
bool consistent_[MAXK];
int totalBal_[2];

void add(int &x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

void solve(int n, int m, int k)
{
	//cout << "SOLVE\n";
	totalBal_[0] = totalBal_[1] = 0;
	fill(cnt + 1, cnt + n + 1, 0);
	fill(isBad + 1, isBad + n + 1, false);
	for (int i = 1; i <= n; i++)
	{
		bal[i][0] = bal[i][1] = 0;
		mp[i].clear();
	}
	int free = n;
	int bad = 0;
	for (int i = 0; i < k; i++)
	{
		int x = get<0>(a[i]);
		int y = get<1>(a[i]);
		int t = get<2>(a[i]);
		
		auto doDelete = [&]() {
			if (mp[x].count(y))
			{
				if (isBad[x])
					bad--;
				cnt[x]--;
				int v = mp[x][y];
				int par = (v + y) & 1;
				bal[x][par]--;	
				totalBal_[(x + y + v) & 1]--;
				mp[x].erase(y);
				isBad[x] = bal[x][0] && bal[x][1];
				if (isBad[x])
					bad++;
				if (!bal[x][0] && !bal[x][1])
					free++;
			}
		};
		
		if (t == -1)
		{
			doDelete();
		}
		else
		{
			doDelete();
			if (!cnt[x])
				free--;
			cnt[x]++;
			if (isBad[x])
				bad--;
			mp[x][y] = t;
			int par = (t + y) & 1;
			bal[x][par]++;
			totalBal_[(x + y + t) & 1]++;
			isBad[x] = bal[x][0] && bal[x][1];
			if (isBad[x])
				bad++;
		}
		empty_[i] = free == n;
		consistent_[i] = !totalBal_[0] || !totalBal_[1];
		//cout << "iter " << i << " " << bad << " " << free << endl;
		if (!bad)
			add(res[i], twopow[free]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	twopow[0] = 1;
	for (int i = 1; i <= MAXN; i++)
	{
		twopow[i] = twopow[i - 1];
		add(twopow[i], twopow[i]);
	}
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y, t;
		cin >> x >> y >> t;
		a[i] = {x, y, t};
	}
	solve(n, m, k);
	for (int i = 0; i < k; i++)
	{
		swap(get<0>(a[i]), get<1>(a[i]));
	}
	solve(m, n, k);
	for (int i = 0; i < k; i++)
	{
		if (empty_[i])
			add(res[i], MOD - 2);
		else if (consistent_[i])
			add(res[i], MOD - 1);
		cout << res[i] << "\n";
	}
	return 0;
}