#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 2e5;

void solve(void)
{
	ll n, m, k;
	cin >> n >> m >> k;

	string path = "";
	string row = ""; 
	for (int i(0); i < m-1; ++i)
		row += "RDU";
	for (int i(1); i < m; ++i)
		row += "L";

	for (int i(0); i < n-1; ++i)
		path += row + "D";

	for (int i(0); i < m-1; ++i)
		path += "R";
	for (int i(0); i < m-1; ++i)
		path += "L";
	for (int i(1); i < n; ++i)
		path += "U";

	if (k > path.size())
	{
		cout << "NO" << endl;
		return ;
	}
	cout << "YES" << endl;

	int lft(k);
	vector<pair<int, string> > op;
	int i(0);
	while (lft > 0 and i < n-1)
	{
		// GO TO THE RIGHT :
		int f = m-1;
		int ff = f;
		while (3 * f > lft)
			--f;
		lft -= 3 * f;
		if (f)
			op.push_back({f, "RDU"});
		if (ff > f)
		{
			string t = "";
			string c = "RDU";
			for (int x(0); x < lft; ++x)
				t += c[x];
			lft = 0;
			if (t.size() > 0)
				op.push_back({1, t});
		}
		if (lft == 0) break;

		// GO LEFT :
		f = m-1;
		if (m > 1)
			op.push_back({min(lft, f), "L"});
		lft -= min(lft, f);
		if (lft == 0) break;

		// GO DOWN
		op.push_back({1, "D"});
		lft--;
		++i;
	}

	if (lft and m > 1)
	{
		op.push_back({(int)min(lft, (int)m-1), "R"});
		lft -= min(lft, (int)m-1);
	}
	if (lft and m > 1)
	{
		op.push_back({(int)min(lft, (int)m-1), "L"});
		lft -= min(lft, (int)m-1);
	}
	if (lft)
	{
		op.push_back({(int)lft, "U"});
		lft = 0;
	}

	cout << op.size() << endl;
	for (auto o : op)
		cout << o.first << ' ' << o.second << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();	
}