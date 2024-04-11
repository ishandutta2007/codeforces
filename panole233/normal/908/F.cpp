#include<cstdio>
#include<cstring>

int mab,mar,n,lab,lar,ans,lag,mib,mir;
bool bob,bor,bog,bo;
char c;

struct node
{
	int x,col;
}a[300001];

int main()
{
	scanf("%d",&n);
	bo=0;
	for (int i=1; i<=n; i++) 
	{
		scanf("%d",&a[i].x);
		c=getchar();
		if (c==' ') c=getchar();
		if (c=='R') a[i].col=1; else if (c=='G') a[i].col=2; else a[i].col=3;
		if (c=='G') bo=1;
	}
	if (bo)
	{
		bog=0; lab=lar=0; ans=0;
		for (int i=1; i<=n; i++)
			if (a[i].col==1)
			{
				if (!bog)
				{
					if (!lar) lar=a[i].x;
				}
				else
				{
					if (a[i].x-lar>mar) mar=a[i].x-lar;
					lar=a[i].x; bor=1;
				}
			} else
			if (a[i].col==3)
			{
				if (!bog)
				{
					if (!lab) lab=a[i].x;
				}
				else
				{
					if (a[i].x-lab>mab) mab=a[i].x-lab;
					lab=a[i].x; bob=1;
				}
			} else
			{
				if (!bog)
				{
					bog=1; 
					if (lar) ans+=a[i].x-lar;
					if (lab) ans+=a[i].x-lab;
					lag=a[i].x; lar=lab=a[i].x; mar=mab=0;
					bor=bob=0;
				} else
				{
					if (bob) 
					{
						if (a[i].x-lab>mab) mab=a[i].x-lab;
						ans+=a[i].x-lag-mab;
					}
					if (bor) 
					{
						if (a[i].x-lar>mar) mar=a[i].x-lar;
						ans+=a[i].x-lag-mar;
					}
					if (bob&&bor&&mab+mar<a[i].x-lag) ans+=mab+mar;
					else ans+=a[i].x-lag;
					lag=a[i].x; lar=lab=a[i].x; mar=mab=0; bor=bob=0;
				}
			}
		if (bob) ans+=lab-lag;
		if (bor) ans+=lar-lag;
		printf("%d\n",ans);
	}
	else
	{
		mir=mar=mib=mab=0;
		for (int i=1; i<=n; i++)
			if (a[i].col==1) 
			{
				if (!mir) mir=a[i].x;
				mar=a[i].x;
			} else
			{
				if (!mib) mib=a[i].x;
				mab=a[i].x;
			}
		printf("%d\n",mar-mir+mab-mib);
	}
	return 0;
}