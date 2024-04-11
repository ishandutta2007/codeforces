#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e5 + 5;
int r, n;
pair<int, pii> v[sz];
ll dp[sz], mxsuf[sz];

int main() {
	fast;
	cin >> r >> n;
	foru(i,0, n) cin >> v[i].first >> v[i].second.first >> v[i].second.second;
	ford(i, n - 1, 0) {
		dp[i] = 1;
		foru(j, i + 1, n) {
			if (v[j].first - v[i].first > 2 * r) {
				dp[i] = max(dp[i], 1 + mxsuf[j]);
				break;
			}
			else {
				if (abs(v[i].second.first - v[j].second.first) + abs(v[i].second.second - v[j].second.second) <= v[j].first - v[i].first)
					dp[i] = max(dp[i], 1 + dp[j]);
			}
		}
		mxsuf[i] = max(mxsuf[i + 1], dp[i]);
	}
	ll tot = 0;
	foru(i, 0, n) {
		if (v[i].second.first - 1 + v[i].second.second - 1 <= v[i].first)tot = max(tot, dp[i]);
	}
	cout << tot << '\n';
	return 0;
}