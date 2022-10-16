#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


struct mcplx
{
	ll r, i;

	mcplx(ll r = 0, ll i = 0) : r(r), i(i)
	{}

	mcplx &operator*=(const mcplx &to)
	{
		auto nr = r * to.r - i * to.i;
		auto ni = r * to.i + i * to.r;

		r = nr;
		i = ni;

		return *this;
	}


	mcplx &operator-=(const mcplx &to)
	{
		r -= to.r;
		i -= to.i;

		return *this;
	}


	bool operator==(const mcplx &to)
	{
		return r == to.r && i == to.i;
	}
};


using pnt = mcplx;


bool right(const pnt &a, pnt b, pnt c)
{
	c -= b;
	b -= a;

	b.i *= -1;

	c *= b;

	return c.i > 0;
}


template<int num>
auto C(ll n)
{
	ll ans = 1;

	for (int i = 0; i < num; i++)
		ans *= n - i;
	for (int i = 2; i <= num; i++)
		ans /= i;

	return ans;
}


int type(const ll &x, const ll &y)
{
	if (y >= 0 && x >= 0)
		return 0;
	if (y >= 0 && x < 0)
		return 1;
	if (x <= 0)
		return 2;
	return 3;
}


ll centered(vector<pnt> arr, const pnt &x)
{
	arr.erase(find(arr.begin(), arr.end(), x));

	sort(arr.begin(), arr.end(), [&x](const pnt &a, const pnt &b) {
		if (type(a.r - x.r, a.i - x.i) != type(b.r - x.r, b.i - x.i))
			return type(a.r - x.r, a.i - x.i) < type(b.r - x.r, b.i - x.i);
		return right(x, a, b);
	});

	ll ans = 0;

	for (int l = 0, r = 0; l < arr.size(); l++)
	{
		while (r == l || right(arr[r % arr.size()], x, arr[l]))
			r++;

		ans += C<3>(r - l - 1);
	}

	return ans;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<pnt> arr(n);

	for (auto &it : arr)
	{
		ll x, y;

		cin >> x >> y;

		it = {x, y};
	}

	ll ans = 0;

	for (const auto &it : arr)
		ans += centered(arr, it);

	cout << 5 * C<5>(arr.size()) - ans << endl;
}


void gen(ostream &cout = std::cout)
{
	const int n = 2500;

	cout << n << endl;

	uniform_int_distribution<int> uid(-(int) 1e9, (int) 1e9);

	for (int i = 0; i < n; i++)
		cout << uid(mt) << ' ' << uid(mt) << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	stringstream ss;

	gen(ss);

	solve(ss);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}