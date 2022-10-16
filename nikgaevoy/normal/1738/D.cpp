#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


auto algo(const vector<int> &arr, int k)
{
	vector<int> brr(arr.size());

	int le = (int) arr.size() + 1, ri = 0;

	for (auto it: arr)
	{
		if (it <= k)
		{
			brr[it - 1] = le;
			ri = it;
		}
		else
		{
			brr[it - 1] = ri;
			le = it;
		}
	}

	return brr;
}


int dfs(const vector<vector<int>> &gr, vector<int> &siz, int v)
{
	siz[v] = 1;

	for (auto it: gr[v])
		siz[v] += dfs(gr, siz, it);

	return siz[v];
}


void out(const vector<vector<int>> &gr, vector<int> &ord, int v)
{
	ord.push_back(v);

	for (auto it: gr[v])
		out(gr, ord, it);
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> brr(n);

	for (auto &it: brr)
		cin >> it;

	int k = 0;

	while (k < ssize(brr) && brr[k] > k)
		k++;

	vector<vector<int>> gr(n + 1);

	for (int i = 0; i < ssize(brr); i++)
		gr[brr[i] == n + 1 ? 0 : brr[i]].push_back(i + 1);

	vector<int> siz(gr.size());
	auto sz = dfs(gr, siz, 0);

	assert(sz == ssize(gr));

	vector<int> arr;

	for (auto &row: gr)
		ranges::sort(row, [&siz](int a, int b)
		{
			return siz[a] < siz[b];
		});

	out(gr, arr, 0);

	assert(arr.front() == 0);
	arr.erase(arr.begin());

	cout << k << '\n';

	for (auto it: arr)
		cout << it << ' ';
	cout << '\n';

#ifdef LOCAL
	cout << flush;
#endif

	assert(algo(arr, k) == brr);
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