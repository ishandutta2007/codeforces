#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define ull unsigned long long
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt--) {
		int a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;
		int newa = max(a - n, x);
		int left = n - (a - newa);
		int newb = max(y, b - left);
		swap(a, b); swap(x, y);
		int newa2 = max(a - n, x);
		int left2 = n - (a - newa2);
		int newb2 = max(y, b - left2);
		cout << min(newa * newb, newa2 * newb2) << '\n';
	}
	
}