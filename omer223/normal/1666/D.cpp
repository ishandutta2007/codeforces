#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#include <stack>
#include <set>
#include <string>
#include <queue>
#include <time.h>
#include <chrono>
#include <random>
#include <iomanip>
#include <map>
#include <numeric>
#include <complex>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, pair<pii, int>> einf;


void solve() {
	string s, t;
	cin >> s >> t; int n = s.length();
	vector<int> occ[26];
	foru(i, 0, n) {
		occ[s[i] - 'A'].push_back(i);
	}
	vector<int> cnts(26, 0);
	for (char c : t)cnts[c - 'A']++;
	vector<bool> is(n, false);
	foru(i, 0, 26) {
		if (cnts[i] > occ[i].size()) {
			cout << "NO\n";
			return;
		}
		else {
			int m = occ[i].size();
			foru(j, 0, cnts[i]) {
				is[occ[i][m - j - 1]] = 1;
			}
		}
	}
	string p = "";
	foru(i, 0, n) {
		if (is[i])p.push_back(s[i]);
	}
	if (p == t)cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}