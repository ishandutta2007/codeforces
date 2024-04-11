#include <iostream>

using namespace std;

long long N;

long long eval (long long m)
{
	long long ans = 0;
	for (long long i = 2; i * i * i <= m; i++)
	{
		ans += m / (i * i * i);
	}
	return ans;
}

int main ()
{
	cin >> N;
	long long l = 1, r = 1E20;
	while (l + 1 < r)
	{
		long long m = (l + r) / 2;
		if (eval (m) < N)
			l = m;
		else
			r = m;
	}
	if (eval (r) == N)
		cout << r << endl;
	else
		cout << -1 << endl;
	return 0;
}