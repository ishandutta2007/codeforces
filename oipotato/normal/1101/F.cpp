#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
vector<int>g[410];
long long ans;
int f[410][410],n,m,a[410],s[250010],t[250010],c[250010],r[250010];
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,m)scanf("%d%d%d%d",&s[i],&t[i],&c[i],&r[i]),g[s[i]].pb(i);
	rep(i,n-1)
	{
		for(int j=i;j<=n;j++)f[0][j]=a[j]-a[i];
		rep(j,n)
		{
			f[j][i]=0;
			int now=i;
			for(int k=i+1;k<=n;k++)
			{
				f[j][k]=f[j-1][k];
				for(;now+1<=k&&a[k]-a[now+1]>f[j-1][now+1];now++);
				f[j][k]=min(f[j][k],min(a[k]-a[now],f[j-1][now+1]));
			}
		}
		for(auto j:g[i])ans=max(ans,1ll*c[j]*f[r[j]][t[j]]);
	}
	printf("%lld\n",ans);
	return 0;
}