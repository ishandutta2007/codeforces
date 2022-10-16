#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<int mod>
class modulo
{
	int x;

public:
	constexpr modulo(int x = 0) : x(x)
	{}

	constexpr bool operator==(const modulo &rhs) const = default;

	constexpr bool operator!=(const modulo &rhs) const = default;

	constexpr modulo &operator+=(modulo rhs)
	{
		x += rhs.x;
		if (x >= mod)
			x -= mod;

		return *this;
	}

	constexpr modulo operator+(modulo rhs) const
	{
		auto q = *this;
		q += rhs;

		return q;
	}

	constexpr modulo &operator-=(modulo rhs)
	{
		x -= rhs.x;
		if (x < 0)
			x += mod;

		return *this;
	}

	constexpr modulo operator-(modulo rhs) const
	{
		auto q = *this;
		q -= rhs;

		return q;
	}

	constexpr modulo operator*(modulo rhs) const
	{
		return modulo{int(x * (ll) rhs.x % mod)};
	}

	constexpr modulo &operator*=(modulo rhs)
	{
		return *this = (*this * rhs);
	}

	constexpr modulo operator/(modulo rhs) const
	{
		return *this * rhs.recip();
	}

	constexpr modulo &operator/=(modulo rhs)
	{
		return *this = (*this / rhs);
	}

	[[nodiscard]] constexpr modulo sqr() const
	{
		return *this * *this;
	}

	[[nodiscard]] constexpr modulo pow(unsigned y) const
	{
		return y == 0 ? modulo{1 % mod} : y & 1u ? *this * pow(y - 1) : pow(y / 2).sqr();
	}

	[[nodiscard]] constexpr modulo recip() const
	{
		return pow(mod - 2);
	}

	constexpr explicit operator int() const
	{
		return x;
	}

	template<int val>
	friend ostream &operator<<(ostream &cout, const modulo<val> &);
};

template<int mod>
ostream &operator<<(ostream &cout, const modulo<mod> &x)
{
	return cout << x.x;
}

using mod_t = modulo<int(1e9) + 7>;


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	if (n == 1)
	{
		cout << 1 << endl;

		return;
	}

	vector<mod_t> suff_prob(n), ps(n + 1);
	suff_prob.back() = 1;
	ps.rbegin()[1] = 1;
	mod_t mult = 1, rmult = 1;

	for (auto i: ranges::iota_view(0, n) | views::reverse | views::drop(1))
	{
		auto to = min(n, 2 * (i + 1) - 1);

		suff_prob[i] = (ps[i + 1] - ps[to]) * rmult;
		ps[i] = ps[i + 1] + suff_prob[i] * mult;
		mult *= 2;
		rmult *= mod_t{2}.recip();
	}

#ifdef LOCAL
	ranges::copy(suff_prob, ostream_iterator<mod_t>(cout, " "));
	cout << endl;
#endif

	vector<mod_t> pref_prob(suff_prob.size());

	for (int i = 0; i < n; i++)
		pref_prob[i] = mod_t{2}.recip().pow(i / 2);

#ifdef LOCAL
	ranges::copy(pref_prob, ostream_iterator<mod_t>(cout, " "));
	cout << endl;
#endif

	vector<mod_t> ans(n);

	for (auto i: ranges::iota_view(0, ssize(ans)))
		ans[i] = pref_prob[i] * suff_prob[i] * mod_t{2}.recip();

	ans.back() = pref_prob.back();
	ans.front() = 0;

	ranges::copy(ans, ostream_iterator<mod_t>(cout, "\n"));
	assert(accumulate(ans.begin(), ans.end(), mod_t{}) == mod_t{1});
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

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

#ifdef STRESS
	for (int cnt = 1;; cnt++)
	{
		stringstream ss, in1, out1, in2, out2;

		gen(ss);

		in1 << ss.str();
		in2 << ss.str();

		solve(in1, out1);
		stress(in2, out2);

		if (out1.str() != out2.str())
		{
			cout << "fail: " << cnt << endl;
			cout << ss.str();
			cout << "solve:" << endl;
			cout << out1.str();
			cout << "stress:" << endl;
			cout << out2.str();

			break;
		}
		else if (cnt % 100 == 0)
			cout << "ok: " << cnt << endl;
	}
#endif

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}