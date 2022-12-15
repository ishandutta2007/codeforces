#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

ll solve(void);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tests;
	cin >> nb_tests;

	for (int i(0); i < nb_tests; ++i)
		cout << solve() << '\n'; 
}

ll solve(void)
{
	int len;
	cin >> len;
	string a, b;
	cin >>  a>> b;
	
	for (int i(0); i < len; ++i)
		if (a[i] > b[i])
			return -1;

	int ans(0);
	array<set<int>, 26> pos;
	for (int i(0); i < len; ++i)
		if (a[i] != b[i])
			pos[a[i]-'a'].insert(b[i]-'a');
	
	for (int i(0); i < 26; ++i)
	{
		if (SZ(pos[i]) == 0)
			continue;
		ans++;
		int where = *pos[i].begin();
		for (auto v : pos[i])
			if (v != where)
				pos[where].insert(v);
	}
	
	return ans;
}