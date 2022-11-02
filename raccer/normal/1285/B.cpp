#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		long long dp = 0, ans = 0, sum = 0;
		multiset <long long> s; s.insert(0);
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			sum += x;
			if (i != n - 1) ans = max(ans, sum - *s.begin());
			else {
				multiset <long long> :: iterator it = s.begin(); it++;
				ans = max(ans, sum - *it);
			}
			s.insert(sum);
		}
		printf(ans >= sum ? "NO\n" : "YES\n");
	}
	return 0;
}