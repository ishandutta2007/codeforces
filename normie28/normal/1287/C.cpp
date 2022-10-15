#include <bits/stdc++.h>
using namespace std;
 #define MOD 998244353
 #define A '@'
 #define B '*'
 #define C '#'
 #define max(a,b) ((a>b)?a:b)
 #define min(a,b) ((a<b)?a:b)
 #define endl "\n"
 struct frac {long x; long y;};
 frac operator+(frac a, frac b)
 {
 	frac res;
 	res.x=((a.x)*(b.y))%MOD+((b.x)*(a.y))%MOD;
 	res.x%=MOD;
 	res.y=a.y*b.y;
 	res.y%=MOD;
 	return res;
 }
 
 long long bow (long long a, long long x)
 {
 	if (!x) return 1;
	long long res=bow(a,x/2);
	res*=res; res%=MOD;
	if (x%2) res*=a;
	return (res)%MOD;
 }
 
 long long get_mod(long long x, long long y)
 {
 	long long d=__gcd(x,y);
 	x/=d;
 	y/=d;
 	x%=MOD;
 	y%=MOD;
 	return (x*(bow(y,MOD-2)))%MOD;
 }
 
 
long long t,k,n,m, i,j,jj,mid,a,b,c=0,res,fail;
vector <long long> cards;
long long blank[200],p[200],o,e;
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>n;
   e=n/2;
   o=n-e;
   k=0;
   for (i=0;i<n;i++) {cin>>p[i]; if (!p[i]) {blank[k]=i; k++;} else if (p[i]%2) o--; else e--;}
   long long dp[100][100][2];
	for (i=1;i<n;i++) if (p[i]*p[i-1]) if ((p[i]-p[i-1])%2) c++;
	for (i=0;i<=o;i++) for (j=0;j<=e;j++) for (k=0;k<2;k++)
	{
		if ((!i)and(!j)) dp[i][j][k]=c;
		else if (!i)
		{
			if (k==1) dp[i][j][k]=MOD;
			else if ((p[blank[i+j-1]-1])and(blank[i+j-1])) dp[i][j][k]=min(dp[i][j-1][0],dp[i][j-1][1])+(p[blank[i+j-1]-1]%2);
			else dp[i][j][k]=min(dp[i][j-1][0],dp[i][j-1][1]+1);
			if (blank[i+j-1]<n-1) if (p[blank[i+j-1]+1]) if (p[blank[i+j-1]+1]%2==1) dp[i][j][k]++;
		}
		else if (!j)
		{
			if (k==0) dp[i][j][k]=MOD;
			else if ((p[blank[i+j-1]-1])and(blank[i+j-1])) dp[i][j][k]=min(dp[i-1][j][0],dp[i-1][j][1])+1-(p[blank[i+j-1]-1]%2);
			else dp[i][j][k]=min(dp[i-1][j][0]+1,dp[i-1][j][1]);
			if (blank[i+j-1]<n-1) if (p[blank[i+j-1]+1]) if (p[blank[i+j-1]+1]%2==0) dp[i][j][k]++; 
		}
		else if (k==0)
		{
			if (k==1) dp[i][j][k]=MOD;
			else if ((p[blank[i+j-1]-1])and(blank[i+j-1])) dp[i][j][k]=min(dp[i][j-1][0],dp[i][j-1][1])+(p[blank[i+j-1]-1]%2);
			else dp[i][j][k]=min(dp[i][j-1][0],dp[i][j-1][1]+1);
			if (blank[i+j-1]<n-1) if (p[blank[i+j-1]+1]) if (p[blank[i+j-1]+1]%2==1) dp[i][j][k]++;
		}
		else 
		{
			if (k==0) dp[i][j][k]=MOD;
			else if ((p[blank[i+j-1]-1])and(blank[i+j-1])) dp[i][j][k]=min(dp[i-1][j][0],dp[i-1][j][1])+1-(p[blank[i+j-1]-1]%2);
			else dp[i][j][k]=min(dp[i-1][j][0]+1,dp[i-1][j][1]);
			if (blank[i+j-1]<n-1) if (p[blank[i+j-1]+1]) if (p[blank[i+j-1]+1]%2==0) dp[i][j][k]++;
		}
//		cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
	}
	 cout<<min(dp[o][e][0],dp[o][e][1]);
}
/*
I don't want a lot for Christmas
There is just one thing I need
I don't care about bi D
That I toang yesterday
I just want you for my own
More than you could ever know
Make my wish come true oh
All I want for Christmas is tm
*/