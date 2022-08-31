#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005],tans[100005][2],f[1005],pn=1000;
int solve(int x)
{
	return lower_bound(f+1,f+pn+1,x)-f;
}
int main()
{
	memset(a,-1,sizeof(a));
	for(int i=1;i<=pn;i++)
		f[i]=i*(i-1)/2;
	scanf("%d%d%d",&n,&tans[0][0],&tans[0][1]);
	for(int i=1;i<=n;i++)
	{
		printf("+ %d\n",i!=n?i:1);
		fflush(stdout);
		scanf("%d%d",&tans[i][0],&tans[i][1]);
	}
	for(int i=n;i>0;i--)
		tans[i][0]-=tans[i-1][0],tans[i][1]-=tans[i-1][1];
	a[1]=solve(tans[n][0])-1;
	for(int i=2;i<n;i++)
		if(tans[i][0])
			a[i]=solve(tans[i][0]);
	if(a[2]==-1&&a[3]==-1)
	{
		if(tans[1][1]) a[2]=a[3]=1;
		else if(tans[2][1]) a[3]=1,a[2]=0;
		else if(tans[n][1]==2) a[2]=1,a[3]=0;
		else a[2]=a[3]=0;
	}
	else if(a[2]==-1) a[2]=tans[1][1]/a[3];
	else if(a[3]==-1) a[3]=tans[1][1]/a[2];
	for(int i=3;i<n;i++)
		if(a[i+1]==-1)
		{
			int v=tans[i][1]-(a[i-1]+1)*(a[i-2]+1);
			if(v) 
			{
				if(i+1<n) a[i+1]=1;
				else a[i+1]=v/(a[i-1]+1);
			}
			else a[i+1]=0;
		}
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}