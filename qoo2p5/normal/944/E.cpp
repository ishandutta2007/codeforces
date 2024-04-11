#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 1e6 + 123;
const ll LINF = (ll) 1e18 + 1e9 + 123;
const ll MOD = (ll) 1e9 + 7;

#define rep(i, s, t) for (auto i = (s); i < (t); ++(i))
#define per(i, s, t) for (auto i = (s); i >= (t); --(i))
#define sz(x) ((int)(x).size())
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

template<typename A, typename B> bool mini(A &x, const B &y) {
	if (y < x) {
		x = y;
		return 1;
	}
	return 0;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
	if (y > x) {
		x = y;
		return 1;
	}
	return 0;
}

ll power(ll x, ll y, ll mod=MOD) {
	if (y == 0) {
		return 1;
	}
	if (y % 2 == 1) {
		return power(x, y - 1, mod) * x % MOD;
	} else {
		ll t = power(x, y / 2, mod);
		return t * t % MOD;
	}
}

void add(ll &x, ll y) {
	x += y;
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

ll mult(ll x, ll y) {
	return x * y % MOD;
}

void run();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
	return 0;
}

const int N = (int) 1e5 + 123;

int n, m;
int a[N];
int l[N], r[N];
int dp[N];
vector<pair<int, int>> st[N];

void run() {
	cin >> n >> m;
	rep(i, 0, n) {
		int l, r;
		cin >> l >> r;
		a[l]++;
		a[r + 1]--;
	}
	rep(i, 1, N) {
		a[i] += a[i - 1];
	}
	
	{
		fill(dp, dp + N, INF);
		dp[0] = 0;
		rep(i, 1, m + 1) {
			int ind = (int) (upper_bound(dp, dp + N, a[i]) - dp);
			l[i] = ind;
			dp[ind] = a[i];
		}
	}
	
	{
		fill(dp, dp + N, INF);
		dp[0] = 0;
		per(i, m, 1) {
			int ind = (int) (upper_bound(dp, dp + N, a[i]) - dp);
			r[i] = ind;
			dp[ind] = a[i];
		}
	}
	
	int ans = -1;
	int best = -1;
	
	rep(i, 1, m + 1) {
		if (maxi(ans, l[i] + r[i] - 1)) {
			best = i;
		}
	}
	
	cout << ans << "\n";
	
	/*vector<int> L, R;
	
	{
		fill(dp, dp + N, INF);
		rep(i, 0, N) st[i].clear();
		dp[0] = 0;
		rep(i, 1, m + 1) {
			int ind = (int) (upper_bound(dp, dp + N, a[i]) - dp);
			l[i] = ind;
			st[ind].pb({a[i], i});
			dp[ind] = a[i];
		}
		
		int len = l[best];
		int cur_pos = best;
		while (len > 0) {
			while (st[len].back().second > cur_pos) {
				st[len].pop_back();
			}
			cur_pos = st[len].back().second;
			L.pb(cur_pos);
			len--;
		}
	}
	
	{
		fill(dp, dp + N, INF);
		rep(i, 0, N) st[i].clear();
		dp[0] = 0;
		per(i, m, 1) {
			int ind = (int) (upper_bound(dp, dp + N, a[i]) - dp);
			r[i] = ind;
			st[ind].pb({a[i], i});
			dp[ind] = a[i];
		}
		
		int len = r[best];
		int cur_pos = best;
		while (len > 0) {
			while (st[len].back().second < cur_pos) {
				st[len].pop_back();
			}
			cur_pos = st[len].back().second;
			R.pb(cur_pos);
			len--;
		}
	}
	
	reverse(all(L));
	L.pop_back();
	for (int x : R) L.pb(x);
	
	assert(ans != -1);
	cout << ans << "\n";
	for (int x : L) cout << x << " ";
	cout << "\n";*/
}