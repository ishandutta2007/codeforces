#include <bits/stdc++.h>
using namespace std;

int n, m, ans=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while(m>n) {
		if (m&1) {
			m++;
			ans++;
		}
		m /= 2;
		ans++;
	}
	ans += n-m;
	cout << ans;
	return 0;
}