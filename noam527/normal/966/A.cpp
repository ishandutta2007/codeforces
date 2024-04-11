#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, c1, c2, v;
set<int> s, e;

int q, p[4];

int main() {
	fast;
	cin >> n >> m >> c1 >> c2 >> v;
	int tmp;
	for (int i = 0; i < c1; i++) {
		cin >> tmp;
		s.insert(tmp);
	}
	for (int i = 0; i < c2; i++) {
		cin >> tmp;
		e.insert(tmp);
	}

	cin >> q;
	int ans;
	while (q--) {
		cin >> p[0] >> p[1] >> p[2] >> p[3];
		if (p[0] == p[2]) cout << abs(p[3] - p[1]) << endl;
		else {
			ans = 2e9;
			if (s.size()) {
				auto it1 = s.lower_bound(p[1]);
				if (it1 == s.begin()) ans = min(ans, abs(*it1 - p[1]) + abs(p[2] - p[0]) + abs(*it1 - p[3]));
				else if (it1 == s.end()) {
					--it1;
					ans = min(ans, abs(*it1 - p[1]) + abs(p[2] - p[0]) + abs(*it1 - p[3]));
				}
				else {
					ans = min(ans, abs(*it1 - p[1]) + abs(p[2] - p[0]) + abs(*it1 - p[3]));
					--it1;
					ans = min(ans, abs(*it1 - p[1]) + abs(p[2] - p[0]) + abs(*it1 - p[3]));
				}
			}
			if (e.size()) {
				auto it1 = e.lower_bound(p[1]);
				if (it1 == e.begin()) ans = min(ans, abs(*it1 - p[1]) + (abs(p[2] - p[0]) + v - 1) / v + abs(*it1 - p[3]));
				else if (it1 == e.end()) {
					--it1;
					ans = min(ans, abs(*it1 - p[1]) + (abs(p[2] - p[0]) + v - 1) / v + abs(*it1 - p[3]));
				}
				else {
					ans = min(ans, abs(*it1 - p[1]) + (abs(p[2] - p[0]) + v - 1) / v + abs(*it1 - p[3]));
					--it1;
					ans = min(ans, abs(*it1 - p[1]) + (abs(p[2] - p[0]) + v - 1) / v + abs(*it1 - p[3]));
				}
			}
			cout << ans << endl;
		}
	}
}