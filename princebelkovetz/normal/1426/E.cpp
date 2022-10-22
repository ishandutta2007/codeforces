#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int n;
	cin >> n;
	vector <int> a(3), b(3);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	int ansmax = 0, ansmin = 0;
	for (int i = 0; i < 3; ++i) {
		ansmax += min(a[i], b[(i + 1) % 3]);
	}
	for (int i = 0; i < 3; ++i) {
		ansmin = max(ansmin, a[i] - b[i] - b[(i + 2) % 3]);
	}
	cout << ansmin << ' ' << ansmax << '\n';  
	return 0;
}