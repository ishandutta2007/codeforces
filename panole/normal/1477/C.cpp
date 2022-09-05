#include<bits/stdc++.h>
using namespace std;

int n,x[5010],y[5010],p[5010];

bool check(int i,int j,int k)
{
	return 1ll*(y[k]-y[j])*(y[j]-y[i])+1ll*(x[k]-x[j])*(x[j]-x[i])<0;
}

int main()
{
	scanf("%d",&n);
	for (int i=1 ;i<=n; i++) scanf("%d%d",&x[i],&y[i]);
	p[1]=1,p[2]=2;
	for (int i=3; i<=n; i++)
	{
		for (int j=0; j<=i; j++) 
		{
			if (j&&j<i-1&&!check(p[j],i,p[j+1])) continue;
			if (j>1&&!check(p[j-1],p[j],i)) continue;
			if (j<i-2&&!check(i,p[j+1],p[j+2])) continue;
			for (int k=i; k>j; k--) p[k]=p[k-1];
			p[j+1]=i;
			break;
		}
	}
	for (int i=1; i<=n; i++) printf("%d ",p[i]);puts("");
	return 0;
}