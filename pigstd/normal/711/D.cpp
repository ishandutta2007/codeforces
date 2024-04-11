#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int Mod=1e9+7;
const int M=2e5+10;
int n,a[M],vis[M],c[M],pow2[M],sum1,sum2,ans=1;
vector<int>v[M];

void dfs1(int x)
{
	vis[x]=1;sum1++;
	for (int i=0;i<v[x].size();i++)
		if (!vis[v[x][i]])
			dfs1(v[x][i]);
}

void dfs2(int x,int p)
{
	if (c[x])
	{
		sum2=p-c[x];
		return;
	}
	c[x]=p;
	dfs2(a[x],p+1);
}

signed main()
{
	n=read();pow2[0]=1;
	for (int i=1;i<=n;i++)
		a[i]=read(),v[i].pb(a[i]),v[a[i]].pb(i),pow2[i]=pow2[i-1]*2%Mod;
	for (int i=1;i<=n;i++)
	{
		if (vis[i])continue;
		sum1=sum2=0;
		dfs1(i);
		dfs2(i,1);
		int x=pow2[sum1]-pow2[sum1-sum2+1];
		if (x<0)x+=Mod;
		ans=ans*x%Mod;
	}cout<<ans<<endl;
	return 0;
}