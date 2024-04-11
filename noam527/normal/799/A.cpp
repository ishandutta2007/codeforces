#include <iostream>
using namespace std;

int main()
{
	int n, t, k, d;
	cin >> n >> t >> k >> d;
	if (((n + k - 1) / k - 1) * t > d)
		cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}