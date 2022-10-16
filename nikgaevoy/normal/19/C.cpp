#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


template<class T>
T sqr(const T &x)
{
	return x * x;
}


ll powmod(ll x, ll y, int mod)
{
	return y ? (y & 1 ? x * powmod(x, y - 1, mod) : sqr(powmod(x, y / 2, mod))) % mod : 1;
}


template<int mod = int(1e9 + 7), int mult = 736>
class hasher
{
	vector<int> ph, mm, om;

public:
	hasher(const vector<int> &str = {}) : ph(str.size() + 1), mm(str.size() + 1), om(str.size() + 1)
	{
		om[0] = mm[0] = 1;
		const int oult = powmod(mult, mod - 2, mod);
		for (int i = 1; i < mm.size(); i++)
		{
			mm[i] = mm[i - 1] * (ll) mult % mod;
			om[i] = om[i - 1] * (ll) oult % mod;
		}

		for (int i = 1; i < ph.size(); i++)
			ph[i] = (ph[i - 1] + str[i - 1] * (ll) mm[i - 1]) % mod;
	}


	int substr(int l, int r) const
	{
		int ans = (ph[r] - ph[l]) * (ll)om[l] % mod;
		if (ans < 0)
			ans += mod;

		return ans;
	}
};


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> str(n);

	for (auto &it : str)
		cin >> it;

	hasher<> hs(str);

	unordered_map<int, vector<int>> pos;

	for (int i = 0; i < str.size(); i++)
		pos[str[i]].push_back(i);

	vector<pair<int, int>> cand;

	for (const auto &it : pos)
	{
		const auto &row = it.second;

		for (int i = 0; i < row.size(); i++)
			for (int j = i + 1; j < row.size(); j++)
				if (2 * row[j] - row[i] <= str.size())
					cand.emplace_back(row[j] - row[i], row[i]);
	}

	sort(cand.begin(), cand.end());

	int st = 0;

	for (const auto &it : cand)
		if (it.second >= st &&
		    hs.substr(it.second, it.second + it.first) == hs.substr(it.second + it.first, it.second + 2 * it.first))
			st = it.second + it.first;

	str.erase(str.begin(), str.begin() + st);

	cout << str.size() << endl;
	for (auto it : str)
		cout << it << ' ';
	cout << endl;
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