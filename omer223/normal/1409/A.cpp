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
#include <stack>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 3e5;
int a[sz], n;

void solve() {
	ll x, y;
	cin >> x >> y;
	if (x == y)cout << 0 << endl;
	else cout << ((abs(x - y) - 1) / 10 + 1) << endl;
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}