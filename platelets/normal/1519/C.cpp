#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
int T, n, u[N], s[N];
ll tot[N], e[N];
vector <int> v[N];
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		cin >> n;
		rep(i, 1, n + 1) v[i].clear(), tot[i] = e[i] = 0;
		rep(i, 1, n) scanf("%d", &u[i]);
		rep(i, 1, n) scanf("%d", &s[i]);
		rep(i, 1, n) v[u[i]].pb(s[i]);
		rep(i, 1, n) {
			sort(v[i].begin(), v[i].end());
			ll su = 0;
			For(j, 0, v[i].size()) {
				if(j) {
					int t = v[i].size() - j;
					for(int k = 1; k * k <= t; k++) if(t % k == 0) {
						if(k > j) e[k] += su;
						if(k * k < t && t / k > j) e[t / k] += su;
					}
				}
				su += v[i][j];
			}
			tot[v[i].size()] += su;
		}
		per(i, n, 1) tot[i] += tot[i + 1];
		rep(i, 1, n) printf("%lld ", tot[i] - e[i]);
		puts("");
	}
	return 0;
}