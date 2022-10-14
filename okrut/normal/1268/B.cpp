#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf 
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	int n;
	scanf ("%d", &n);
	ll b=0, w=0, a;
	rep(i,0,n)
	{
		scanf ("%lld", &a);
		
		if (i%2==1) 
		{
			b+= (a+1)/2LL;
			w += a/2LL;	
		}
		else
		{
			b+= a/2LL;
			w += (a+1)/2LL;
		}
	}
	printf ("%lld\n", min(b, w));
}