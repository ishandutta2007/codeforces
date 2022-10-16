#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


auto foo(const string &s, const string &t, int a = 0, int b = 0, int bal = 0)
{
	static vector<vector<vector<pair<int, char>>>> dp
			(s.size() + t.size() + 1,
			 vector<vector<pair<int, char>>>(s.size() + 1, vector<pair<int, char>>(t.size() + 1, {-1, ' '})));

	if (a == s.size() && b == t.size())
		return pair{bal, ']'};
	if (bal > dp.size())
		return pair{numeric_limits<int>::max() / 2, ' '};

	auto &ans = dp[bal][a][b];

	if (ans.first == -1)
	{
		ans.first = numeric_limits<int>::max();

		for (char nxt : string("()"))
		{
			auto nbal = nxt == '(' ? bal + 1 : bal - 1;

			if (nbal >= 0)
			{
				int na = a == s.size() || s[a] != nxt ? a : a + 1;
				int nb = b == t.size() || t[b] != nxt ? b : b + 1;

				if (na != a || nb != b || bal == 0)
					ans = min(ans, pair{foo(s, t, na, nb, nbal).first + 1, nxt});
			}
		}

		assert(ans.first < numeric_limits<int>::max());
	}

	return ans;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	string s, t;

	cin >> s >> t;

	string ans(foo(s, t).first, ')');

	int ca = 0, cb = 0, cbal = 0;

	for (auto &it : ans)
	{
		auto dp = foo(s, t, ca, cb, cbal);

		if (dp.second == ']')
			break;
		it = dp.second;

		if (ca < s.size() && s[ca] == dp.second)
			ca++;
		if (cb < t.size() && t[cb] == dp.second)
			cb++;
		if (dp.second == '(')
			cbal++;
		else
			cbal--;
	}

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