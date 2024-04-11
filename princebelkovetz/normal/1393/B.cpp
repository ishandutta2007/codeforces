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
	int cnt2 = 0, cnt4 = 0, cnt6 = 0, cnt8 = 0;
	int n; cin >> n;
	map <int, int> ok;
	while (n--) {
		int x; cin >> x;
		ok[x]++;
		if (ok[x] == 2) cnt2++;
		if (ok[x] == 4) {
			cnt2--;
			cnt4++;
		}
		if (ok[x] == 6) {
			cnt4--;
			cnt6++;
		}
		if (ok[x] == 8) {
			cnt6--;
			cnt8++;
		}
	}
	int m; cin >> m;
	while (m--) {
		string s; cin >> s;
		int x; cin >> x;
		if (s == "+") {
			ok[x]++;
			if (ok[x] == 2) cnt2++;
			if (ok[x] == 4) {
				cnt2--;
				cnt4++;
			}
			if (ok[x] == 6) {
				cnt4--;
				cnt6++;
			}
			if (ok[x] == 8) {
				cnt6--;
				cnt8++;
			}
		}
		if (s == "-") {
			ok[x]--;
			if (ok[x] == 1) cnt2--;
			if (ok[x] == 3) {
				cnt2++;
				cnt4--;
			}
			if (ok[x] == 5) {
				cnt4++;
				cnt6--;
			}
			if (ok[x] == 7) {
				cnt6++;
				cnt8--;
			}
		}
		if (cnt8 >= 1) cout << "YES";
		else if (cnt6 >= 1 and cnt2 >= 1) cout << "YES";
		else if (cnt6 >= 1 and cnt4 >= 1) cout << "YES";
		else if (cnt6 >= 2) cout << "YES";
		else if (cnt4 >= 1 and cnt2 >= 2) cout << "YES";
		else if (cnt4 >= 2) cout << "YES";
		else cout << "NO";
		cout << "\n";
		
	}
}