#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int n, m;


int countCycs(vector<int> v) {
	vector<bool> vis(n, false);
	int cnt = 0;
	foru(i, 0, n) {
		if (!vis[i]) {
			cnt++;
			int cur = v[i];
			while (!vis[cur]) {
				vis[cur] = 1;
				cur = v[cur];
			}
		}
	}
	return cnt;
}

void solve() {
	vector<int> ans;
	cin >> n >> m;
	vector<int> v(n);
	foru(i, 0, n)cin >> v[i], v[i]--;
	vector<int> shft(n, 0);
	foru(i, 0, n)shft[(v[i] - i + n) % n]++;
	foru(i, 0, n) {
		if (shft[i] >= n / 3 - 5) {
			vector<int> u(n);
			foru(j, 0, n)u[(j+i)%n] = (v[j]);
			int cy = countCycs(u);
			if (n - cy <= m)ans.push_back(i);
		}
	}
	cout << ans.size() << ' ';
	foru(i, 0, ans.size()) {
		if (ans[i])ans[i] = n - ans[i];
	}
	sort(ans.begin(), ans.end());
	for (int x : ans)cout << x << ' ';
	cout << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}