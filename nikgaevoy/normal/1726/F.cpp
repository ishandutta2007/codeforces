#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, t;

	cin >> n >> t;

	vector<pair<int, int>> lights(n);

	for (auto &[g, c]: lights)
		cin >> g >> c;

	ll add = 0;

	for (auto i: ranges::iota_view(1, n))
	{
		int d;

		cin >> d;

		add += d;

		lights[i].second = int((lights[i].second + add) % t);
	}

	for (auto &[c, g]: lights)
	{
		swap(g, c);

		c = -c;

		if (c < 0)
			c += t;

		assert(0 <= c && c < t);

		c += g;

		if (c >= t)
			c -= t;

		g = t - g;
	}

	map<int, int> segs;
	segs.emplace(0, int(lights.size()));

	auto get_pnt = [&segs, &t](int x)
	{
		assert(0 <= x && x < t);

		auto q = --segs.lower_bound(x + 1);

		return q->second;
	};

	auto add_seg = [&](int val, int l, int r)
	{
		assert(0 <= l && l < r && r <= t);

		if (r + 1 < t)
		{
			auto suff = get_pnt(r + 1);

			segs[r + 1] = suff;
		}

		while (true)
		{
			auto it = segs.lower_bound(l);

			if (it != segs.end() && it->first < r)
				segs.erase(it);
			else
				break;
		}

		segs[l] = val;
	};

	auto add_seg_cyc = [&](int val, int l, int len)
	{
		if (l + len > t)
		{
			add_seg(val, l, t);
			add_seg(val, 0, l + len - t);
		}
		else
			add_seg(val, l, l + len);
	};

	vector<ll> dp(lights.size());

	auto get_val = [&](int q, int st)
	{
		assert(0 <= st && st < t);
		if (q < dp.size())
			return dp[q] + (lights[q].first + lights[q].second - st) % t;
		return 0ll;
	};

	for (auto i: ranges::iota_view(0, ssize(dp)) | views::reverse)
	{
		const auto [l, len] = lights[i];
		auto st = l + len;

		if (st >= t)
			st -= t;

		auto q = get_pnt(st);

		dp[i] = get_val(q, st);

		add_seg_cyc(i, l, len);
	}

	ll best = numeric_limits<ll>::max();

	for (auto it = segs.begin(); it != segs.end(); ++it)
	{
		auto nx = it;
		++nx;

		auto st = nx == segs.end() ? t - 1 : nx->first - 1;
		auto q = it->second;

		best = min(best, get_val(q, st));
	}

	cerr << best << " + " << add << endl;
	cout << best + add << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

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
			cout << ss.str() << endl;
			cout << "solve:" << endl;
			cout << out1.str() << endl;
			cout << "stress:" << endl;
			cout << out2.str() << endl;

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