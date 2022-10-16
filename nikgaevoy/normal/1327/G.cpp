#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


const size_t alph = 14;


template<class T>
auto &remax(T &x, const T &y)
{
	return x = max(x, y);
}


template<class T>
auto &remin(T &x, const T &y)
{
	return x = min(x, y);
}


class crucian
{
	struct node
	{
		array<int, alph> nxt;
		int link, x;

	public:
		node() : link(-1), x(0)
		{
			fill(nxt.begin(), nxt.end(), -1);
		}


		int &operator[](int v)
		{
			return nxt[v];
		}
	};

	vector<node> mem;


	int trie_move(int v, int q)
	{
		if (mem[v][q] == -1)
		{
			mem[v][q] = mem.size();
			mem.emplace_back();
		}

		return mem[v][q];
	}

public:
	crucian() : mem(1)
	{}


	size_t size() const
	{
		return mem.size();
	}


	void insert(const string &str, int w)
	{
		auto cur = 0;

		for (auto it : str)
			cur = trie_move(cur, it - 'a');

		mem[cur].x += w;
	}


	void build()
	{
		queue<tuple<int, int, int>> q;
		q.emplace(0, -1, -1);

		while (!q.empty())
		{
			int v, p, i;

			tie(v, p, i) = q.front();
			q.pop();

			if (v != -1)
			{
				if (p != -1)
				{
					auto prev = p;

					while ((mem[prev][i] == -1 || mem[prev][i] == v) && prev != 0)
						prev = mem[prev].link;

					if (mem[prev][i] == -1 || mem[prev][i] == v)
						mem[v].link = prev;
					else
						mem[v].link = mem[prev][i];

					mem[v].x += mem[mem[v].link].x;
				}
				else
					mem[v].link = 0;

				for (int j = 0; j < mem[v].nxt.size(); j++)
					q.emplace(mem[v][j], v, j);
			}
		}
	}


	ll walk(const string &str, int &v)
	{
		ll ans = 0;

		for (auto it : str)
		{
			assert(it != '?');

			it -= 'a';

			while (v != 0 && mem[v][it] == -1)
				v = mem[v].link;

			if (mem[v][it] != -1)
				v = mem[v][it];

			ans += mem[v].x;
		}

		return ans;
	}


	pair<ll, int> mem_walk(const vector<string> &pal, int q, int st)
	{
		static vector<vector<pair<ll, int>>> dp(pal.size(), vector<pair<ll, int>>(mem.size(), {0, -1}));

		if (dp[q][st].second == -1)
		{
			auto cur = st;

			dp[q][st].first = walk(pal[q], cur);
			dp[q][st].second = cur;
		}

		return dp[q][st];
	}
};


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int k;

	cin >> k;

	crucian tr;

	for (int i = 0; i < k; i++)
	{
		string str;
		int w;

		cin >> str >> w;

		tr.insert(str, w);
	}

	tr.build();

	string str;

	cin >> str;

	int st = 0;
	auto nxt = str.find('?');
	ll ans = tr.walk(str.substr(0, nxt), st);

	str = nxt == std::string::npos ? "" : str.substr(nxt);

	vector<string> parts;

	while (!str.empty())
	{
		assert(str.front() == '?');

		nxt = str.find('?', 1);

		parts.push_back(str.substr(1, nxt - 1));
		str = nxt == std::string::npos ? "" : str.substr(nxt);
	}

	vector<vector<ll>> dp(1u << alph, vector<ll>(tr.size(), numeric_limits<ll>::min()));
	dp[0][st] = ans;

	for (unsigned mask = 0; mask < dp.size(); mask++)
		for (int q = 0; q < dp[mask].size(); q++)
			if (dp[mask][q] != numeric_limits<ll>::min())
			{
				auto pc = __builtin_popcount(mask);

				if (pc < parts.size())
					for (unsigned i = 0; i < alph; i++)
						if ((mask & (1u << i)) == 0)
						{
							int v = q;

							ll add = tr.walk(string(1, 'a' + i), v);
							auto tmp = tr.mem_walk(parts, pc, v);
							add += tmp.first;
							v = tmp.second;

							remax(dp[mask | (1u << i)][v], dp[mask][q] + add);
						}
			}

	ans = numeric_limits<ll>::min();

	for (unsigned mask = 0; mask < dp.size(); mask++)
		if (__builtin_popcount(mask) == parts.size())
			remax(ans, *max_element(dp[mask].begin(), dp[mask].end()));

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

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}