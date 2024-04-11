#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<pair<int, int>> arr(n);

	vector<int> xs;
	xs.reserve(n);

	for (auto &[x, p]: arr)
	{
		cin >> x >> p;

		xs.push_back(x);
	}

	{
		ranges::sort(xs);
		auto [l, r] = ranges::unique(xs);
		xs.erase(l, r);
	}

	vector<pair<int, int>> events;

	for (auto [x, p]: arr)
	{
		events.emplace_back(x - p, 1);
		events.emplace_back(x, -2);
		events.emplace_back(x + p, 1);
	}

	ranges::sort(events);

	vector<ll> sum(xs.size());

	int cumm = 0;
	int pos = numeric_limits<int>::lowest();
	ll cur = 0;

	auto sh = [&](int x)
	{
		assert(x >= pos);
		cur += cumm * ll(x - pos);
		pos = x;
	};

	for (int ep = 0, xp = 0; xp < (int) xs.size(); xp++)
	{
		auto x = xs[xp];

		while (ep < events.size() && events[ep].first < x)
		{
			sh(events[ep].first);
			cumm += events[ep].second;

			ep++;
		}

		sh(x);

		sum[xp] = cur;
	}

	for (auto &it: sum)
		it -= m;

	vector<pair<ll, ll>> bnds(sum.size());

	{
		ll st = numeric_limits<ll>::max();
		bool fnd = false;

		for (auto i: ranges::iota_view(0, ssize(sum)))
		{
			if (sum[i] > 0)
			{
				if (!fnd || (xs[i] - sum[i]) < st)
				{
					st = xs[i] - sum[i];
					fnd = true;
				}
			}

			if (fnd)
				bnds[i].first = xs[i] - st;
		}
	}


	{
		ll st = numeric_limits<ll>::lowest();
		bool fnd = false;

		for (auto i: ranges::iota_view(0, ssize(sum)) | views::reverse)
		{
			if (sum[i] > 0)
			{
				if (!fnd || (xs[i] + sum[i]) > st)
				{
					st = xs[i] + sum[i];
					fnd = true;
				}
			}

			if (fnd)
				bnds[i].second = st - xs[i];
		}
	}

	for (auto [x, p]: arr)
	{
		auto ind = ranges::lower_bound(xs, x) - xs.begin();

		if (p >= max(bnds[ind].first, bnds[ind].second))
			cout << '1';
		else
			cout << '0';
	}

	cout << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


void stress_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<pair<int, int>> arr(n);

	int lb = numeric_limits<int>::max(), rb = numeric_limits<int>::lowest();

	for (auto &[x, p]: arr)
	{
		cin >> x >> p;
		lb = min(lb, x - p);
		rb = max(rb, x + p);
	}

	vector<ll> sum(rb - lb + 1);

	auto add = [&](int x, int p)
	{
		for (int y = x, val = p; val > 0; y--, val--)
			sum[y - lb] += val;
		for (int y = x + 1, val = p - 1; val > 0; y++, val--)
			sum[y - lb] += val;
	};

	auto sub = [&](int x, int p)
	{
		for (int y = x, val = p; val > 0; y--, val--)
			sum[y - lb] -= val;
		for (int y = x + 1, val = p - 1; val > 0; y++, val--)
			sum[y - lb] -= val;
	};

	for (auto [x, p]: arr)
		add(x, p);

	for (auto [x, p]: arr)
	{
		sub(x, p);
		cout << (ranges::max(sum) > m ? 0 : 1);
		add(x, p);
	}

	cout << endl;
}


void stress(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	cin >> t;

	for (int i = 0; i < t; i++)
		stress_test(cin, cout);
}


void gen(ostream &cout = std::cout)
{
	cout << 1 << endl;

	int n = 10, m = 1e2;

	cout << n << ' ' << m << endl;

	uniform_int_distribution<int> uid(1, (int) 1e2);

	for (int i = 0; i < n; i++)
		cout << uid(mt) << ' ' << uid(mt) << endl;
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