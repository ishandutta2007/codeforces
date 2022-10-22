#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
//pragma GCC optimize("Ofast")
//pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native" )
#define endl "\n";
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

void solve(){
	int n, pr = 1, curi = 0; cin >> n;
	vector <int> cur(10, 1);
	while (pr < n) {
		pr *= (cur[curi] + 1);
		pr /= cur[curi];
		cur[curi]++;
		curi++; curi %= 10;
	}
	for (int i = 0; i < cur[0]; ++i) cout << 'c';
	for (int i = 0; i < cur[1]; ++i) cout << 'o';
	for (int i = 0; i < cur[2]; ++i) cout << 'd';
	for (int i = 0; i < cur[3]; ++i) cout << 'e';
	for (int i = 0; i < cur[4]; ++i) cout << 'f';
	for (int i = 0; i < cur[5]; ++i) cout << 'o';
	for (int i = 0; i < cur[6]; ++i) cout << 'r';
	for (int i = 0; i < cur[7]; ++i) cout << 'c';
	for (int i = 0; i < cur[8]; ++i) cout << 'e';
	for (int i = 0; i < cur[9]; ++i) cout << 's';

	
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}