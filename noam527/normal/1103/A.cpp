#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 9e18;
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	int nxt1 = 0, nxt2 = 0;
	for (auto &i : s) {
		if (i == '0') {
			cout << "1 " << 1 + nxt1 << '\n';
			nxt1 = (nxt1 + 1) % 4;
		}
		else {
			cout << "4 " << 1 + nxt2 << '\n';
			nxt2 = (nxt2 + 2) % 4;
		}
	}
}