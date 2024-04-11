#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int s[3010][3010],a[3010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n)rep(j,n)s[i][j]=0;
		rep(i,n)rep(j,i-1)s[j][n-i+1]=a[i]==a[j];
		rep(i,n)rep(j,n)s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		long long ans=0;
		rep(i,n)rep(j,i-1)if(a[i]==a[j])ans+=s[i-1][n-i]-s[j][n-i];
		printf("%lld\n",ans);
	}
    return 0;
}