// You AK, wo bao ling. wo men de qian tu ... dou guang ming ! 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define uint unsigned int
using namespace std;
const int N = 2e5 + 7;
const int M = 4e6 + 7;
const int inf = (1 << 30);
int n, m, a[N];
int f[N], tot = 1, ch[M][2], col[M], vis[M];
int best[N], tok[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void upd(int x) {
	if(!ch[x][0] || !ch[x][1]) col[x] = (col[ch[x][0]] | col[ch[x][1]]);
	else if(col[ch[x][0]] ^ col[ch[x][1]]) col[x] = -1;
	else col[x] = col[ch[x][0]];
}
ll ans;
void ins(int x) {
	int now = 1;
	R(i, 29, 0) {
		int fg = ((a[x] >> i) & 1);
		if(!ch[now][fg]) ch[now][fg] = ++tot;
		now = ch[now][fg];
	}
	vis[now] = x;
	// cout << tot << endl;
}
void better(int x, int v, int val) {
	if(best[x] > val) best[x] = val, tok[x] = v;
}
void Boruvka() {
	L(i, 1, n) f[i] = i;
	bool ok = 1;
	while(ok) {
		ok = 0;
		R(i, tot, 1) if(!vis[i]) upd(i); else col[i] = find(vis[i]);
		if(col[1] != -1) break;
		L(i, 1, n) best[i] = inf;
		L(i, 1, n) {
			int now = 1, len = 0;
			R(j, 29, 0) {
				bool flag = ((a[i] >> j) & 1);
				if(ch[now][flag] && col[ch[now][flag]] != find(i)) now = ch[now][flag];
				else len += (1 << j), now = ch[now][flag ^ 1];
			}
			// cout << len << endl;
			better(find(i), col[now], len);
		}
		L(i, 1, n) if(find(i) == i) {
			if(best[i] == inf) continue;
			if(find(i) == find(tok[i])) continue;
			ans += best[i], f[i] = find(tok[i]), ok = 1;
		}
	}
}
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]), ins(i);
	Boruvka();
	printf("%lld\n", ans);
	return 0;
}