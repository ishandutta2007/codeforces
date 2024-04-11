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
    	string s;
    	cin >> n >> s;
    	vector<int> a(n), b(n);
    	bool higher = false;
    	for(int i = 0;i < n;i++) {
    		if (!higher) {
    			b[i] = (s[i] - '0') / 2;
    			a[i] = s[i] - '0' - b[i];
    		}else {
    			b[i] = s[i] - '0';
    		}
    		if (a[i] > b[i]) higher = true;
    	}

    	for(int i : a) cout << i;
    	cout << '\n';
    	for(int i : b) cout << i;
    	cout << '\n';
    }

}