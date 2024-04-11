#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
 
const int N = 1e5 + 10;
 
struct ST_Array {
	int s[N], n;
	void init(int k) {
		n = k;
		for (int i = 1; i <= n; i++)
			s[i] = 0;
	}
	void Mdf(int x, int v) {
		for (; x <= n; x += x & (-x)) s[x] += v;
	}
	int Qry(int x) {
		int ret = 0;
		for (; x; x -= x & (-x)) ret += s[x];
		return ret;
	}
}	Tr;
 
map <pair<ull,ull>,int> m;
map <int,int> lt;
vector <int> G[N], d[N], D[N];
int cnt = 0;
 
struct Query {int l, r, id;};
bool operator < (Query A, Query B) {
	return A.r < B.r;
}
vector <Query> q[N];
 
int n, Q, fa[N], c[N], M, Ans[N], wh[N];
int dep[N], L[N], R[N], cur = 0, lst[N];
 
void dfs(int x, int f) {
	if (x != 0) dep[x] = dep[f] + 1;
	L[x] = ++cur;
	for (int i : G[x]) dfs(i, x);
	R[x] = cur;
}
 
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ull k1 = 0, k2 = 0; string s;
		cin >> s >> fa[i]; G[fa[i]].pb(i);
		for (int j = 0; j < s.size(); j++)
			k1 = k1 * 233 + s[j], k2 = k2 * 257 + s[j];
		if (!m[mp(k1, k2)]) m[mp(k1, k2)] = ++cnt;
		c[i] = m[mp(k1, k2)];
	}
	dfs(0, 0);
	for (int i = 1; i <= n; i++)
		d[dep[i]].pb(i), M = max(M, dep[i]);
	for (int i = 1; i <= M; i++)
		sort (d[i].begin(), d[i].end(), [&] (int A, int B) {return L[A] < L[B];});
	scanf("%d", &Q);
	for (int i = 1; i <= Q; i++) {
		int v, k; cin >> v >> k;
		if (dep[v] + k > M) continue;
		q[dep[v] + k].pb((Query){L[v], R[v], i});
	}
	for (int i = 1; i <= M; i++) {
		lt.clear();
		for (int j : d[i]) lst[j] = lt[c[j]], lt[c[j]] = j;
		for (int j = 0; j < d[i].size(); j++) wh[d[i][j]] = j + 1;
	}
	for (int i = 1; i <= M; i++)
		for (int j : d[i]) D[i].pb(L[j]);
	for (int i = 1; i <= M; i++) {
		int k = 0; sort(q[i].begin(), q[i].end());
		Tr.init(d[i].size());
		for (Query j : q[i]) {
			while (k < d[i].size() && j.r >= L[d[i][k]]) {
				if (lst[d[i][k]]) Tr.Mdf(wh[lst[d[i][k]]], -1);
				Tr.Mdf(wh[d[i][k++]], 1);
			}
			int x = lower_bound(D[i].begin(), D[i].end(), j.l) - D[i].begin() + 1,
				y = upper_bound(D[i].begin(), D[i].end(), j.r) - D[i].begin();
			if (x <= y) Ans[j.id] = Tr.Qry(y) - Tr.Qry(x - 1);
		}
	}
	for (int i = 1; i <= Q; i++) cout << Ans[i] << "\n";
	return 0;
}