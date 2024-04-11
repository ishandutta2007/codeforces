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
#include <bitset>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e3;
int n;

void solve() {
	cin >> n;
	string s;
	vector<vector<bool>> a(n, vector<bool>(n)), b = a, c;
	foru(i, 0, n) { cin >> s; foru(j, 0, n)a[i][j] = (s[j] - '0'); }
	foru(i, 0, n) { cin >> s; foru(j, 0, n)b[i][j] =(s[j] - '0'); }
	c = a;
	foru(i, 0, n) {
		if (c[0][i] != b[0][i]) {
			foru(j, 0, n)c[j][i] = !c[j][i];
		}
	}
	foru(i, 1, n) {
		if (c[i][0] != b[i][0]) {
			foru(j, 0, n)c[i][j] = !c[i][j];
		}
	}
	if (c == b) {
		cout << "YES\n";
		return;
	}
	c = a;
	foru(i, 0, n)c[0][i] = !c[0][i];
	foru(i, 0, n) {
		if (c[0][i] != b[0][i]) {
			foru(j, 0, n)c[j][i] = !c[j][i];
		}
	}
	foru(i, 1, n) {
		if (c[i][0] != b[i][0]) {
			foru(j, 0, n)c[i][j] = !c[i][j];
		}
	}if (c == b) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}