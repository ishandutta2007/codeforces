#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<class T>
T &remax(T &x, const T &y)
{
	return x = max(x, y);
}


vector<vector<ll>> zero(int n)
{
	vector<vector<ll>> matr(n, vector<ll>(n, numeric_limits<ll>::min() / 1000));

	return matr;
}


vector<vector<ll>> id(int n)
{
	auto matr = zero(n);

	for (int i = 0; i < n; i++)
		matr[i][i] = 0;

	return matr;
}


class crucian
{
	struct node
	{
		array<int, 27> nxt;
		ll val;
		int link, par;

		node(int par = -1) : val(0), link(-1), par(par)
		{
			fill(nxt.begin(), nxt.end(), -1);
		}


		int &operator[](char it)
		{
			return nxt[it - 'a'];
		}
	};

	vector<node> mem;

public:
	crucian() : mem(1)
	{}


	void add(const string &str, int add)
	{
		auto cur = 0;

		for (auto it : str)
		{
			if (mem[cur][it] == -1)
			{
				mem[cur][it] = mem.size();
				mem.emplace_back(cur);
			}

			cur = mem[cur][it];
		}

		mem[cur].val += add;
	}


	[[nodiscard]] auto link_walk(int cur, int ch, int ind = -1) const
	{
		while (mem[cur].par != -1 && (mem[cur].nxt[ch] == -1 || mem[cur].nxt[ch] == ind))
			cur = mem[cur].link;

		if (mem[cur].nxt[ch] != -1 && mem[cur].nxt[ch] != ind)
			cur = mem[cur].nxt[ch];

		return cur;
	}


	void build()
	{
		queue<pair<int, int>> q;
		q.emplace(0, -1);

		while (!q.empty())
		{
			int ind, ch;
			tie(ind, ch) = q.front();
			q.pop();

			auto &v = mem[ind];

			for (int i = 0; i < v.nxt.size(); i++)
				if (v.nxt[i] != -1)
					q.emplace(v.nxt[i], i);

			if (v.par != -1)
			{
				v.link = link_walk(v.par, ch, ind);
				v.val += mem[v.link].val;
			}
		}
	}


	[[nodiscard]] vector<vector<ll>> to_matr() const
	{
		vector<vector<ll>> matr = zero(mem.size());

		for (int i = 0; i < mem.size(); i++)
			for (int j = 0; j < mem[i].nxt.size(); j++)
			{
				auto it = link_walk(i, j);

				if (it != -1)
					remax(matr[i][it], mem[it].val);
			}

		return matr;
	}
};


vector<vector<ll>> mult(const vector<vector<ll>> &a, const vector<vector<ll>> &b)
{
	vector<vector<ll>> c = zero(a.size());

	for (int i = 0; i < c.size(); i++)
		for (int j = 0; j < c[i].size(); j++)
			for (int k = 0; k < b.size(); k++)
				remax(c[i][j], a[i][k] + b[k][j]);

	return c;
}


template<class T>
T sqr(const T &x)
{
	return mult(x, x);
}


vector<vector<ll>> powmod(const vector<vector<ll>> &x, ull y)
{
	return y == 0 ? id(x.size()) : (y & 1u ? mult(x, powmod(x, y - 1)) : sqr(powmod(x, y / 2)));
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	ll y;

	cin >> n >> y;

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	crucian tr;

	for (auto it : arr)
	{
		string str;

		cin >> str;

		tr.add(str, it);
	}

	tr.build();

	auto matr = tr.to_matr();

	matr = powmod(matr, y);

	ll ans = 0;

	for (int i = 0; i < matr.size(); i++)
		remax(ans, matr[0][i]);

	cout << ans << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}