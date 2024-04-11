#include <bits/stdc++.h>
using namespace std;

int main() {
	
	long long a, b;
	cin >> a >> b;
	long long ans = 1;
	while (a != b) {
		a++;
		ans *= a;
		ans %= 10;
		if (ans == 0) break;
	}
	cout << ans;
	
	return 0;
}