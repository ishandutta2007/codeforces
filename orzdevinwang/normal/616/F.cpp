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
int n, w[N];
int ch[N][26], fa[N], len[N], tot = 1, las = 1;
ll cnt[N];
void cpy(int x, int y) {
	copy(ch[x], ch[x] + 26, ch[y]), fa[y] = fa[x], len[y] = len[x];
}
void ins(int x, int w) {
	if(ch[las][x] && len[ch[las][x]] == len[las] + 1) {
		las = ch[las][x], cnt[las] += w;
		return;
	}
	int p = las, now = las = ++tot;
	len[now] = len[p] + 1, cnt[now] += w;
	for(; !ch[p][x]; p = fa[p]) ch[p][x] = now;
	if(!p) fa[now] = 1;
	else {
		int pto = ch[p][x];
		if(len[pto] == len[p] + 1) fa[now] = pto;
		else {
			int sp = ++tot;
			cpy(pto, sp), len[sp] = len[p] + 1;
			fa[pto] = fa[now] = sp;
			for(; ch[p][x] == pto; p = fa[p]) ch[p][x] = sp;
		}
	}
}
int c[N], q[N];
ll ans;
void work() {
	L(i, 1, tot) c[len[i]] ++;
	L(i, 1, tot) c[i] += c[i - 1];
	L(i, 1, tot) q[c[len[i]] --] = i;
	R(i, tot, 1) cnt[fa[q[i]]] += cnt[q[i]];
	L(i, 1, tot) ans = max(ans, len[i] * cnt[i]);
}
string t[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> t[i];
	L(i, 1, n) cin >> w[i];
	L(i, 1, n) {
		las = 1;
		L(j, 0, t[i].size() - 1) ins(t[i][j] - 'a', w[i]);
	}
	work();
	cout << ans << "\n";
	return 0;
}