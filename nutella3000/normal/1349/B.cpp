#include <bits/stdc++.h>
using namespace std;
  
//#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e9 + 7;
 
 
vector<int> pre_min(vector<int> a) {
	vector<int> res(sz(a));
	res[0] = a[0];
	for(int i = 1;i < sz(a);i++) res[i] = min(res[i - 1], a[i]);
	return res;
}
 
vector<int> suf_max(vector<int> a) {
	vector<int> res(sz(a));
	res[sz(a) - 1] = a[sz(a) - 1];
	for(int i = sz(a) - 2;i >= 0;i--) res[i] = max(res[i + 1], a[i]); 
	return res;
}
 
 
 
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
 
    	vector<int> a(n), pref1(n + 2), pref2(n + 2), min1, min2, max1, max2;
    	for(int i = 0;i < n;i++) cin >> a[i];
    	for(int i = 0;i < n;i++) {
    		if (a[i] < k) a[i] = -1;
    		else if (a[i] == k) a[i] = 0;
    		else a[i] = 1;
 
    		//pref1[i + 1] = a[i] + pref1[i];
 
    		if (a[i] >= 0) pref2[i + 1] = pref2[i] + 1;
    		else pref2[i + 1] = pref2[i] - 1;
    	}
 
    	//pref1[n + 1] = -inf;
    	pref2[n + 1] = -inf;
 
		
 
    	//min1 = pre_min(pref1);
    	min2 = pre_min(pref2);
    	//max1 = suf_max(pref1);
    	max2 = suf_max(pref2);
 
    	bool good = false;
 	
 		for(int i = 0;i < n;i++) if (a[i] == 0) good = true;
 		if (good) {
 			good = false;
 			for(int i = 1;i < n;i++) {
 				if (a[i] >= 0 && a[i - 1] >= 0) good = true;
 				if (i > 1 && a[i] >= 0 && a[i - 2] >= 0) good = true;
 			}
 		}

    	/*for(int i = 1;i <= n;i++) {
    		if (a[i - 1] != 0) continue;
    		if (max2[i + 1] - min2[i - 1] >= 1) good = true;
    		if (i >= 2 && pref2[i] - min2[i - 2] >= 1) good = true;
    	}*/
 
    	if (n == 1 && a[0] == 0) good = true;
    		
    	if (good) cout << "yes" << endl;
    	else cout << "no" << endl;

    }
}