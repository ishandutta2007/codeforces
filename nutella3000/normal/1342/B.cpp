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
    	string s;
    	cin >> s;
    	vector<bool> num(2);
    	for(int i = 0;i < sz(s);i++) num[s[i] - '0'] = true;
    	if (num[0] && num[1]) {
    		for(int i = 0;i < sz(s);i++) cout << "01";
    		cout << endl;
    	}else{
    		for(int i = 0;i < sz(s);i++) cout << s[0];
    		cout << endl;
    	}
    }
}