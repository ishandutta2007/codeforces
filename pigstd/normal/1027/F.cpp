#include<bits/stdc++.h>
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=4e6+10;
int n,maxn,pp[M],a[M],b[M],cnt,ppp[M];
int max1,max2,sum1,sum2,vis[M];
map<int,int>t;vector<int>e[M];

void dfs(int u)
{
	if (vis[u])return;
	vis[u]=1,sum2++;
	max2=max(max2,u);
	if (max1<max2)swap(max1,max2);
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
//		cout<<u<<' '<<to<<endl;
		sum1++;dfs(to);
	}
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		pp[++cnt]=a[i]=read(),pp[++cnt]=b[i]=read();
	sort(pp+1,pp+1+cnt);cnt=0;
	for (int i=1;i<=2*n;i++)
		if (pp[i]!=pp[i-1]||i==1)
			t[pp[i]]=++cnt,ppp[cnt]=pp[i];
	for (int i=1;i<=n;i++)
		a[i]=t[a[i]],b[i]=t[b[i]],
		e[a[i]].pb(b[i]),e[b[i]].pb(a[i]);
	for (int i=1;i<=cnt;i++)
		if (!vis[i])
		{
			max1=max2=sum1=sum2=0;
			dfs(i);sum1/=2;
			if (sum2==sum1)maxn=max(maxn,max1);
			else if (sum2>sum1)maxn=max(maxn,max2);
			else return puts("-1"),0;
		}
	cout<<ppp[maxn]<<endl;
	return 0;
}
// fuck cf /qq