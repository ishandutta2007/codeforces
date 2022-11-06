#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5;
int n, id[maxn + 10], pos, cnt, f[maxn + 10];
ll a[maxn + 10], all, ans;
set<int> st[maxn + 10], res;
ll val[maxn + 10];

void merge(set<int> &x, const set<int> &y) {
	for (auto i: y) {
		if (x.count(i)) x.erase(i);
		else x.insert(i);
	}
}

void ins(ll v, int p) {
	static set<int> t;
	t.clear(); t.insert(p);
	ll tmp = v;
	for (int i = 0; i <= 60; ++i)
		if (val[i]) {
			if (tmp >> id[i] & 1) tmp ^= val[i];
		} else if (tmp >> id[i] & 1) break;
	if (!tmp) return;
	for (int i = 0; i <= 60; ++i)
		if (val[i]) {
			if (v >> id[i] & 1) {
				v ^= val[i]; merge(t, st[i]);
			}
		} else if (v >> id[i] & 1) {
			val[i] = v; st[i] = t; break;
		}
}


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		all ^= a[i];
	}
	for (int i = 60; i >= 0; --i)
		if (~all >> i & 1) id[cnt++] = i;
	pos = cnt;
	for (int i = 60; i >= 0; --i)
		if (all >> i & 1) id[cnt++] = i;
	for (int i = 1; i <= n; ++i)
		ins(a[i], i);
	ans = 0;
	for (int i = 0; i < pos; ++i)
		if (val[i] && (~ans >> id[i] & 1)) {
			ans ^= val[i]; merge(res, st[i]);
		}
	for (int i = pos; i <= 60; ++i)
		if (val[i] && (ans >> id[i] & 1)) {
			ans ^= val[i]; merge(res, st[i]);
		}
	for (auto i: res) f[i] = 1;
	for (int i = 1; i <= n; ++i) printf("%d ", f[i] ? 1 : 2);
}