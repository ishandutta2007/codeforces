
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <numeric>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e5 + 5;
int n, a[sz], b[sz];

void solve() {
	int n,d;
	cin >> n>>d;

	int e = d;
	d = gcd(n, d);
	vector<int> a(n);
	vector<bool> has0(d, false), has1(d,false);
	int cnt = 0;
	foru(i, 0, n) {
		cin >> a[i];
		cnt += a[i];
		if (!a[i])has0[i % d] = 1;
		if (a[i])has1[i % d] = 1;
	}
	foru(i, 0, d) {
		if (has1[i] && !has0[i]) {
			cout << -1 << '\n';
			return;
		}
	}
	cnt = 0;
	vector<int> dp(n, 0);
	vector<vector<int>> adj(n);
	vector<int> indeg(n, 0);
	foru(i, 0, n) {
		if (a[i]) {
			if (a[(i + e) % n])adj[i].pb((i + e) % n);
		}
	}
	foru(i, 0, n) {
		for (int x : adj[i]) {
			indeg[x]++;
		}
	}
	queue<int> q;
	foru(i, 0, n) {
		if (!indeg[i] && a[i]) {
			q.push(i);
			dp[i] = 1;
		}
	}
	if (q.empty()) {
		cout << 0 << '\n';
		return;
	}
	int mx = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : adj[x]) {
			indeg[y]--;
			if (!indeg[y]) {
				dp[y] = dp[x] + 1;
				mx = max(mx, dp[y]);
				q.push(y);
			}
		}
	}
	cout << mx << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}