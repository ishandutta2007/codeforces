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

const int sz = 3e5;
ll a[sz];


void solve() {
	ll n, x, y, z;
	cin >> n;
	foru(i, 0, n)cin >> a[i];
	sort(a, a + n);
	ll tmp = 1;
	foru(i, 0, 5)tmp *= a[n - i - 1];
	ll ans = tmp;
	tmp = 1;
	foru(i, 0, 4)tmp *= a[i];
	tmp *= a[n - 1];
	ans = max(ans, tmp);
	tmp = 1;
	foru(i, 0, 2)tmp *= a[i];
	foru(i, 0, 3)tmp *= a[n - i - 1];
	ans = max(ans, tmp);
	cout << ans << endl;
}


int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}