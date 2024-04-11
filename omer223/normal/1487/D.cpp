#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <map>
#include <bitset>
#include <math.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int fsq(int n) {
	int b = sqrtl(n), bst=0,guess;
	for (int del = -3; del <= 3; del++) {
		guess = b + del;
		if (guess*guess <= n)bst = guess;
	}
	return bst;
}

void solve() {
	int n;
	cin >> n;
	int sq = fsq(n);
	ll t = fsq(2 * n + 1);
	cout << (t - 1) / 2 - (t*t == 2 * n + 1) << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}