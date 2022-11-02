#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e18 + 7;


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
    	vector<string> s(n);
    	for(int i = 0;i < n;i++) cin >> s[i];
    	bool bad = false;
    	for(int i = n - 2;i >= 0;i--) {
    		for(int j = n - 2;j >= 0;j--) {
    			if (s[i][j] == '1') {
    				if (s[i + 1][j] != '1' && s[i][j + 1] != '1') bad = true;
    			}
    		}
    	}
    	if (bad) cout << "NO";
    	else cout << "YES";
    	cout << endl;
    }
}