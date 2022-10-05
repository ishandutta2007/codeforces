#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n, m;
ll k;
string s;
int sp[12][1005];
int lg2[1005];

vector<pair<int, int>> p;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.second - p1.first > p2.second - p2.first)
		return !cmp(p2, p1);

	int lg = lg2[p1.second - p1.first + 1];
	int d = p1.second - p1.first + 1;
	if (sp[lg][p1.first] != sp[lg][p2.first])
		return sp[lg][p1.first] < sp[lg][p2.first];
	if (sp[lg][p1.first + d - (1 << lg)] != sp[lg][p2.first + d - (1 << lg)])
		return sp[lg][p1.first + d - (1 << lg)] < sp[lg][p2.first + d - (1 << lg)];
	if (p1.second - p1.first == p2.second - p2.first)
		return false;
	return true;
}

void prep() {
	lg2[1] = 0;
	for (int i = 2; i <= n; i++)
		lg2[i] = 1 + lg2[i / 2];

	for (int i = 0; i < n; i++)
		sp[0][i] = s[i];
	for (int i = 1, l = 2; l <= n; i++, l *= 2) {
		vector<vector<int>> tmp(n);
		for (int j = 0; j < n; j++) {
			if (j + l / 2 < n)
				tmp[j] = { sp[i - 1][j], sp[i - 1][j + l / 2], j };
			else {
				tmp[j] = { sp[i - 1][j], -1, j };
			}
		}
		sort(tmp.begin(), tmp.end());
		sp[i][tmp[0][2]] = 0;
		for (int k = 1; k < n; k++) {
			if (tmp[k - 1][0] == tmp[k][0] && tmp[k - 1][1] == tmp[k][1])
				sp[i][tmp[k][2]] = sp[i][tmp[k - 1][2]];
			else
				sp[i][tmp[k][2]] = 1 + sp[i][tmp[k - 1][2]];
		}
	}
}

ll dp[1005][1005];

ll calc(int l, int r) {
	string low = "";
	for (int i = l; i <= r; i++)
		low.push_back(s[i]);

	vector<int> R(n);
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (j < low.size() && i + j < s.size() && low[j] == s[i + j])
			j++;
		if (j == low.size())
			R[i] = i + j;
		else if (i + j == s.size())
			R[i] = -1;
		else {
			if (low[j] < s[i + j])
				R[i] = i + j + 1;
			else
				R[i] = -1;
		}
	}

	if (OO) {
		cout << "calc " << l << " " << r << '\n';
		for (const auto &i : R) cout << i << " "; cout << '\n';
	}

	dp[n][0] = 1;
	for (int i = 0; i < n; i++)
		dp[i][0] = 0;

	for (int j = 1; j <= m; j++) {

		for (int i = n - 1; i >= 0; i--)
			dp[i][j - 1] = min(inf, dp[i][j - 1] + dp[i + 1][j - 1]);

		dp[n][j] = 0;
		for (int i = 0; i < n; i++) {
			if (R[i] == -1)
				dp[i][j] = 0;
			else
				dp[i][j] = dp[R[i]][j - 1];
		}
	}
	if (OO) {
		cout << "returned " << dp[0][m] << '\n';
	}
	return dp[0][m];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k >> s;
	prep();

	p.reserve(n * (n + 1) / 2);
	for (int i = 0; i < n; i++) for (int j = i; j < n; j++) {
		if (j - i + 1 <= n - m + 1)
			p.emplace_back(i, j);
	}
	sort(p.begin(), p.end(), cmp);
	reverse(p.begin(), p.end());

	if (OO) {
		cout << "pairs\n";
		for (const auto &i : p) cout << i.first << " " << i.second << '\n'; cout << '\n';
	}

	int lo = 0, hi = (int)p.size() - 1, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		ll v;
		/*
		if (mid > 0)
			v = calc(p[mid].first, p[mid].second) - calc(p[mid - 1].first, p[mid - 1].second);
		else
			v = calc(p[0].first, p[0].second);
			*/
		v = calc(p[mid].first, p[mid].second);
		if (v < k)
			lo = mid + 1;
		else
			hi = mid;
	}
	//cout << p[lo].first << " " << p[lo].second << '\n';
	string ans = "";
	for (int i = p[lo].first; i <= p[lo].second; i++)
		ans.push_back(s[i]);
	cout << ans << '\n';
}