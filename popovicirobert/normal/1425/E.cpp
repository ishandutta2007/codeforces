#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

const ll INF = 1e18;


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    vector<ll> a(n + 1), d(n + 1);
    for(i = 1; i <= n; i++) {
    	cin >> a[i];
    }
    for(i = 1; i <= n; i++) {
    	cin >> d[i];
    }
    
    ll ans = 0;
    if(k == 0) {
    	ll sum = 0;
    	for(i = n; i >= 1; i--) {
    		sum += a[i];
    		ans = max(ans, sum - d[i]);
    	}
    	cout << ans;
    	return 0;
    }
    if(k >= 2) {
    	ans = max(ans, a[n] - d[n]);
    	ll sum = a[n], mn = INF;
    	for(i = 1; i < n; i++) {
    		sum += a[i];
    		mn = min(mn, d[i]);
    	}
    	cout << max(ans, sum - mn);
    	return 0;
    }

    ll sum = 0, mn = INF;
    for(i = n; i >= 2; i--) {
    	sum += a[i];
    	ans = max(ans, sum - d[i]);
    }
    sum += a[1];
    for(i = 2; i + 1 <= n; i++) {
    	ans = max(ans, sum - d[1] - a[i]);
    }

   	ll tot = sum;
    sum = 0, mn = INF;
    for(i = 1; i < n; i++) {
    	sum += a[i];
    	mn = min(mn, d[i]);
    	ans = max(ans, max(0LL, sum - mn) + max(0LL, tot - sum - d[i + 1]));
    }

    cout << ans;
 	
    return 0;
}