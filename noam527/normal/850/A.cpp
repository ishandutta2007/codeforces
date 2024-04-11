#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

struct point {
	int v[5];
	point() {};
	bool isgood(point x, point y) {
		for (int i = 0; i < 5; i++)
			x.v[i] -= v[i], y.v[i] -= v[i];
		int val = 0;
		for (int i = 0; i < 5; i++) val += x.v[i] * y.v[i];
		return val <= 0;
	}
};

int main() {
	fast;
	int n;
	cin >> n;
	vector<point> a(n);
	vector<int> ans;
	for (int i = 0; i < n; i++) for (int j = 0; j < 5; j++) cin >> a[i].v[j];
	if (n > 20) return cout << 0 << endl, 0;
	for (int i = 0; i < n; i++) {
		bool isgood = true;
		for (int j = 0; j < n && isgood; j++)
			for (int k = 0; k < n && isgood; k++)
				if (i != j && i != k && j != k)
					isgood = isgood && a[i].isgood(a[j], a[k]);
		if (isgood) ans.push_back(i + 1);
	}
	cout << ans.size() << endl;
	for (auto i : ans) cout << i << endl;
}