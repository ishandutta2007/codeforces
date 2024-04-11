#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> a(n);

	for (auto &it : a)
	{
		cin >> it;
		it--;
	}

	vector<bool> used(n);
	vector<int> bad;
	vector<int> b(n, -1);

	for (int i = 0; i < a.size(); i++)
		if (!used[a[i]])
		{
			b[i] = a[i];
			used[a[i]] = true;
		}
		else
			bad.push_back(i);

	if (bad.size() == 1 && !used[bad.front()])
	{
		int add = find(b.begin(), b.end(), a[bad.front()]) - b.begin();

		b[bad.front()] = a[bad.front()];
		bad.front() = add;
		b[add] = -1;
	}

	vector<int> super_bad;

	for (int i = 0; i < bad.size(); i++)
		if (!used[bad[i]])
		{
			super_bad.push_back(bad[i]);
			swap(bad[i], bad.back());
			bad.pop_back();
			i--;
		}

	if (super_bad.size() == 1)
	{
		for (int j = 0; j < used.size(); j++)
			if (!used[j] && j != super_bad.front())
			{
				b[super_bad.front()] = j;
				used[j] = true;

				super_bad.clear();

				break;
			}
	}
	else
	{
		for (int j = 0; j < super_bad.size(); j++)
		{
			b[super_bad[(j + 1) % super_bad.size()]] = super_bad[j];
			used[super_bad[j]] = true;
		}

		super_bad.clear();
	}

	assert(super_bad.empty());

	int wh = 0;

	for (auto it : bad)
	{
		while (used[wh])
			wh++;
		b[it] = wh;
		used[wh] = true;
	}

	{
		auto tmp = b;

		sort(tmp.begin(), tmp.end());

		assert(unique(tmp.begin(), tmp.end()) == tmp.end());
	}

	int ans = 0;

	for (int i = 0; i < b.size(); i++)
	{
		assert(b[i] != -1 && b[i] != i);

		if (b[i] == a[i])
			ans++;
	}

	cout << ans << endl;

	for (auto it : b)
		cout << it + 1 << ' ';
	cout << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


void gen(ostream &cout = std::cout)
{
	cout << 1 << endl;

	const int n = 5;

	uniform_int_distribution<int> uid{0, n - 1};

	vector<int> a(n);

	for (int i = 0; i < a.size(); i++)
	{
		a[i] = uid(mt);

		if (a[i] >= i)
			a[i]++;
	}

	cout << n << endl;

	for (auto it : a)
		cout << it + 1 << ' ';
	cout << endl;
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

	while (!true)
	{
		stringstream ss;

		gen(ss);

		cout << ss.str() << endl;

		solve(ss);
	}

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}