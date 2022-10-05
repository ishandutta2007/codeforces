#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-6, pi = acos(-1);
using namespace std;

bool cmp(pair<ll, ll> &aa, pair<ll, ll> &bb) {
	if (aa.first != bb.first) return aa.first > bb.first;
	return aa.second > bb.second;
}
bool cmp2(pair<ldb, int> &aa, pair<ldb, int> &bb) {
	if (aa.first != bb.first) return aa.first < bb.first;
	return aa.second < bb.second;
}

ll n;
vector<pair<ll, ll>> a;
vector<ldb> b[50];
vector<ll> sum;

ldb dp[51][51];

ldb sumof(const vector<ldb> &bb, int first) {
	ldb rtn = 0;
	for (int i = 0; i < first; i++) rtn += bb[i];
	return rtn;
}

bool can(ldb P) {
	int nxt = 0, p1 = 1, p2;
	while (p1 <= n) {
		while (p1 < n && a[p1].first == a[p1 - 1].first) p1++;
		p2 = p1 - 1;
		b[nxt].clear();
		while (p2 >= 0 && a[p2].first == a[p1 - 1].first) {
			b[nxt].push_back(a[p2].first - P * a[p2].second);
			p2--;
		}
		sort(b[nxt].begin(), b[nxt].end());
		if (sum.size() == 0) sum.push_back(b[nxt].size());
		else sum.push_back(sum.back() + b[nxt].size());
		nxt++;
		p1++;
	}
//	for (int i = 0; i < nxt; i++) {
//		for (const auto &j : b[i]) cout << j << " "; cout << endl;
//	}
	for (int i = 0; i < 51; i++) dp[0][i] = 7e18;
	dp[0][sum[0]] = sumof(b[0], b[0].size());
	for (int i = 1; i < nxt; i++) {
		for (int j = 0; j < 51; j++) dp[i][j] = 7e18;
		for (int j = (sum[i - 1] + 1) / 2; j <= sum[i - 1]; j++) {
			for (int take = 0; take <= sum[i] - sum[i - 1]; take++) {
				if (2 * j - sum[i - 1] >= sum[i] - sum[i - 1] - take) {
					dp[i][j + take] = min(dp[i][j + take], dp[i - 1][j] + sumof(b[i], take));
				}
			}
		}
//		for (int j = 0; j <= sum[i]; j++) cout << dp[i][j] << " "; cout << endl;
	}
	for (int i = 0; i < 51; i++)
		if (dp[nxt - 1][i] <= 0) return true;
	return false;
}

int main() {
	fast;
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i.first;
	for (auto &i : a) cin >> i.second;
	sort(a.begin(), a.end(), cmp);
	
	ldb lo = 0, hi = 1e8 + 5, mid;
	while (abs(hi - lo) > eps) {
		mid = (lo + hi) / 2;
		if (can(mid)) hi = mid;
		else lo = mid;
	}
	ll ans = ceil(1000 * lo);
	cout << ans << endl;
	
}