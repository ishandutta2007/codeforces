#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int rnd() {
	return ((rand() % (1 << 15)) << 16) + (rand() % (1 << 15));
}

int n, m, p;
vector<string> s;
vector<ll> a;

const int M = 1 << 15;

int dp[16][1 << 15];
int bitcnt[M] = {};

pair<int, ll> work(ll val) {
	vector<ll> bits;
	ll tmp = val;
	while (tmp) {
		bits.push_back(tmp & -tmp);
		tmp ^= (tmp & -tmp);
	}
	if (bits.size() == 0) {
		return{ 0, 0 };
	}

	for (int i = 0; i < M; i++)
		dp[0][i] = 0;
	for (int i = 0; i < n; i++) {
		int cur = 0;
		for (int j = 0; j < bits.size(); j++) {
			if (a[i] & bits[j]) cur |= (1 << j);
		}
		dp[0][cur]++;
	}
	for (int i = 1; i <= bits.size(); i++) {
		ll bit = (1 << (i - 1));
		for (int mask = 0; mask < M; mask++) {
			if (mask & bit)
				dp[i][mask] = dp[i - 1][mask];
			else
				dp[i][mask] = dp[i - 1][mask] + dp[i - 1][mask | bit];
		}
	}
	int best = 0;
	int bestval = 0;
	for (int mask = 1; mask < M; mask++) {
		if (2 * dp[bits.size()][mask] >= n) {
			int cnt = bitcnt[mask];
			if (best < cnt) {
				best = cnt;
				bestval = mask;
			}
		}
	}
	//cout << best << " " << bestval << '\n';
	ll ans = 0;
	for (int i = 0; i < bits.size(); i++) {
		if (bestval & (1 << i)) ans |= bits[i];
	}
	return{ best, ans };
}

void solve() {
	cin >> n >> m >> p;
	s.resize(n);
	a.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (ll j = 0; j < m; j++)
			if (s[i][j] == '1')
				a[i] += (1LL << j);
	}
	int iter = 25;
	pair<int, ll> best = { 0, 0 };
	for (int i = 0; i < iter; i++) {
		int ind = rnd() % n;
		//cout << ind << '\n';
		best = max(best, work(a[ind]));
	}
	for (ll j = 0; j < m; j++) {
		if (best.second & (1LL << j))
			cout << 1;
		else
			cout << 0;
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for (int i = 1; i < M; i++)
		bitcnt[i] = 1 + bitcnt[i - (i & -i)];
	int cur = time(NULL);
	int curcur = cur % md;
	
	while (cur == time(NULL)) {
		curcur = 2 * curcur % md;
	}
	
	srand(curcur);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}