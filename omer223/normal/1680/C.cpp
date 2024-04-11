#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <unordered_map>
#include <chrono>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

string s;
int n;

bool ok(int x) {
	int totones = 0;
	for (char c : s)totones += (c == '1');
	int l = 0, r = 0, ocnt = 0, zcnt = 0;
	while (l < n) {
		while (r < n && totones - ocnt > x) {
			if (s[r] == '0')zcnt++;
			else ocnt++;
			r++;
		}
		if (zcnt <= x && totones - ocnt <= x)return 1;
		if (s[l] == '0')zcnt--;
		else ocnt--;
		l++;
	}
	return 0;
}

void solve() {
	cin >> s; n = s.length();
	vector<int> v(n);
	int sm = 0, totones = 0;
	foru(i, 0, n) {
		v[i] = (s[i] == '0' ? 1 : -1);
		sm += v[i];
		totones += (s[i] == '1');
	}
	int l = 0, r = n, bst = n, mid;
	ok(0);
	while (l <= r) {
		mid = (l + r + 1) / 2;
		if (ok(mid)) {
			bst = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << bst << '\n';
}


int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}