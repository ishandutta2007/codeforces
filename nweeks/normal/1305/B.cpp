#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	string s;
	cin >> s;
	int n = SZ(s);
	

	vector<vector<int>> sol;
	deque<pair<int, int> > data(n);
	for (int i(0); i < n; ++i)
		data[i] = {i, (s[i] == '(' ? 1 : -1)};
	
	while (data.size() > 1)
	{
		set<int> cur_sol;
		
		while (data.size() > 1)
		{
			if (data.front().second== 1 and data.back().second == -1)
			{
				cur_sol.insert(data.front().first+1);
				cur_sol.insert(data.back().first+ 1);
				data.pop_front();
				data.pop_back();
			}
			else if (data.front().second == -1)
				data.pop_front();
			else
				data.pop_back();
		}
		if (SZ(cur_sol) > 0)
		{
			vector<int> s;
			s.reserve(SZ(cur_sol));
			for (auto e : cur_sol)
				s.push_back(e);
			sol.push_back(s);
		}
	}
	cout << sol.size() << endl;
	for (auto v : sol)
	{
		cout << SZ(v) << '\n';
		for (auto e : v)
			cout << e << ' ';
		cout << '\n';
	}
}