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
	vector <int> cnt(20,0);
	
	int n;
	scanf ("%d", &n);
	rep(i,0,n)
	{
		int a;
		scanf ("%d", &a);
		rep(j,0,20) if (a&(1<<j)) cnt[j]++;
	}
	
	ll res = 0LL;
	rep(i,0,n)
	{
		ll a= 0;
		rep(j,0,20) if (cnt[j]>0)
		{
			cnt[j]--;
			a|=1LL<<j;
		}
		res+=a*a;
	}
	printf ("%lld\n", res);
}