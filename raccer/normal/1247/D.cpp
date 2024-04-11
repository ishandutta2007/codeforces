#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int mod = 1000000007;

int a[100010];
int prime[100010], vis[100010], tot;

void get_pre() {
	for (int i = 2; i <= 100000; i++) {
		if (vis[i]) continue;
		prime[tot++] = i;
		for (int j = i + i; j <= 100000; j += i) {
			vis[j] = 1;
		}
	}
}

map <vector <int>, int> s;

int main () {
	get_pre();
	int n, k; scanf("%d%d", &n, &k);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		vector <pii> factor;
		for (int j = 0; j < tot && 1ll * prime[j] * prime[j] <= a[i]; j++) {
			int x = prime[j];
			if (a[i] % x) continue;
			factor.push_back(mp(x, 0));
			while (a[i] % x == 0) factor.back().se++, a[i] /= x;
		}
		if (a[i] > 1) factor.push_back(mp(a[i], 1));
		vector <int> h1, h2;
		for (int i = 0; i < factor.size(); i++) {
			if (factor[i].se % k) h1.push_back(factor[i].fi * k + factor[i].se % k);
			if (factor[i].se % k) h2.push_back(factor[i].fi * k + (k - factor[i].se % k) % k);
		}
		ans += s[h1], s[h2]++;
	}
	printf("%I64d\n", ans);
	return 0;
}