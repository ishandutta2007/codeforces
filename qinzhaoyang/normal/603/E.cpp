#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10 , M = 3e5 + 10;

struct Edge {int x, y, v, t;} a[M], b[M];
bool operator < (Edge A , Edge B) {return A.v > B.v;}
int n, m, cnt, fa[N], s[N], d[N], top, ans[M];
pair <pair<int,int>,int> st[M];

int find(int x) {
	while(fa[x] != x) x = fa[x];
	return x;
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	cnt -= (s[x] & 1) + (s[y] & 1);
	if(d[x] > d[y]) swap(x, y);
	int t = d[x] == d[y];
	fa[x] = y, s[y] += s[x], d[y] += t, cnt += (s[y] & 1);
	st[++top] = make_pair(make_pair(x, y), t);
}

void del(int tp) {
	int x = st[tp].first.first, y = st[tp].first.second, t = st[tp].second;
	cnt -= (s[y] & 1), fa[x] = x, s[y] -= s[x], d[y] -= t;
	cnt += (s[x] & 1) + (s[y] & 1);
}

priority_queue <Edge> q;
vector <Edge> A[M << 2];

void add(int p, int l, int r, int tl, int tr, Edge e) {
	if(tl > tr) return;
	if(tl <= l && r <= tr) return A[p].push_back(e), void();
	int mid = (l + r) >> 1;
	if(tl <= mid) add(p << 1, l, mid, tl, tr, e);
	if(tr > mid) add(p << 1 | 1, mid + 1, r, tl, tr, e);
}

void dfs(int p, int l, int r, int res) {
	int tmp = top;
	for(auto i : A[p]) {
		merge(i.x, i.y);
		res = max(res, i.v); 
	}
	if(l == r) {
		int cur = 0;
		while(cnt && !q.empty()) {
			Edge k = q.top(); q.pop();
			if(k.t <= l) {
				merge(k.x, k.y), res = max(res, k.v);
				b[++cur] = k;
			}
		}
		if(!cnt) {
			for(int i = 1; i <= cur; i++)
				add(1, 1, m, b[i].t, l - 1, b[i]);
			ans[l] = res;
		}
		else ans[l] = -1;
	}
	else {
		int mid = (l + r) >> 1;
		dfs(p << 1 | 1, mid + 1, r, res);
		dfs(p << 1, l , mid, res);
	}
	while(top != tmp) del(top--); 
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m, cnt = n	;
	for(int i = 1; i <= n; i++)	fa[i] = i, s[i] = 1;
	for(int i = 1; i <= m; i++) {
		cin >> a[i].x >> a[i].y >> a[i].v, a[i].t = i;
		q.push(a[i]);
	}
	dfs(1, 1, m, -1);
	for(int i = 1; i <= m; i++)
		cout << ans[i] << endl;
	return 0;
}