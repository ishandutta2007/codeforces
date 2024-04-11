#include <bits/stdc++.h>
#define N 2005  
using namespace std;
int n,k,ans=0,num=0;
int rf[N],re[N],cf[N],ce[N],rn[N][N],cn[N][N];
char xc;
int main(){
	int i,j,p;
	cin>>n>>k;
	memset(rf,-1,sizeof(rf));
	memset(cf,-1,sizeof(cf));
	memset(re,-1,sizeof(re));
	memset(ce,-1,sizeof(ce));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>xc;
			if(xc=='B')
			{
				if(rf[i]==-1)
				{
					rf[i]=j;
				}
				if(cf[j]==-1)
				{
					cf[j]=i;
				}
				re[i]=j;
				ce[j]=i;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(rf[i]==-1)
		{
			num++;
		}
		if(cf[i]==-1)
		{
			num++;
		}
	}
	for(i=0;i+k<=n;i++)
	{
		for(j=0;j+k<=n;j++)
		{
			if(i==0)
			{
				for(p=0;p<k;p++)
				{
					if(rf[i+p]>=j&&re[i+p]<j+k)
					{
						rn[i][j]++;
					}
				}
			}
			else
			{
				rn[i][j]=rn[i-1][j]-(rf[i-1]>=j&&re[i-1]<j+k)+(rf[i+k-1]>=j&&re[i+k-1]<j+k);
			}
		}
	}
	for(i=0;i+k<=n;i++)
	{
		for(j=0;j+k<=n;j++)
		{
			if(i==0)
			{
				for(p=0;p<k;p++)
				{
					if(cf[i+p]>=j&&ce[i+p]<j+k)
					{
						cn[i][j]++;
					}
				}
			}
			else
			{
				cn[i][j]=cn[i-1][j]-(cf[i-1]>=j&&ce[i-1]<j+k)+(cf[i+k-1]>=j&&ce[i+k-1]<j+k);
			}
		}
	}
	for(i=0;i+k<=n;i++)
	{
		for(j=0;j+k<=n;j++)
		{
			ans=max(ans,rn[i][j]+cn[j][i]);
		}
	}
	cout<<ans+num<<endl;
	return 0;
}