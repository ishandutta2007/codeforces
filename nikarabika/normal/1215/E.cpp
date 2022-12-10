//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 4e5 + 10,
	  maxl = 20,
	  maxmask = 1 << 20;
int a[maxn],
	sum[maxn],
	n;
vector<int> vec[20];
LL dp[maxmask],
   cnt[maxl][maxl];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		vec[a[i]].PB(i);
	}
	for (int i = 0; i < maxl; i++) {
		for (int j = 0; j < n; j++)
			sum[j + 1] = sum[j] + (a[j] == i);
		for (int j = 0; j < maxl; j++)
			if (j ^ i)
				for (auto pos : vec[j])
					cnt[j][i] += sum[pos];
	}
	for (int mask = 1; mask < maxmask; mask++) {
		dp[mask] = 1e18;
		for (int i = 0; i < maxl; i++)
			if ((mask >> i) & 1) {
				int nmask = mask ^ (1 << i);
				LL curdp = dp[nmask];
				for (int j = 0; j < maxl; j++)
					if ((nmask >> j) & 1)
						curdp += cnt[i][j];
				smin(dp[mask], curdp);
			}
	}
	cout << dp[maxmask - 1] << endl;
	return 0;
}