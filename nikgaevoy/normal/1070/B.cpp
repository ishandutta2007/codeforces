#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool bit (int mask, int id)
{
	return ((mask >> id) & 1);
}

struct trie
{
	vector<vector<int>> son;
	vector<int> mask, type;

	trie () : son(1, vector<int>(2, -1)), mask(1), type(1, -1) {}

	bool add (string s, int tp)
	{
		int cur = 0;
		mask[cur] |= (1 << tp);
		for (char ch : s)
		{
			assert(ch == '0' || ch == '1');
			int &dest = son[cur][ch - '0'];
			if (dest == -1)
			{
				son.emplace_back(2, -1);
				mask.push_back(0);
				type.push_back(-1);
				dest = (int)son.size() - 1;
			}

			cur = dest;
			mask[cur] |= (1 << tp);
		}

		if (type[cur] != -1 && type[cur] != tp)
			return false;
		if (bit(mask[cur], tp ^ 1))
			return false;

		type[cur] = tp;
		return true;
	}

	void dfs (int root, string path, vector<string> &res)
	{
		if (root == -1)
			return;

		if (!bit(mask[root], 0))
			return;

		if (!bit(mask[root], 1))
		{
			res.push_back(path);
			return;
		}

		for (int i = 0; i < 2; i++)
			dfs(son[root][i], path + char('0' + i), res);
	}
};

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	cin >> n;

	trie data;

	bool ok = true;
	vector<pair<string, int>> v;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		const int tp = (s[0] == '-' ? 0 : 1);
		s = s.substr(1);

		string what;
		{
			for (char &ch : s) if (ch == '/') ch = ' ';

			for (char &ch : s) if (ch == '.') ch = ' ';
			stringstream ss(s);

			int x;
			for (int it = 0; it < 4; it++)
			{
				assert(ss >> x);
				for (int j = 7; j >= 0; j--)
					what += bit(x, j) + '0';
			}

			if (ss >> x)
				assert(0 <= x && x <= 32);
			else
				x = 32;
			what = what.substr(0, x);

			v.emplace_back(what, tp);
			ok &= data.add(what, tp);
		}
	}

	for (auto x : v)
		ok &= data.add(x.first, x.second);

	if (!ok)
		cout << -1 << endl;
	else
	{
		try
		{
			vector<string> res;
			data.dfs(0, "", res);
			cout << (int)res.size() << "\n";
			for (string x : res)
			{
				int len = (int)x.size();
				while (x.size() < 32U)
					x += "0";

				for (int i = 0; i < 4; i++)
				{
					if (i > 0)
						cout << ".";
					int ox = 0;
					for (int j = 0; j < 8; j++)
						ox *= 2, ox += x[i * 8 + j] - '0';
					cout << ox;
				}

				cout << "/" << len << "\n";
			}
		}
		catch (...)
		{
			cout << -1 << endl;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}