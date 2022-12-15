#include<bits/stdc++.h>
using namespace std;

int n,m,c,a[1101],l,r,nw;

int main()
{
	scanf("%d%d%d",&n,&m,&c);
	l=1,r=n,a[0]=0,a[n+1]=c+1;
	while (l<=r)
	{
		scanf("%d",&nw);
		if (nw<=c/2)
		{
			if (a[l-1]<=nw) printf("%d\n",l),fflush(stdout),a[l++]=nw;
			else 
			{
				int po=0;
				for (int i=1; i<=l-1; i++)
					if (a[i]>nw) {po=i; break;}
				printf("%d\n",po),fflush(stdout),a[po]=nw;
			}
		} else
		{
			if (a[r+1]>=nw) printf("%d\n",r),fflush(stdout),a[r--]=nw;
			else
			{
				int po=0;
				for (int i=r+1; i<=n; i++)
					if (a[i]<nw) po=i;
				printf("%d\n",po),fflush(stdout),a[po]=nw;
			}
		}
	}
	return 0;
}