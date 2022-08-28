#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int l,r;
}p[1000005];
int n,m,maxn[1000005],c[500005][22],maxm=0,b[500005];
int pw[1005];
bool cmp(const pt x,const pt y)
{
	return x.l==y.l?x.r<y.r:x.l<y.l;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].l,&p[i].r),maxm=max(maxm,p[i].r);
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
		maxn[i]=max(maxn[i-1],p[i].r);
	pw[0]=1;
	for(int i=1;i<=20;i++)
		pw[i]=pw[i-1]*2;
	for(int i=1;i<=n;i++)
		b[i]=p[i].l;
	for(int i=0;i<=maxm;i++)
	{
		int nw=upper_bound(b+1,b+n+1,i)-b;
		if(nw==1) c[i][0]=i;
		else c[i][0]=maxn[nw-1];
	}
	for(int i=1;i<=19;i++)
		for(int j=0;j<=maxm;j++)
			c[j][i]=c[c[j][i-1]][i-1];
	for(int i=1;i<=m;i++)
	{
		int ql,qr,x,ans=0;
		scanf("%d%d",&ql,&qr);
		x=ql;
		for(int j=19;j>=0;j--)
			if(c[x][j]<qr)
			{
				ans=ans+pw[j];
				x=c[x][j];
			}
		if(c[x][0]<qr)
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",ans+1);
	}
	return 0;
}