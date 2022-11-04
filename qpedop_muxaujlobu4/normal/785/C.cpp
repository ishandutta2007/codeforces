#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	unsigned long long b = 1, e, n, m;
	cin >> n >> m;
	if (m >= n) {
		cout << n;
		return 0;
	}
	else n -= m;
	e = 2000000001;
	if (n == 1) {
		cout << m + 1;
		return 0;
	}
	while (b + 1 != e) {
		unsigned long long mid = (b + e) / 2;
		if ((mid)* (mid + 1)/2 < n)b = mid;
		else e = mid;
	}
	cout << (m + e);
	return 0;
}