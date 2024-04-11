#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
using namespace std;
const int N = 2e6 + 7;
int n, m, ch[N][26], fa[N], len[N], cnt[N], las = 1, tot = 1;
void copy(int x, int y) {
	for(int i = 0; i < 26; i++) ch[y][i] = ch[x][i];
	fa[y] = fa[x], len[y] = len[x];
}
void ins(int x) {
	int p = las, now = las = ++tot;
	len[now] = len[p] + 1, cnt[now] = 1;
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
int c[N], q[N];
char s[N];
void work() {
	L(i, 1, tot) c[len[i]]++;
	L(i, 1, tot) c[i] += c[i - 1];
	L(i, 1, tot) q[c[len[i]]--] = i;
	R(i, tot, 1) cnt[fa[q[i]]] += cnt[q[i]];
}
int gx[N];
void query(int x) {
	int now = 1, L = 0;
	for(int i = 1; i <= n; i++) {
		while(L > 0 && !ch[now][s[i] - 'a']) 
			now = fa[now], L = len[now];
		if(ch[now][s[i] - 'a']) now = ch[now][s[i] - 'a'], ++L;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		if(n == L) {
			if(gx[now] != x) ans += cnt[now], gx[now] = x;
			--L;
			if(L == len[fa[now]]) now = fa[now];
		}
		while(L > 0 && !ch[now][s[i] - 'a']) 
			now = fa[now], L = len[now];
		if(ch[now][s[i] - 'a']) now = ch[now][s[i] - 'a'], ++L;
	}
	printf("%lld\n", ans);
}
int main() {
	scanf("%s", s), n = strlen(s);
	L(i, 0, n - 1) ins(s[i] - 'a');
	work();
	scanf("%d", &m);
	L(i, 1, m) {
		scanf("%s", s + 1), n = strlen(s + 1);
		query(i);
	}
	return 0;
}