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
typedef long long ll;
typedef long double ldb;
using namespace std;

int a[6];
ll dist(int x1, int y1, int x2, int y2) {
	return (ll)(x1 - x2) * (x1 - x2) + (ll)(y1 - y2) * (y1 - y2);
}
int main() {
	fast;
	for (int i = 0; i < 6; i++) cin >> a[i];
	if (dist(a[0], a[1], a[2], a[3]) == dist(a[2], a[3], a[4], a[5])) {
		if (a[4] - a[2] == a[2] - a[0] && a[5] - a[3] == a[3] - a[1]) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	else cout << "No" << endl;
}