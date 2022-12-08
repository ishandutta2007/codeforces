#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, inf = 0x3f3f3f3f;

struct Query {
	int l, r, id;
}	q[N];

int cmp(Query x, Query y) {
	if (x.r == y.r) return x.l < y.l;
	return x.r < y.r;
}

int m, b[N], n, ans[N];

struct ST {
	int s[N];
	ST() {memset(s, 0, sizeof s);}
	void Mdf(int x, int a) {
		for (; x <= m; x += x & (-x))
			s[x] += a;
	}
	int Qry(int x) {
		int ret = 0;
		for (; x; x -= x & (-x))
			ret += s[x];
		return ret;
	}
}	st;

int lst[N];
void Cal1() {
	for (int i = 1, j = 1; i <= m; i++) {
		if (lst[b[i]] != 0) st.Mdf(lst[b[i]], -1);
		st.Mdf(i, 1), lst[b[i]] = i;
		while (j <= n && q[j].r == i)
			ans[q[j].id] = st.Qry(q[j].r) - st.Qry(q[j].l - 1), j++;
	}
}

struct St {
	int Min[N << 2];
	void PushUp(int x) {
		Min[x] = min(Min[x << 1], Min[x << 1 | 1]);
	}
	void Build(int p, int l, int r) {
		Min[p] = inf;
		if (l == r) return;
		int mid = (l + r) >> 1;
		Build(p << 1, l, mid);
		Build(p << 1 | 1, mid + 1, r);
	}
	void Mdf(int p, int l, int r, int s, int t) {
		if (l == r) return Min[p] = t, void();
		int mid = (l + r) >> 1;
		if (s <= mid) Mdf(p << 1, l, mid, s, t);
		else Mdf(p << 1 | 1, mid + 1, r, s, t);
		PushUp(p);
	}
	int Qry(int p, int l, int r, int tl, int tr) {
		if (tl <= l && r <= tr) return Min[p];
		int mid = (l + r) >> 1; int ret = inf;
		if (tl <= mid) ret = min(ret, Qry(p << 1, l, mid, tl, tr));
		if (tr > mid) ret = min(ret, Qry(p << 1 | 1, mid + 1, r, tl, tr));
		return ret;
	}
}	sg;

int now[N], lenc[N], et[N];
vector <int> G[N];

void Cal2() {
	sg.Build(1, 1, m);
	for (int i = 1, j = 1; i <= m; i++) {
		if (et[b[i]] == 0) {
			lenc[b[i]] = inf;
			now[b[i]] = 1;
			sg.Mdf(1, 1, m, i, 1);
		}
		else {
			if (lenc[b[i]] == inf || lenc[b[i]] == i - et[b[i]]) {
				sg.Mdf(1, 1, m, et[b[i]], inf);
				sg.Mdf(1, 1, m, i, now[b[i]]);
			}
			else {
				now[b[i]] = G[b[i]][G[b[i]].size() - 2] + 1;
				sg.Mdf(1, 1, m, et[b[i]], inf);
				sg.Mdf(1, 1, m, i, now[b[i]]);
			}
			lenc[b[i]] = i - et[b[i]];
		}
		et[b[i]] = i;
		G[b[i]].push_back(i);
		while (j <= n && q[j].r == i) {
			int t = sg.Qry(1, 1, m, q[j].l, q[j].r);
			if (t > q[j].l) ans[q[j].id]++;
			j++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].id = i;
	}
	sort (q + 1, q + n + 1, cmp);
	Cal1(), Cal2();
	for (int i = 1; i <= n; i++)	
		cout << ans[i] << endl;
	return 0;
}