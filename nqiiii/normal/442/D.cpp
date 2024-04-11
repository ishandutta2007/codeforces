#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6;
int n, fa[maxn + 10], ans[maxn + 10];
int ch[maxn + 10], mx[maxn + 10], semx[maxn + 10];

int calc(int k) {
	for (int i = 0; i <= k; ++i)
		mx[i] = semx[i] = 0;
	for (int i = k; i >= 1; --i) {
		int w = max(mx[i], semx[i] + 1);
		if (w > mx[fa[i]]) {
			semx[fa[i]] = mx[fa[i]]; mx[fa[i]] = w;
		} else if (w > semx[fa[i]]) semx[fa[i]] = w;
	}
	return mx[0];
}

void solve(int l, int r, int rl, int rr) {
	if (l > r) return;
	if (rl == rr) {
		for (int i = l; i <= r; ++i) ans[i] = rl;
		return;
	}
	int mid = (l + r) >> 1;
	ans[mid] = calc(mid);
	solve(l, mid - 1, rl, ans[mid]);
	solve(mid + 1, r, ans[mid], rr);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &fa[i]); --fa[i];
	}
	solve(1, n, calc(1), calc(n));
	for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
}