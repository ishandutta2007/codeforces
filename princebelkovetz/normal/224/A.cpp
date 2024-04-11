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
	int a, b, c, temp, cnt = 0;
	cin >> a >> b >> c;
	cout <<  4 * (int)((int)sqrt(a * b / c) + (int)sqrt(b * c / a) + (int)sqrt(c * a / b));

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