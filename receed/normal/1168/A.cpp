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
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n)
		cin >> a[i];
	int l = -1, r = m, md;
	while (r - l > 1) {
		md = (l + r) / 2;
		int cm = 0;
		for (int i : a)
			if ((cm - i + m) % m > md) {
				if (i > cm)
					cm = i;
				else {
					cm = -1;
					break;
				}
			}
		if (cm == -1)
			l = md;
		else
			r = md;
	}
	cout << r;
}