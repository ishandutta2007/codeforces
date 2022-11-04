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
    int i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;
    cin >> str;
    int n = (int)str.size();
    vector<string> pref(n + 1), suff(n + 1);
    vector<int> len(n + 1);
    for(i = n - 1; i >= 0; i--) {
    	pref[i] = str[i] + pref[i + 1];
    	suff[i] = suff[i + 1];
    	len[i] = len[i + 1] + 1;

    	if((int)pref[i].size() == 11) {
    		if(suff[i].empty()) {
    			suff[i].push_back(pref[i][9]);
    			suff[i].push_back(pref[i][10]);
    		}
    		pref[i].pop_back();
    	}

    	if(i + 1 < n && str[i] == str[i + 1]) {
    		if(pref[i] > pref[i + 2]) {
    			pref[i] = pref[i + 2];
    			suff[i] = suff[i + 2];
    			len[i] = len[i + 2];
    		}
    	}
    }

    for(i = 0; i < n; i++) {
    	cout << len[i] << " ";
    	if(suff[i].size()) {
    		pref[i].resize(5);
    		cout << pref[i];
    		cout << "..." << suff[i] << "\n";
    	}
    	else {
    		cout << pref[i] << "\n";
    	}
    }
 	
    return 0;
}