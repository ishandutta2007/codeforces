#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <bitset>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	cout << a + b + c - 1 << endl;
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}