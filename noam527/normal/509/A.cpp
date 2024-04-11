#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	long long f[19];
	cin >> n;
	f[0] = 1; for (int i = 1; i <= n * 2 - 2; i++) f[i] = i * f[i - 1];
	cout << f[n * 2 - 2] / f[n - 1] / f[n - 1] << endl;
	return 0;
}