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

struct Event
{
	int	t;
	int	d;

	bool	operator<(Event other) const
	{
		return t < other.t;
	}
};

int	n, m, k;

std::vector<Event>	events;
vl					operations;
vl					delta_op;
vl					delta_a;
vii					range;
vl					a;


int		main(void)
{
	std::ios_base::sync_with_stdio(false);

	std::cin >> n >> m >> k;
	a.resize(n), operations.resize(m), delta_op.resize(m), delta_a.resize(n+1), range.resize(m), events.resize(2*k);

	for (auto &v  : a) std::cin >> v;

	FOR(i,0,m) std::cin >> range[i].first >> range[i].second >> operations[i];

	FOR(i,0,k)
	{
		std::cin >> events[2*i].t >> events[2*i+1].t;
		events[2*i].d = 1, events[2*i+1].d = -1;
		events[2*i].t--;
	}
	std::sort(all(events));

	for (int i(0); i < 2*k;)
	{
		int	right(i);
		if (events[i].t >= m) break;
		while (right < 2*k and events[right].t == events[i].t) delta_op[events[right].t] += events[right].d, ++right;
		i = right;
	}

	ll	coeff = 0;
	for (int i(0); i < m; ++i)
	{
		coeff += delta_op[i];
		delta_a[range[i].first-1] += coeff * operations[i];
		delta_a[range[i].second] -= coeff * operations[i];
	}

	ll	add(0);
	for (int i(0); i < n; ++i)
	{
		add += delta_a[i];
		std::cout << a[i] + add << " ";
	}
	std::cout << std::endl;

}