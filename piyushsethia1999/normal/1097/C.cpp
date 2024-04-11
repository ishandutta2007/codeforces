#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

bool left_valid(string& a)
{
	int cn = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] == '(')
			cn++;
		else
		{
			cn--;
			if (cn < 0)
				return false;
		}
	}
	return true;
}
bool right_valid(string& a)
{
	int cn = 0;
	for (int i = a.size() - 1; i >= 0; --i)
	{
		if (a[i] == ')')
			cn++;
		else
		{
			cn--;
			if (cn < 0)
				return false;
		}
	}
	return true;
}

int rig(string& a)
{
	int cn = 0;
	for (int i = 0; i < a.size(); ++i)
		if (a[i] == ')')
			cn++;
	return cn;
}

int lef(string& a)
{
	int cn = 0;
	for (int i = 0; i < a.size(); ++i)
		if (a[i] == '(')
			cn++;
	return cn;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	vector<string> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	int zero = 0;
	std::map<int, int> m;
	for (int i = 0; i < n; ++i)
	{
		bool l = left_valid(a[i]);
		bool r = right_valid(a[i]);
		if (l && r)
			zero++;
		else if (r)
			m[rig(a[i]) - lef(a[i])]++;
		else if (l)
			m[rig(a[i]) - lef(a[i])]++;
	}
	int tot = zero / 2;
	auto m1 = m;
	for (auto p : m1)
	{
		int f = p.first;
		if (f > 0)
			tot += min(p.second, m[-f]);
	}
	cout << tot;
}