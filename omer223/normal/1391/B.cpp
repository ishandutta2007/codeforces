#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

void solve() {
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	foru(i, 0, n) {
		string s;
		cin >> s;
		foru(j, 0, m) {
			if (j == m - 1 && i != n - 1 && s[j] == 'R')cnt++;
			if (i == n - 1 && j != m - 1 && s[j] == 'D')cnt++;
		}
	}
	cout << cnt << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}