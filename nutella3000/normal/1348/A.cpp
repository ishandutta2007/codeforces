#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e13 + 7;




signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);

   	int q;
   	cin >> q;
   	while(q--) {

   		int n;
   		cin >> n;
   		int res = (1 << n);
   		for(int i = 1;i < n / 2;i++) res += (1 << i);
   		for(int i = n / 2;i < n;i++) res -= (1 << i);
   		cout << res << '\n';

	}
}