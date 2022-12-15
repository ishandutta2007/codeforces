#include<cstdio>
#include<cstring>

int f[19][524288],a[100002],mi,n,x,l,r,ans[21],nw[21];

int main()
{
	scanf("%d",&n); mi=0;
	for (int i=1; i<=n; i++) 
	{
		scanf("%d",&a[i]); 
		if (a[i]<mi) mi=a[i];
	}
	a[++n]=0;
	memset(f,0,sizeof(f));
	for (int i=1; i<=n; i++) 
	{
		a[i]-=mi;
		for (int j=0; j<19; j++) f[j][a[i]%(1<<j)]++;
	}
	for (int j=0; j<19; j++)
		for (int i=1; i<(1<<j); i++) f[j][i]+=f[j][i-1];
	ans[0]=18;
	for (int i=0; i<18; i++) ans[i+1]=(1<<i);
	for (int i=0; i<17; i++) ans[i+1]=-ans[i+1];
	for (int i=0; i<=200000; i++)
	{
		nw[0]=0;
		for (int j=1; j<19; j++)
		{
			x=i%(1<<j); l=((1<<(j-1))-x+(1<<j))%(1<<j); r=(1<<j)-1-x;
			if (l<=r) 
			{
				if ((l>0&&f[j][r]>f[j][l-1])||(l==0&&f[j][r])) nw[++nw[0]]=(1<<(j-1));
			} else
			{
				if (f[j][(1<<j)-1]+f[j][r]>f[j][l-1]) nw[++nw[0]]=(1<<(j-1));
			}
		}
		for (int j=1; j<=nw[0]; j++) if ((i-mi)&nw[j]) nw[j]=-nw[j];
		if (nw[0]<ans[0]) for (int j=0; j<=nw[0]; j++) ans[j]=nw[j];
	}
	printf("%d\n",ans[0]);
	for (int i=1; i<=ans[0]; i++) printf("%d ",ans[i]); printf("\n");
	return 0;
}