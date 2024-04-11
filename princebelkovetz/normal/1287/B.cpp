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
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(3);
	int n, k, ans = 0; cin >> n >> k;
	set <string> card;
	vector <string> ok;
	for (int i = 0; i < n; ++i) {
		string x; cin >> x;
		card.insert(x);
		ok.push_back(x);
	}
	for (int i = 0; i < n - 1; ++i) {
		string cur1 = ok[i];
		for (int j = i + 1; j < n; ++j) {
			string cur2 = ok[j], cur3 = "";
			for (int i = 0; i < k; ++i) {
				if (cur1[i] == cur2[i]) cur3 += cur1[i];
				else {
					if (cur1[i] == 'E') {
						if (cur2[i] == 'S') cur3 += 'T';
						if (cur2[i] == 'T') cur3 += 'S';
					}
					if (cur1[i] == 'T') {
						if (cur2[i] == 'S') cur3 += 'E';
						if (cur2[i] == 'E') cur3 += 'S';
					}
					if (cur1[i] == 'S') {
						if (cur2[i] == 'E') cur3 += 'T';
						if (cur2[i] == 'T') cur3 += 'E';
					}
				}
			}
			if (card.find(cur3) != card.end()) ++ans;
		}
	}
	cout << ans / 3 << endl;
}