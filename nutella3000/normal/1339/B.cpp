#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e15 + 7;


// f[n] = f[n - 3] + f[n - 1]
 
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

   		sort(a.begin(), a.end());

   		int id1 = n / 2 - 1;
   		int id2 = n / 2;

   		while(id2 < n) {
   			cout << a[id2] << " ";
   			id2++;

   			if (id1 >= 0) {
   				cout << a[id1] << " ";
   				id1--;
   			}
   		}

   		cout << '\n';

   	}
 
}