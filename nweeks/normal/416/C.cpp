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


const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

struct Group
{
	int		size, spend, index;

	bool	operator<(Group other) const
	{
		return spend > other.spend;
	}
};

struct Table
{
	int	size, index, group;

	bool	operator<(Table other) const
	{
		return size < other.size;
	}
};


int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int		n_groups;
	std::cin>>n_groups;
	std::vector<Group>	groups(n_groups);
	FOR(i,0,n_groups)
	{
		std::cin >> groups[i].size >> groups[i].spend;
		groups[i].index = i+1;
	}
	std::sort(all(groups));
	int		n_tables;
	std::cin >> n_tables;
	std::vector<Table>	tables(n_tables);
	FOR(i, 0, n_tables)
	{
		std::cin >> tables[i].size;	
		tables[i].index=i+1, tables[i].group = 0;;
	}
	std::sort(all(tables));
	int		total(0), groups_assigned(0);
	for (int i(0); i < n_groups; ++i)
	{
		int		cur(0);
		while (cur < n_tables and tables[cur].size < groups[i].size)
			++cur;
		while (cur < n_tables and tables[cur].group != 0)
			++cur;
		if (cur == n_tables)
			continue ;
		total += groups[i].spend;
		groups_assigned++;
		tables[cur].group = groups[i].index;
	}
	std::cout << groups_assigned << " " << total << std::endl;
	for (auto v : tables)
		if (v.group != 0)
			std::cout << v.group << " " << v.index << "\n";
}