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
   		int n;
   		cin >> n;
   		vector<int> a(n);
   		int sum = 0;
   		for(int i = 0;i < n / 2;i++) {
   			a[i] = 2 * (i + 1);
   			sum += a[i];
   		}

   		int q = 1;
   		for(int i = n / 2;i < n;i++) {
   			a[i] = q;
   			sum -= q;
   			q += 2;
   		}

   		if (sum % 2 == 1) cout << "NO" << '\n';
   		else {
   			cout << "YES" << '\n';
   			a[n - 1] += sum;
   			for(int i : a) cout << i << " ";
   			cout << '\n';
   		}
   	}

}