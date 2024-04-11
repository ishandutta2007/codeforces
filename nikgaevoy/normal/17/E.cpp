#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


const int mod = 51123987;


string extend(const string &str)
{
	string ret = "*";

	for (auto it : str)
	{
		ret += it;
		ret += '*';
	}

	return ret;
}


vector<int> Manacher(const string &str)
{
	vector<int> arr(str.size(), 1);

	int rb = 0, pos = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (i < rb)
			arr[i] = min(rb - i, arr[2 * pos - i]);

		while (0 <= i - arr[i] && i + arr[i] < str.size() && str[i - arr[i]] == str[i + arr[i]])
			arr[i]++;

		if (rb < i + arr[i])
		{
			rb = i + arr[i];
			pos = i;
		}
	}

	return arr;
}


int up(int n)
{
	int r = 1;

	while (r < n)
		r *= 2;

	return r;
}


int &add(int &x, const int &y)
{
	x += y;

	if (x >= mod)
		x -= mod;

	return x;
}


class segtree
{
	vector<int> arr, laza, lazb;

	void push(int l, int r, int v)
	{
		if (laza[v] == 0 && lazb[v] == 0)
			return;

		arr[v] = (arr[v] + (r - l) * (r - l - 1ll) / 2 % mod * laza[v] + ll(r - l) * lazb[v]) % mod;
		if (arr[v] < 0)
			arr[v] += mod;

		if (v < arr.size() / 2)
		{
			add(laza[2 * v], laza[v]);
			add(lazb[2 * v], lazb[v]);
			add(laza[2 * v + 1], laza[v]);
			add(lazb[2 * v + 1], (lazb[v] + laza[v] * ll(r - l) / 2) % mod);
		}

		laza[v] = 0;
		lazb[v] = 0;
	}


	void upd(int l, int r, int v)
	{
		push(l, r, v);

		if (v < arr.size() / 2)
		{
			auto t = (l + r) / 2;
			push(l, t, 2 * v);
			push(t, r, 2 * v + 1);

			arr[v] = arr[2 * v] + arr[2 * v + 1];
			if (arr[v] >= mod)
				arr[v] -= mod;
		}
	}


	int segsum(int l, int r, int cl, int cr, int v)
	{
		if (r <= cl || cr <= l)
			return 0;

		push(cl, cr, v);

		if (l <= cl && cr <= r)
			return arr[v];

		int ct = (cl + cr) / 2;

		int ans = segsum(l, r, cl, ct, 2 * v) + segsum(l, r, ct, cr, 2 * v + 1);

		upd(cl, cr, v);

		if (ans >= mod)
			ans -= mod;

		return ans;
	}


	void segadd(int l, int r, int cl, int cr, int v, int a, int b)
	{
		if (r <= cl || cr <= l)
			return;

		if (l <= cl && cr <= r)
		{
			add(laza[v], a);
			add(lazb[v], (b + a * ll(cl - l)) % mod);

			return;
		}

		push(cl, cr, v);

		int ct = (cl + cr) / 2;

		segadd(l, r, cl, ct, 2 * v, a, b);
		segadd(l, r, ct, cr, 2 * v + 1, a, b);

		upd(cl, cr, v);
	}


public:
	segtree(int n) : arr(2 * up(n)), laza(2 * up(n)), lazb(2 * up(n))
	{}


	int segsum(int l, int r)
	{
		return segsum(l, r, 0, arr.size() / 2, 1);
	}


	void segadd(int l, int r, int a, int b)
	{
		if (a < 0)
			a += mod;
		if (b < 0)
			b += mod;
		segadd(l, r, 0, arr.size() / 2, 1, a, b);
	}
};


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	string str;

	cin >> str;

	auto vl = Manacher(extend(str));

	vector<pair<int, int>> pals;
	pals.reserve(2 * str.size() + 1);

	for (int i = 0; i < vl.size(); i++)
	{
		auto l = (i - vl[i] + 1) / 2;
		auto r = (i + vl[i]) / 2;

		if (l < r)
			pals.emplace_back(l, r);
	}

	vector<int> lb(str.size() + 1), rb(str.size() + 1);
	int all = 0;

	for (const auto &it : pals)
	{
		int cnt = (it.second - it.first + 1) / 2;
		add(all, cnt);
		lb[it.first]++;
		lb[(it.first + it.second + 1) / 2]--;
		rb[(it.first + it.second) / 2]++;
		rb[it.second]--;
	}

	vector<int> plbs(lb.size() + 1), prbs(rb.size() + 1);

	for (int i = 1; i < plbs.size(); i++)
	{
		add(plbs[i], plbs[i - 1] + lb[i - 1]);
		add(prbs[i], prbs[i - 1] + rb[i - 1]);
	}

	assert(plbs.back() == 0);
	assert(prbs.back() == 0);
	plbs.pop_back();
	prbs.pop_back();

	vector<int> ppls(plbs.size() + 1), pprs(prbs.size() + 1);

	for (int i = 1; i < ppls.size(); i++)
	{
		add(ppls[i], ppls[i - 1] + plbs[i - 1]);
		add(pprs[i], pprs[i - 1] + prbs[i - 1]);
	}

	ll ans = 0;

	for (int i = 0; i < plbs.size(); i++)
		ans += plbs[i] * ll(pprs.back() - pprs[i]) % mod;
	ans -= all * (all - 1ll) / 2 % mod;
	ans -= all;

	ans %= mod;
	if (ans < 0)
		ans += mod;

	cout << ans << endl;
}


void stress(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	string str;

	cin >> n >> str;

	vector<pair<int, int>> pals;

	for (int l = 0; l < str.size(); l++)
		for (int r = l + 1; r <= str.size(); r++)
		{
			auto tmp = str.substr(l, r - l);
			auto pmt = tmp;
			reverse(pmt.begin(), pmt.end());

			if (tmp == pmt)
				pals.emplace_back(l, r);
		}

	ll ans = 0;

	for (int i = 0; i < pals.size(); i++)
		for (int j = i + 1; j < pals.size(); j++)
			if (pals[j].first < pals[i].second && pals[i].first < pals[j].second)
				ans++;

	cout << ans % mod << endl;
}


void gen(ostream &cout = std::cout)
{
	const int n = 10;

	string str(n, ' ');

	uniform_int_distribution<char> uid('a', 'z');

	for (auto &it : str)
		it = uid(mt);

	cout << n << endl;
	cout << str << endl;
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

	int cnt = 0;

	while (true)
	{
		stringstream ss, in1, in2, out1, out2;

		gen(ss);

		in1 << ss.str();
		in2 << ss.str();

		solve(in1, out1);
		stress(in2, out2);

		if (out1.str() != out2.str())
		{
			cout << "fail:\t" << cnt << endl;

			cout << ss.str() << endl;
			cout << out1.str() << endl;
			cout << out2.str() << endl;

			break;
		}
		else if (++cnt % 10 == 0)
			cout << "ok:\t" << cnt << endl;
	}

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}