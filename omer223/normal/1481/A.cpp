#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void solve() {
	int px, py;
	string s;
	cin >> px >> py >> s;
	vector<int> cnt(26, 0);
	for (char c : s)cnt[c - 'A']++;
	if (px < 0) {
		if (cnt['l' - 'a'] < -px) {
			cout << "NO\n";
			return;
		}
	}
	else {
		if (cnt['r' - 'a'] < px) {
			cout << "NO\n";
			return;
		}
	}
	if (py < 0) {
		if (cnt['d' - 'a'] < -py) {
			cout << "NO\n";
			return;
		}
	}
	else {
		if (cnt['u' - 'a'] < py) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}