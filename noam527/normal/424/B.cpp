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

struct point {
	int x, y, k;
	point() {};
	bool operator < (point &a) {
		return (x * x + y * y) < (a.x * a.x + a.y * a.y);
	}
};

int n, s;
vector<point> a;

int main() {
	fast;
	cin >> n >> s;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y >> a[i].k;
	sort(a.begin(), a.end());
	int p = 0;
	while (p < n && s < 1e6) {
		s += a[p++].k;
	}
	if (s < 1e6) return cout << -1 << endl, 0;
	p--;
	cout.precision(12);
	cout << sqrt(a[p].x * a[p].x + a[p].y * a[p].y) << endl;
}