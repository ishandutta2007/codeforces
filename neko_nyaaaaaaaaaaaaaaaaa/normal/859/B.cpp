#include <iostream>
using namespace std;

int main() {
	
	long n;
	cin >> n;
	long i = 1;
	while (i*i < n) {
		i++;
	}
	long tmp = i*i;
	long ans;
	ans = i*4;
	long k = i * (i - 1);
	if (k >= n) {ans -= 2;}
	cout << ans;
	
	return 0;
}