#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
const int N = 1e5 + 5, P = 998244353;
int n, K, sz, ai, lst[N], pre[N];
int w[N], f[N], tag[320], c[320][N], tmp, ans;
void pushdown(int i) {
	if(tag[i]) {
		For(j, i * sz, i * sz + sz)
			(c[i][w[j]] -= f[j]) %= P, (c[i][w[j] += tag[i]] += f[j]) %= P;
		tag[i] = 0;
	}
}
void upd(int p, int ty) {
	For(i, 0, p / sz) {
		if(ty == -1) tag[i]--;
		int j = K - tag[i];
		if(j >= 0 && j < n) (ans -= ty * c[i][j]) %= P;
		if(ty == 1) tag[i]++;
	}
	pushdown(p / sz);
	For(i, p / sz * sz, p) {
		if(~ty ? w[i] == K : w[i] == K + 1) (ans -= ty * f[i]) %= P;
		(c[p/sz][w[i]] -= f[i]) %= P, (c[p/sz][w[i] += ty] += f[i]) %= P;
	}
}
int main() {
	ans = c[0][0] = f[0] = 1;
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> K, sz = sqrt(n);
	rep(i, 1, n) {
		scanf("%d", &ai);
		pre[i] = lst[ai];
		upd(i, 1); if(pre[i]) {
			upd(pre[i], -1), upd(pre[i], -1);
			if(pre[pre[i]]) upd(pre[pre[i]], 1);
		}
		f[i] = ans;
		if(i < n) pushdown(i / sz), (c[i/sz][0] += ans) %= P;
		lst[ai] = i, (ans *= 2) %= P;
	}
	cout << (f[n] + P) % P;
	return 0;
}