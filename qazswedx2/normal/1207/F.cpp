#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n=500000,sn,m,a[1000005],tans[5005][5005];
int main()
{
	sn=sqrt(n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			a[x]+=y;
			for(int j=1;j<=sn;j++)
				tans[j][x%j]+=y;
		}
		else
		{
			if(x<=sn)
			{
				printf("%d\n",tans[x][y]);
			}
			else
			{
				int ans=0;
				for(int i=y;i<=n;i+=x)
					ans+=a[i];
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}