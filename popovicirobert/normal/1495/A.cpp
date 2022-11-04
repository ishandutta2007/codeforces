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
		int n;
		cin >> n;

		vector<int> xs, ys;
		for (int i = 0; i < 2 * n; i++) {
			int x, y;
			cin >> x >> y;
			if (x == 0) {
				ys.push_back(abs(y));
			} else {
				xs.push_back(abs(x));
			}
		}

		sort(xs.begin(), xs.end());
		sort(ys.begin(), ys.end());

		double ans = 0;
		for (int i = 0; i < n; i++) {
			ans += sqrt(1LL * xs[i] * xs[i] + 1LL * ys[i] * ys[i]);
		}

		cout << fixed << setprecision(20) << ans << "\n";
	}
    
		
    return 0;
}