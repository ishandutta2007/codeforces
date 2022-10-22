#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define upd(a, b) (a = min(a, b))

using namespace std;
typedef long long ll;
const int N = 1e5, M = N + 5;
int n, m, f[M], nxt[M], vis[M], ok[M];
int main() {
	mem(f, -1);
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	int t, y; ll x;
	cin >> n >> m;
	f[0] = 0;
	rep(k, 1, n) {
		scanf("%d%lld%d", &t, &x, &y);
		if(t == 1) {
			x = (x + N - 1) / N;
			rep(i, 0, m) nxt[i] = min(i + x, m + 1ll);
		} else {
			nxt[0] = m + 1;
			rep(i, 1, m) nxt[i] = min((i * x + N - 1) / N, m + 1ll);
		}
		mem(vis, 0);
		rep(i, 0, m) if(!vis[i]) {
			vector <int> v;
			for(int j = i; j <= m; j = nxt[j]) vis[j] = 1, v.push_back(j);
			int cnt = 0;
			For(j, 0, v.size()) {
				if(cnt) ok[v[j]] = 1;
				cnt += f[v[j]] != -1;
				if(j >= y) cnt -= f[v[j - y]] != -1;
			}
		}
		rep(i, 0, m) if(!~f[i] && ok[i]) f[i] = k;
	}
	rep(i, 1, m) printf("%d ", f[i]);
	return 0;
}