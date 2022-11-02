#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;
 
 
 
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	// 2 * n + m - 3 > n * m
	cout << n * m + n + m - 2 << '\n';
	for(int i = 0;i < n - 1;i++) cout << "D";
	for(int i = 0;i < m - 1;i++) cout << "L";
	
	for(int i = 0; i < n;i++) {
		if (i % 2 == 0) {
			for(int j = 0;j < m - 1;j++) cout << "R";
			cout << "U";
		}else {
			for(int j = 0;j < m - 1;j++) cout << "L";
			cout << "U";
		}
	} 
 
}