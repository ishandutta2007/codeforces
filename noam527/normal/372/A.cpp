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
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, p1, p2, c = 0;
vector<int> a, vis;

int main() {
	fast;
	cin >> n;
	a.resize(n), vis.resize(n, 0);
	for (int i = 0; i < n; i++) cin >> a[i];
	p1 = (n - 1) / 2, p2 = n - 1;
	sort(a.begin(), a.end());

	while (p1 >= 0) {
		if (vis[p1]) p1--;
		else if (vis[p2]) p2--;
		else if (2 * a[p1] > a[p2]) p1--;
		else c++, vis[p1] = vis[p2] = 1, p2--;
	}

	cout << n - c << endl;
}