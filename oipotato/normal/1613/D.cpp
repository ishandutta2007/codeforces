#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int MOD=998244353;
const int N=500010;
int a[N],f[N],g[N],n;
void update(int&x,int y){(x+=y)%=MOD;}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		for(int i=0;i<=n;i++)f[i]=g[i]=0;
		int ans=0;
		rep(i,n)
		{
			if(!a[i])
			{
				update(f[0],f[0]+1);
				update(g[2],g[2]);
			}
			else if(a[i]==1)
			{
				update(f[1],(f[0]+f[1])%MOD);
				update(g[1],g[1]);
				update(g[1],1);
				update(g[3],g[3]);
			}
			else
			{
				int x=a[i];
				update(f[x],(f[x]+f[x-1])%MOD);
				update(g[x],g[x]);
				update(g[x],f[x-2]);
				update(g[x+2],g[x+2]);
			}
		}
		for(int i=0;i<=n;i++)update(ans,(f[i]+g[i])%MOD);
		printf("%d\n",ans);
	}
    return 0;
}