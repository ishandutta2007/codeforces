#include<bits/stdc++.h>
using namespace std;

const int N=301;

typedef long long ll;

int T;

int n,k,a[N][N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=0;
		int num=k/n,r=k%n;
		for(int i=1;i<=num-1;i++)
			for(int j=n;j>=n-(num-i)+1;j--)
				a[i][j]=1;
		for(int d=0;d<=num+(r!=0)-1;d++)
		{
			int res=(d>=num+1-1)?r:k;
			for(int i=1;i<=n;i++)
			{
				int j=i-d;
				if(j<1||j>n)
					continue;
				if(res)
					a[i][j]=1,res--;
			}
		}
		int now=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				now+=a[i][j];
		now=k-now;
		for(int d=n-1;d>=0;d--)
			for(int i=1;i<=n;i++)
				if(i+d<=n&&a[i][i+d]==0&&now)
					now--,a[i][i+d]=1;
		int mxR=0,mnR=n,mxC=0,mnC=n;
		for(int i=1;i<=n;i++)
		{
			int sum=0;
			for(int j=1;j<=n;j++)
				sum+=a[i][j];
			mxR=max(mxR,sum);
			mnR=min(mnR,sum);
		}
		for(int j=1;j<=n;j++)
		{
			int sum=0;
			for(int i=1;i<=n;i++)
				sum+=a[i][j];
			mxC=max(mxC,sum);
			mnC=min(mnC,sum);
		}
		printf("%d\n",(mxR-mnR)*(mxR-mnR)+(mxC-mnC)*(mxC-mnC));
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=n;j++)
				printf("%d",a[i][j]);
	} 
}