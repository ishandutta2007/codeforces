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
	int n, c1 = 0, c2 = 0, x;
	cin >> n;
	rep(i, n) {
		cin >> x;
		if (x == 2)
			c2++;
		else
			c1++;
	}	
	if (c2 > 0) {
		c2--;
		cout << "2 ";
	}
	if (c1 > 0) {
		c1--;
		cout << "1 ";
	}
	rep(i, c2)
		cout << "2 ";
	rep(i, c1)
		cout << "1 ";
}