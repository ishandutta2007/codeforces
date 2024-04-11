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
typedef vector<int> vi;

int ask(int x1, int y1, int x2, int y2) {
	cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	fflush(stdout);
	int ans;
	cin >> ans;
	return ans;
}

void ans(int x1, int y1, int x2, int y2) {
	cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	fflush(stdout);
	return;
}

int main() {
	fast;
	vector<int> r, c;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		bool isr = ask(i, 1, i, n) & 1, isc = ask(1, i, n, i) & 1;
		if (isr)r.push_back(i);
		if (isc)c.push_back(i);
	}
	if (!r.empty() && !c.empty()) {
		if (ask(r[0], c[0], r[0], c[0]) == 1) {
			ans(r[0], c[0], r[1], c[1]);
		}
		else {
			ans(r[0], c[1], r[1], c[0]);
		}
	}
	else if (!r.empty()) {
		int lb = 1, rb = n, mid;
		while (lb < rb) {
			mid = (lb + rb) / 2;
			if (ask(r[0], 1, r[0], mid) & 1)
				rb = mid;
			else
				lb = mid + 1;
		}
		ans(r[0], lb, r[1], lb);
	}
	else if (!c.empty()) {
		int lb = 1, rb = n, mid;
		while (lb < rb) {
			mid = (lb + rb) / 2;
			if (ask(1, c[0], mid, c[0]) & 1)
				rb = mid;
			else
				lb = mid + 1;
		}
		ans(lb, c[0], lb, c[1]);
	}
	return 0;
}