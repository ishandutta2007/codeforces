#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
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
    	int cnt = 0;
    	int Min = 0;
    	for(int i = 0;i < n;i++) {
    		if (s[i] == '(') cnt++;
    		else cnt--;
    		Min = min(Min, cnt);
    	}

    	cout << -Min << endl;
    }
}