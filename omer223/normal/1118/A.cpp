#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;


int main() {
	fast;
	int q;
	cin >> q;
	while (q--) {
		ll n, a, b;
		cin >> n >> a >> b;
		if (n % 2 == 0)cout << min(n*a, (n / 2)*b) << '\n';
		else cout << min((n - 1)*a, (n / 2)*b) + a << '\n';
	}
	return 0;
}