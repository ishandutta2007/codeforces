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
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		int n;
		scanf ("%d", &n);
		
		ll res = 0;
		ll rightmod = 0;
		ll left;
		
		scanf ("%lld", &left);
		
		rep(i,1,n) {
			ll right;
			scanf ("%lld", &right);
			right += rightmod;
			
			ll delta = abs(left - right);
			res += delta;
			
			if (left < right) {
				rightmod -= delta;
			} else {
				left -= delta;
			}
		}
		
		res += abs(left);
		
		printf ("%lld\n", res);
	}
}