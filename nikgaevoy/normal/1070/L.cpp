#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2001;
using bs = bitset<N>;

vector<int> work (vector<bs> mat)
{
	const int n = (int)mat.size();

	vector<int> x(n, -1);
	int cur = 0;

	for (int i = 0; i < n; i++)
	{
		int where = -1;
		for (int j = cur; j < n; j++)
		{
			if (mat[j][i])
				where = j;
		}

		if (where == -1)
			continue;

		x[i] = -2;
		swap(mat[where], mat[cur]);
		assert(mat[cur][i]);

		for (int j = 0; j < n; j++)
		{
			if (j != cur && mat[j][i])
				mat[j] ^= mat[cur];
		}

		cur++;
	}

//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j <= n; j++)
//			cerr << mat[i][j];
//		cerr << endl;
//	}

	for (int &p : x)
	{
		if (p == -1)
			p = 0;
	}
	assert(!count(x.begin(), x.end(), -1));

	for (int i = cur - 1; i >= 0; i--)
	{
		int who = -1, val = mat[i][n];
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] && x[j] == -2)
			{
				assert(who == -1);
				who = j;
			}
			else if (mat[i][j])
			{
				assert(x[j] == 0 || x[j] == 1);
				val ^= x[j];
			}
		}

		assert(who != -1);
		x[who] = val;
	}

	assert(!count(x.begin(), x.end(), -2));
	return x;
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;
	cin >> t;

	int n, m;

	while (cin >> n >> m)
	{
		vector<bs> g(n);
		vector<int> d(n);

		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			--x, --y;
			g[x][y] = g[y][x] = 1;
			d[x]++, d[y]++;
		}

		bool ok = true;
		for (int x : d)
			ok &= (x % 2 == 0);

		if (ok)
		{
			cout << 1 << "\n";
			for (int i = 0; i < n; i++)
				cout << "1" << " \n"[i + 1 == n];
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (d[i] % 2 == 1)
				{
					g[i].set(i);
					g[i].set(n);
				}
			}
			
			auto x = work(g);
			cout << 2 << "\n";
			for (int s = 0; s < n; s++)
				cout << x[s] + 1 << " \n"[s + 1 == n];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}