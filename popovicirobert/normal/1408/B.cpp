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
    	int n, k;
    	cin >> n >> k;
    	vector<int> a(n);
    	for(i = 0; i < n; i++) {
    		cin >> a[i];
    	}

    	if(a[0] != a[n - 1] && k == 1) {
    		cout << -1 << "\n";
    		continue;
    	}

    	int cnt = 1;
    	for(i = 1; i < n; i++) {
    		cnt += (a[i] - a[i - 1] > 0);
    	}
    	int ans = 1;
    	cnt -= k;
    	while(cnt > 0) {
    		cnt -= (k - 1);
    		ans++;
    	}
    	cout << ans << "\n";
    }
   	
 	
    return 0;
}