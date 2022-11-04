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
		int n, u, v;
		cin >> n >> u >> v;

		int mx = 0;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i > 0) {
				mx = max(mx, abs(a[i] - a[i - 1]));
			}
		}

		if (mx == 0) {
			cout << min(u, v) + v << "\n";
		} else if (mx > 1) {
			cout << 0 << "\n";
		} else {
			cout << min(u, v) << "\n";
		}
	}
	

    return 0;
}