#include <iostream>
using namespace std;

int digsum(long long n) { return n < 10 ? n : digsum(n / 10) + n % 10; }

int main() {
	long long n, s;
	cin >> n >> s;
	long long lo = 1, hi = 2e18, mid;
	while (lo < hi) {
		mid = lo + (hi - lo) / 2;
		if (mid - digsum(mid) >= s)
			hi = mid;
		else
			lo = mid + 1;
	}
	cout << (n - lo + 1 > 0 ? n - lo + 1 : 0) << endl;
}