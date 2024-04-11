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
#define size fuck
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int MOD=(int)1e9+7;
const int inv2=(MOD+1)/2;
const int N=210;
int siz[N],size[N],top,g[N][N],ans,n,invn;
vector<int>G[N];
int mypow(int x,int n){int res=1;for(;n;n>>=1,x=1ll*x*x%MOD)if(n&1)res=1ll*res*x%MOD;return res;}
void pre(int p,int fa)
{
	siz[p]=1;
	for(auto i:G[p])if(i!=fa)pre(i,p),siz[p]+=siz[i];
}
void dfs(int p,int fa,int R)
{
	if(p<R)rep(i,top)ans=(ans+1ll*size[i]*invn%MOD*g[i-1][top-i+1])%MOD;
	top++;
	for(auto i:G[p])if(i!=fa)size[top]=siz[p]-siz[i],dfs(i,p,R);
	top--;
}
int main()
{
	scanf("%d",&n);
	invn=mypow(n,MOD-2);
	rep(i,n-1){int x,y;scanf("%d%d",&x,&y);G[x].pb(y);G[y].pb(x);}
	rep(i,n)g[0][i]=1,g[i][0]=0;
	rep(i,n)rep(j,n)g[i][j]=1ll*(g[i-1][j]+g[i][j-1])*inv2%MOD;
	rep(i,n)pre(i,0),dfs(i,0,i);
	printf("%d\n",ans);
    return 0;
}