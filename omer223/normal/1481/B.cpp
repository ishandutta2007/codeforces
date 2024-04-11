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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	foru(i, 0, n)cin >> a[i];
	int stp = -1;
	while (k--) {
		bool found = 0;
		foru(i, 0, n - 1) {
			if (a[i] < a[i + 1]) {
				a[i]++;
				stp = i+1;
				found = 1;
				break;
			}
		}
		if (!found) {
			stp = -1; break;
		}
	}
	cout << stp << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}