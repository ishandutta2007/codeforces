#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


bool isprime(int n)
{
	if (n < 2)
		return false;

	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;

	return true;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	int m = n;

	vector<vector<int>> gr(n);

	for (int i = 0; i < n; i++)
	{
		gr[i].push_back((i + 1) % n);
		gr[(i + 1) % n].push_back(i);
	}

	int p = m;

	while (!isprime(p))
		p++;

	if (p < m + m / 2)
	{
		for (int i = 0; m + i < p; i++)
		{
			gr[i].push_back((i + n / 2) % n);
			gr[(i + n / 2) % n].push_back(i);
		}

		cout << p << endl;

		for (int i = 0; i < n; i++)
			for (auto j : gr[i])
				if (i < j)
					cout << i + 1 << ' '  << j + 1 << endl;
	}
	else
	{
		cerr << n << endl;
		assert(false);

		cout << -1 << endl;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve (fin);
	for (int n = 3; n <= 1000; n++)
	{
		stringstream ss, out;
		ss << n << endl;
		solve(ss, out);
	}
	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}