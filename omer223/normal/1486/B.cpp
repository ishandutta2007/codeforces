#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
	int n;
	cin >> n;
	vector<ll> x(n),y(n);
	foru(i, 0, n)cin >> x[i] >> y[i];
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	if (n & 1)cout << 1 << '\n';
	else cout << (x[n / 2] - x[n / 2 - 1] + 1)*(y[n / 2] - y[n / 2 - 1] + 1) << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}