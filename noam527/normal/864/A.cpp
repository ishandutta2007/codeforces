#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 149;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, x, y;
map<int, int> m;

int main() {
	fast;
	cin >> n;
	y = n;
	while (y--) {
		cin >> x;
		m[x]++;
	}
	if (m.size() == 2) {
		if (m.begin()->second != n / 2) return cout << "NO" << endl, 0;
		cout << "YES" << endl;
		int v1, v2;
		auto it = m.begin();
		v1 = it->first, it++, v2 = it->first;
		cout << v1 << " " << v2 << endl;
	}
	else cout << "NO" << endl;
}