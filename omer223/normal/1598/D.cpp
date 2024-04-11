#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <math.h>
#include <chrono>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n), b(n), ca(n),cb(n);
	foru(i, 0, n)cin >> a[i] >> b[i], ca[--a[i]]++, cb[--b[i]]++;
	ll tot = (n * (n - 1) * (n - 2)) / 6;
	foru(i, 0, n) {
		tot -= (ca[a[i]] - 1) * (cb[b[i]] - 1);
	}
	cout << tot << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}