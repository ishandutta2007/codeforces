#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	int n, ans;
	int max = 0;
	long a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a > max) {max = a;}
	}
	ans = max - 25;
	if (ans > 0) {cout << ans;}
	else cout << 0;
	
	return 0;
}