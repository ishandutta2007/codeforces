#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <iomanip>
#include <numeric>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
	string str;
	int ret = 0, c = 0, s = 0;
	cin >> str;
	for (char ch : str) {
		if (ch == '(')c++;
		else if (ch == ')') { if (c) { ret++; c--; } }
		else if (ch == '[')s++;
		else { if (s) { ret++; s--; } }
	}
	cout << ret << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}