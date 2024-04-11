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

string s;

void solve() {
	cin >> s;
	int crbst = 10;
	foru(i, 0, (1 << 10)) {
		string t = s;
		foru(j, 0, 10) {
			if (t[j] == '?')t[j] = (((i >> j) & 1) ? '1' : '0');
		}
		int o = 0, tt = 0, orem=5,trem=5;
		foru(k, 0, 10) {
			if (k & 1) {
				if (t[k] == '1')tt++;
				trem--;
			}
			else {
				if (t[k] == '1')o++;
				orem--;
			}
			if (trem < (o - tt) || orem < (tt - o)) {
				crbst = min(crbst, (int)k + 1);
				break;
			}
		}
	}
	cout << crbst << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}