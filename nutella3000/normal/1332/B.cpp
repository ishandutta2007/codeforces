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
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	for(int i = 0;i < n;i++) cin >> a[i];
    	vector<int> col(n);
    	int v_col = 1;
    	for(int del = 2;del <= 1000;del++) {
    		bool good = false;
    		for(int i = 0;i < n;i++) {
    			if (col[i]) continue;
    			if (a[i] % del == 0) {
    				col[i] = v_col;
    				good = true;
    			}
    		}
    		if (good) v_col++;
    	}

    	cout << v_col - 1 << '\n';
    	for(int i = 0;i < n;i++) cout << col[i] << " ";
    	cout << '\n';
	}
}