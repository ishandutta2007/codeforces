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


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	string s; cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0') {
			cout << s.substr(0, i) << s.substr(i + 1, s.size() - i - 1);
			return 0;
		}
	}
	cout << s.substr(0, s.size() - 1);
	return 0;
}