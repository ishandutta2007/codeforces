#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6;
int n, m;
int a[maxn + 10], b[maxn + 10];
int ida[maxn + 10], idb[maxn + 10], ccnt;
ll c[maxn + 10];
ll g, lcm, k, ans;

void exgcd(ll n, ll m, ll &a, ll &b) {
	if (m == 0) {
		a = 1; b = 0; return;
	} else {
		exgcd(m, n % m, b, a); b -= n / m * a;
	}
}

void solve(int x, int y) {
	if (x % g != y % g) return;
	ll a, b;
	exgcd(n, m, a, b);
	int d = (y - x) / g;
	a *= d;
	a = (a % lcm + lcm) % lcm;
	ll v = (a * n + x) % lcm;
	c[++ccnt] = v;
}

int main() {
	scanf("%d%d%lld", &n, &m, &k);
	g = __gcd(n, m);
	lcm = n / g * m;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		ida[a[i]] = i;
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &b[i]);
		idb[b[i]] = i;
	}
	for (int i = 1; i <= maxn; ++i)
		if (ida[i] && idb[i])
			solve(ida[i] - 1, idb[i] - 1);
	sort(c + 1, c + ccnt + 1);
	ll d = (k - 1) / (lcm - ccnt);
	k -= d * (lcm - ccnt);
	c[ccnt + 1] = lcm; c[0] = -1;
	for (int i = 0; i <= ccnt; ++i)
		if (k <= c[i + 1] - c[i] - 1) {
			ans = c[i] + k;
			break;
		} else k -= c[i + 1] - c[i] - 1;
	printf("%lld", ans + d * lcm + 1);
}