#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

const int N = 205;
const ll P = 1e9 + 7;

int n, d[N];
vector<int> G[N], s[N], T[N];
ll as, F[N][N], two[N];

ll Pow(ll a, int n, ll r = 1) {
	for(; n; n /= 2, a = a * a % P)
	if(n & 1) r = r * a % P;
	return r;
}

void dfs(int u, int fa) {
	T[u] = {u}, s[u].clear();
	for(int v : G[u]) if(v ^ fa)
		s[u].pb(v), d[v] = d[u] + 1, dfs(v, u), T[u].insert(T[u].end(), all(T[v]));
	for(int v : T[u]) as += u > v;
	for(int a : s[u]) for(int b : s[u]) if(a ^ b)
	for(int x : T[a]) for(int y : T[b]) if(x > y)
		(as += F[d[x] - d[u]][d[y] - d[u] - 1]) %= P;
}
int main() {
#ifdef local
	freopen(".in", "r", stdin);
#endif
	// int T; for(cin >> T; T--; solve());
	scanf("%d", &n);
	two[0] = 1;
	rep(i, 1, n) two[i] = two[i - 1] * (P / 2 + 1) % P;
	F[0][0] = 1;
	rep(i, 1, n) rep(j, 0, n) rep(k, 0, j) (F[i][j] += F[i - 1][k] * two[j - k + 1]) %= P;
	rep(i, 1, n) rep(j, 1, n) (F[i][j] += F[i][j - 1]) %= P;
	int u, v;
	rep(i, 2, n) scanf("%d%d", &u, &v), G[u].pb(v), G[v].pb(u);
	rep(i, 1, n) d[i] = 0, dfs(i, 0);
	cout << as * Pow(n, P - 2) % P;
	return 0;
}