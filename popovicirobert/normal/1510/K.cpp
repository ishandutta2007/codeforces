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

    int n;
    cin >> n;
    vector<int> p(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
    	cin >> p[i];
    }

    auto check = [&cout, &n](vector<int> p, bool type) {
    	vector<int> e(2 * n + 1);
    	iota(e.begin(), e.end(), 0);

    	for (int i = 0; i <= 2 * n; i++) {
    		if (p == e) {
    			return i;
    		}
    		if (i % 2 == type % 2) {
    			for (int i = 1; i <= n; i++) {
    				swap(p[i], p[i + n]);
    			}
    		} else {
    			for (int i = 1; i <= 2 * n; i += 2) {
    				swap(p[i], p[i + 1]);
    			}
    		}
    	}

    	return (int)1e9;
    };

    int ans = min(check(p, 0), check(p, 1));
    if (ans == 1e9) {
    	ans = -1;
    }
    cout << ans << "\n";

    return 0;
}