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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 80;
int n, m, k;
int a[sz][sz];

int main() {
	fast;
	cin >> n >> m >> k;
	int maxTake = m / 2;
	foru(i, 0, n) {
		foru(j, 0, m)cin >> a[i][j];
	}
	vector<ll> dp(k, -1e15);
	dp[0] = 0;
	foru(i, 0, n) {
		vector<vector<ll>> dprow(maxTake + 1, vector<ll>(k, -1e15));
		foru(j, 0, k)dprow[0][j] = dp[j];
		foru(j, 0, m) {
			ll myrem = a[i][j] % k;
			ford(take, maxTake, 1) {
				foru(rem, 0, k)dprow[take][rem] = max(dprow[take][rem], dprow[take - 1][(rem - myrem + k) % k] + a[i][j]);
			}
		}
		foru(j, 0, k) {
			foru(i, 0, maxTake + 1)dp[j] = max(dp[j], dprow[i][j]);
		}
	}
	cout << dp[0] << '\n';
	return 0;
}