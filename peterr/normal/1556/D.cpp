#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
int a[MAXN + 1];

int query(int x, int y)
{
	cout << "and " << x << " " << y << endl;
	int q1, q2;
	cin >> q1;
	cout << "or " << x << " " << y << endl;
	cin >> q2;
	return q1 + q2;
}

int main()
{
	int n, k;
	cin >> n >> k;
	int x = query(1, 2);
	int y = query(2, 3);
	int z = query(3, 1);
	a[1] = (x - y + z) / 2;
	a[2] = x - a[1];
	a[3] = y - a[2];
	for (int i = 4; i <= n; i++)
	{
		int sum = query(i, i - 1);
		a[i] = sum - a[i - 1];
	}
	//for (int i = 1; i <= n; i++)
		//cout << a[i] << " \n"[i == n];
	sort(a + 1, a + n + 1);
	cout << "finish " << a[k] << "\n";
	return 0;
}