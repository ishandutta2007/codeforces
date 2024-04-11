#include<bits/stdc++.h>
using namespace std;
const int N=50;

int n,x[N],y[N];

int main()
{
	scanf("%d",&n);
	n=n*4+1;
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for (int x1=0;x1<=50;x1++)
	for (int x2=0;x2<=50;x2++)
	if (x1<x2)
	for (int y1=0;y1<=50;y1++)
	for (int y2=0;y2<=50;y2++)
	if (y1<y2)
	{
		int tot=0,w;
		for (int i=1;i<=n;i++)
		if (((x[i]==x1||x[i]==x2)&&y1<=y[i]&&y[i]<=y2)||
			((y[i]==y1||y[i]==y2)&&x1<=x[i]&&x[i]<=x2)) tot++;
												   else w=i;
		if (tot==n-1)
		{
			printf("%d %d\n",x[w],y[w]);
			return 0;
		}
	}

	return 0;
}