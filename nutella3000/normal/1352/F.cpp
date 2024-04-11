#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e11 + 7;



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
    	int n1, n2, n3;
    	cin >> n1 >> n2 >> n3;
    	if (n2 == 0) {
    		if (n1 == 0) for(int i = 0;i <= n3;i++) cout << 1;
    		else for(int i = 0;i <= n1;i++) cout << 0;
    	}else{
    		if (n2 % 2 == 0) {
    			cout << 0;
    			n2--;
    		}
    		cout << 1;
    		for(int i = 0;i < n3;i++) cout << 1;
    		for(int i = 0;i < n2 / 2;i++) cout << "01";
    		cout << 0;
    		for(int i = 0;i < n1;i++) cout << 0;
    	}
    	cout << endl;
    }
}