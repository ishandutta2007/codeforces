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
   		int n, m;
   		cin >> n >> m;
   		vector<bool> a(n), b(m);

   		for(int i = 0;i < n;i++) {
   			for(int j = 0;j < m;j++) {
   				bool v;
   				cin >> v;
   				a[i] = (a[i] | v);
   				b[j] = (b[j] | v);
   			}
   		}

   		int res1 = 0, res2 = 0;
   		for(bool i : a) if (!i) res1++;
   		for(bool i : b) if (!i) res2++;
   		//cout << res1 << " " << res2 << endl;
   		int res = min(res1, res2);

   		if (res % 2 == 0) cout << "Vivek";
   		else cout << "Ashish";
   		cout << endl;
   	}
}