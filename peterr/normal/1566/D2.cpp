#include <bits/stdc++.h>

using namespace std;

struct bit
{
	bit() = default;
	
	bit(int n) : vec(n)
	{
	}
	
	int query(int pos)
	{
		int ans = 0;
		while (pos)
		{
			ans += vec[pos];
			pos -= pos & -pos;
		}
		return ans;
	}
	
	void inc(int pos, int amt)
	{
		while (pos < (int) vec.size())
		{
			vec[pos] += amt;
			pos += pos & -pos;
		}
	}
	
	vector<int> vec;
};

const int MAXN = 300;
bit seats[MAXN + 1];
int a[MAXN * MAXN];
int b[MAXN * MAXN];
map<int, vector<pair<int, int>>> where;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n * m; i++)
		{
			cin >> a[i];
		}
		copy(a, a + n * m, b);
		sort(b, b + n * m);
		int ptr = 0;
		int r = 1;
		int c = 1;
		where.clear();
		while (ptr < n * m)
		{
			int sight = b[ptr];
			vector<pair<int, int>> vec;
			while (ptr < n * m && b[ptr] == sight)
			{
				vec.push_back({r, c});
				c++;
				if (c == m + 1)
				{
					c = 1;
					r++;
				}
				ptr++;
			}
			sort(vec.begin(), vec.end(), [&] (pair<int, int> x, pair<int, int> y) {
				if (x.first == y.first)
					return x.second < y.second;
				return x.first > y.first;
			});
			where[sight] = vec;
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			seats[i] = bit(m + 1);
		}
		for (int i = 0; i < n * m; i++)
		{
			pair<int, int> pr = where[a[i]].back();
			where[a[i]].pop_back();
			ans += seats[pr.first].query(pr.second);
			seats[pr.first].inc(pr.second, 1);
		}
		cout << ans << "\n";
	}
	return 0;
}