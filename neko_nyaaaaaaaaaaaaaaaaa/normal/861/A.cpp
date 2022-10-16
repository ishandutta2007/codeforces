#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	
	long long n, k;
	cin >> n >> k;
	if (k == 0) {cout << n;}
	else {
		long long ans = (pow(10, k))*n;
		int tmp1 = k;
		int tmp2 = k;
		while (tmp1 != 0 && n % 2 == 0) {
			ans /= 2;
			n /= 2;
			tmp1--;
		}
		while (tmp2 != 0 && n % 5 == 0) {
			ans /= 5;
			n /= 5;
			tmp2--;
		}
		cout << ans;
	}
	
	return 0;
}