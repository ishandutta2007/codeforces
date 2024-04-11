#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


const int mod = 998244353;


int fact(int n)
{
	int ans = 1;

	for (int i = 1; i <= n; i++)
		ans = (ans * (ll) i) % mod;

	return ans;
}


template<class T>
auto sqr(T x)
{
	return x * x;
}


ll powmod(ll x, ull y)
{
	return y ? (y & 1 ? x * powmod(x, y - 1) : sqr(powmod(x, y / 2))) % mod : 1;
}


int ofact(int n)
{
	return powmod(fact(n), mod - 2);
}


int C(int n, int k)
{
	return fact(n) * (ll) ofact(k) % mod * (ll) ofact(n - k) % mod;
}


int put(int places, int things)
{
	return C(things + places - 1, places - 1);
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	string str;

	cin >> n >> str;

	list<int> blocks;

	for (int l = 0, r; l < str.size(); l = r + 1)
	{
		for (r = l; r < str.size() && str[r] == '0'; r++);

		blocks.push_back(r - l);
	}

	if (str.back() == '1')
		blocks.push_back(0);

	assert(blocks.size() == count(str.begin(), str.end(), '1') + 1);

	int sz = 0;

	for (auto cur = blocks.begin(); cur != blocks.end(); ++cur)
		if (cur != blocks.begin())
		{
			auto pr = cur;
			auto ne = cur;
			--pr;
			++ne;

			if (ne != blocks.end())
			{
				if (*cur == 0)
				{
					sz += 2;

					auto q = blocks.insert(cur, *pr + 1 + *cur + 1 + *ne);
					blocks.erase(pr);
					blocks.erase(cur);
					blocks.erase(ne);

					cur = q;
					--cur;
				}
			}
		}

//	cerr << "sz: " << sz << endl;
//	cerr << "ones: " << count(str.begin(), str.end(), '1') << endl;
//	for (auto it : blocks)
//		cerr << it << ' ';
//	cerr << endl;

	cout << put(sz / 2 + 1, count(str.begin(), str.end(), '0')) << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = chrono::steady_clock::now();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}