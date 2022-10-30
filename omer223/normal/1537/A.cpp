
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;




int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int sum = 0;
		foru(i, 0, n) {
			int t;
			cin >> t;
			sum += t;
		}
		if (sum < n)cout << 1 << '\n';
		else if (sum == n)cout << 0 << '\n';
		else cout << sum - n << '\n';
	}
	return 0;
}