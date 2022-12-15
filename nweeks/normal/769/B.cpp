#include <bits/stdc++.h>

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define dbg(x) std::cerr<<#x<<" = " << (x) << std::endl
#define pnl(x) std::cout << x << "\n"

typedef	std::vector<int>	vi;
typedef std::pair<int,int>	ii;
typedef std::vector<std::string>	vs;
typedef std::vector<ii>	vii;
typedef std::vector<long long>	vl;
typedef	long long ll;

struct P
{
	int		id, messages;

	bool	operator<(P other) const
	{
		return messages < other.messages;
	}
};

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	
	int		n;
	std::cin >> n;
	
	vi	a(n);
	for (int i(0); i < n; ++i)
		std::cin >> a[i];
	std::priority_queue<P>	knows;
	std::priority_queue<P>	doesnt;
	vii		messages;
	for (int i(1); i < n; ++i)
		doesnt.push({i+1, a[i]});
	if (a[0] == 0)
	{
		pnl(-1); return 0;
	}
	knows.push({1, a[0]});

	while (!doesnt.empty() and !knows.empty())
	{
		P	cur = knows.top(); knows.pop();
		P	next = doesnt.top(); doesnt.pop();
		if (cur.messages != 1) knows.push({cur.id, cur.messages - 1});
		if (next.messages != 0)	knows.push({next.id, next.messages});
		messages.pb({cur.id, next.id});
	}
	if (!doesnt.empty()) {
		pnl(-1); return 0;
	}
	pnl(messages.size());
	for (auto v : messages)
		std::cout << v.first << " " << v.second << "\n";
	

}