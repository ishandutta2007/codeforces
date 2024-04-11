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

ldb a, b, m, x, y, z, t, cx, cz;

int main() {
	fast;
	cin >> a >> b >> m >> x >> y >> z;
	cx = a / 2, cz = 0;
	t = m / -y;

	cx += t * x, cz += t * z;
	while (cx >= 2 * a) cx -= 2 * a;
	while (cx <= -a) cx += 2 * a;
	if (cx > a) cx = 2 * a - cx;
	if (cx < 0) cx = abs(cx);

	while (cz >= 2 * b) cz -= 2 * b;
	if (cz > b) cz = 2 * b - cz;

	cout.precision(12);
	cout << cx << " " << cz << endl;
}