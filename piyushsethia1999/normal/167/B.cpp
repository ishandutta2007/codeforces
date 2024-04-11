#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

void Print(std::vector<std::vector<std::vector<double> > >& pg, int n)
{
	for (int i = 0; i <= n ; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 0; k < j; ++k)
				cout << " ";
			for (int k = 0; k < 2*n+1; ++k)
			{
				cout << pg[i][j][k] << " ";
 			}
 			cout << "\n";
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, l, k;
	cin >> n >> l >> k;
	std::vector<double> p(n+1, 0);
	std::vector<int> space(n+1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> p[i];
		p[i] /= 100;
	}
	for (int i = 1; i <= n; ++i)
		cin >> space[i];
	print(space);
	print(p);
	std::vector<std::vector<std::vector<double> > > pg(n+1, std::vector<std::vector<double> > (n+1, std::vector<double> (2*n+1, 0)));
	k = min(n, k) + n;
	print(k);
	pg[0][0][k] = 1;
	for (int i = 1; i < n+1; ++i)
		pg[i][0][k] = pg[i-1][0][k]*(1 - p[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) 
		{
			for (k = 0; k < 2 * n; ++k) {
				if(k - space[i] >= 0)
					pg[i][j][k] = pg[i-1][j][k]*(1 - p[i]) + pg[i-1][j-1][k - space[i]]*p[i];
				else
					pg[i][j][k] = pg[i-1][j][j]*(1 - p[i]);
			}
			if (space[i] < 0)
				pg[i][j][2*n] = pg[i-1][j][2*n]*(1-p[i]);
			if(space[i] > 0) {
				for (k = max(2*n - space[i], 0); k <= 2*n; ++k)
					pg[i][j][2*n] += pg[i-1][j-1][k]*p[i];
				pg[i][j][2*n] += pg[i-1][j][2*n]*(1 - p[i]);
			}
		}
	}
	// Print(pg, n);
	print(pg);
	double res = 0;
	for (int j = l; j <= n; ++j)
		for (int k = n; k < 2 * n + 1; ++k)
			res += pg[n][j][k];
	cout << res;
}