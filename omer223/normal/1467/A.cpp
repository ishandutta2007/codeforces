
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void solve() {
	int n;
	cin >> n;
	if (n == 1)cout << 9;
	else if (n == 2)cout << 98;
	else {
		cout << 98;
		foru(i, 2, n)cout << ((9+(i - 2)) % 10);
	}
	cout << '\n';
}


int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();

	return 0;
}