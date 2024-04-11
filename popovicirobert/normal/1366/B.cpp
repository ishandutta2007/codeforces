#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;




int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
   	int	t;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
    	int n, x, m;
    	cin >> n >> x >> m;

    	int left = x, right = x;
    	while(m--) {
    		int l, r;
    		cin >> l >> r;

    		if(max(left, l) <= min(right, r)) {
    			left = min(left, l);
    			right = max(right, r);
    		}
    	}
    	
    	cout << right - left + 1 << "\n";
    }
  	

    return 0;
}