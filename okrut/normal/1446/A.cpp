#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n;
		ll W;
		scanf ("%d %lld", &n, &W);
		vector <pair <ll, int> > A(n);
		int cnt = 1;
		for (auto &a: A) 
		{
			scanf ("%lld", &a.fi);
			a.se = cnt++;
		}
		sort(A.begin(), A.end());
		reverse(A.begin(), A.end());
		vector <int> res;
		ll s = 0;
		ll M = (W+1)/2;
		
		for (auto a: A)
		{
			if (s+a.fi <= W) {
				s += a.fi;
				res.pb(a.se);
			}
		}
		
		if (s<M) printf ("-1\n");
		else {
			printf ("%d\n", (int)res.size());
			for (int x: res) printf ("%d ", x);
			printf ("\n");
		}
	}
}