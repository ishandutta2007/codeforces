#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
 
using namespace std;
const int inf = 1e15 + 7;


signed main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int t;
    cin >> t;
    while(t--) {
    	int n, m;
    	cin >> n >> m;
    	if (n % m == 0) cout << "YES";
    	else cout << "NO";
    	cout << '\n';
    }
}