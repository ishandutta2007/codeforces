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
   		int n, k;
   		cin >> n >> k;
   		vector<int> a(n);
   		for(int i = 0;i < n;i++) cin >> a[i];

   		set<int> b;
   		for(int i = 0;i < n;i++) b.emplace(a[i]);

   		if (b.size() > k) {
   			cout << -1 << '\n';
   		}else{

   			for(int i : b) a.emplace(a.begin(), i);

   			for(int i = k;i < a.size();i++) {
   				if (a[i] != a[i - k]) {
   					a.emplace(a.begin() + i, a[i - k]);	
   				}
   			}

   			cout << a.size() << '\n';
   			for(int i : a) cout << i << " ";
   			cout << '\n';
   		}	
   	}

}