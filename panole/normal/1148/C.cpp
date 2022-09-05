#include<bits/stdc++.h>
using namespace std;

int po[300010],p[300010],ansn,ans[2000010][2],n,nn;

void add(int x,int y)
{
	swap(p[x],p[y]);
	po[p[x]]=x,po[p[y]]=y;
	ans[++ansn][0]=x,ans[ansn][1]=y;
}

int main()
{
	scanf("%d",&n),nn=(n>>1),ansn=0;
	for (int i=1; i<=n; i++) scanf("%d",&p[i]),po[p[i]]=i;
	for (int i=0; i<nn; i++)
	{
		if (po[nn-i]!=nn-i) 
		{
			if (po[nn-i]>nn&&po[nn-i]-(nn-i)<nn) add(po[nn-i],1);
			if (po[nn-i]<=nn) add(po[nn-i],n);
			add(po[nn-i],nn-i);
		}
		if (po[nn+i+1]!=nn+i+1)
		{
			if (po[nn+i+1]<=nn&&nn+i+1-po[nn+i+1]<nn) add(po[nn+i+1],n);
			if (po[nn+i+1]>nn) add(po[nn+i+1],1);
			add(po[nn+i+1],nn+i+1);
		}
	}
	printf("%d\n",ansn);
	for (int i=1; i<=ansn; i++) printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}