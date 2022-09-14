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
 
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n)
		cin >> a[i];
	for (int i = 0; i < (1 << n); i++) {
		int s = 0;
		rep(j, n) {
			if (i & (1 << j))
				s += a[j];
			else
				s -= a[j];
		}
		if (s % 360 == 0) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}