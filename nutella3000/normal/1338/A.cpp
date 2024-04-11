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
   		for(int i = 0;i < n;i++) cin >> a[i];

   		int res = 0;
   		bool good = false;
   		while(!good) {
   			bool bad = false;
   			int m = (1ll << res) - 1;
   			int last = -inf;
   			for(int i = 0;i < n;i++) {
   				if (a[i] < last) {
   					if (a[i] + m < last) bad = true;
   				}
   				last = max(last, a[i]);
   				//cout << "last" << " " << last << '\n';
   			}

   			//cout << res << " " << bad << '\n';
   			if (!bad) good = true;
   			res++;
   		}
   		res--;

   		cout << res << '\n';
   	}


}