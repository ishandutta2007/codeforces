#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#include <iostream>
#include <iomanip>
#include <vector>
const int N = 5001, G = 200;
const double H = 1e18;
using namespace std;

int main()
{
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, r;
	cin >> n >> r;
	cout << setprecision(12) << setiosflags(ios::fixed);
	vector<int> f(n), s(n);
	vector<double> p(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> f[i] >> s[i] >> p[i];
		p[i] /= 100;
	}
	vector<vector<double>> Mb(n + 1);
	double x = 0, y = H, z = (y - x) / 2;
	for (int i = 0; i <= n; ++i)
		Mb[i] = vector<double>(N);
	for (int I = 0; I < G; ++I)
	{
		z += x;
		for (int t = 0; t < N; ++t)
			Mb[n][t] = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			for (int t = 0; t < N; ++t)
			{
				Mb[i][t] = 0;
				if (t >= f[i])
					Mb[i][t] += p[i] * (f[i] + Mb[i + 1][t - f[i]]);
				else
					Mb[i][t] += p[i] * (f[i] + z);
				if (t >= s[i])
					Mb[i][t] += (1 - p[i]) * (s[i] + Mb[i + 1][t - s[i]]);
				else
					Mb[i][t] += (1 - p[i]) * (s[i] + z);
				if ((Mb[i][t] > z) && (i != 0))
					Mb[i][t] = z;
			}
		}
		//cout << I << ':' << "Mb[0][r] = " << Mb[0][r] << ", x = " << x << '\n';
		if (Mb[0][r] > z)
			x = z;
		else
			y = z;
		z = (y - x) / 2;
	}
	cout << x;
	return 0;
}