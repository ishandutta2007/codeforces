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
#include <numeric>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6;
int n;
ll k;
ll a[sz];

void solve() {
	cin >> n >> k;
	foru(i, 0, n)cin >> a[i];
	sort(a, a + n);
	ll g = 0;
	foru(i, 0, n - 1)g = gcd(a[i + 1] - a[i], g);
	if (g == 1)cout << "YES\n";
	else {
		if (abs(k - a[0]) % g == 0)cout << "YES\n";
		else cout << "NO\n";
	}
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}