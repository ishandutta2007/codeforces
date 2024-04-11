#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int n, k, a[200005];
vector<int> v;

int main() {
	scanf("%d%d", &n, &k);
	long long ans = 0;
	for (int i = n; i > n-k; i--) ans += i;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) if (a[i] > n-k) v.push_back(i);
	long long ans2 = 1;
	for (int i = 0; i < v.size() - 1; i++) {
		ans2 *= v[i+1] - v[i];
		ans2 %= MOD;
	}
	printf("%lld %lld\n", ans, ans2);
}