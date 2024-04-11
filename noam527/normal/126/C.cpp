#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, a[2002][2002], R[2002], ans = 0;

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		char c;
		cin >> c;
		a[i][j] = c - '0';
	}
	int exp;

	for (int times = 0; times < 2; times++) {
		for (int i = 0; i < n; i++) R[i] = 0;
		for (int j = n - 1; j >= 0; j--) {
			exp = 1;
			for (int i = 0; i < j; i++) {
				if ((a[i][j] ^ R[i]) == exp) {
					exp ^= 1;
					ans++;
					R[i] ^= 1;
					a[i][i] ^= 1;
					a[j][j] ^= 1;
				}
			}
		}
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) swap(a[i][j], a[j][i]);
	}
	for (int i = 0; i < n; i++) ans += a[i][i];
	finish(ans);
}