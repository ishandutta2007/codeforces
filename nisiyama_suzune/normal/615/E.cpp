#include <iostream>

using namespace std;

typedef long long llong;

llong N;

int main ()
{
	cin >> N;
	llong l = 0, r = 1E9, ans = 0;
	while (l <= r)
	{
		llong m = (l + r) / 2;
		if (3 * m * m - 3 * m + 1 <= N)
		{
			ans = m;
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	llong x = 2 * ans - 1, y = 2;
//	cout << ans << endl;
	N -= (3 * ans * ans - 3 * ans + 1);
//	cout << N << endl;
	if (N <= ans - 1)
	{
		x -= N;
		y += 2 * N;
		cout << x << " " << y << endl;
		return 0;
	}
	N -= (ans - 1);
	x -= (ans - 1);
	y += 2 * (ans - 1);
	if (N <= ans)
	{
		x -= 2 * N;
		cout << x << " " << y << endl;
		return 0;
	}
	N -= ans;
	x -= 2 * ans;
	if (N <= ans)
	{
		x -= N;
		y -= 2 * N;
		cout << x << " " << y << endl;
		return 0;
	}
	N -= ans;
	x -= ans;
	y -= 2 * ans;
	if (N <= ans)
	{
		x += N;
		y -= 2 * N;
		cout << x << " " << y << endl;
		return 0;
	}
	N -= ans;
	x += ans;
	y -= 2 * ans;
	if (N <= ans)
	{
		x += 2 * N;
		cout << x << " " << y << endl;
		return 0;
	}
	x += 2 * ans;
	N -= ans;
	x += N;
	y += 2 * N;
	cout << x << " " << y << endl;
}