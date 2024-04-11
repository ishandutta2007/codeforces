#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define int long long
#define endl "\n";
using namespace std;
void solve(){
	int n, curi = 0, curj = 0; string s;
	pair <int, int> ans = { 0, 999999999 };
	map <pair <int, int>, int> save;
	save[{curi, curj}] = 0;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		char x = s[i];
		if (x == 'L') curi--;
		else if (x == 'R') curi++;
		else if (x == 'D') curj--;
		else if (x == 'U') curj++;
		if (save.find({ curi, curj }) != save.end() and i - save[{curi, curj}] < ans.second - ans.first) {
				ans = { save[{curi, curj}] + 1, i + 1};
		}
		save[{curi, curj}] = i + 1;
		//cout << curi << " " << curj << endl;
	}
	if (ans.first) {
		cout << ans.first << " " << ans.second << endl;
	}
	else { cout << "-1\n"; }
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}