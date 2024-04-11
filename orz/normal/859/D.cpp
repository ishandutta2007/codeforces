#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <vector>
#define ll long long
#define ld long double

using namespace std;
int main()
{
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int m = (1 << n);
	vector<vector<ld>> v(m);
	vector<vector<ld>> expect(m);
	vector<vector<ld>> prob(m);
	for (int i = 0; i < m; ++i)
	{
		expect[i] = vector<ld>(n + 1);
		prob[i] = vector<ld>(n + 1);
		expect[i][0] = 0;
		prob[i][0] = 1;
		v[i] = vector<ld>(m);
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
			v[i][j] /= 100;
		}
	}
	ld w = .5;
	int d = 1, p;
	for (int k = 1; k <= n; ++k)
	{
		w += w;
		p = d;
		d += d;

		for (int i = 0; i < m; ++i)
		{
			prob[i][k] = 0;
			int t = i / p;
			if (t & 1)
				--t;
			else
				++t;
			t *= p;
			for (int j = 0; j < p; ++j)
				prob[i][k] += v[i][j + t] * prob[j + t][k - 1];
			prob[i][k] *= prob[i][k - 1];
		}

		for (int i = 0; i < m; ++i)
		{
			expect[i][k] = 0;
			int t = i / p;
			if (t & 1)
				--t;
			else
				++t;
			t *= p;
			ld lllddd;
			for (int j = 0; j < p; ++j)
			{
				lllddd = expect[j + t][k - 1] + expect[i][k - 1] + prob[i][k] * w;
				if (lllddd > expect[i][k])
					expect[i][k] = lllddd;
			}
		}
	}
	ld lllddd = 0;
	for (int i = 0; i < m; ++i)
	if (expect[i][n] > lllddd)
		lllddd = expect[i][n];
	/*
	for (int k = 0; k <= n; ++k)
	{
		cout << k << "th round prob: ";
		for (int i = 0; i < m; ++i)
			cout << prob[i][k] << ' ';
		cout << endl;
	}
	for (int k = 0; k <= n; ++k)
	{
		cout << k << "th round expect: ";
		for (int i = 0; i < m; ++i)
			cout << expect[i][k] << ' ';
		cout << endl;
	}
	*/
	cout << setiosflags(ios::fixed) << setprecision(15) << lllddd;
	return 0;
}