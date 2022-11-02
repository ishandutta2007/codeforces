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


	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		if (n % 2 != k % 2) {
			cout << "NO" << '\n';
			continue;
		}

		int Min = k + (k - 1) * k;
		if (Min <= n) cout << "YES" << '\n';
		else cout <<"NO" << '\n';
	}    
}