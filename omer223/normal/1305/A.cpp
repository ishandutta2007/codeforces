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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	foru(i, 0, n)cin >> a[i];
	foru(i, 0, n)cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int x : a)cout << x << ' ';
	cout << '\n';
	for (int x : b)cout << x << ' ';
	cout << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}