#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
const int B = 1500;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar();
	return x * f;
}
struct node {
	int id, l, r, k, nowid; 
} ask[N];
int d[N], f[N], tt;
int n, m, opt, tot, pnt, a[N], A[N];
int p[N], From[N], To[N], ans[N], cnt[N], mp[N];
bool flag[N];
void del(int val) {
	mp[cnt[val]] --, cnt[val] --, mp[cnt[val]] ++;
	if(mp[cnt[val]] == 1) d[++tt] = cnt[val];
}
void add(int val) {
	mp[cnt[val]] --, cnt[val] ++, mp[cnt[val]] ++;
	if(mp[cnt[val]] == 1) d[++tt] = cnt[val];
}
void fix() {
	int mx = 0;
	L(i, 1, tt) if(d[i] && mp[d[i]]) d[++mx] = d[i];
	tt = mx;
	sort(d + 1, d + tt + 1);
	tt = unique(d + 1, d + tt + 1) - d - 1;
}
int work(int k) {
	L(i, 1, tt) f[i] = mp[d[i]];
	L(i, 1, tt) f[i] += f[i - 1];
	int now = 1, res = 1e9;
	L(i, 1, tt) {
		if(f[i] < k) continue;
		while(f[i] - f[now] >= k) ++ now;
		res = min(res, d[i] - d[now]);
	}
	return res;
}
int main() {
	n = read(), m = read();
	L(i, 1, n) A[i] = a[i] = read();
	L(i, 1, m) {
		flag[i] = (read() - 1) ^ 1;
		if(!flag[i]) ++pnt, p[pnt] = read(), From[pnt] = A[p[pnt]], To[pnt] = A[p[pnt]] = read();
		else flag[i] = 1, ++tot, ask[tot].id = i, ask[tot].nowid = pnt, ask[tot].l = read(), ask[tot].r = read(), ask[tot].k = read();
	}
	sort(ask + 1, ask + tot + 1, [&](node aa, node bb) {
		return aa.nowid / B == bb.nowid / B ? (aa.l / B == bb.l / B ? aa.r < bb.r : aa.l < bb.l) : aa.nowid < bb.nowid;
	});
	L(i, 1, n) A[i] = a[i];
	int nowid = 0, l = 1, r = 0;
	L(i, 1, tot) {
		while(nowid < ask[i].nowid) {
			++nowid;
			if(p[nowid]) {
				if(l <= p[nowid] && p[nowid] <= r) del(From[nowid]), add(To[nowid]);
				A[p[nowid]] = To[nowid];
			}
		}
		while(nowid > ask[i].nowid) {
			if(p[nowid]) {
				if(l <= p[nowid] && p[nowid] <= r) del(To[nowid]), add(From[nowid]);
				A[p[nowid]] = From[nowid];
			}
			--nowid;
		}
		while(r < ask[i].r) ++r, add(A[r]);
		while(l > ask[i].l) --l, add(A[l]);
		while(l < ask[i].l) del(A[l]), ++l;
		while(r > ask[i].r) del(A[r]), --r;
		fix();
		ans[ask[i].id] = work(ask[i].k);
	}
	L(i, 1, m) if(flag[i]) {
		if(ans[i] <= 1e6) printf("%d\n", ans[i]);
		else puts("-1");
	}
	return 0;
}