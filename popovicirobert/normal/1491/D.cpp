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
   		int x, y;
   		cin >> x >> y;

   		bool answer = true;
   		int balance = 0;
   		for (int bit = 0; bit < 30; bit++) {
   			if (x & (1 << bit)) {
   				balance++;
   			}
   			if (y & (1 << bit)) {
   				balance--;
   			}
   			if (balance < 0) {
   				answer = false;
   			}
   		}

   		if (x > y) {
   			answer = false;
   		}

   		cout << (answer ? "Yes" : "No") << "\n";
   	}
   	

    return 0;
}