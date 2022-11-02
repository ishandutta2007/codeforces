#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int P=37,MOD=(int)1e9+7;
const int N=200010;
int ans,h[10][10],H,lk[N][10],cnt[N],u[N],v[N],n,m,k;
void dfs(int now,int hsh)
{
	if(now>k)
	{
		ans+=hsh==H;
		return;
	}
	rep(i,now)dfs(now+1,1ll*hsh*h[now][i]%MOD);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	rep(i,m){int x,y,z;scanf("%d%d%d",&x,&y,&z);u[z]=x;v[z]=y;}
	rep(i,m)lk[u[i]][++cnt[u[i]]]=v[i];
	rep(i,k)rep(j,i)h[i][j]=1;
	H=1;
	rep(i,n)H=1ll*H*(i+P)%MOD;
	rep(i,n)rep(j,cnt[i])h[cnt[i]][j]=1ll*h[cnt[i]][j]*(lk[i][j]+P)%MOD;
	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}