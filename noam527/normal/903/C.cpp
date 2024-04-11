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

int n;
vector<int> a;
map<int, int> m;

int main() {
	fast;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	m[0] = 1;
	sort(a.begin(), a.end());
	for (auto &i : a) {
		auto it = m.lower_bound(i);
		if (it == m.begin()) {
			it->second++;
		}
		else {
			it--;
			it->second--, m[i]++;
			if (it->second == 0) m.erase(it);
		}
	}
	int sum = 0;
	for (auto &i : m) sum += i.second;
	cout << sum << endl;
}