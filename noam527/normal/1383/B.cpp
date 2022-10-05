#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define finish(X) return cout << (X) << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a;

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	int x = 0;
	for (auto &i : a) x ^= i;
	if (x == 0) {
		cout << "DRAW\n";
		return;
	}
	int mx = 1 << 30;
	while ((x & mx) == 0) mx /= 2;
	int A = 0, B = 0;
	for (int i = 0; i < n; i++)
		if (a[i] & mx)
			A++;
		else
			B++;
	if (B % 2 == 0) {
		if (A % 4 == 1) {
			cout << "WIN\n";
		}
		else {
			cout << "LOSE\n";
		}
	}
	else {
		cout << "WIN\n";
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}