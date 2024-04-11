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


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		ll x;
		cin >> x;
		while (x % 2 == 0)x /= 2;
		if (x == 1)cout << "NO\n";
		else cout << "YES\n";

	}
	return 0;
}