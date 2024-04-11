#include <bits/stdc++.h>
using namespace std;
  
//#define int long long
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
    	vector<int> cnt(26);
    	cin >> n >> k;
    	for(int i = 0;i < n;i++) {
    		char v;
    		cin >> v;
    		cnt[v - 'a']++;
    	}

    	int first = 0;
    	for(int i = 25;i >= 0;i--) if (cnt[i] != 0) first = i;

    	if (cnt[first] < k) {
    		int num = 0;
    		for(int i = 0;i < 26;i++) {
    			if (num + cnt[i] >= k) {
    				cout << (char) ('a' + i) << endl;
    				break;
    			}
    			num += cnt[i];
    		}
    	}else{
    		cnt[first] -= k;
    		string res = "";
    		res += (char) ('a' + first);
    		int num = 0;
    		for(int i = 0;i < 26;i++) num += cnt[i] > 0;

    		if (num >= 2) {
    			for(int i = 0;i < 26;i++) while(cnt[i]--) res += (char) ('a' + i); 
    		}else{
    			for(int i = 0;i < 26;i++) {
    				if (cnt[i] != 0) {
    					while(cnt[i] > 0) {
    						cnt[i] -= k;
    						res += (char) ('a' + i);
    					}
    				}
    			}
    		}

    		cout << res << endl;
    	}
    }
}