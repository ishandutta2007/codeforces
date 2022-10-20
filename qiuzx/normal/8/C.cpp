#include<bits/stdc++.h>
#define N 30
#define M 33554433
#define CTM 1061109567
using namespace std;
int n,x[N],y[N],dp[M],path[M][2],stx,sty,mask;
int fdbn(int x1,int y1,int x2,int y2)
{
	int k,l;
	k=abs(x1-x2);
	l=abs(y1-y2);
	return k*k+l*l;
}
void print()
{
	int mask,lt;
	mask=(1<<n)-1;
	cout<<dp[mask]<<endl<<"0 ";
	while(mask>0)
	{
		lt=mask;
		mask-=(1<<path[lt][0]);
		cout<<path[lt][0]+1<<" ";
		if(path[lt][1]!=-1)
		{
			mask-=(1<<path[lt][1]);
			cout<<path[lt][1]+1<<" ";
		}
		cout<<"0 ";
	}
	return;
}
int main()
{
	int i,j,k,lt;
	cin>>stx>>sty;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	for(mask=0;mask<(1<<n);mask++)
	{
		if(dp[mask]==CTM)
		{
			continue;
		}
		for(i=0;i<n;i++)
		{
			if(1&(mask>>i))
			{
				continue;
			}
			for(j=0;j<n;j++)
			{
				if(i==j||1&(mask>>j))
				{
					continue;
				}
				if(dp[mask+(1<<i)+(1<<j)]>dp[mask]+fdbn(stx,sty,x[i],y[i])+fdbn(x[i],y[i],x[j],y[j])+fdbn(x[j],y[j],stx,sty))
				{
					dp[mask+(1<<i)+(1<<j)]=dp[mask]+fdbn(stx,sty,x[i],y[i])+fdbn(x[i],y[i],x[j],y[j])+fdbn(x[j],y[j],stx,sty);
					path[mask+(1<<i)+(1<<j)][0]=i;
					path[mask+(1<<i)+(1<<j)][1]=j;
				}
			}
			if(dp[mask+(1<<i)]>dp[mask]+fdbn(stx,sty,x[i],y[i])*2)
			{
				dp[mask+(1<<i)]=dp[mask]+fdbn(stx,sty,x[i],y[i])*2;
				path[mask+(1<<i)][0]=i;
				path[mask+(1<<i)][1]=-1;
			}
			break;
		}
	}
	print();
	return 0;
}