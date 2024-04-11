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
#include <bitset>
#include <stack>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e2, gridsz = 100, dim = 2 * gridsz + 1;

int n, d;
int a[sz], x[sz], y[sz];
vector<pii> adj[sz];
vector<pair<pii, int>> e;

void input() {
	cin >> n >> d;
	foru(i, 0, n - 2)cin >> a[i + 1];
	foru(i, 0, n)cin >> x[i] >> y[i];
	foru(i, 0, n) {
		foru(j, i + 1, n) {
			int myDist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			e.pb({ {i,j},myDist });
		}
	}
}

int main() {
	fast;
	input();
	int l = d, r = 1e9, mid, bst = 1e9;
	while (l <= r) {
		mid = (l + r + 1) / 2;
		vector<int> dp(n, -1);
		dp[0] = mid;
		for (int i = 0; i < n - 1; i++) {
			for (auto t : e) {
				if (dp[t.first.first] >= d * t.second)dp[t.first.second] = max(dp[t.first.second], dp[t.first.first] - d * t.second + a[t.first.second]);
				if (dp[t.first.second] >= d * t.second)dp[t.first.first] = max(dp[t.first.first], dp[t.first.second] - d * t.second + a[t.first.first]);
			}
		}
		if (dp[n - 1] != -1) {
			bst = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << bst << endl;
	return 0;
}