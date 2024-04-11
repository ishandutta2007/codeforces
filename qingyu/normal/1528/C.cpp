#include <bits/stdc++.h>

const int N = 5e5 + 50; 
int n, l[N], r[N], tot, ans;
std::vector<int> G[N], H[N];
std::set<std::pair<int, int>> set;
std::vector<std::pair<int, std::pair<int, int>>> events;

void tour(int x)
{
	l[x] = ++tot;
	for (int y : H[x])
		tour(y);
	r[x] = ++tot;
}

inline void emplace(int l, int r)
{
	auto q = set.upper_bound(std::make_pair(l, -1));
	if (q != set.end() && q->second <= r) return;
	auto p = set.lower_bound(std::make_pair(l, -1));
	
	if (p != set.begin())
	{
		--p;
		if (p->second >= r)
		{
			events.emplace_back(2, *p);
			set.erase(p);
		}
	}
	events.emplace_back(1, std::make_pair(l, r));
	set.emplace(l, r);
}

void dfs(int x)
{
	int cur = events.size();
	emplace(l[x], r[x]);
	ans = std::max(ans, (int)set.size());
	for (int y : G[x])
		dfs(y);
	while (events.size() > cur)
	{
		auto [x, p] = events.back(); events.pop_back();
		if (x == 1) set.erase(p);
		else set.emplace(p);
	}
}

int main()
{
	int t;
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		for (int i = 1; i <= n; ++i)
			G[i].clear(), H[i].clear();
		for (int i = 2; i <= n; ++i)
		{
			int x; std::cin >> x; G[x].push_back(i);
		}
		for (int i = 2; i <= n; ++i)
		{
			int x; std::cin >> x; H[x].push_back(i);
		}
		ans = tot = 0;
		events.clear();
		tour(1);
		dfs(1);
		std::cout << ans << '\n';
	}
	return 0;
}