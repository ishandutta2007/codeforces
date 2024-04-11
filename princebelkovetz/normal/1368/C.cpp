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
	int n; cin >> n;
	cout << 4 + n * 3 << endl;
	cout << "1 1\n1 2\n2 1\n";
	for (int i = 2; i <= n + 1; ++i) {
		cout << i << " " << i << endl;
		cout << i + 1 << " " << i << endl;
		cout << i << " " << i + 1 << endl;
	}
	cout << n + 2 << " " << n + 2;
	


	
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