#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void C()
{
	long long n, k;
	cin >> n >> k;
	vector<long long> result;
	long long sum = 0;
	long long c = (long long)(sqrt(0.25 + 2 * k) - 0.5) + 1;
	int l = k - c * (c - 1) / 2;
	int t = c + (l > 0 ? 1 : 0);
	if (t > n)
		cout << "Impossible" << endl;
	else
	{
		for (int i = 0; i < c; i++)
			cout << '(';
		for (int i = 0; i < c - l; i++)
			cout << ')';
		if (l > 0)
			cout << "()";
		for (int i = c - l; i < c; i++)
			cout << ')';
		for (int i = t; i < n; i++)
			cout << "()";
		cout << endl;
	}
}

int main()
{
	C();
	return 0;
}