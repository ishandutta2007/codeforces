#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = (1 << 20), mod = 1e9 + 7 ;
int n, m, op[N], siz[N], cnt[N];
int ehd[N], ev[N], ew[N], enx[N], eid;
void eadd (int u, int v, int w) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ew[eid] = w, ehd[u] = eid; 
} 
ll mn, mx, dep[N];
void dfs1 (int x, int fa) {
	op[x] = siz[x] = 1;
	for (int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa) {
		int v = ev[i];
		dep[v] = dep[x] + ew[i], dfs1 (v, x); 
		op[x] += op[v], siz[x] += siz[v];
	}
	mx += (ll) (op[x] / 2) * dep[x];
	op[x] %= 2;
}
int all = 0;
void dfs2 (int x, int fa) {
//	cout << "count of " << x << " is " << cnt[x] << '\n';
	siz[n * 2 + 1] = 1;
	vector < pair < int, int > > vc;
	vc.push_back(make_pair (1, n * 2 + 1));
	for (int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa) 
		vc.push_back(make_pair (siz[ev[i]], ev[i]));
	sort(vc.begin(), vc.end());
	reverse(vc.begin(), vc.end());
	int p = -1;
	L(i, 0, sz(vc) - 1) {
		int s = vc[i].first - (i + 1 == sz(vc) ? 0 : vc[i + 1].first);
		if(s * (i + 1) >= cnt[x]) {
			p = i;
			break ;
		}
		cnt[x] -= s * (i + 1);
	}
	if(p == -1) assert (0);
	L(i, 0, p - 1) vc[i].first = vc[p].first;
	int k = cnt[x] / (p + 1);
	cnt[x] -= (p + 1) * k;
	L(i, 0, p) vc[i].first -= k;
	L(i, 0, cnt[x] - 1) vc[i].first -= 1;
	L(i, 0, sz(vc) - 1) 
		cnt[vc[i].second] += siz[vc[i].second] - vc[i].first, siz[vc[i].second] = vc[i].first;
	cnt[x] = 0;
	
	priority_queue < pair < int, int > > q;
	if(siz[n * 2 + 1]) q.push(make_pair (1, n * 2 + 1)); 
	for (int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa && siz[ev[i]]) 
		q.push(make_pair (siz[ev[i]], ev[i]));
	while (sz(q) > 1) {
		int u = q.top().second;
		q.pop();
		int v = q.top().second;
		q.pop();
		mn += dep[x];
		all += 1;
		
		if(all > n) 
			assert (0);
		
		siz[u] -= 1, cnt[u] += 1;
		if(siz[u]) q.push(make_pair (siz[u], u));
		
		siz[v] -= 1, cnt[v] += 1;
		if(siz[v]) q.push(make_pair (siz[v], v));
	}
	for (int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa) dfs2 (ev[i], x);
}
void Main () {
	all = 0;
	mn = mx = 0;
	cin >> n;
	L(i, 1, n * 2 - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		eadd (u, v, w);
		eadd (v, u, w); 
	}
	dfs1 (1, 0);
	dfs2 (1, 0);
	mn = -mn * 2, mx = -mx * 2;
	L(i, 1, n * 2) mn += dep[i], mx += dep[i];
	cout << mx << ' ' << mn << '\n';
	eid = 0;
	L(i, 1, n * 2 + 1) ehd[i] = cnt[i] = siz[i] = op[i] = 0;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}
/*
2
2
1 2 1
1 3 2
1 4 3
3
1 2 3
3 2 4
2 4 3
4 5 6
5 6 5
*/