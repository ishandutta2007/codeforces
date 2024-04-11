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
    	vector<char> res(n, 'a');

    	int type = 1;
    	for(int i = 0;i < n;i++) {
    		int w;
    		if (type == 2) w = (n - i - 1);
    		else w = (n - i - 1) * (n - i - 2) / 2;
    		if (w < k) {
    			k -= w;
    			res[i] = 'b';
    			type++;
    			if (type == 3) break;
    		}
    	}

    	for(char i : res) cout << i;
    	cout << '\n';
    }

}