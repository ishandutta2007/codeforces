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
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

ll foo(int n) {
	int pw = 0;
	while (n % 2 == 0) {
		pw++;
		n /= 2;
	}
	return (n == 1 && (pw & 1));
}

void solve() {
	int n;
	cin >> n;
	if (foo(n))cout << "Bob\n";
	else if (n & 1)cout << "Bob\n";
	else cout << "Alice\n";
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}