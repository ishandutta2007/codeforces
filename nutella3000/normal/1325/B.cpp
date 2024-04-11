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

    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	int a[n];
    	for(int i = 0;i < n;i++) cin >> a[i];
    	int res = 0;
    	int last = -1;
    	sort(a, a + n);
    	for(int i = 0;i < n;i++) {
    		if (last != a[i]) {
    			last = a[i];
    			res++;
    		}
    	}

    	cout << res << '\n';
    }
}