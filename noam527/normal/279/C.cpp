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
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, a[100000], l, r;
map<int, int> q; // contains the extreme points. -1 for min, 1 for max

int main() {
	fast;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];

	int curr = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1]) {
			if (curr == -1) q[i - 1] = -1;
			curr = 1;
		}
		else if (a[i] < a[i - 1]) {
			if (curr == 1) q[i - 1] = 1;
			curr = -1;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> l >> r, --l, --r;
//		if (i == 19007 && n == 100000 && m == 100000 && a[0] == 5 && a[1] == 3) {
//			for (int j = l; j <= r; j++) cout << a[j] << ",";
//		}
		auto it1 = q.upper_bound(l), it2 = q.lower_bound(r);
		if (it1 == q.end() || it2 == q.begin()) cout << "Yes" << endl;
		else {
			it2--;
			if (a[it1->first] == a[l]) it1++;
			if (it1->first > it2->first) cout << "Yes" << endl;
			else if (it1->first < it2->first) cout << "No" << endl;
			else {
				if (it1->second == 1) cout << "Yes" << endl;
				else cout << "No" << endl;
			}
		}
	}
}