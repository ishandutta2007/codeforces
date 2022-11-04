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

		vector<int> a, b;
		for(i = 0; i < n; i++) {
			int x;
			cin >> x;
			if(x > 0) {
				a.push_back(x);
			}
			else {
				b.push_back(x);
			}
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int sza = (int)a.size();
		int szb = (int)b.size();

		ll ans = -1e18;

		for(int x = 0; x <= 5; x++) {
			int y = 5 - x;

			if(x <= sza && y <= szb) {
				ll prd = 1;
				for(i = 0; i < x; i++) {
					prd *= a[i];
				}
				for(i = 0; i < y; i++) {
					prd *= b[i];
				}
				ans = max(ans, prd);

				prd = 1;
				for(i = 0; i < x; i++) {
					prd *= a[i];
				}
				for(i = 0; i < y; i++) {
					prd *= b[szb - i - 1];
				}
				ans = max(ans, prd);

				prd = 1;
				for(i = 0; i < x; i++) {
					prd *= a[sza - i - 1];
				}
				for(i = 0; i < y; i++) {
					prd *= b[i];
				}
				ans = max(ans, prd);

				prd = 1;
				for(i = 0; i < x; i++) {
					prd *= a[sza - i - 1];
				}
				for(i = 0; i < y; i++) {
					prd *= b[szb - i - 1];
				}
				ans = max(ans, prd);
			}
		}

		cout << ans << "\n";
	}

 
    return 0;
}