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
#include <set>
#include <bitset>
#include <cmath>
#include <unordered_map>
#include <map>
#include <intrin.h>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 3e3;
int n;
int dp[sz][sz], a[sz];
void reset() {
	foru(i, 0, n) {
		foru(j, 0, n) {
			dp[i][j] = 0;
		}
	}
}

void solve() {
	cin >> n;
	reset();
	foru(i, 0, n) {
		cin >> a[i];
		a[i]--;
	}
	ll cnt = 0;
	int l = 2, r = 3;
	while (l < n) {
		foru(i, 0, l - 1)dp[a[i]][a[l - 1]]++;
		while (r < n) cnt += dp[a[l]][a[r++]];
		l++;
		r = l + 1;
	}
	cout << cnt << endl;
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();

	return 0;
}