#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std; 
typedef long long ll;
typedef long double ld;

const int N = 2000;

int zer[N], jed[N], dp[N][2], arr[N];
int main ()
{
	int n;
	scanf ("%d", &n);
	rep(i,0,n) 
	{
		scanf ("%d", &arr[i]);
		arr[i]--;
	}
	
	rep(i,0,n) 
	{
		if (i>0) zer[i] = zer[i-1];
		zer[i]+=(arr[i]==0);
	}
	for (int i=n-1; i>=0; i--)
	{
		if (i<n-1) jed[i] = jed[i+1];
		jed[i]+=(arr[i]==1);
	}
	
	int res = 0;
	rep(p,0,n) //poczatek odwroconego
	{
		rep(e,p,n)
		{
			if (e==p) dp[e][0] = dp[e][1] = 0;
			else
			{
				dp[e][0] = dp[e-1][0];
				dp[e][1] = dp[e-1][1];
			}
			
			if (arr[e]==1) dp[e][1]++;
			else
			{
				dp[e][0]++;
			}
			dp[e][0] = max(dp[e][0], dp[e][1]);
			
			int d = dp[e][0];
			if (p>0) d+=zer[p-1];
			if (e<n-1) d+=jed[e+1];
			
			res = max(res, d);
		}
	}
	printf ("%d\n", res);
}