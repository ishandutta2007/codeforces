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
		int n, k1, k2, w, b;
		cin >> n >> k1 >> k2 >> w >> b;

		if ((k1 + k2) / 2 >= w && (2 * n - k1 - k2) / 2 >= b) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}

	}

    return 0;
}