#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n, ans, now;

int calcmu(int v) {
	int ans = 1;
	for (int i = 2; i * i <= v; ++i)
		if (v % i == 0) {
			v /= i;
			if (v % i == 0) return 0;
			ans = -ans;
		}
	if (v > 1) ans = -ans; return ans;
}

ll getit(ll x, int k) {
	ll t = powl(n, 1.0 / k) - 0.5;
	return t + (powl(t + 1, k) - 0.5 <= n);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n); ans = 0;
		for (int i = 1; (now = getit(n, i)) >= 2; ++i)
			ans += calcmu(i) * (now - 1);
		printf("%lld\n", ans);
	}
}