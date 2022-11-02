
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <unordered_map>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



void solve() {
	string s;
	int n;
	cin >> n >> s;
	string ret = "";
	int prv = -1;
	foru(i, 0, n) {
		if (i == 0) {
			ret.pb('1');
			prv = 1 + s[i] - '0';
		}
		else {
			if (1 + s[i] - '0' != prv) {
				ret.pb('1');
				prv = 1 + s[i] - '0';
			}
			else {
				ret.pb('0');
				prv = s[i] - '0';
			}
		}
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