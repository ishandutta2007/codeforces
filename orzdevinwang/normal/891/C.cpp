#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 5e5 + 7;
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x * f; 
}
struct UFS {
	stack< pii > stk;
	int h[N], f[N];
	void init(int x) {
		L(i, 1, x) f[i] = i, h[i] = 0;
	}
	int find(int x) {
		return f[x] == x ? x : f[x] = find(f[x]);
	}
	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return 0;
		if(h[x] > h[y]) swap(x, y);
		stk.push(mkp(x, h[x] == h[y])), h[y] += (h[x] == h[y]), f[x] = y;
		return 1;
	}
	void revoke() {
		int u = stk.top().first;
		h[f[u]] -= stk.top().second, f[u] = u, stk.pop();
	}
} ufs;
struct node {
	int u, v, val, id; 
} E[N];
int n, m, tot = 1, du[N], dv[N], w[N];
int main() {
	n = read(), m = read();
	L(i, 1, m) E[i].u = read(), E[i].v = read(), w[i] = E[i].val = read(), E[i].id = i;
	sort(E + 1, E + m + 1, [&](node aa, node bb) { return aa.val < bb.val; });
	ufs.init(n);
	while(tot <= m) {
		int now = tot;
		while(tot <= m && E[tot].val == E[now].val) {
			du[E[tot].id] = ufs.find(E[tot].u);
			dv[E[tot].id] = ufs.find(E[tot].v);
			++tot;
		}
		L(i, now, tot - 1) ufs.merge(E[i].u, E[i].v);
	}
	ufs.init(n);
	int q = read();
	while(q--) {
		int k = read(), ok = 1;
		L(i, 1, k) {
			int a = read();
			E[i].u = du[a], E[i].v = dv[a], E[i].val = w[a];
		}
		sort(E + 1, E + k + 1, [&](node aa, node bb) { return aa.val < bb.val; });
		tot = 1;
		while(tot <= k) {
			int now = tot, cnt = 0;
			while(tot <= k && E[tot].val == E[now].val) {
				if(ufs.find(E[tot].u) == ufs.find(E[tot].v)) ok = 0;
				else cnt += ufs.merge(E[tot].u, E[tot].v);
				++tot;
			}
			while(cnt) --cnt, ufs.revoke();
		}
		if(!ok) puts("NO");
		else puts("YES");
	}
	return 0;
}