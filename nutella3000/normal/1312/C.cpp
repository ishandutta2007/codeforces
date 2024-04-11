#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
 
using namespace std;
const int inf = 1e15 + 7;

int pow(int a, int b) {
	int ans = 1;
	for(int i = 0;i < b;i++) ans *= a;
		return ans;
}


signed main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int t;
    cin >> t;
    while(t--) {
    	int n, k;
    	cin >> n >> k;
    	int a[n];
    	for(int i = 0;i < n;i++) cin >> a[i];
    	bool bad = false;
    	for(int bit = 0;bit < 100;bit++) {
    		int num = pow(k, bit);
    		if (num > 1e16) break;
    		int cnt = 0;
    		for(int i = 0;i < n;i++) cnt += (a[i] % (num * k)) / num;

  			if (cnt >= 2) bad = true;
    	}

    	if (bad) cout << "NO";
    	else cout << "YES";
    	cout << '\n';
    }
}