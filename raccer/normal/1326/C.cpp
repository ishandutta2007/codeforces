#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int mod = 998244353;

pii a[200010];

int main () {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].fi);
		a[i].se = i;
	}
	sort(a, a + n), reverse(a, a + n);
	vector <int> all;
	long long sum = 0;
	for (int i = 0; i < k; i++) {
		sum += a[i].fi;
		all.push_back(a[i].se);
	}
	sort(all.begin(), all.end());
	long long ans = 1;
	for (int i = 1; i < all.size(); i++) {
		ans = ans * (all[i] - all[i - 1]) % mod;
	}
	printf("%I64d %I64d\n", sum, ans);
	return 0;
}