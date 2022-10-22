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
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int n; cin >> n;
	vector <int> a(n), b(n);
	for (auto& x : a) cin >> x;
	sort(a.begin(), a.end());
	
	int j = 0;
	for (int i = 1; i < n; i += 2, j++) {
		b[i] = a[j];
	}
	for (int i = 0; i < n; i += 2, j++)
		b[i] = a[j];
	int cnt = 0;
	for (int i = 1; i < n - 1; ++i)
		cnt += (b[i] < b[i - 1] && b[i] < b[i + 1]);
	cout << cnt << '\n';
	for (auto x : b) cout << x << ' ';

	return 0;
}