//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define smin(x, y) x = min(x, y)
#define base bs

const int maxn = 1e5 + 10,
	  maxval = 2e7;
const LL Mod = 1e9 + 7;
int base[30],
	a[maxn],
	ord[maxn],
	ql[maxn],
	qx[maxn];
int n, bcnt, q;
int ans[maxn];

int Pow(int x) {
	LL ret = 1,
	   an = 2;
	while (x) {
		if (x % 2 == 1) ret = (ret * an) % Mod;
		an = (an * an) % Mod;
		x >>= 1;
	}
	return ret;
}

bool qcmp(int i, int j) {
	return ql[i] < ql[j];
}

void add(int x) {
	for (int i = 0; i < 20; i++)
		if (base[i] != -1 and ((x >> i) & 1))
			x ^= base[i];
	if (x == 0)
		return;
	int pos = __builtin_ctz(x);
	for (int i = 0; i < 20; i++)
		if (base[i] != -1 and ((base[i] >> pos) & 1))
			base[i] ^= x;
	bcnt++;
	base[pos] = x;
}

bool can(int x) {
	for (int i = 0; i < 20; i++)
		if (base[i] != -1 and ((x >> i) & 1))
			x ^= base[i];
	return x == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(base, -1, sizeof base);
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < q; i++)
		cin >> ql[i] >> qx[i], ql[i]--, ord[i] = i;
	sort(ord, ord + q, qcmp);

	int pos = 0;
	for (int i = 0; i < q; i++) {
		int id = ord[i];
		while (pos <= ql[id])
			add(a[pos++]);//, cout << "#" << bcnt << endl;
		if (can(qx[id]))
			ans[id] = Pow(pos - bcnt);
		else
			ans[id] = 0;
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << '\n';
	return 0;
}