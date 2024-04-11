#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m, x;

	cin >> n >> m >> x;

	minheap<pair<int, int>> pq;

	for (int i = 0; i < m; i++)
		pq.emplace(0, i);

	cout << "YES" << endl;

	for (int j = 0; j < n; j++)
	{
		int h;

		cin >> h;

		auto[x, v] = pq.top();
		pq.pop();

		cout << v + 1 << ' ';

		pq.emplace(x + h, v);
	}

	cout << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

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

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}