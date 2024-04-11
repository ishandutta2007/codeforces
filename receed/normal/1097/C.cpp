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

const int N = 500001;
int l[N], r[N];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, b, mb;
	cin >> n;
	string s;
	rep(i, n) {
		cin >> s;
		b = mb = 0;
		for (char c : s) {
			b += (c == '(' ? 1 : -1);
			mb = min(mb, b);
		}
		if (b >= 0) {
			if (mb >= 0)
				l[b]++;
		}
		else {
			if (mb >= b)
				r[-b]++;
		}
	}
	int ans = l[0] / 2;
	for (int i = 1; i < N; i++)
		ans += min(l[i], r[i]);
	cout << ans;
}