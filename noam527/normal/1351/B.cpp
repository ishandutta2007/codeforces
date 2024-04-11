#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;



int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a[2], b[2];
		cin >> a[0] >> a[1] >> b[0] >> b[1];
		bool found = false;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (a[i] == b[j] && a[1 ^ i] + b[1 ^ j] == a[i])
					found = true;
			}
		}
		cout << (found ? "Yes" : "No") << endl;
	}
}