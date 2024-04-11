#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 7;
int T, n, ch[N][26], fa[N], len[N], cnt[N];
int las, tot;
ll ans;
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
void work() {
	for(int i = 1; i <= tot; i++) c[len[i]] ++;
	for(int i = 1; i <= tot; i++) c[i] += c[i - 1];
	for(int i = 1; i <= tot; i++) q[c[len[i]] --] = i;
	for(int i = tot; i >= 1; i--) cnt[fa[q[i]]] += cnt[q[i]];
	for(int i = 1; i <= tot; i++) ans += 1ll * cnt[i] * cnt[i] * (len[i] - len[fa[i]]);
}
char s[N];
int main() {
	scanf("%d", &T);
	while(T--) {
		ans = 0;
		memset(c, 0, sizeof(c));
		memset(q, 0, sizeof(q));
		memset(ch, 0, sizeof(ch));
		memset(len, 0, sizeof(len));
		memset(cnt, 0, sizeof(cnt));
		memset(fa, 0, sizeof(fa));
		las = 1, tot = 1;
		scanf("%s", s);
		n = strlen(s);
		for(int i = 0; i < n; i++) ins(s[i] - 'a');
		work();
		printf("%lld\n", ans);
	}
	return 0;
}