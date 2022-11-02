#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <queue>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	ll a = 0, b = 0;
	foru(i, 0, n)cin >> v[i];
	sort(v.rbegin(), v.rend());
	foru(i, 0, n) {
		if (!(i & 1) && !(v[i] & 1))a += v[i];
		if ((i & 1) && (v[i] & 1))b += v[i];
	}
	if (a > b)cout << "Alice\n";
	if (a < b)cout << "Bob\n";
	if (a == b)cout << "Tie\n";
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}