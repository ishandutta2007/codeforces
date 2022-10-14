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

const int N = 3e5 + 10;
const ll inf = 1e17;
ll dp[N][3]; 

int main ()
{
	int q;
	scanf ("%d", &q);
	rep(w,0,q)
	{
		int n;
		scanf ("%d", &n);
		int a;
		ll b;
		scanf ("%d %lld", &a, &b);
		dp[0][2] = 2LL *b;
		dp[0][1] = b;
		dp[0][0] = 0;
		int old = a;
		rep(i,1,n)
		{
			scanf ("%d %lld", &a, &b);
			dp[i][0] = dp[i][1] = dp[i][2] = inf;
			
			rep(ear,0,3) rep(now,0,3) if (old+ear != a + now)
			{
				dp[i][now] = min(dp[i][now], dp[i-1][ear]+ll(now)*b);
			}
			old = a;
		}
		printf ("%lld\n", min(dp[n-1][0], dp[n-1][1]));
	}
}