#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e18 + 7;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}


signed main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
  	#endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int test;
    cin >> test;
    while(test--) {
    	int n, k;
    	string temp;
    	cin >> n >> k >> temp;
    	vector<int> cnt(26);
    	for(char i : temp) cnt[i - 'a']++;

    	for(int res = n;res >= 1;res--) {
    		int q = gcd(res, k);

    		int cn = 0;
    		for(int i : cnt) {
    			cn += i / (res / q);
    		}
    		
    		if (cn >= q) {
    			cout << res << endl;
    			break;
    		} 
    	}
    }
}