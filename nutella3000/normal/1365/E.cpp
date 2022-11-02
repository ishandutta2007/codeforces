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


    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0;i < n;i++) cin >> a[i];

    int res = 0;
    for(int i = 0;i < n;i++) {
    	for(int j = i;j < n;j++) {
    		for(int k = j;k < n;k++) {
    			res = max(res, a[i] | a[j] | a[k]);
    		}
    	}
    }
    cout << res;
}