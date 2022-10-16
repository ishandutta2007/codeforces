#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int d, s;
	cin >> d >> s;

	vector<int> dist (d * (s + 1), -1);
	auto par = dist, dig = dist;

	auto state = [&] (int x, int y)
	{
		return x * d + y;
	};

	auto decode = [&] (int x)
	{
		return pair<int, int>{x / d, x % d};
	};

	queue<int> q;
	dist[state(0, 0)] = 0;
	q.push(state(0, 0));

	while (!q.empty())
	{
		int cur = q.front();

		int sum, rem;
		tie(sum, rem) = decode(cur); q.pop();

		for (int i = 0; i < 10; i++)
		{
			int sum_to = sum + i;
			int rem_to = (rem * 10 + i) % d;
			if (sum_to > s)
				continue;
			int to = state(sum_to, rem_to);
			if (dist[to] == -1)
			{
				dist[to] = dist[cur] + 1;
				par[to] = cur;
				dig[to] = i;
				q.push(to);
			}
		}
	}

	if (dist[state(s, 0)] == -1)
		cout << -1 << endl;
	else
	{
		string ans;
		int cur = state(s, 0);
		while (par[cur] != -1)
		{
			ans += dig[cur] + '0';
			cur = par[cur];
		}

		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}