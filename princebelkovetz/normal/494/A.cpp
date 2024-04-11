#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int inf = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(2);
	string s; cin >> s;
	int couLeft = 0, couRight = 0, lastSharp = 0;
	vector <int> ans;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') couLeft++;
		else if (s[i] == ')') couRight++;
		else lastSharp = i;
	}
	int ok = couLeft - couRight;
	if (ok <= 0) {
		cout << -1; return 0;
	}
	couRight = 0; couLeft = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') couLeft++;
		else if (s[i] == ')') couRight++;
		else {
			if (i != lastSharp) {
				if (ok and couLeft > couRight) {
					--ok;
					ans.push_back(1);
					++couRight;
				}
				else {
					cout << -1;
					return 0;
				}
			}
			else {
				if (couLeft + ok >= couRight) {
					ans.push_back(ok);
					couRight += ok;
				}
				else {
					cout << -1; return 0;
				}
			}
		}
		if (couRight > couLeft) {
			cout << -1;
			return 0;
		}
	}
	for (auto x: ans) cout << x << endl;

}