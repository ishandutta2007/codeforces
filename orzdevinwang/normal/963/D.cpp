#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = 3e5 + 7, M = 5e6, cN = 26;
int n, m, hd[N];
int ch[M][2], tot;
bool sum[M];
void add(int &id, int L, int R, int p) {
	if(!id) id = ++tot;
	sum[id] = 1;
	if(L == R) return;
	int mid = (L + R) / 2;
	if(p <= mid) add(ch[id][0], L, mid, p);
	else add(ch[id][1], mid + 1, R, p);
}
int merge(int x, int y) {
	if(!x || !y) return x | y;
	int nw = ++tot;
	sum[nw] = (sum[x] | sum[y]);
	ch[nw][0] = merge(ch[x][0], ch[y][0]);
	ch[nw][1] = merge(ch[x][1], ch[y][1]);
	return nw;
}
int pos[N], tp;
void DFS(int x, int L, int R) {
	if(L == R) {
		pos[++tp] = L;
		return ;
	}
	int mid = (L + R) >> 1;
	if(ch[x][0]) DFS(ch[x][0], L, mid);
	if(ch[x][1]) DFS(ch[x][1], mid + 1, R);
}
struct SAM {
	int ch[N][cN], fa[N], len[N], las = 1, tot = 1;
	void copy(int x, int y) {
		L(i, 0, cN - 1) ch[y][i] = ch[x][i];
		len[y] = len[x], fa[y] = fa[x];
	}
	void ins(int x, int y) {
		int p = las, now = las = ++tot;
		len[now] = len[p] + 1, add(hd[now], 1, n, y);
		for(; p && !ch[p][x]; p = fa[p]) ch[p][x] = now;
		if(!p) fa[now] = 1;
		else {
			int pto = ch[p][x];
			if(len[pto] == len[p] + 1) fa[now] = pto;
			else {
				int sp = ++tot;
				copy(pto, sp), len[sp] = len[p] + 1;
				fa[pto] = fa[now] = sp;
				for(; p && ch[p][x] == pto; p = fa[p]) ch[p][x] = sp;
			}
		}
	}
} sam;
int c[N], q[N];
void work() {
	L(i, 1, sam.tot) c[sam.len[i]]++;
	L(i, 1, sam.tot) c[i] += c[i - 1];
	L(i, 1, sam.tot) q[c[sam.len[i]]--] = i;
	R(i, sam.tot, 1) hd[sam.fa[q[i]]] = merge(hd[sam.fa[q[i]]], hd[q[i]]);
}
char s[N], t[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> (s + 1), n = strlen(s + 1);
	L(i, 1, n) sam.ins(s[i] - 'a', i);
	work();
	cin >> m;
	while(m--) {
		int k;
		cin >> k >> (t + 1);
		int cur = 1, len = strlen(t + 1);
		L(i, 1, len) cur = sam.ch[cur][t[i] - 'a'];
		if(!cur) {
			cout << -1 << '\n';
			continue ;
		}
		tp = 0, DFS(hd[cur], 1, n);
//		cout << cur << ' ' << "tp = " << tp << endl;
		if(tp < k) {
			cout << -1 << '\n';
			continue ;
		}
		int ns = 1e9;
		L(i, 1, tp - k + 1) 
			ns = min(ns, pos[i + k - 1] - pos[i]);
		cout << ns + len << '\n';
	}
	return 0;
}