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
		int a, b; cin >> a >> b;
		int cs, cw; cin >> cs >> cw;
		int s, w; cin >> s >> w;
		if (s > w) {
			swap(s, w);
			swap(cs, cw);
		}
		int ans = 0;
		for (int i = 0; i <= cs; ++i) {
			if (i * s > a) break;
			int cura = a, curb = b, res = 0, ccw = cw, ccs = cs;
			cura -= s * i;
			res = i + min(cura / w, ccw);
			ccw -= min(cura / w, ccw);
			res += min(ccs - i, curb / s);
			curb -= min(ccs - i, curb / s) * s;
			res += min(ccw, curb / w);
			ans = max(ans, res);
		}
		cout << ans << '\n';
	}
}