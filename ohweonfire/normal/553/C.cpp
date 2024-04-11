#include <bits/stdc++.h>
using namespace std;
int f[200005],ans=1,n,m;
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+n;i++)f[i]=i;
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(z==1)
		{
			f[gf(x)]=gf(y);
			f[gf(x+n)]=gf(y+n);
			if(gf(x)==gf(x+n))ans=0;
		}
		else
		{
			f[gf(x)]=gf(y+n);
			f[gf(x+n)]=gf(y);
			if(gf(x)==gf(x+n))ans=0;
		}
	}
	int cnt=0;
	for(int i=1;i<=n+n;i++)if(f[i]==i)
	{
		cnt++;
		if(cnt>2&&(cnt&1)==0)ans=ans+ans;
		if(ans>=1000000007)ans-=1000000007;
	}
	printf("%d\n",ans);
	return 0;
}