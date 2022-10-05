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

int a, b, c;

void solve() {
	cin >> a >> b >> c;
	cout << a + 1000000000 * (ll)b << " " << b << " " << c << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}