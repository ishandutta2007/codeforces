#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const int OO = 1;
using namespace std;

string s;

void solve() {
	cin >> s;
	int x = *min_element(s.begin(), s.end()) - '0';
	if (s.size() == 2) {
		cout << s[1] << '\n';
		return;
	}
	cout << x << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}