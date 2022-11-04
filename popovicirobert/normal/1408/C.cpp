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
    	int n, l;
    	cin >> n >> l;
    	vector<int> a(n);
    	for(i = 0; i < n; i++) {
    		cin >> a[i];
    	}

    	int pa = 0, pb = n - 1;
    	int sa = 1, sb = 1;
    	double xa = 0, xb = l;
    	double ans = 0;

    	while(xa < xb) {
    		double ta = 1.0 * (a[pa] - xa) / sa;
    		double tb = 1.0 * (xb - a[pb]) / sb;

    		if(a[pa] >= xb || a[pb] <= xa) {
    			ans += 1.0 * (xb - xa) / (sa + sb);
    			break;
    		}

    		if(ta < tb) {
    			xa += sa * ta;
    			xb -= sb * ta;
    			ans += ta;
    		}
    		else {
				xa += sa * tb;
    			xb -= sb * tb;
    			ans += tb;
    		}
    		while(pa < n && a[pa] <= xa) {
    			pa++;
    			sa++;
    		}
    		while(pb >= 0 && a[pb] >= xb) {
    			pb--;
    			sb++;
    		}
    	}

    	cout << fixed << setprecision(20) << ans << "\n";
    }
   	
 	
    return 0;
}