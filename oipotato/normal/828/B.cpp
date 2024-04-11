#include<cstdio>
#include<algorithm>
using namespace std;
int ans=-1,n,m,a[110][110],num;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		getchar();
		for(int j=1;j<=m;j++)a[i][j]=getchar()=='B';
		for(int j=1;j<=m;j++)num+=a[i][j];
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		int tnum=0,tans=0;
		for(int k=1;k<=min(n-i+1,m-j+1);k++)
		{
			for(int p=1;p<=k;p++)tnum+=a[i+p-1][j+k-1],tans+=!a[i+p-1][j+k-1];
			for(int p=1;p<k;p++)tnum+=a[i+k-1][j+p-1],tans+=!a[i+k-1][j+p-1];
			if(tnum==num)if(ans==-1||tans<ans)ans=tans;
		}
	}
	printf("%d",ans);
	return 0;
}