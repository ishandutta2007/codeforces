#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=3e5+10;
int n,sum[M],m,ans[M<<1],tot,deg[M];
pair<int,int>p[M<<1];
set<pair<int,int>>e[2][M];

int f(int x){if (x>0)return 1;if (x==0)return 0;return -1;}

void dfs(int u)
{
	if (e[0][u].size())
	{
		auto p=*e[0][u].begin();
		if (!ans[abs(p.y)])
		{
			if (sum[u]<=0)sum[u]++,sum[p.x]--,ans[abs(p.y)]=f(p.y);
			else sum[u]--,sum[p.x]++,ans[abs(p.y)]=-f(p.y);
			dfs(p.x);
		}
	}
	if (e[1][u].size())
	{
		auto p=*e[1][u].begin();
		if (!ans[abs(p.y)])
		{
			if (sum[u]<=0)sum[u]+=2,sum[p.x]-=2,ans[abs(p.y)]=f(p.y);
			else sum[u]-=2,sum[p.x]+=2,ans[abs(p.y)]=-f(p.y);
			dfs(p.x);
		}
	}
}

signed main()
{
//	freopen("qwq.txt","r",stdin);
	n=read(),m=tot=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		deg[u]+=w,deg[v]+=w;
		e[w-1][u].insert(mp(v,i)),e[w-1][v].insert(mp(u,-i));
	}//puts("Qwq");
	for (int i=1;i<=n;i++)
	{
		while(e[0][i].size()>1)
		{
			auto p1=*e[0][i].begin();e[0][i].erase(p1);
			auto p2=*e[0][i].begin();e[0][i].erase(p2);
			int U=p1.x,V=p2.x;p[++tot]=mp(-p1.y,p2.y);
//			cout<<1<<' '<<U<<' '<<V<<endl;
			e[0][U].erase(mp(i,-p1.y));
			e[0][V].erase(mp(i,-p2.y));
			if (U==V)continue;
			e[0][U].insert(mp(V,tot));
			e[0][V].insert(mp(U,-tot));
		}
		while(e[1][i].size()>1)
		{
			auto p1=*e[1][i].begin();e[1][i].erase(p1);
			auto p2=*e[1][i].begin();e[1][i].erase(p2);
			int U=p1.x,V=p2.x;p[++tot]=mp(-p1.y,p2.y);
//			cout<<2<<' '<<U<<' '<<V<<endl;
			e[1][U].erase(mp(i,-p1.y));
			e[1][V].erase(mp(i,-p2.y));
			if (U==V)continue;
			e[1][U].insert(mp(V,tot));
			e[1][V].insert(mp(U,-tot));
		}
	}//puts("qwq");
	for (int i=1;i<=n;i++)
	{
		if (e[0][i].size()&&(*e[0][i].begin()).x==i)e[0][i].clear();
		if (e[1][i].size()&&(*e[1][i].begin()).x==i)e[1][i].clear();
	}int res=0,res2=0;
	for (int i=1;i<=n;i++)dfs(i);
	for (int i=1;i<=n;i++)
		if (abs(sum[i])==1)res++;
	for (int i=1;i<=n;i++)res2+=deg[i]&1;
	assert(res==res2);
	cout<<res<<endl;
	for (int i=tot;i>=1;i--)
	{
		if (!ans[i])ans[i]=1;
		ans[abs(p[i].x)]=f(p[i].x)*ans[i],
		ans[abs(p[i].y)]=f(p[i].y)*ans[i];
	}
	for (int i=1;i<=m;i++)cout<<(ans[i]==1?1:2);puts("");
	return 0;
}