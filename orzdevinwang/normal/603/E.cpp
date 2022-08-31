#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 3e5 + 7;
struct UFS {
	int f[N], cnt, siz[N];
	stack< int > stk;
	int find(int x) {
		return f[x] == x ? x : find(f[x]);
	}
	void init(int x) {
		L(i, 1, x) f[i] = i, siz[i] = 1;
		cnt = x;
	}
	bool merge(int u, int v) {
		u = find(u), v = find(v);
		if(u == v) return false;
		if(siz[u] > siz[v]) swap(u, v);
		if((siz[u] & 1) && (siz[v] & 1)) cnt -= 2;
		f[u] = v, siz[v] += siz[u], stk.push( u );
		return true;
	}
	void revoke() {
		int u = stk.top(), v = f[stk.top()];
		if((!(siz[v] & 1)) && (siz[u] & 1)) cnt += 2;
		siz[f[stk.top()]] -= siz[stk.top()], f[stk.top()] = stk.top(), stk.pop();
	}
} ufs;
int n, m, arr[N], mp[N], cnt, ans[N];
struct edge {
	int u, v, w, id;
} e[N];
void work(int l, int r, int sl, int sr) { //  id < l  w < sl 
	if(l > r) return ;
	int mid = (l + r) >> 1, o1 = 0, o2 = 0, mans = m + 1;
	L(i, l, mid) if(e[i].w < sl) o1 += ufs.merge(e[i].u, e[i].v);
	L(i, sl, sr) if(i < m + 1 && e[mp[i]].id <= mid) {
		o2 += ufs.merge(e[mp[i]].u, e[mp[i]].v);
		if(ufs.cnt == 0) {
			mans = i;
			break ;
		}
	}
	ans[mid] = mans;
	if(l == r) {
		while(o2 --) ufs.revoke();
		while(o1 --) ufs.revoke();
		return ;
	}
	while(o2 --) ufs.revoke();
	work(mid + 1, r, sl, mans);
	while(o1--) ufs.revoke();
	o2 = 0;
	L(i, sl, mans - 1) if(i < m + 1 && e[mp[i]].id < l) o2 += ufs.merge(e[mp[i]].u, e[mp[i]].v);
	work(l, mid - 1, mans, sr);
	while(o2 --) ufs.revoke();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, m) cin >> e[i].u >> e[i].v >> e[i].w, e[i].id = i;
	sort(e + 1, e + m + 1, [&](edge aa, edge bb) { return aa.w == bb.w ? aa.id < bb.id : aa.w < bb.w; });
	L(i, 1, m) arr[i] = e[i].w, e[i].w = i, mp[i] = e[i].id;
	// L(i, 1, m) cout << mp[i] << " \n"[i == m];
	sort(e + 1, e + m + 1, [&](edge aa, edge bb) { return aa.id < bb.id; });
	ufs.init(n);
	work(1, m, 1, m + 1);
	// L(i, 1, m) cout << ans[i] << "\n";
	L(i, 1, m) cout << (ans[i] == m + 1 ? -1 : arr[ans[i]]) << "\n";
	return 0;
}