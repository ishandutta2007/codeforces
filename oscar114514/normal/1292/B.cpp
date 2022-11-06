#include<bits/stdc++.h>
using namespace std;
int n,k;
long long x0,y0,ax,ay,bx,by,xs,ys,t;
const int S=100;
long long x[233],y[233];
long long dp[233][233][2];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
//	x[S]=sx,y[S]=sy;
	x[0]=x0,y[0]=y0;
	while(x[n]<=4e16&&y[n]<=4e16)
	{
		n++;
		x[n]=x[n-1]*ax+bx;
		y[n]=y[n-1]*ay+by;
	}
	n--;
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		dp[i][i][0]=dp[i][i][1]=abs(x[i]-xs)+abs(y[i]-ys);
//		cerr<<i<<' '<<x[i]<<' '<<y[i]<<' '<<dp[i][i][0]<<endl;
		if(!ans&&dp[i][i][0]<=t)ans=1;
	}
	for(int l=1;l<=n;l++)
	{
		for(int i=0;i<=n;i++)
		{
			dp[i][i+l][0]=min(dp[i+1][i+l][0]+abs(x[i]-x[i+1])+abs(y[i]-y[i+1]),dp[i+1][i+l][1]+abs(x[i]-x[i+l])+abs(y[i]-y[i+l]));
			dp[i][i+l][1]=min(dp[i][i+l-1][0]+abs(x[i]-x[i+l])+abs(y[i]-y[i+l]),dp[i][i+l-1][1]+abs(x[i+l-1]-x[i+l])+abs(y[i+l-1]-y[i+l]));
			if(dp[i][i+l][0]<=t)ans=max(ans,l+1);
			if(dp[i][i+l][1]<=t)ans=max(ans,l+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}