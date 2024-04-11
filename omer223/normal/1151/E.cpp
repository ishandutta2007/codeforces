#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
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
#include <bitset>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;



int main() {
	fast;
	int n;
	cin >> n;
	vector<ll> a(n);
	ll tot = 0;
	foru(i, 0, n)cin >> a[i];
	tot += (a[0] * (n - a[0] + 1));
	foru(i, 1, n) {
		if (a[i] > a[i - 1]) {
			tot += ((a[i] - a[i - 1]) * (n - a[i] + 1));
		}
		else {
			tot += (a[i] * (a[i - 1] - a[i]));
		}
	}
	cout << tot;
	return 0;
}