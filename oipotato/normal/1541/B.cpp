#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010],pos[200010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		rep(i,2*n)pos[i]=-1;
		rep(i,n){int x;scanf("%d",&x);pos[x]=i;}
		int ans=0;
		rep(i,2*n)if(pos[i]!=-1)for(int j=1;1ll*j*i<=2*n;j++)if(pos[j]!=-1&&pos[j]<pos[i]&&i*j==pos[i]+pos[j])ans++;
		printf("%d\n",ans);
	}
    return 0;
}