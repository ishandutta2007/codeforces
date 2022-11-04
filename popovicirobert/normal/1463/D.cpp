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
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
    	int n, i;
    	cin >> n;
    	
    	vector<int> b(n + 1);
    	vector<bool> vis(2 * n + 1);
    	for(i = 1; i <= n; i++) {
    		cin >> b[i];
    		vis[b[i]] = true;
    	}
    	set<int> values;
    	for(i = 1; i <= 2 * n; i++) {
    		if(vis[i] == false) {
    			values.insert(i);
    		}
    	}

    	vector<bool> pref(n + 1), suff(n + 2);

    	pref[0] = true;
    	for(i = 1; i <= n; i++) {
    		auto itr = values.upper_bound(b[i]);
    		if(itr == values.end()) {
    			break;
    		}
    		values.erase(itr);
    		pref[i] = true;
    	}

    	for(i = 1; i <= 2 * n; i++) {
    		if(vis[i] == false) {
    			values.insert(i);
    		}
    	}

    	suff[n + 1] = true;
    	for(i = n; i >= 1; i--) {
    		auto itr = values.upper_bound(b[i]);
    		if(itr == values.begin()) {
    			break;
    		}
    		itr--;
    		values.erase(itr);
    		suff[i] = true;
    	}

    	int ans = 0;
    	for(i = 0; i <= n; i++) {
    		if(pref[i] && suff[i + 1]) {
    			ans++;
    		}
    	}
    	cout << ans << "\n";
    }

    return 0;
}