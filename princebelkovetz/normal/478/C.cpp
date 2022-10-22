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
	int r, g, b; cin >> r >> g >> b;
	vector <int> a;
	a.push_back(r);
	a.push_back(g);
	a.push_back(b);
	sort(a.rbegin(), a.rend());
	a[0] = min(a[0], 2 *(a[1] + a[2]));
	cout << (a[0] + a[1] + a[2]) / 3;
}