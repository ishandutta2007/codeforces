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


const int sz = 5e5 + 5;
int n, k;
ll a[sz];

int foo(int l, int r) {
	if (a[l] > a[r])return -1e9;
	int len = r - l + 1;
	vector<ll> bst{ -1,-1 };
	bst[1] = a[l];
	int bi;
	for (int i = l + 1; i <= r; i++) {
		int lb = 1, rb = bst.size() - 1, mid;
		bi = -1;
		while (lb <= rb) {
			mid = (lb + rb) / 2;
			if (bst[mid] <= a[i]) {
				bi = mid;
				lb = mid + 1;
			}
			else rb = mid - 1;
		}
		if (bi + 1 == bst.size())
			bst.push_back(a[i]);
		else if (bi != -1)
			bst[bi + 1] = min((ll)bst[bi + 1], a[i]);
	}
	return len - (bi+1);
}

int main() {
	fast;
	cin >> n >> k;
	a[0] = -1e15, a[n + 1] = 1e15;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 0; i <= n + 1; i++)a[i] -= i;
	int l = 0, r;
	ll ans = 0;
	while (k--) {
		cin >> r;
		ans += foo(l, r);
		l = r;
	}
	r = n + 1;
	ans += foo(l, r);
	if (ans >= 0)cout << ans;
	else cout << -1;
	return 0;
}