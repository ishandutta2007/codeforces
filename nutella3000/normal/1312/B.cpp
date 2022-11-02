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
    	int n;
    	cin >> n;
    	int a[n];
    	for(int i = 0;i < n;i++) cin >> a[i];
    	sort(a, a + n);
    	for(int i = n - 1;i >= 0;i--) cout << a[i] << " ";
    		cout << '\n';
    }
}