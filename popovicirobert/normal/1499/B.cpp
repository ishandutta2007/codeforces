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
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);	
		
	int q;
    cin >> q;

    while (q--) {
    	string str;
    	cin >> str;

    	int n = (int)str.size();
    	str = " " + str;

    	vector<bool> pref(n + 1);
    	pref[0] = pref[1] = true;

    	for (int i = 2; i <= n; i++) {
    		if (str[i] == '1') {
    			if (str[i - 1] == '1') {
    				pref[i] = false;
    			} else if (i > 1) {
    				pref[i] = pref[i - 2];
    			}
    		} else {
    			pref[i] = pref[i - 1];
    		}
    	}

    	vector<bool> suff(n + 2);
    	suff[n + 1] = suff[n] = true;

    	for (int i = n - 1; i >= 1; i--) {
    		if (str[i] == '0') {
    			if (str[i + 1] == '0') {
    				suff[i] = false;
    			} else if (i < n) {
    				suff[i] = suff[i + 2];
    			}
    		} else {
    			suff[i] = suff[i + 1];
    		}
    	}

    	bool answer = false;
    	for (int i = 0; i <= n; i++) {
    		bool cur = (pref[i] & suff[i + 1]);
    		if (str[i] == '1' && str[i + 1] == '0') {
    			cur = false;
    		}
    		if (q == 1) {
    			cerr << i << " " << pref[i] << " " << suff[i] << "\n";
    		}
    		answer |= cur;
    	}
    	cout << (answer ? "YES\n" : "NO\n");
    }

    return 0;
}