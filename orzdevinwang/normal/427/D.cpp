#include<bits/stdc++.h>
using namespace std;
const int N = 3e4;
int n, m, ans = 114514;
int c[N], q[N];
struct sam {
	int ch[N][26], las = 1, tot = 1, fa[N], len[N], cnt[N];
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
	void work() {
		memset(c, 0, sizeof(c));
		memset(q, 0, sizeof(q));
		for(int i = 1; i <= tot; i++) c[len[i]] ++;
		for(int i = 1; i <= tot; i++) c[i] += c[i - 1];
		for(int i = 1; i <= tot; i++) q[c[len[i]]--] = i;
		for(int i = tot; i >= 1; i--) cnt[fa[q[i]]] += cnt[q[i]];
	}
} sa, sb;
char a[N], b[N];
int main() {
	scanf("%s%s", a, b), n = strlen(a), m = strlen(b);
	for(int i = 0; i < n; i++) sa.ins(a[i] - 'a');
	for(int i = 0; i < m; i++) sb.ins(b[i] - 'a');
	sa.work(), sb.work();
	for(int i = 0; i < n; i++) {
		int pa = 1, pb = 1;
		for(int j = i; j < n; j++) {
			pa = sa.ch[pa][a[j] - 'a'];
			pb = sb.ch[pb][a[j] - 'a'];
			if(!pb) break;
			if(sa.cnt[pa] == 1 && sb.cnt[pb] == 1) 
				ans = min(ans, j - i + 1);
		}
	}
	printf("%d\n", ans == 114514 ? -1 : ans);
	return 0;
}