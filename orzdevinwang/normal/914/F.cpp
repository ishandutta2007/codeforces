#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define pil pair<int, lonf long>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
const int B = 320;
const int kzB = 200;
const int S = B * 2 + 5;
const int Bs = N / B + 5;
int n, m;
char s[N], p[N];
struct SAM1 {
	int las = 1, tot = 1, ch[S][26], fa[S], len[S], cnt[S];
	void copy(int x, int y) {
		L(i, 0, 25) ch[y][i] = ch[x][i];
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
	int c[S], q[S];
	void work() {
		L(i, 1, tot) c[len[i]] ++;
		L(i, 1, tot) c[i] += c[i - 1];
		L(i, 1, tot) q[c[len[i]] --] = i;
		R(i, tot, 1) cnt[fa[q[i]]] += cnt[q[i]]; 
	}
	void clear() {
		fill(c + 1, c + tot + 1, 0);
		fill(q + 1, q + tot + 1, 0);
		fill(len + 1, len + tot + 1, 0);
		fill(fa + 1, fa + tot + 1, 0);
		fill(cnt + 1, cnt + tot + 1, 0);
		L(i, 1, tot) fill(ch[i], ch[i] + 26, 0);
	}
	void build(int l, int r) {
		clear(), las = 1, tot = 1;
		L(i, l, r) ins(s[i] - 'a');
		work();
	}
	int getans(char *s, int Len) {
		int now = 1;
		L(i, 1, Len) now = ch[now][s[i] - 'a'];
		if(!now) return 0;
		return cnt[now];
	}
} f[Bs];
struct SAM2 {
	int las = 1, tot = 1, ch[N][26], fa[N], len[N], cnt[N];
	void copy(int x, int y) {
		L(i, 0, 25) ch[y][i] = ch[x][i];
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
		L(i, 1, tot) c[len[i]] ++;
		L(i, 1, tot) c[i] += c[i - 1];
		L(i, 1, tot) q[c[len[i]] --] = i;
		R(i, tot, 1) cnt[fa[q[i]]] += cnt[q[i]]; 
	}
	void clear() {
		fill(c + 1, c + tot + 1, 0);
		fill(q + 1, q + tot + 1, 0);
		fill(len + 1, len + tot + 1, 0);
		fill(fa + 1, fa + tot + 1, 0);
		fill(cnt + 1, cnt + tot + 1, 0);
		L(i, 1, tot) fill(ch[i], ch[i] + 26, 0);
	}
	void build(int l, int r) {
		clear(), las = 1, tot = 1;
		L(i, l, r) ins(s[i] - 'a');
		work();
	}
	int getans(char *s, int Len) {
		int now = 1;
		L(i, 1, Len) now = ch[now][s[i] - 'a'];
		if(!now) return 0;
		return cnt[now];
	}
} sav;
int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	L(i, 1, (n - 1) / B + 1) f[i].build((i - 1) * B + 1, min(i * B, n));
	scanf("%d", &m);
	while(m--) {
		int opt, l, r, Len; scanf("%d%d", &opt, &l);
		if(opt == 1) {
			scanf("%s", p + 1), s[l] = p[1], r = (l - 1) / B + 1;
			f[r].build((r - 1) * B + 1, min(r * B, n));
		}
		else {
			scanf("%d%s", &r, p + 1), Len = strlen(p + 1);
			if(Len > kzB) sav.build(l, r), printf("%d\n", sav.getans(p, Len));
			else {
				int res = 0, Bl = (l - 1) / B + 1, Br = (r - 1) / B + 1;
				if(Bl == Br) {
					sav.build(l, r), printf("%d\n", sav.getans(p, Len));
					continue;
				}
				L(i, Bl + 1, Br - 1) res += f[i].getans(p, Len);
				sav.build(l, Bl * B), res += sav.getans(p, Len);
				sav.build((Br - 1) * B + 1, r), res += sav.getans(p, Len);
				L(i, Bl + 1, Br) {
					int pl = max(l, B * (i - 1) - Len + 2), pr = min(B * (i - 1) + Len - 1, r);
					sav.build(pl, pr), res += sav.getans(p, Len);
				}
				printf("%d\n", res);
			}
		}
	}
	return 0;
}