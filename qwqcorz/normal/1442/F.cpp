#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int deg[N],p[N],id[N];
vector<int>e[N];
void topo(int n)
{
	int h=1,t=0;
	for (int i=1;i<=n;i++) if (!deg[i]) p[++t]=i;
	while (h<=t)
	{
		int now=p[h++];
		for (int to:e[now]) if (!--deg[to]) p[++t]=to;
	}
}
int vis[1<<20];
vector<int>x[21];
vector<pair<int,int>>del,ins;

signed main()
{
	int n=read(),m=read(),Q=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		deg[v]++;
	}
	topo(n);
	memset(id,-1,sizeof(id));
	int tot=min(n,20);
	for (int i=0;i<(1<<tot);i++) x[__builtin_popcount(i)].push_back(i);
	for (int i=0;i<tot;i++) id[p[n-i]]=i;
	for (int i=1;i<=n;i++)
	{
		int S=0;
		for (int to:e[i]) if (~id[to]) S|=1<<id[to];
		if (~id[i])
		{
			for (int t=0;t<id[i];t++) if (~S>>t&1) ins.push_back(make_pair(i,p[n-t]));
		}
		else
		{
			ins.push_back(make_pair(i,i));
			bool flag=0;
			for (int j=0;!flag&&j<=tot;j++)
			for (int k:x[j]) if (!vis[S^k])
			{
				for (int t=0;t<tot;t++)
				if (k>>t&1)
				{
					if (S>>t&1) del.push_back(make_pair(i,p[n-t]));
						   else ins.push_back(make_pair(i,p[n-t]));
				}
				vis[S^k]=i;
				flag=1;
				break;
			}
		}
	}
	print(ins.size()+del.size());
	for (auto i:ins) printf("+ %d %d\n",i.first,i.second);
	for (auto i:del) printf("- %d %d\n",i.first,i.second);
	fflush(stdout);
	while (Q--)
	{
		int S=0,ans=-1;
		for (int i=0;i<tot;i++)
		{
			printf("? 1 %d\n",p[n-i]);
			fflush(stdout);
			string s; cin>>s;
			if (s=="Lose"){ans=p[n-i];break;}
			if (s=="Win") S|=1<<i;
		}
		if (ans<0) ans=vis[S];
		printf("! %d\n",ans);
		fflush(stdout);
		string s; cin>>s;
		if (s=="Wrong Answer") return 0;
	}
	
	return 0;
}