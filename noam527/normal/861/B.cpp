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
const int md = 1e9 + 7;
const long long hs = 137;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, m;
vector<int> a, b;
set<int> p;

int main() {
	fast;
	cin >> n >> m;
	a.resize(105, -1), b.resize(105);
	for (int i = 0, u, v; i < m; i++)
		cin >> u >> v, a[u] = v;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++)
			b[j] = (j + i - 1) / i;
		bool good = true;
		for (int j = 1; j <= 100; j++)
			if (a[j] != -1 && a[j] != b[j]) good = false;
		if (good) p.insert(b[n]);
	}
	if (p.size() == 1) cout << *p.begin() << endl;
	else cout << -1 << endl;
}