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

double dist(int x, int y) {
	return sqrt(x * x + y * y);
}

int main() {
	fast;
	int r, d, n, x, y, z, ans = 0;
	cin >> r >> d >> n;
	r -= d;
	while (n--) {
		cin >> x >> y >> z;
		double dis, close, far;
		dis = dist(x, y);
		close = dis - z, far = dis + z;
		if (close >= r && far <= r + d) ans++;
	}
	cout << ans << endl;
}