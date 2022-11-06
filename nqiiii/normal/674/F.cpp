#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
int n, p, q;
vector<ui> a;
ui f[200], ans;

ui calc() {
	ui ans = 1;
	for (int i = 0; i < (int)a.size(); ++i)
		ans *= a[i];
	return ans;
}

void div(ui x) {
	for (int i = 0; i < (int)a.size(); ++i) {
		ui g = __gcd(x, a[i]);
		x /= g; a[i] /= g;
		if (x == 1) break;
	}
}

void init() {
	for (int i = 0; i <= p && i < n; ++i) {
		f[i] = calc();
		a.push_back(n - i);
		div(i + 1);
	}
}

ui calc(int x) {
	ui ans = 0, w = 1;
	for (int i = 0; i <= p && i < n; ++i) {
		ans += f[i] * w; w *= x;
	}
	return ans;
}

int main() {
	scanf("%d%d%d", &n, &p, &q);
	init();
	for (int i = 1; i <= q; ++i)
		ans ^= i * calc(i);
	printf("%u", ans);
}