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


void solve(){
	int n, sum = 0;
	cin >> n;
	vector<int> a(n);
	foru(i, 0, n) {
		cin >> a[i];
		sum += a[i];
	}
	bool f = 0;
	for (int i = 2; i * i <= sum; i++) {
		if (sum % i == 0) {
			f = 1;
			break;
		}
	}
	if (f) {
		cout << n << '\n';
		foru(i, 0, n)cout << i + 1 << ' ';
		cout << '\n';
	}
	else {
		cout << n - 1 << '\n';
		bool fo = 0;
		foru(i, 0, n) {
			if (a[i] & 1) {
				if (!fo)fo = 1;
				else cout << i + 1 << ' ';
			}
			else cout << i + 1 << ' ';
		}
		cout << '\n';
	}
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}