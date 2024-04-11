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
int dp[1<<16][2][16 * 16+1]; //mask, which done ile jeszcze zostalo
vector <char > type;
vector <int> R, B;
int n;
void update (int &a, int b)
{
	a = min( a, b);
}
int main ()
{
	scanf ("%d", &n);
	type.resize(n);
	R.resize(n); B.resize(n);
	int res = 1e9, offr=0, offb=0;
	rep(i,0,n) 
	{
		scanf (" %c %d %d", &type[i], &R[i], &B[i]);
		offr += max(0, R[i] - n);
		offb += max(0, B[i] - n);
		R[i] -=max(0, R[i] - n);
		B[i] -=max(0, B[i] - n);
	}
	int off = max(offr, offb);
	
	rep(i,0,1<<n) rep(j,0,2) rep(k,0,16 * 16 +1) dp[i][j][k] = 1e9; //duzo
	
	int  d, r, b, pr, pb, ur, ub, x, wait;
	
	ub = off - offb;
	ur = off - offr;
	if (ur==0)
	{
		if (ub>n*n)
		{
			rep(i,0,n) B[i]=0;
		}
		else dp[0][0][ub] = 0;
	}
	if (ub==0)
	{
		if (ur>n*n)
		{
			rep(i,0,n) R[i]=0;
		}
		else dp[0][1][ur] = 0;
	}
	dp[0][0][0] = 0;
	
	rep(m,0,1<<n) rep(j,0,2) rep(z,0,n*n+1) if (dp[m][j][z] < (int)1e9)
	{
		r=0, b=0;
		rep(i,0,n) if (m & (1<<i)) if (type[i]=='R') r++;
		else b++;
		
		rep(i,0,n) if (! (m & (1<<i))) 
		{
			pr = max(0, R[i] - r); //ned to pay
			pb = max(0, B[i] - b); //need to pay
			
			if (j==1) //zostalo R
			{
				ur=z;
				ub=0;
			}
			else //zostalo B
			{
				ur=0;
				ub=z;
			}
			
			d = min(pr, ur);
			ur-=d;
			pr-=d;
			
			d = min(pb, ub);
			ub-=d;
			pb-=d;
			
			
			wait = max(pb, pr);
			
			ub +=wait - pb;
			ur += wait - pr;
			
			if (ub >n*n || ur >n * n)
			{
				debug ("mamy problem\n");
			}
			//debug ("buy %d mask %d, (%d %d): pr: %d, pb: %d, ur: %d, ub: %d - %d\n", i, m, j, z, pr, pb, ur, ub, wait);
			
			if (ub==0)
			{
				update ( dp[m + (1<<i)][1][ur], dp[m][j][z] + wait+1);
			}
			
			if (ur==0)
			{
				update ( dp[m + (1<<i)][0][ub], dp[m][j][z] + wait+1);
			}
			assert(ub==0 || ur==0);
		}
		
		if (m==(1<<n) - 1) 
		{
			res = min(res, dp[m][j][z]);
		}
	}
	/*debug ("moj dp\n");
	rep(m,(1<<n) -1,1<<n) 
	{
		debug ("\nmask %d: \n", m);
		rep(j,0,2) rep(z,0,n*n+1) if (dp[m][j][z]<100) debug ("%d %d = %d\n", j, z, dp[m][j][z]);
	}*/
	
	printf ("%d\n", res+off);
}