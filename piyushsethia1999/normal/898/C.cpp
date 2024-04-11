#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

bool issub(string s, string t)
{
	int ts = t.size();
	int ss = s.size();
	for (int i = 0; i < min(ss, ts); i++)
		if (s[ss - i - 1] != t[ts - i - 1])
			return false;
	return true;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	std::vector<std::vector<string> > v;
	std::map<string, int> m;
	int y = 0;
	for (int i = 0; i < n; ++i)
	{
		string s; cin >> s;
		int j;
		if (m[s] != 0)
		{
			j = m[s];
		}
		else {
			j = m[s] = (++y);
			v.pb(std::vector<string> ());
		}
		j--;
		int c; cin >> c;
		for (int k = 0; k < c; ++k)
		{
			cin >> s;
			bool b = false;
			for (int p = 0; p < v[j].size(); ++p)
				if (issub(v[j][p], s)) {
					v[j][p] = (v[j][p].size() > s.size()) ? v[j][p] : s;
					b = true;
					break;
				}
			if (!b)
			{
				v[j].pb(s);
			}
		}
	}
	cout << m.size() << "\n";
	for (auto p : m)
	{
		cout << p.first << " " << v[p.second - 1].size() << " ";
		for (string s : v[p.second - 1])
			cout << s << " ";
		cout << "\n";
	}
}