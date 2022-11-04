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
    	int a, b, c, d;
    	cin >> a >> b >> c >> d;
    	vector<string> sol(5, "Tidak");
    	if((a + b) % 2 == 0) {
    		if(a == 0 && d == 0) {
    			sol[3] = "Ya";
    		}
    		else if(b == 0 && c == 0) {
    			sol[4] = "Ya";
       		}
    		else {
    			sol[3] = sol[4] = "Ya";
    		}
    	}
    	else {
    		if(a == 0 && d == 0) {
    			sol[2] = "Ya";
    		}
    		else if(b == 0 && c == 0) {
    			sol[1] = "Ya";
       		}
    		else {
    			sol[1] = sol[2] = "Ya";
    		}
    	}
    	for(i = 1; i <= 4; i++) {
    		cout << sol[i] << " ";
    	}
    	cout << "\n";
    }
 
    return 0;
}