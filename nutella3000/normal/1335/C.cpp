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
   		map<int, int> a;
   		int r2 = 0;
   		for(int i = 0;i < n;i++) {
   			int v;
   			cin >> v;
   			a[v]++;
   			r2 = max(r2, a[v]);
   		}

   		int r1 = a.size();

   		cout << max(min(r1 - 1, r2), min(r1, r2 - 1)) << '\n';
   	}
}