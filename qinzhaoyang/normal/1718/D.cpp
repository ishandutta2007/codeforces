#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10, M = 1e6;

int T, n, q, k, p[N], a[N], fa[N], ok[N], val[N], ans[N];

int rt, st[N], tp, mx[N], mn[N], L[N], R[N];
void build_dke() {
	tp = 0;
	for (int i = 1; i <= n; i++)
		L[i] = R[i] = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = tp;
		while (tp && p[st[tp]] < p[i])
			tp--;
		if (tp) R[st[tp]] = i;
		if (tp < tmp) L[i] = st[tp + 1];
		st[++tp] = i;
	}
	rt = st[1];
}

int flag = 0;
void dfs(int x) {
	if (a[x] > 0) {
		if (mx[x] < a[x]) flag = 1;
		mx[x] = mn[x] = a[x];
	}
	if (L[x]) {
		mx[L[x]] = mx[x];
		dfs(L[x]);
	}
	if (R[x]) {
		mx[R[x]] = mx[x];
		dfs(R[x]);
	}
	if (a[x] == 0) {
		if (L[x]) mn[x] = max(mn[x], mn[L[x]]);
		if (R[x]) mn[x] = max(mn[x], mn[R[x]]);
	}
}

inline int cmp(pair<int,int> x, pair<int,int> y) {
	return x.second < y.second;
}

void solve() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	build_dke();
	/*
	for (int i = 1; i <= n; i++)
		cerr << L[i] << " ";
	cerr << endl;
	for (int i = 1; i <= n; i++)
		cerr << R[i] << " ";
	cerr << endl;
	*/
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		mx[i] = 1e6 + 10, mn[i] = -1;
	flag = 0, dfs(rt);
	/*
	for (int i = 1; i <= n; i++)
		cerr << mx[i] << " ";
	cerr << endl;
	for (int i = 1; i <= n; i++)
		cerr << mn[i] << " ";
	cerr << endl;
	*/
	vector<pair<int,int> > v, use;
	multiset<int> nod;
	k = 0;
	for (int i = 1; i <= n; i++)
		if (!a[i]) k++;
	for (int i = 1, x; i < k; i++)
		scanf("%d", &x), nod.insert(x);
	if (flag == 0) {
		for (int i = 1; i <= n; i++)
			if (!a[i]) v.push_back(make_pair(mn[i], mx[i]));
		sort (v.begin(), v.end(), cmp);
		/*
		cerr << k << endl;
		for (int i = 0; i < k; i++)
			cerr << v[i].first << " " << v[i].second << endl;
		*/
		for (int i = 1; i <= k; i++)
			fa[i] = 0, ok[i] = 0;
		int cnt = 0;
		multiset<pair<int,int> > fd;
		for (int i = 0; i < k; i++) {
			int l = v[i].first, r = v[i].second, id = i + 1;
			auto it = nod.lower_bound(l);
			if (it == nod.end() || *it > r) {
				auto jt = fd.lower_bound(make_pair(l, 0));
				while (jt != fd.end() && jt->first <= r) {
					fa[jt->second] = id;
					fd.erase(jt);
					jt = fd.lower_bound(make_pair(l, 0));
				}
				val[id] = r;
				cnt++;
				continue;
			}
			//cerr << "Run " << id << endl;
			ok[id] = 1;
			int nw = *it;
			nod.erase(it);
			val[id] = nw;
			auto jt = fd.lower_bound(make_pair(l, 0));
			while (jt != fd.end() && jt->first <= nw) {
				fa[jt->second] = id;
				fd.erase(jt);
				jt = fd.lower_bound(make_pair(l, 0));
			}
			fd.insert(make_pair(nw, id));
		}
		if (cnt > 1) flag = 1;
		else {
			int im = 0;
			for (int i = 1; i <= k; i++) {
				if (!ok[i]) im = i;
				ok[i] = 0;
			}
			/*
			for (int i = 1; i <= k; i++)
				cerr << fa[i] << " ";
			cerr << endl;
			*/
			ok[im] = 1;
			for (int i = k; i >= 1; i--)
				if (ok[fa[i]]) ok[i] = 1;
			for (int i = 1; i <= k; i++)
				if (ok[i])
					use.push_back(make_pair(v[i - 1].first, val[i]));
		}
	}
	/*
	for (pair<int,int> pr : use)
		cerr << pr.first << " " << pr.second << endl;
	*/
	multiset<pair<int,int> > qry;
	for (int i = 1; i <= q; i++) {
		int x; scanf("%d", &x); ans[i] = 0;
		qry.insert(make_pair(x, i));
	}
	if (flag == 0) {
		for (pair<int,int> pr : use) {
			int l = pr.first, r = pr.second;
			auto it = qry.lower_bound(make_pair(l, 0));
			while (it != qry.end() && it->first <= r) {
				ans[it->second] = 1;
				qry.erase(it);
				it = qry.lower_bound(make_pair(l, 0));
			}
		}
	}
	for (int i = 1; i <= q; i++)
		puts(ans[i] ? "YES" : "NO");
}

int main() {
	//freopen("1.in", "r", stdin);
	for (scanf("%d", &T); T; T--) solve();
	return 0;
}