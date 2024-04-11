#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


constexpr array dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};


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


void color(const vector<string> &tr, vector<array<int, 3>> &q, int x, int y, int col)
{
	if (y < 0 || y >= tr.size() || x < 0 || x >= tr[y].size() || tr[y][x] == '0' || q[y][x] != -1)
		return;

	q[y][x] = col;

	for (int i = 0; i < dx.size(); i++)
		color(tr, q, x + dx[i], y + dy[i], col);
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	array<string, 3> field;

	for (auto &row: field)
		cin >> row;

	vector<string> tr(n, string(3, ' '));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < field.size(); j++)
			tr[i][j] = field[j][i];

	set<int> ioi, none;

	for (int j = 0; j < n; j++)
		(tr[j] == "101" ? ioi : none).insert(j);

	vector<array<int, 3>> colors(tr.size(), {-1, -1, -1});
	int cnt = 0;

	for (int i = 0; i < colors.size(); i++)
		for (int j = 0; j < colors[i].size(); j++)
			if (colors[i][j] == -1 && tr[i][j] == '1')
				color(tr, colors, j, i, cnt++);

	vector<pair<int, int>> segs(cnt, {numeric_limits<int>::max(), numeric_limits<int>::lowest()});

	for (int i = 0; i < colors.size(); i++)
		for (auto col: colors[i])
			if (col != -1)
			{
				remax(segs[col].second, i + 1);
				remin(segs[col].first, i);
			}

	vector<int> ps(colors.size() + 1), ss(colors.size() + 1);

	for (auto[l, r]: segs)
	{
		ps[r]++;
		ss[l]++;
	}

	for (auto i: ranges::iota_view(1, ssize(ps)))
		ps[i] += ps[i - 1];
	for (auto i: ranges::iota_view(0, ssize(ss) - 1) | views::reverse)
		ss[i] += ss[i + 1];

	int q;

	cin >> q;

	for (auto query: ranges::iota_view(0, q))
	{
		int l, r;

		cin >> l >> r;
		l--;

		auto ans = cnt - ps[l] - ss[r];

		bool ll = false, rr = false;

		if (tr[l] == "101" && colors[l].front() == colors[l].back())
		{
			auto it = none.lower_bound(l);

			if (it == none.end() || *it >= r || tr[*it] != "111")
			{
				ans++;
				ll = true;
			}
		}

		if (tr[r - 1] == "101" && colors[r - 1].front() == colors[r - 1].back())
		{
			auto it = none.lower_bound(r);

			if (it == none.begin())
			{
				ans++;
				rr = true;
			}
			else
			{
				--it;

				if (*it < l || tr[*it] != "111")
				{
					ans++;
					rr = true;
				}
			}
		}

		if (ll && rr && none.lower_bound(l) == none.lower_bound(r))
			ans--;

		cout << ans << '\n';
	}
}


void stress(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	array<string, 3> field;

	for (auto &row: field)
		cin >> row;

	vector<string> tr(n, string(3, ' '));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < field.size(); j++)
			tr[i][j] = field[j][i];

	int q;

	cin >> q;

	for (auto query: ranges::iota_view(0, q))
	{
		int l, r;

		cin >> l >> r;
		l--;

		vector part(tr.begin() + l, tr.begin() + r);
		vector<array<int, 3>> cc(part.size(), {-1, -1, -1});

		int ans = 0;

		for (auto y: ranges::iota_view(0, ssize(part)))
			for (auto x: ranges::iota_view(0, ssize(part[y])))
				if (part[y][x] == '1' && cc[y][x] == -1)
					color(part, cc, x, y, ans++);

		cout << ans << '\n';
	}
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


void gen(ostream &cout = std::cout)
{
	const int n = 20, q = 100;

	cout << n << endl;

	uniform_int_distribution ch{'0', '1'};

	for (auto j: ranges::iota_view(0, 3))
	{
		for (auto i: ranges::iota_view(0, n))
			cout << ch(mt);
		cout << endl;
	}

	cout << q << endl;

	uniform_int_distribution<int> uid(1, n);

	for (auto t: ranges::iota_view(0, q))
	{
		int l = uid(mt), r = uid(mt);

		if (r < l)
			swap(l, r);

		cout << l << ' ' << r << endl;
	}
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

	for (auto cnt: ranges::iota_view(0))
	{
		stringstream ss, in1, in2, out1, out2;

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

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}