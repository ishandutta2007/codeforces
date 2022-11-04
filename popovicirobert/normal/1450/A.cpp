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
    int i, t;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
    	int n;
    	string str;
    	cin >> n >> str;
    	int cnt = 0;
    	for(auto it : str) {
    		if(it == 't') {
    			cnt++;
    		}
    		else {
    			cout << it;
    		}
    	}
    	while(cnt--) {
    		cout << (char)'t';
    	}
    	cout << "\n";
    }
   	
	
    return 0;
}