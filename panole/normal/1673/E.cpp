#include<bits/stdc++.h>
using namespace std;

int n,k,a[1100010],t[1100010];

void calc(int l,int r,int v)
{
	int s=l-1+n-r,ans=0,kk=k;
//	if (s<k) return;
	if (l!=1) s--,kk--;
	if (r!=n) s--,kk--;
	if (kk<0) kk=0;
	if (s<kk) return;
	int lb=(s&-s);
	for (int j=20; j>=0; j--)
	{
		if ((kk>>j)&1) 
		{
			if (!((s>>j)&1)) break;
		} else
		{
			if ((s>>j)&1)
			{
				if ((1<<j)==lb) ans^=1;
			}
		}
	}
	if ((s&kk)==kk) ans^=1;
	t[v]^=ans;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int i=1; i<=n; i++)
	{
		calc(i,i,a[i]);
		for (int j=i+1,nw=a[i]; j<=n; j++)
		{
			if (a[j]>20) break;
			long long nww=nw*(1ll<<a[j]);
			if (nww>=(1<<20)) break;
			nw=nww,calc(i,j,nw);
		}
	}
	bool bo=0;
	for (int i=(1<<20)-1; i>=0; i--)
		if (t[i]) putchar('1'),bo=1;
		else if (bo) putchar('0');
	if (!bo) putchar('0');
	putchar('\n');
	return 0;
}