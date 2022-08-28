#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[500005],ans,l=1,r=1,b[500005],bt,sum[500005][2],c[500005],ct;
char s[500005];
void upd(int x,int y,int nw)
{
//	printf("upd:x=%d,y=%d,nw=%d\n",x,y,nw);
	if(nw>ans)
	{
		ans=nw;
		l=x;
		r=y;
	}
}
int query(int l,int r,int fl)
{
//	printf("query:l=%d,r=%d,fl=%d\n",l,r,fl);
	if(l<=r) return sum[r][fl]-sum[l-1][fl];
	return sum[n][fl]-sum[l-1][fl]+sum[r][fl];
}
int F(int x)
{
	x=(x%n+n)%n;
	if(x==0) return n;
	return x;
}
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(') a[i]=a[i-1]+1;
		else a[i]=a[i-1]-1;
	}
	if(a[n]!=0)
	{
		printf("0\n1 1\n");
		return 0;
	}
	int mn=0;
	for(int i=1;i<=n;i++)
		if(a[i]<mn)
			mn=a[i];
	for(int i=1;i<=n;i++)
	{
		sum[i][0]=sum[i-1][0];
		sum[i][1]=sum[i-1][1];
		if(a[i]==mn)
			b[++bt]=i,ans++;
		if(a[i]==mn+1)
			c[++ct]=i,sum[i][0]++;
		if(a[i]==mn+2)
			sum[i][1]++;
		//printf("i=%d,sum=%d,%d\n",i,sum[i][0],sum[i][1]);
	}
	int nw=ans;
	b[bt+1]=b[1];
	for(int i=1;i<=bt;i++)
		upd(b[i]%n+1,b[i+1],query(b[i]%n+1,b[i+1],0));
	c[ct+1]=c[1];
	for(int i=1;i<=ct;i++)
		upd(c[i]%n+1,c[i+1],nw+query(c[i]%n+1,c[i+1],1));
	printf("%d\n%d %d\n",ans,l,r);
	return 0;
}