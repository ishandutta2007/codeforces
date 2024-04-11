#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string command;

map<char, pair<int, int>> delta;

void init()
{
	delta['L'] = {-1, 0};
	delta['R'] = {1, 0};
	delta['U'] = {0, 1};
	delta['D'] = {0, -1};
}

pair<int, int> get_nxt(char c, pair<int, int> cur)
{
	auto p = delta[c];
	return make_pair(cur.first + p.first, cur.second + p.second);
}

bool simulate(pair<int, int> block)
{
	pair<int, int> cur = make_pair(0, 0);
	for (auto c : command)
	{
		auto nxt = get_nxt(c, cur);
		if (nxt != block)
			cur = nxt;
	}
	if (cur == make_pair(0, 0))
		return true;
	return false;
}

void solve()
{
	cin >> command;
	if (simulate(make_pair((int)1e9, (int)1e9)))
	{
		cout << (int)1e9 << ' ' << (int)1e9 << '\n';
		return ;
	}
	pair<int, int> cur = make_pair(0, 0);
	for (auto c : command)
	{
		cur = get_nxt(c, cur);
		if (cur != make_pair(0,0) and simulate(cur))
		{
			cout << cur.first << ' ' << cur.second << '\n';
			return ;
		}

	}
	cout << "0 0\n";
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	init();
	int t;
	cin >> t;
	while (t--)
		solve();
}