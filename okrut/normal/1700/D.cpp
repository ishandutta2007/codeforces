#include <bits/stdc++.h>
#define pb push_back
#define rep(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main()
{
	//ios_base::sync_with_stdio(false);
	int n;
	scanf ("%d", &n);
	
	vector <ll> limits(n), thresholds;
	ll sum = 0;
	rep(i,0,n) {
		ll v;
		scanf ("%lld", &v);
		sum += v;
		debug ("%lld for %d ==> %lld \n", sum, i+1, (sum + i) / (i + 1));
		limits[i] = (sum + i) / (i + 1);
	}
	
	set <pair <ll, int> > limitSet;
	rep(i,0,n) limitSet.insert({limits[i], i});
	
	
	for (int i = n-1; i >= 0; i--) {
		ll lmt = (--limitSet.end())->fi;
		
		ll total = (sum + i) / (i + 1);
		
		debug ("For %d pipes: %lld %lld\n", i+1, lmt, total);
		
		thresholds.pb(max(lmt, total));
		
		limitSet.erase({limits[i], i});
	}
	
	int q;
	scanf ("%d", &q);
	rep(i,0,q) {
		int t;
		scanf ("%d", &t);
		
		auto it = upper_bound(thresholds.begin(), thresholds.end(), (ll) t);
		int idx = it - thresholds.begin();
		int ans = n - idx + 1;
		
		if (ans > n) ans = -1;
		printf ("%d\n", ans);
		
	}
	
}