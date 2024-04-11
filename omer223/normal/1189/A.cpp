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

int cnt[2];

int main() {
	fast;
	int n;
	string s;
	cin >> n >> s;
	for (char c : s)cnt[c - '0']++;
	if (cnt[0] != cnt[1])cout << 1 << '\n' << s;
	else {
		cout << 2 << '\n' << s.substr(0, n - 1) << ' ' << s[n - 1];
	}
	return 0;
}