#include<bits/stdc++.h>
using namespace std;

int n,f[301][301][301],cnt[2],s[301][301],nw;
struct P{int x,y;}a[311];
long long ans,sum;

bool cmp(P a,P b) {return a.x<b.x;}
P operator -(P a,P b) {return (P){a.x-b.x,a.y-b.y};}
long long operator ^(P a,P b) {return 1ll*a.x*b.y-1ll*a.y*b.x;}

int main()
{
	scanf("%d",&n),ans=1ll*n*(n-1)*(n-2)*(n-3)*(n-4)/120;
	for (int i=1; i<=n; i++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,cmp);
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
		{
			cnt[0]=cnt[1]=0;
			for (int k=1; k<=n; k++)
				if (i!=k&&j!=k) cnt[((a[j]-a[i])^(a[k]-a[i]))>0]++;
			for (int k=1; k<i; k++) f[k][i][j]+=cnt[((a[j]-a[i])^(a[k]-a[i]))<0];
			for (int k=i+1; k<j; k++) f[i][k][j]+=cnt[((a[j]-a[i])^(a[k]-a[i]))<0];
			for (int k=j+1; k<=n; k++) f[i][j][k]+=cnt[((a[j]-a[i])^(a[k]-a[i]))<0];
			for (int k=1; k<=n; k++)
				if (i!=k&&j!=k&&a[k].x>=a[i].x&&a[k].x<=a[j].x)
					s[i][j]+=(((a[j]-a[i])^(a[k]-a[i]))<0);
		}
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			for (int k=j+1; k<=n; k++)
			{
				if (a[i].x==a[j].x) nw=abs(s[i][k]-s[j][k])-1; else
				if (a[j].x==a[k].x) nw=abs(s[i][j]-s[i][k])-1; else
				{
					nw=s[i][j]+s[j][k]-s[i][k];
					if (nw<0) nw=-nw-1;
				}
				sum+=1ll*f[i][j][k]*nw;
				ans+=1ll*nw*(nw-1)/2;
			}
	return printf("%I64d\n",ans-sum/2),0;
}