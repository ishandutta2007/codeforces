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
    	string s;
    	cin >> s;
    	vector<int> cnt(2);
    	for(char i : s) {
    		cnt[i - '0']++;
    	}

    	vector<int> cnt1(2);

    	int res = inf;

    	for(int i = 0;i <= s.size();i++) {
    		res = min(res, min(cnt[1] + cnt1[0], cnt[0] + cnt1[1]));

    		if (i != s.size()) {
    			cnt[s[i] - '0']--;
    			cnt1[s[i] - '0']++;
    		}
    	}

    	cout << res << endl;
    }
}