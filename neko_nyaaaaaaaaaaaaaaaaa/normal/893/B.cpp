#include <bits/stdc++.h>
using namespace std;

int main() {
	
	long long n;
	cin >> n;
	for (long long i = 10; i >= 1; i--) {
		long long k = (pow(2, i) - 1)*pow(2, i-1);
		if (n % k == 0) {
			cout << k; return 0;
		}
	} 
	
	return 0;
}