#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

const int sz = 1e2 + 5;
int n;
int a[3][sz];

void solve() {
	cin >> n;
	foru(i, 0, 3) {
		foru(j, 0, n)cin >> a[i][j];
	}
	vector<int> res;
	foru(i, 0, n) {
		if (!i)res.pb(a[0][i]);
		else if (i == n - 1) {
			foru(j, 0, 3) {
				if (a[j][i] != res[i - 1] && a[j][i] != res[0]) {
					res.pb(a[j][i]);
					break;
				}
			}
		}
		else {
			foru(j, 0, 3) {
				if (a[j][i] != res[i - 1]) {
					res.pb(a[j][i]);
					break;
				}
			}
		}
	}
	for (int k : res)cout << k << " ";
	cout << endl;
}


int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}