#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);

template<class T>
T &remin(T &x, const T &y)
{
	return x = min(x, y);
}

template<class T>
T &remax(T &x, const T &y)
{
	return x = max(x, y);
}


void Floyd(vector<vector<int>> &matr)
{
	for (auto k: ranges::iota_view(0, ssize(matr)))
		for (auto i: ranges::iota_view(0, ssize(matr)))
			for (auto j: ranges::iota_view(0, ssize(matr)))
				remin(matr[i][j], matr[i][k] + matr[k][j]);
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<tuple<int, int, int>> edges(m);

	for (auto &[u, v, w]: edges)
	{
		cin >> u >> v >> w;
		u--;
		v--;
	}

	vector dist(n, vector(n, numeric_limits<int>::max() / 2));

	for (auto [a, b, w]: edges)
		dist[a][b] = dist[b][a] = 1;

	for (auto i: ranges::iota_view(0, ssize(dist)))
		dist[i][i] = 0;

	Floyd(dist);

	ll ans = numeric_limits<ll>::max();

	for (auto [a, b, w]: edges)
	{
		remin(ans, (dist.front()[a] + dist.back()[b] + 1ll) * w);
		remin(ans, (dist.front()[b] + dist.back()[a] + 1ll) * w);
	}

	for (auto q: ranges::iota_view(0, n))
		for (auto [a, b, w]: edges)
			remin(ans, (dist.front()[q] + dist.back()[q] + min(dist[a][q], dist[b][q]) + 2ll) * w);

	cout << ans << endl;
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