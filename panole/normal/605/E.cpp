#include<bits/stdc++.h>
using namespace std;

bool bo[1010];
double ans[1010],nw[1010],p[1010][1010],mi,fz[1010];
int n,mii;

int main()
{
	scanf("%d",&n);
	if (n==1) return puts("0.0000000000"),0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++) scanf("%lf",&p[i][j]),p[i][j]/=100.0;
		ans[i]=1.0/p[i][n],nw[i]=1-p[i][n],fz[i]=1;
	}
	memset(bo,1,sizeof(bo)),bo[n]=0;
	while (1)
	{
		mi=1000000000,mii=0;
		for (int i=1; i<=n; i++)
			if (bo[i]&&ans[i]<mi) mi=ans[i],mii=i;
		if (mii==1) return printf("%.10lf\n",ans[1]),0;
		bo[mii]=0;
		for (int i=1; i<=n; i++)
			if (bo[i]) 
			{
				fz[i]+=nw[i]*p[i][mii]*ans[mii];
				nw[i]=nw[i]*(1-p[i][mii]);
				ans[i]=fz[i]/(1-nw[i]);
			}
	}
	return 0;
}