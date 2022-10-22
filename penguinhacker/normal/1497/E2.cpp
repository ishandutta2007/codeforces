#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 10000001;
bool p[mxN];
vector<int> primes;
int n, k, a[200000];
ar<int, 2> dp[200000][21];

void ck(ar<int, 2>& x, ar<int, 2> y) {
	if (y[0]<x[0]||(x[0]==y[0]&&y[1]>x[1]))
		x=y;
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j : primes) {
			if (j * j > a[i])
				break;
			while(a[i] % (j * j) == 0)
				a[i] /= j * j;
		}
	}
	for (int j = 0; j <= k; ++j)
		dp[0][j] = {1, 0};
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int prv = mp.find(a[i]) == mp.end() ? -1 : mp[a[i]];
		mp[a[i]] = i;
		if (!i)
			continue;
		dp[i][0] = {69696969};
		for (int j = 1; j <= k; ++j)
			dp[i][j] = dp[i - 1][j - 1];
		for (int j = 0; j <= k; ++j) {
			if (prv < dp[i - 1][j][1])
				ck(dp[i][j], dp[i - 1][j]);
			else
				ck(dp[i][j], {dp[i - 1][j][0] + 1, i});
		}
	}
	cout << dp[n - 1][k][0] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(p, 1, sizeof(p));
	for (int i = 2; i < mxN; ++i) {
		if (p[i]) {
			if ((ll)i * i < mxN)
				for (int j = i * i; j < mxN; j += i)
					p[j] = 0;
			primes.push_back(i);
		}
	}
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}