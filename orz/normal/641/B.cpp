#include <iostream>

using namespace std;

int main()
{
	int n, m, q, i, j, **a, *t, *r, *c, *x, u;
	cin >> n >> m >> q;
	a = new int*[n] - 1;
	for (i = 1; i <= n; ++i)
	{
		a[i] = new int[m] - 1;
		for (j = 1; j <= m; ++j)
			a[i][j] = 0;
	}
	t = new int[q];
	r = new int[q];
	c = new int[q];
	x = new int[q];
	for (i = 0; i < q; ++i)
	{
		cin >> t[i];
		if (t[i] == 1)
			cin >> r[i];
		else if (t[i] == 2)
			cin >> c[i];
		else
			cin >> r[i] >> c[i] >> x[i];
	}
	for (i = q - 1; i >= 0; --i)
	if (t[i] == 1)
	{
		u = a[r[i]][m];
		for (j = m - 1; j > 0; --j)
			a[r[i]][j + 1] = a[r[i]][j];
		a[r[i]][1] = u;
	}
	else if (t[i] == 2)
	{
		u = a[n][c[i]];
		for (j = n - 1; j > 0; --j)
			a[j + 1][c[i]] = a[j][c[i]];
		a[1][c[i]] = u;
	}
	else
		a[r[i]][c[i]] = x[i];
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= m; ++j)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	//system("pause");
}