#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<class T>
T &remax(T &x, const T &y)
{
	return x = max(x, y);
}


template<class T>
T &remin(T &x, const T &y)
{
	return x = min(x, y);
}


void build(const vector<vector<int>> &gr, vector<int> &arr, int v = 0, int sum = 0)
{
	arr[v] += sum;

	for (auto it: gr[v])
		build(gr, arr, it, arr[v]);
}


pair<ll, int> solve(const vector<vector<int>> &gr, const vector<int> &arr, int v, ll k)
{
	if (gr[v].empty())
		return {arr[v] * k, arr[v]};

	vector<int> ch;
	ch.reserve(gr[v].size());
	ll ans = 0;

	for (auto it: gr[v])
	{
		auto [a, b] = solve(gr, arr, it, k / ssize(gr[v]));

		ans += a;
		ch.push_back(b);
	}

	ranges::sort(ch, greater());
	ans += accumulate(ch.begin(), ch.begin() + k % ssize(gr[v]), 0ll);

	return {ans, ch[k % ssize(gr[v])]};
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	cin >> n >> k;

	vector<vector<int>> gr(n);

	for (int i = 1; i < n; i++)
	{
		int p;

		cin >> p;
		p--;

		gr[p].push_back(i);
	}

	vector<int> arr(n);

	for (auto &it: arr)
		cin >> it;

	build(gr, arr);

	cout << solve(gr, arr, 0, k).first << '\n';
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