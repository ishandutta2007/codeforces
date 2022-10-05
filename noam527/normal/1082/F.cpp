#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, k;
vector<pair<string, int>> a;
vector<int> L;
vector<int> dp[505][505][11]; // dp[left][right][can take][height already taken] = how much we can add
int lcp[505][505], pos[505][505], sum[505][505];

void preprocess() {
	for (int i = 0; i < L.size(); i++) {
		lcp[i][i] = L[i];
		pos[i][i] = i;
		for (int j = i + 1; j < L.size(); j++) {
			if (lcp[i][j - 1] <= L[j])
				pos[i][j] = pos[i][j - 1];
			else
				pos[i][j] = j;
			lcp[i][j] = min(lcp[i][j - 1], L[j]);
		}
	}
	for (int i = 0; i < n; i++) {
		sum[i][i] = a[i].second;
		for (int j = i + 1; j < n; j++)
			sum[i][j] = sum[i][j - 1] + a[j].second;
	}
}

inline int Qm(int l, int r) {
	if (l == r) return a[l].first.size();
	return lcp[l][r - 1];
}
inline int Qs(int l, int r) {
	return sum[l][r];
}
inline int Qp(int l, int r) {
	return pos[l][r - 1];
}

int calc(int l, int r, int left, int h) {
	if (l > r) return 0;
	if (dp[l][r][left][h] != -1) return dp[l][r][left][h];
	if (left == 0) return dp[l][r][left][h] = 0;
	if (l == r) return dp[l][r][left][h] = Qs(l, r) * (Qm(l, r) - h);
	int res = 0;
	res = max(res, Qs(l, r) * (Qm(l, r) - h) + calc(l, r, left - 1, Qm(l, r)));
	res = max(res, calc(l + 1, r, left, h));
	for (int split = 0; split <= left; split++)
		res = max(res, calc(l, Qp(l, r), split, h) + calc(Qp(l, r) + 1, r, left - split, h));
	return dp[l][r][left][h] = res;
}

int main() {
	fast;
	cin >> n >> k;
	a.resize(n);
	for (auto &i : a) cin >> i.first >> i.second;
	sort(a.begin(), a.end());
	L.resize(n - 1);
	for (int i = 0; i < n - 1; i++) {
		L[i] = 0;
		while (L[i] < a[i].first.size() && L[i] < a[i + 1].first.size() && a[i].first[L[i]] == a[i + 1].first[L[i]]) L[i]++;
	}
	for (int i = 0; i < n; i++) {
		int mn = inf;
		for (int j = i; j < n; j++) {
			mn = min(mn, (int)a[j].first.size());
			for (int A = 0; A <= k; A++)
				dp[i][j][A].resize(mn + 1, -1);
		}
	}
	preprocess();
	int tot = 0;
	for (auto &i : a)
		tot += i.first.size() * i.second;
	cout << tot - calc(0, n - 1, k, 0) << endl;
}