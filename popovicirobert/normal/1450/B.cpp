#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, t;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
    	int n, k;
    	cin >> n >> k;
    	vector<pair<int, int>> p(n);
    	for(i = 0; i < n; i++) {
    		cin >> p[i].first >> p[i].second;
    	}
    	int ans = -1;
    	for(i = 0; i < n; i++) {
    		bool ok = true;
    		for(j = 0; j < n; j++) {
    			int cur = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
    			if(cur > k) {
    				ok = false;
    			}
    		}
    		if(ok == true) {
    			ans = 1;
    		}
    	}
    	cout << ans << "\n";
    }
   	
	
    return 0;
}