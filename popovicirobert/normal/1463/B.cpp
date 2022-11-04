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
    	vector<int> arr(n);
    	ll s1 = 0, s2 = 0;
    	for(i = 0; i < n; i++) {
    		cin >> arr[i];
    		if(i & 1) {
    			s1 += arr[i];
    		}
    		else {
    			s2 += arr[i];
    		}
    	}
    	for(i = 0; i < n; i++) {
    		int cur = arr[i];
    		if(s1 < s2) {
    			if(i & 1) {
    				cur = 1;
    			}
    		}
    		else {
    			if(i % 2 == 0) {
    				cur = 1;
    			}
    		}
    		cout << cur << " ";
    	}
    	cout << "\n";
    }

    return 0;
}