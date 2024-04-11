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
const int N = 2e5 + 7;
int n, m;
int las = 1, tot = 1, ch[N][26], fa[N], col[N], len[N], cnt[N];
void copy(int x, int y) {
	L(i, 0, 25) ch[y][i] = ch[x][i];
	fa[y] = fa[x], len[y] = len[x];
}
void ins(int x) {
	if(ch[las][x] && len[ch[las][x]] == len[las] + 1) {
		las = ch[las][x];
		return;
	}
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
char s[N];
vector<int> pos[N];
int c[N], q[N]; ll qz[N];
void work() {
	L(i, 1, tot) if(cnt[i] >= m) qz[i] = len[i] - len[fa[i]]; 
	L(i, 1, tot) c[len[i]] ++;
	L(i, 1, tot) c[i] += c[i - 1];
	L(i, 1, tot) q[c[len[i]] --] = i;
	L(i, 1, tot) qz[q[i]] += qz[fa[q[i]]];
}
int main() {
	scanf("%d%d", &n, &m);
	L(t, 1, n) {
		las = 1;
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		L(i, 1, len) ins(s[i] - 'a'), pos[t].push_back(s[i] - 'a');
	}
	L(i, 1, n) {
		int wz = 1;
		L(j, 0, pos[i].size() - 1) {
			wz = ch[wz][pos[i][j]];
			for(int now = wz; now && col[now] != i; now = fa[now]) col[now] = i, cnt[now] ++;
		}
	}
	work();
	L(i, 1, n) {
		ll sum = 0; int wz = 1;
		L(j, 0, pos[i].size() - 1) wz = ch[wz][pos[i][j]], sum += qz[wz];
		printf("%lld ", sum);
	}
	puts("");
	return 0;
}