#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;


const int INF = (int)1e9;


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

    	vector<int> cst(n);
    	for (auto& it : cst) {
    		cin >> it;
    	}

    	int x = n - 1, y = n;
    	int mnx = cst[0], mny = INF;
    	ll ans = 1e18, sum = cst[0];

    	for (int i = 1; i < n; i++) {
    		if (x < 0 || y < 0) {
    			break;
    		}

    		if (i % 2 == 1) {
    			mny = min(mny, cst[i]);
    		} else {
    			mnx = min(mnx, cst[i]);
    		}

    		ans = min(ans, sum + 1LL * mnx * x + 1LL * mny * y);

    		if (i % 2 == 0) {
    			x--;
    		} else {
    			y--;
    		}

    		sum += cst[i];
    	}

    	cout << ans << "\n";
    }
	

    return 0;
}