#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#define mp make_pair
#define mul(a,b) (ll)(a)*(b)%mod
#define add(a,b) ((ll)(a)+(b))%mod

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int val[1000020];
int inv[1000020];
int invfact[1000020];

int pow(int n, int e) {
	if (e == 0) return 1;
	int tmp = pow(n, e / 2);
	tmp = mul(tmp, tmp);
	if (e % 2) tmp = mul(tmp, n);
	return tmp;
}

int axpby(int a, int b) {
	//a,b must be less than 2^30
	int xx = 1; int yy = 0; int dd = a;
	int x = 0; int y = 1; int d = b;
	while (d) {
		int q = dd / d;

		int tmp = d;
		d = dd - d*q;
		dd = tmp;

		tmp = x;
		x = xx - x*q;
		xx = tmp;

		tmp = y;
		y = yy - y*q;
		yy = tmp;
	}
	if (xx < 0)  xx += b;
	return xx;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	scanf("%d %d", &n, &k);
	if (k == 0) {
		printf("%d", n);
		return 0;
	}
	val[0] = 0;
	for (int i = 1; i <= k + 1; i++) {
		val[i] = add(val[i - 1], pow(i, k));
	}
	if (n <= k + 1) {
		printf("%d", val[n]);
		return 0;
	}
	invfact[0] = invfact[1] = 1;
	inv[1] = 1;
	for (int i = 2; i <= 1000002; i++) {
		inv[i] = mul(-mod / i, inv[mod%i]);
		if (inv[i] < 0)inv[i] += mod;
		invfact[i] = mul(invfact[i - 1], inv[i]);
	}
	int ans = 0;
	int M = 1;
	for (int i = 0; i <= k + 1; i++) {
		M = mul(M, n - i);
	}
	for (int i = 0; i <= k + 1; i++) {
		int tmp = val[i];
		tmp = mul(tmp, M);
		tmp = mul(tmp, axpby(n - i, mod));
		tmp = mul(tmp, invfact[i]);
		tmp = mul(tmp, invfact[k + 1 - i]);
		if ((k + 1 - i) % 2) tmp = -tmp;
		if (tmp < 0) tmp += mod;
		ans = add(ans, tmp);
	}
	printf("%d", ans);
}