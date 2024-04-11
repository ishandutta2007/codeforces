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
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	string t;
	rep(i, n) {
		t = s.substr(i) + s.substr(0, i);
		if (s == t)
			continue;
		int f = 1;
		rep(i, n / 2)
			if (t[i] != t[n - 1 - i]) {
				f = 0;
				break;
			}
		if (f) {
			cout << 1;
			return 0;
		}
	}
	int f = 0;
	rep(i, n / 2)
		if (s[i] != s[0])
			f = 1;
	if (f)
		cout << 2;
	else
		cout << "Impossible";
}