#include<bits/stdc++.h>

using namespace std;

const int maxi = 2e3+10;
long long f[maxi], fi[maxi];
const long long mo = 1e9+7;
int x[maxi], y[maxi], b[maxi],z[maxi][maxi],dp[maxi][maxi];
int n, m, r;

long long step(long long x, long long y)
{
    if (!y) return 1;

    long long p = step(x, y/2);

    if (y&1) return p*p%mo*x%mo;

    return p*p%mo;
}
long long bin(int x, int y)
{
    if (y>x) return 0;
    return f[x]*fi[y]%mo*fi[x-y]%mo;
}
int find(int xl,int yl,int xr,int yr)
{
	if(xl>xr || yl>yr) return 0;
	if(xl<=0) xl=1;
	if(yl<=0) yl=1;
	return dp[xr][yr]-dp[xl-1][yr]-dp[xr][yl-1]+dp[xl-1][yl-1];
}
int main()
{
    cin>>n>>m>>r;

   f[0] = 1;
   for (int i = 1;i<=n+10;i++)
    f[i] = (f[i-1]*i)%mo;

   for (int i = 0; i<=n+10;i++)
    fi[i] = step(f[i], mo-2);

    for (int i = 1;i<=n;i++)
    {
		cin>>x[i]>>y[i]>>b[i];
        z[x[i]][y[i]]=1;	
	}
   long long cn = bin(n, m);
   long long ans = 0;
   int a=2002;
   for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+z[i][j];
   for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
   {
   		int br1=find(x[i]-r,y[i]-r,x[i]+r,y[i]+r),br2=find(x[j]-r,y[j]-r,x[j]+r,y[j]+r),br3=find(max(x[i],x[j])-r,max(y[i],y[j])-r,min(x[i],x[j])+r,min(y[i],y[j])+r);
   		ans+=((2LL*b[i]*b[j])%mo)*(cn-bin(n-br1,m)-bin(n-br2,m)+bin(n-br1-br2+br3,m));
   		//cout<<(cn-bin(n-br1,m)-bin(n-br2,m)+bin(n-br1-br2+br3,m))<<endl;
   		ans%=mo;
   }
   for (int i = 1;i<=n;i++)
   {
       int skver = 0;

       for (int j = 1;j<=n;j++)
        if (max(abs(x[i]-x[j]), abs(y[i]-y[j]))<=r) skver++;

       ans = ans + (cn - bin(n-skver, m))*b[i]%mo*b[i]%mo;
       ans%=mo;
       if (ans<0) ans+=mo;
   }
   cout<<ans<<endl;
}