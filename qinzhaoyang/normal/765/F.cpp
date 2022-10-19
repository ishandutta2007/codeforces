#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int B = 350, inf = 0x3f3f3f3f;

int n, m, a[N], preans[B + 10][N], st[N], ans[N * 3];

void init() {
	for (int i = 1; i <= n; i++) preans[1][i] = inf;
	for (int i = 2; i <= B; i++) for (int j = 1; j + i - 1 <= n; j++)
		preans[i][j] = min(min(preans[i - 1][j], preans[i - 1][j + 1]), abs(a[j] - a[i + j - 1]));
	vector<pair<int,int> > v;
	for (int i = 1; i <= n; i++) v.push_back(make_pair(a[i], i));
	sort (v.begin(), v.end());
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(v.begin(), v.end(), make_pair(a[i], i)) - v.begin() + 1;
	for (int i = 1; i <= n; i++) st[i] = v[i - 1].first;
}

int suf[N], pre[N], tans[N];

void Del(int x) {
	suf[pre[x]] = suf[x];
	pre[suf[x]] = pre[x];
}

int Ins(int x) {
	int ret = inf, t = suf[x];
	assert(x < t);
	if (t != n + 1) ret = min(ret, st[t] - st[x]);
	t = pre[x];
	assert(t < x);
	if (t) ret = min(ret, st[x] - st[t]);
	return suf[pre[x]] = pre[suf[x]] = x, ret;
}

struct Qry {int l, r, id;};
vector<Qry> q[N / B + 10];
inline int operator < (Qry x, Qry y) {
	return x.r > y.r;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	init(), scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int l, r; scanf("%d%d", &l, &r);
		if (r - l + 1 <= B) ans[i] = preans[r - l + 1][l];
		else q[(l - 1) / B].push_back((Qry){l, r, i});
	}
	for (int i = 0; i <= (n - 1) / B; i++) {
		if (!q[i].size()) continue;
		int tl = i * B + 1, tr = tl + B - 1;
		for (int j = 1; j <= n + 1; j++) suf[j - 1] = j, pre[j] = j - 1;
		for (int j = 1; j < tr; j++) Del(a[j]);
		for (int j = n; j > tr; j--) Del(a[j]);
		tans[tr] = inf;
		for (int j = tr + 1; j <= n; j++) tans[j] = min(tans[j - 1], Ins(a[j]));
		sort (q[i].begin(), q[i].end());
		for (int j = tr - 1; j >= tl; j--) Ins(a[j]);
		int k = n;
		for (Qry tmp : q[i]) {
			while (k > tmp.r) Del(a[k--]);
			for (int j = tl; j < tr; j++) Del(a[j]);
			int kans = tans[k];
			for (int j = tr - 1; j >= tmp.l; j--) kans = min(kans, Ins(a[j]));
			for (int j = tmp.l - 1; j >= tl; j--) Ins(a[j]);
			ans[tmp.id] = kans;
		}
	}
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}