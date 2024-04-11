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

int ch(char c1, char c2) {
	return abs((int) c1 - (int) c2) != 1;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	rep(z, t) {
		string s;
		cin >> s;
		vector<string> a(2);
		for (char c : s)
			a[(c - 'a') % 2].push_back(c);
		sort(all(a[0]));
		sort(all(a[1]));
		if (a[0].empty() || a[1].empty() || ch(a[0].back(), a[1][0])) {
			cout << a[0] << a[1] << '\n';
			continue;
		}
		if (ch(a[0].back(), a[1].back()))
			reverse(all(a[1]));
		else if (ch(a[0][0], a[1][0]))
			reverse(all(a[0]));
		else if (ch(a[0][0], a[1].back())) {
			reverse(all(a[0]));
			reverse(all(a[1]));
		}
		else {
			cout << "No answer\n";
			continue;
		}
		cout << a[0] << a[1] << '\n';
	}	
}