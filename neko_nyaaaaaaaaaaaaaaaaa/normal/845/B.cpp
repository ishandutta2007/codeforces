#include <bits/stdc++.h>
using namespace std;

bool check(int i) {
	int sum1 = i%10; i/=10; sum1+=i%10; i/=10; sum1+=i%10; i/=10;
	int sum2 = i%10; i/=10; sum2+=i%10; i/=10; sum2+=i%10; i/=10;
	return sum2 == sum1;
}

int dif(int a, int b) {
	int ans = 0;
	while (a || b) {
		ans += (a%10 != b%10);
		a /= 10;
		b /= 10;
	}
	return ans;
}

int main() {
	
	int n;
	cin >> n;
	if (n == 0) {cout << n; return n;}
	int ans = 6;
	for (int i = 1; i < 1e6; i++) {
		if (!check(i)) continue;
		ans = min(ans, dif(n, i));
	}
	cout << ans;
	
	return 0;
}