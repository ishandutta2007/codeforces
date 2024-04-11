#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
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
const int N=300010;
vector<int>g[N];
int fa[N],siz[N],v[N],must[N],tag[N],n,k,ans;
char s[N];
void add(int x)
{
	if(must[x]!=-1)ans+=must[x]?siz[x]-v[x]:v[x];
	else ans+=min(v[x],siz[x]-v[x]);
}
void del(int x)
{
	if(must[x]!=-1)ans-=must[x]?siz[x]-v[x]:v[x];
	else ans-=min(v[x],siz[x]-v[x]);
}
int find(int x)
{
	if(x==fa[x])return x;
	int tmp=find(fa[x]);
	tag[x]^=tag[fa[x]];
	fa[x]=tmp;
	return tmp;
}
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	rep(i,k)
	{
		int c;scanf("%d",&c);
		rep(j,c){int x;scanf("%d",&x);g[x].pb(i);}
	}
	rep(i,k)fa[i]=i,siz[i]=1,v[i]=0,must[i]=-1,tag[i]=0;
	ans=0;
	rep(i,n)
	{
		if(s[i]=='0')
		{
			if(g[i].size()==1)
			{
				int a=find(g[i][0]);
				del(a);
				must[a]=tag[g[i][0]]^1;
				add(a);
			}
			else if(g[i].size())
			{
				int a=find(g[i][0]),b=find(g[i][1]);
				if(a!=b)
				{
					del(a);del(b);
					fa[b]=a;
					tag[b]=tag[g[i][0]]^tag[g[i][1]]^1;
					v[a]+=tag[b]?siz[b]-v[b]:v[b];
					siz[a]+=siz[b];
					if(must[b]!=-1)must[a]=must[b]^tag[b];
					add(a);
				}
			}
		}
		else
		{
			if(g[i].size()==1)
			{
				int a=find(g[i][0]);
				del(a);
				must[a]=tag[g[i][0]];
				add(a);
			}
			else if(g[i].size())
			{
				int a=find(g[i][0]),b=find(g[i][1]);
				if(a!=b)
				{
					del(a);del(b);
					fa[b]=a;
					tag[b]=tag[g[i][0]]^tag[g[i][1]];
					v[a]+=tag[b]?siz[b]-v[b]:v[b];
					siz[a]+=siz[b];
					if(must[b]!=-1)must[a]=must[b]^tag[b];
					add(a);
				}
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}