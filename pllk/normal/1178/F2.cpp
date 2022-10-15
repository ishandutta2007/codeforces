#include <iostream>

using namespace std;

#define M 998244353

typedef long long ll;

int n, m;
int b[1222333];
int p1[555], p2[555];
int c[1111];
ll z = 1;

int vv[1111][1111];
ll dd[1111][1111];

ll calc(int a, int b) {
	if (a > b) return 1;
	if (vv[a][b]) return dd[a][b];
	int pi = a;
	for (int i = a; i <= b; i++) {
		if (c[i] < c[pi]) pi = i;
	}
	int g = c[pi];
	if (p1[g] < a || p2[g] > b) {
		vv[a][b] = 1;
		dd[a][b] = 0;
		return 0;
	}
	if (a == b) {
		vv[a][b] = 1;
		dd[a][b] = 1;
		return 1;
	}
	int pp = p1[g];
	ll du = 1;
	int ua = p1[g];
	int ub = p2[g];
	for (int i = ua+1; i <= ub; i++) {
		if (c[i] == g) {
			du *= calc(pp+1,i-1);
			du %= M;
			pp = i;
		}
	}
	pi = p1[g];
	ll d1 = 0;
	for (int i = a-1; i < pi; i++) {
		d1 += calc(a,i)*calc(i+1,pi-1);
		d1 %= M;
	}
	pi = p2[g];
	ll d2 = 0;
	for (int i = pi; i <= b; i++) {
		d2 += calc(pi+1,i)*calc(i+1,b);
		d2 %= M;
	}
	vv[a][b] = 1;
	dd[a][b] = du*d1%M*d2%M;
	return dd[a][b];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		if (!p1[b[i]]) p1[b[i]] = i;
		p2[b[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (p2[i] < p1[j]) continue;
			if (p2[j] < p1[i]) continue;
			if (p1[i] < p1[j] && p2[j] < p2[i]) continue;
			//if (p1[j] < p1[i] && p2[i] < p2[j]) continue;
			cout << 0 << "\n";
			return 0;
		}
	}
	int k = 0;
	for (int i = 1; i <= m; i++) {
		if (i == 1 || b[i-1] != b[i]) {
			k++;
			c[k] = b[i];
		}
	}
	for (int i = 1; i <= n; i++) p1[i] = p2[i] = 0;
	for (int i = 1; i <= k; i++) {
		if (!p1[c[i]]) p1[c[i]] = i;
		p2[c[i]] = i;
	}
	cout << calc(1,k) << "\n";
}