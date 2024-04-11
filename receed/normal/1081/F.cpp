#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

int nt, n, t;

int q(int l, int r) {
	cout << "? " << l + 1 << ' ' << r + 1 << endl;
	cin >> t;
	if (t == -1)
		exit(0);
	return t;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> t;
	vector<int> a(n), oc(n);
	for (int i = n - 1; i > 0; i--) {
		int ot = t;
		for (int j = 0; j < 25 && t == ot; j++) {
			q(0, i - 1);
			q(0, i - 1);
		}
		oc[i] = (n - i + ot - t) / 2;
		while (t != ot) {
			q(0, i - 1);
			q(0, i - 1);
		}
	}
	oc[0] = t;
	for (int i = 0; i < n - 1; i++)
		oc[i] -= oc[i + 1];
	cout << "! ";
	for (int i : oc)
		cout << i;
	cout << endl;
}