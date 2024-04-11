#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int sz = 5e5, mx = 2e5;
int n;
int a[sz];
ll cnt[sz];
ll p[sz], ps[sz];

int main() {
	fast;
	cin >> n;
	ll tot = 0;
	foru(i, 0, n) {
		cin >> a[i], tot += a[i], cnt[a[i]]++;
	}
	foru(i, 1, sz) {
		ps[i] = ps[i - 1] + cnt[i] * i;
		p[i] = p[i - 1] + cnt[i];
	}
	sort(a, a + n);
	ll bst = 0;
	int prv = -1;
	foru(i, 0, n) {
		if (a[i] != prv) {
			ll cur = tot;
			ll j = a[i];
			while (j <= mx) {
				cur -= ((ps[j + a[i] - 1] - ps[j]) - j*(p[j+a[i]-1]-p[j]));
				j += a[i];
			}
			bst = max(bst, cur);
		}
		prv = a[i];
		tot -= a[i];
	}
	cout << bst << '\n';
	return 0;
}