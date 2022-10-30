#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <numeric>
#include <random>
#include <time.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void solve() {
	int n;
	bool f = 0;
	cin >> n;
	set<int> s;
	int x, y;
	cin >> x;
	s.insert(x);
	y = x;
	foru(i, 0, n - 1) {
		cin >> x;
		if (x > y) {
			auto it = s.find(y);
			it++;
			if (it != s.end() && *it < x) {
				f = 1;
			}
		}
		else if (x < y) {
			auto it = s.find(y);
			it--;
			if (it != s.end() && *it > x) {
				f = 1;
			}
		}
		s.insert(x);
		y = x;
	}
	cout << (f?"NO\n":"YES\n");
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}