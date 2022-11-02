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
long long f[110][110][110],g[110][110];
int a[110],n;
char s[110];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)rep(j,n){rep(k,n)f[i][j][k]=-1000000000ll*1000000000;g[i][j]=-1000000000ll*1000000000;}
	rep(i,n)
	rep(l,n-i+1)
	{
		int r=l+i-1;
		rep(j,r-l+1)
		{
			if(s[l]==s[r])f[l][r][j]=max(f[l][r][j],f[l][r-1][j-1]-a[j-1]+a[j]);
			for(int k=l+j;k<=r;k++)f[l][r][j]=max(f[l][r][j],f[l][k-1][j]+g[k][r]);
			g[l][r]=max(g[l][r],f[l][r][j]);
		}
	}
	printf("%lld\n",g[1][n]);
	return 0;
}