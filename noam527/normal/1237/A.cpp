#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, x;
int lst = 0;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	while (n--) {
		cin >> x;
		if (x % 2 == 0) {
			cout << x / 2 << '\n';
			continue;
		}
		if (lst == 0) {
			if (x > 0) cout << x / 2 << '\n';
			else cout << x / 2 - 1 << '\n';
		}
		else {
			if (x > 0) cout << x / 2 + 1 << '\n';
			else cout << x / 2 << '\n';
		}
		lst ^= 1;
	}
}