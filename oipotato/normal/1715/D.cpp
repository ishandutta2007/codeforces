#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=200010;
int n,q,u[N],v[N],x[N],a[N],ans[N];
vector<pair<int,int>>g[N];
int main()
{
	scanf("%d%d",&n,&q);
	rep(i,q){scanf("%d%d%d",&u[i],&v[i],&x[i]);g[u[i]].pb(mp(v[i],x[i]));g[v[i]].pb(mp(u[i],x[i]));}
	for(int i=29;i>=0;i--)
	{
		rep(j,n)ans[j]=-1;
		rep(j,q)if(!((x[j]>>i)&1))ans[u[j]]=ans[v[j]]=0;
		rep(j,n)if(ans[j]==-1)
		{
			ans[j]=0;
			for(auto [x,y]:g[j])
			{
				if(!((y>>i)&1))continue;
				if(ans[x]==0){ans[j]=1;break;}
			}
		}
		rep(j,n)a[j]|=ans[j]<<i;
	}
	rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
    return 0;
}