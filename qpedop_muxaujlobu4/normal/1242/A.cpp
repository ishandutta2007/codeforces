#include <iostream>
#include<vector>
using namespace std;
int main()
{
	long long t,m=0,n,ct=0,i;
	cin >> n;
	if (n <= 3) {
		cout << n;
		return 0;
	}
	if (n == 4) {
		cout << 2;
		return 0;
	}
	for (i = 2; i * i <= n; ++i) {
		if (n%i==0) {
			m = i;
			++ct;
			while (n % i == 0) {
				n /= i;
			}
		}
	}
	if (ct == 0) {
		cout << n;
		return 0;
	}
	if (n != 1) {
		++ct;
		if(n>m)m = n;
	}
	if (ct == 1)cout << m;
	else cout << 1;

	return 0;
}