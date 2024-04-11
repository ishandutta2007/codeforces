#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e9 + 7;

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
    	int n, k;
    	cin >> n >> k;
    	vector<int> a(n);
    	for(int i = 0;i < n;i++) cin >> a[i];
    	int res1 = 0;
    	int res2 = 0;
    	int now = 0;
    	for(int i = 1;i < k - 1;i++) if (a[i] > a[i - 1] && a[i] > a[i + 1]) now++;
    	res2 = now;

   		for(int i = k;i < n;i++) {
   			if (a[i - 1] > a[i - 2] && a[i - 1] > a[i]) now++;	
   			if (a[i - k + 1] > a[i - k] && a[i - k + 1] > a[i - k + 2]) now--;
   			if (now > res2) {
   				res1 = i - k + 1;
   				res2 = now;
   			}
   		}

   		cout << res2 + 1 << " " << res1 + 1 << endl;

    }
}