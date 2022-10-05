#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, a[1000005];
int D[22][1 << 21] = {};

void add(int i, int k) {
	if (D[i][k] == 2) return;
	D[i][k]++;
	if (i == 21) return;
	if (k >> i & 1) {
		add(i + 1, k ^ (1 << i));
		add(i + 1, k);
	}
	else {
		add(i + 1, k);
	}
}

bool can(int i, int need) {
	need = need ^ (a[i] & need);
	if (D[21][need] >= 2) return true;
	return false;
}

int calc(int i) {
	int rtn = 0;
	for (int b = (1 << 20); b; b /= 2) {
		if (can(i, rtn | b)) rtn |= b;
	}
	add(0, a[i]);
	return rtn;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;
	for (int i = n - 1; i >= 0; i--)
		ans = max(ans, calc(i));
	cout << ans << '\n';
}