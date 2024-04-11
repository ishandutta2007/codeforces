#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e15 + 7;



int sgn(int a) {
	if (a > 0) return 1;
	return -1;
}



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

   		int res = 0;
   		int type = sgn(a[0]);
   		int m = -inf;

   		for(int i = 0;i <= n;i++) {
   			if (i == n || sgn(a[i]) != type) {
   				res += m;
   				if (i != n) type = sgn(a[i]);
   				m = a[i];
   			}else{
   				m = max(m, a[i]);
   			}
   		}

   		cout << res << '\n';
   	}


}