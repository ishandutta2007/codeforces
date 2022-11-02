#include<cstdio>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long ll;
const int N=5010;
ll f[N][N],s[N],g[N],ans;
pair<int,int>p[N];
int n,m,a[N],q[N];
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,m)scanf("%d%d",&p[i].first,&p[i].second);
	sort(a+1,a+n+1);
	sort(p+1,p+m+1);
	rep(i,n)s[i]=s[i-1]+a[i];
	rep(i,m)rep(j,n)f[i][j]=-1;ans=-1;
	rep(i,m)
	{
		if(i==1){rep(j,min(n,p[1].second))f[i][j]=f[i][j-1]+abs(a[j]-p[i].first);if(f[i][n]!=-1)ans=f[i][n];continue;}
		int t=1,w=1,j=1;g[0]=0;q[t]=0;
		for(;j<=n&&a[j]<=p[i].first;j++)
		{
			if(f[i-1][j]!=-1)
			{
				g[j]=f[i-1][j]+s[j]-1ll*p[i].first*j;
				for(;t<=w&&g[q[w]]>=g[j];w--);
				q[++w]=j;
			}
			for(;t<=w&&j-q[t]>p[i].second;t++);
			if(t<=w)f[i][j]=g[q[t]]+1ll*j*p[i].first-s[j];
		}
		for(int k=0;k<j;k++)g[k]+=2ll*(j-1)*p[i].first-2*s[j-1];
		for(;j<=n;j++)
		{
			if(f[i-1][j]!=-1)
			{
				g[j]=f[i-1][j]-s[j]+1ll*p[i].first*j;
				for(;t<=w&&g[q[w]]>=g[j];w--);
				q[++w]=j;
			}
			for(;t<=w&&j-q[t]>p[i].second;t++);
			if(t<=w)f[i][j]=g[q[t]]-1ll*j*p[i].first+s[j];
		}
		if(f[i][n]!=-1&&(ans==-1||f[i][n]<ans))ans=f[i][n];
	}
	//rep(i,m)rep(j,n)printf("%d %d %lld\n",i,j,f[i][j]);
	printf("%lld\n",ans);
	return 0;
}