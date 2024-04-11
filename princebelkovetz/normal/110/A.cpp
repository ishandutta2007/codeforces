#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
using namespace std;
void solve() {
	string n; int cnt = 0; bool c = true;
	cin >> n;
	for (auto x : n) {
		if (x == '4' or x == '7') ++cnt;
	}
	if (!cnt) {
		cout << "NO"; return;
	}
	while (c and cnt) {
		if (cnt % 10 != 4 and cnt % 10 != 7) c = false;
		else cnt /= 10;
	}
	if (c) cout << "YES"; else cout << "NO";

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t; t = 1;
	while (t--) {
		solve();
	}
}