#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 1E5;
int a[MAXN];

void add(int &x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

vector<tuple<int, int, int>> decompose(int x)
{
	int blocks = 1;
	vector<tuple<int, int, int>> vec;
	while (blocks <= x)
	{
		int lo = x / blocks;
		int hi = (x + blocks - 1) / blocks;
		vec.push_back({lo, hi, blocks - 1});
		if (lo == hi)
		{
			blocks++;
		}
		else
		{
			if (hi == 1)
				break;
			blocks = (x + hi - 2) / (hi - 1);
		}
	}
	return vec;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			//cout << "blocks of " << a[i] << endl;
			//for (tuple<int, int, int> tup : decompose(a[i]))
			//{
				//cout << get<0>(tup) << " " << get<1>(tup) << " " << get<2>(tup) << endl;
			//}
		}
		vector<tuple<int, int, int>> buckets = {{MAXN, MAXN, 0}};
		vector<pair<int, int>> cnts = {{0, 0}};
		for (int i = n - 1; i >= 0; i--)
		{
			vector<tuple<int, int, int>> new_buckets = decompose(a[i]);
			vector<pair<int, int>> new_cnts(new_buckets.size());
			int ptr = 0;
			new_cnts[0].first++;
			for (int j = 0; j < (int) cnts.size(); j++)
			{
				while (get<1>(new_buckets[ptr]) > get<0>(buckets[j]))
					ptr++;
				new_cnts[ptr].first += cnts[j].first;
				add(new_cnts[ptr].second, cnts[j].second);
				add(new_cnts[ptr].second, (int) ((long long) cnts[j].first * get<2>(new_buckets[ptr]) % MOD));
			}
			for (pair<int, int> pr : new_cnts)
			{
				add(ans, pr.second);
			}
			//cout << "iter " << i << endl;
			//for (int i = 0; i < (int) new_buckets.size(); i++)
			//{
				//cout << "bucket " << i << " " << get<0>(new_buckets[i]) << " " << get<1>(new_buckets[i]) << " " << get<2>(new_buckets[i]) << " " << new_cnts[i].first << " " << new_cnts[i].second << endl;
			//}
			swap(new_buckets, buckets);
			swap(new_cnts, cnts);
		}
		cout << ans << "\n";
	}
	return 0;
}