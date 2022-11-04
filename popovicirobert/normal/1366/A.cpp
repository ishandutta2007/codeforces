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
    	int a, b;
    	cin >> a >> b;
    	// x <= min(a, b)
    	// a - x + b - x >= x
    	cout << min(min(a, b), (a + b) / 3) << "\n";
    }
  	

    return 0;
}