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

const int sz = 1e6;
int n, k;
int a[sz], b[sz], p[sz], mxp[sz];

bool ok(int x) {
	b[0] = 0;
	foru(i, 0, n)b[i+1] = (a[i] >= x ? 1 : -1);
	p[0] = 0;
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] + b[i];
		mxp[i] = min(mxp[i - 1], p[i]);
	}
	for (int i = k; i <= n; i++) {
		if (p[i] - mxp[i - k] > 0)return 1;
	}
	return 0;
}

int main() {
	fast;
	cin >> n >> k;
	foru(i, 0, n)cin >> a[i];
	int l = 1, r = 1e9, mid, bst = -1;
	while (l <= r) {
		mid = (l + r + 1) / 2;
		if (ok(mid)) {
			bst = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << bst << '\n';
	return 0;
}