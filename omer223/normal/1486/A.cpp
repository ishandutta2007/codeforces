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
	vector<ll> x(n);
	foru(i, 0, n)cin >> x[i];
	ll tot = 0;
	foru(i, 0, n) {
		if (x[i] + tot >= i)tot = (x[i] + tot - i);
		else {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}