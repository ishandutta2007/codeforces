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
    int t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	vector<int> a(n), b(n), c(n);
    	for(i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	for(i = 0; i < n; i++) {
    		cin >> b[i];
    	}
    	for(i = 0; i < n; i++) {
    		cin >> c[i];
    	}
    	vector<int> sol(n);
    	sol[0] = a[0];
    	for(i = 1; i < n; i++) {
    		if(i == n - 1) {
    			if(a[i] != sol[i - 1] && a[i] != sol[0]) {
    				sol[i] = a[i];
    			}
    			else if(b[i] != sol[i - 1] && b[i] != sol[0]) {
    				sol[i] = b[i];
    			}
    			else {
    				sol[i] = c[i];
    			}
    		}
    		else {
    			if(a[i] != sol[i - 1]) {
    				sol[i] = a[i];
    			}
    			else {
    				sol[i] = b[i];
    			}
    		}
    	}
    	for(auto it : sol) {
    		cout << it << " ";
    	}
    	cout << "\n";
    }
   	
 	
    return 0;
}