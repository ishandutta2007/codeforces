#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--) 
using namespace std;
const int N = 1e6;
const int mod = 1e9 + 7;
int n, m, tt = 1919810;
int len[N], fa[N], ch[N][26], tot = 1, las = 1;
int cnt[N][5], sum[N];
void copy(int x, int y) {
	for(int i = 0; i < 26; i++) ch[y][i] = ch[x][i];
	fa[y] = fa[x], len[y] = len[x];
}
void ins(int x, int y) {
	if(ch[las][x] && len[ch[las][x]] == len[las] + 1) {
		las = ch[las][x];
		cnt[las][y] = 1;
		return;
	}
	int p = las, now = las = ++tot;
	len[now] = len[p] + 1;
	cnt[now][y] = 1;
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
void ad(int l, int r, int c) {
	(sum[r + 1] += mod - c) %= mod;
	(sum[l] += c) %= mod;
}
int q[N], c[N];
void work() {
	L(i, 1, tot) c[len[i]]++;
	L(i, 1, tot) c[i] += c[i - 1];
	L(i, 1, tot) q[c[len[i]]--] = i;
	R(i, tot, 1) L(p, 1, 3) cnt[fa[q[i]]][p] += cnt[q[i]][p];
	L(i, 1, tot) 
		 ad(len[fa[i]] + 1, len[i], 1ll * cnt[i][1] * cnt[i][2] % mod * cnt[i][3] % mod);
}
char a[N];
int main() {
	L(p, 1, 3) {
		las = 1;
		scanf("%s", a);
		n = strlen(a), tt = min(tt, n);
		for(int i = 0; i < n; i++) ins(a[i] - 'a', p);
	}
	work();
	for(int i = 1; i <= tt; i++) printf("%d ", (sum[i] += sum[i - 1]) %= mod);
	return 0;
}