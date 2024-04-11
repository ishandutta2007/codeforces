#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int a, b;
	cin >> a >> b;
	int ans = 0;
	if (a == 1 && b == 1) {cout << 0; return 0;}
	while (a > 0 && b > 0) {
		if (a > b) {
			a -= 2;
			b++;
			ans++;
		} else {
			b -= 2;
			a++;
			ans++;
		}
	}
	cout << ans;
	
	return 0;
}