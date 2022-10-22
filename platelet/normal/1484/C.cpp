#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define mid ((l + r) / 2)
#define lch l, mid, o * 2
#define rch mid + 1, r, o * 2 + 1

using namespace std;
const int N = 1e5 + 5;
int T, n, m, c[N], ans[N]; vector <int> a[N];

void solve() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) c[i] = 0;
	rep(i, 1, m) ans[i] = 0, a[i].clear();
	int k, x;
	rep(i, 1, m) {
		scanf("%d", &k);
		if(k == 1) scanf("%d", &ans[i]), c[ans[i]]++;
		else while(k--) scanf("%d", &x), a[i].push_back(x);
	}
	rep(i, 1, n) if(c[i] > (m + 1) / 2) return puts("NO"), void();
	rep(i, 1, m) if(!ans[i]) {
		int v = 0;
		for(int x : a[i]) if(c[x] < (m + 1) / 2) { v = x; break; }
		if(!v) return puts("NO"), void();
		ans[i] = v, c[v]++;
	}
	puts("YES");
	rep(i, 1, m) printf("%d ", ans[i]);
	puts("");	
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--; solve());
	return 0;
}