#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<class K, class V>
class add_map
{
	K shift = 0;
	map<K, V> val;

public:
	auto &operator[](const K &t)
	{
		return val[t + shift];
	}

	auto &operator+=(const K &t) noexcept
	{
		shift += t;

		return *this;
	}

	auto &operator-=(const K &t) noexcept
	{
		shift -= t;

		return *this;
	}

	void swap(add_map &q)
	{
		::swap(shift, q.shift);
		val.swap(q.val);
	}
	
	void pop_small(const K &x)
	{
		while (!val.empty() && val.begin()->first - shift < x)
			val.erase(val.begin());
	}
	
	void pop_big(const K &x)
	{
		while (!val.empty() && val.rbegin()->first - shift > x)
			val.erase(--val.end());
	}
};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	add_map<int, int> pos, neg;
	
	ll ans = 0;
	
	for (auto it : arr)
	{
		pos[0]++;
		neg[0]++;

		pos.pop_big(0);
		neg.pop_small(0);

		pos.swap(neg);

		pos += it;
		neg -= it;

		ans += pos[0];
	}

	cout << ans << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (auto it: ranges::iota_view(0, t))
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