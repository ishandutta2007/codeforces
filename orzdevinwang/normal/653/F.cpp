#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define pll pair<ll, ll> 
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
const int O = 5e5 + 1;
int tot = 1, las = 1, edp[N], ch[N][2], fa[N], len[N];
void copy(int x, int y) {
	ch[y][0] = ch[x][0], ch[y][1] = ch[x][1], len[y] = len[x], fa[y] = fa[x]; 
}
void ins(int x) {
	int p = las, now = las = ++tot;
	len[now] = len[p] + 1;
	for(; p && !ch[p][x]; p = fa[p]) ch[p][x] = now;
	if(!p) fa[now] = 1;
	else {
		int pto = ch[p][x];
		if(len[pto] == len[p] + 1) fa[now] = pto;
		else {
			int sp = ++tot;
			copy(pto, sp), len[sp] = len[p] + 1;
			fa[now] = fa[pto] = sp;
			for(; p && ch[p][x] == pto; p = fa[p]) ch[p][x] = sp;
		}
	}
}
int n, st[20][N], qz[N];
vector<int> ve[N];
int query(int l, int r) {
	int p = log2(r - l + 1);
	return min(st[p][l], st[p][r - (1 << p) + 1]);
}
int q[N], c[N];
void qsort() {
	L(i, 1, tot) c[len[i]] ++;
	L(i, 1, tot) c[i] += c[i - 1];
	L(i, 1, tot) q[c[len[i]] --] = i;
	R(i, tot, 1) edp[fa[q[i]]] = edp[q[i]];
}
bool vis[N];
ll ans;
char s[N];
int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	ve[O].push_back(0);
	L(i, 1, n) {
		if(s[i] == '(') qz[i] = qz[i - 1] + 1, ins(0);
		if(s[i] == ')') qz[i] = qz[i - 1] - 1, ins(1);
		edp[las] = i, ve[O + qz[i]].push_back(i), st[0][i] = qz[i];
	}
	L(i, -n, n) ve[O + i].push_back(19260817);
	L(i, 1, 19) L(j, 0, n - (1 << i) + 1) st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	qsort();
	L(x, 2, tot) {
		int l = edp[x] - len[x], r = edp[x], wz = edp[x];
		while(l <= r) {
			int mid = (l + r) / 2;
			if(query(mid, edp[x]) == qz[edp[x]]) wz = mid, r = mid - 1;
			else l = mid + 1;
		}
		int toget = O + qz[edp[x]], L = max(wz, edp[x] - len[x]), R = edp[x] - len[fa[x]] - 1;
		if(L > R) continue;
		ans += lower_bound(ve[toget].begin(), ve[toget].end(), R + 1) - lower_bound(ve[toget].begin(), ve[toget].end(), L);
	} 
	printf("%lld\n", ans);
	return 0;
}
// [len_{fa_x} + 1, len_x]