#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
typedef long long ll;
const int N = 3005;
int n, K;
vector <ll> su[N];
ll f[15][N], as;
void solve(int l, int r, int d) {
	if(l == r) {
		For(i, 0, su[l].size()) if(i <= K) as = max(as, f[d - 1][K - i] + su[l][i]);
		return;
	}
	int mid = (l + r) / 2;
	rep(i, 0, K) f[d][i] = f[d - 1][i];
	rep(i, mid + 1, r) {
		int k = su[i].size() - 1;
		per(j, K, k) f[d][j] = max(f[d][j], f[d][j - k] + su[i].back());
	}
	solve(l, mid, d + 1);
	rep(i, 0, K) f[d][i] = f[d - 1][i];
	rep(i, l, mid) {
		int k = su[i].size() - 1;
		per(j, K, k) f[d][j] = max(f[d][j], f[d][j - k] + su[i].back());
	}
	solve(mid + 1, r, d + 1);
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> K;
	int t, x;
	rep(i, 1, n) {
		scanf("%d", &t), su[i].pb(0);
		while(t--) scanf("%d", &x), su[i].pb(su[i].back() + x);
	}
	solve(1, n, 1);
	cout << as;
	return 0;
}