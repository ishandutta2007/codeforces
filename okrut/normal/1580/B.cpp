//#pragma GCC optimize "O3"
#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 101;

ll Dp[N][N][N]; //m, n, k
ll Choose[N][N];
ll Fac[N];

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int na, ma, ka;
	ll p;
	scanf ("%d %d %d %lld", &na, &ma, &ka, &p);
	
	rep(n,0,N) Choose[n][0] = 1;
	
	rep(n,1,N-1) rep(k,1,n+1) {
		Choose[n][k] = (Choose[n-1][k] + Choose[n-1][k-1]) % p;
	}
	
	Fac[0] = 1;
	rep(n,1,N) Fac[n] = Fac[n-1] * ll(n) % p;
	
	
	// for m = 1
	rep(n,1,N) Dp[1][n][1] = Fac[n];
	
	// for n < m
	rep(m,1,N) rep(n,0,m) Dp[m][n][0] = Fac[n];
	
	rep(m,2,N) rep(n,m,N) {
		
		for (int n1 = 0; n1 * 2 < n; n1++) {
			int n2 = n-1 - n1;
			ll x = (n1 * 2 == n-1 ? 1 : 2);
			
			
			debug ("\nCombine %d & %d\n", n1, n2);
			debug ("Dp[%d][%d] = ", m-1, n1);
			//rep(k,0,n1+1) debug ("%lld ", Dp[m-1][n1][k]);
			debug ("\n");
			
			debug ("Dp[%d][%d] = ", m-1, n2);
		//	rep(k,0,n2+1) debug ("%lld ", Dp[m-1][n2][k]);
			debug ("\n");
			
			
			rep(k1,0,n1+1) if (Dp[m-1][n1][k1]) rep(k2,0,n2+1) {
				Dp[m][n][k1+k2] += Choose[n-1][n1] * Dp[m-1][n1][k1] % p * Dp[m-1][n2][k2] * x;
				Dp[m][n][k1+k2] %= p;
			}
			
			
			
			debug ("Try %d\n", n1+1);
			
		}
		
		debug ("\nDp[%d][%d] = ", m, n);
		//rep(k,0,n+1) debug ("%lld ", Dp[m][n][k]);
		debug ("\n\n\n");
		
		ll sum = 0;
			rep(k,0,n+1) sum += Dp[m][n][k];
			sum %= p;
			
			assert(sum == Fac[n]);
	}
	
	printf ("%lld\n", Dp[ma][na][ka]);
}