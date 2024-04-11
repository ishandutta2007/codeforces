#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e9 + 7;
const int max_n = 2e5 + 7;


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
   		set<int> a;
   		int v;
   		int last = -1;
   		bool good = true;
   		for(int i = 0;i < n;i++) {
   			cin >> v;
   			if (last > v) good = false;
   			last = v;
   		}
   		for(int i = 0;i < n;i++) {
   			cin >> v;
   			a.emplace(v);
   		}

   		if (a.size() > 1 || good) cout << "Yes" << endl;
   		else cout << "No" << endl;
   	}
}