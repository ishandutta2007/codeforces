#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


int foo(vector<vector<int>> &gr, vector<int> &dn0, vector<int> &dn1, int v, int p = -1)
{
	for (int i = 0; i < gr[v].size(); i++)
	{
		if (gr[v][i] == p)
		{
			swap(gr[v][i], gr[v].back());
			gr[v].pop_back();

			i--;
		}
		else
		{
			dn0[v] += foo(gr, dn0, dn1, gr[v][i], v);
			dn1[v] += dn0[gr[v][i]] + 1;
		}
	}

	return dn1[v];
}


void goo(const vector<vector<int>> &gr, const vector<int> &dn0, const vector<int> &dn1,
         vector<int> &up0, vector<int> &up1, int v, int p = -1)
{
	if (p != -1)
	{
		up0[v] = dn1[p] + up1[p] - dn0[v] - 1;
		up1[v] = dn0[p] + up0[p] - dn1[v] + 1;
	}

	for (auto &it : gr[v])
		goo(gr, dn0, dn1, up0, up1, it, v);
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<int>> gr(n);

	for (int i = 1; i < gr.size(); i++)
	{
		int a, b;

		cin >> a >> b;
		a--;
		b--;

		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	vector<int> dn0(n), dn1(n), up0(n), up1(n);

	foo(gr, dn0, dn1, 0);
	goo(gr, dn0, dn1, up0, up1, 0);

	int ans = 10 * n;

	for (int i = 0; i < gr.size(); i++)
		ans = min(ans, dn0[i] + up0[i]);

	cout << ans << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}