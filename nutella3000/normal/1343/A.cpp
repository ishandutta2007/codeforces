#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e15 + 7;




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
   		int k = 3;
   		int n;
   		cin >> n;
   		
   		int x = -1;
   		while(x == -1) {
   			if (n % k == 0) {
   				x = n / k;
   				break;
   			}
   			k = 2 * k + 1;
   			if (k > 1e15) break;
   		}	

   		cout << x << '\n';
   	}

}