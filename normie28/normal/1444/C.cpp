#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
using namespace std;
const int N=1e6+100;
int n,m,k,dfn,c[N],vi[N];
vector <pair<int,int> > tmp;
unordered_map <int,vector<pair<int,int> > > e[N/2];
unordered_map <int,vector<pair<int,int> > > :: iterator it;
namespace dsu
{
	int fa[N],sz[N];
	struct node
	{
		int fax,fay,szy,ti;
	};
	stack <node> s;
	inline void init()
	{
		for (int i=1;i<=n+n;i++) fa[i]=i,sz[i]=1;
	}
	int find(int x)
	{
		if (fa[x]==x) return fa[x];
		return find(fa[x]);
	}
	inline void connect(int x,int y)
	{
		int fax=find(x),fay=find(y);
		if (fax==fay) return;
		if (sz[fax]>sz[fay]) swap(fax,fay);
		s.push((node){fax,fay,sz[fay],dfn});
		fa[fax]=fay;sz[fay]+=sz[fax];
	}
	inline bool add_edge(int x,int y)
	{
		int fax=find(x),faex=find(x+n),fay=find(y),faey=find(n+y);
		dfn++;connect(fax,faey);connect(fay,faex);
		if (find(x)==find(x+n)||find(y)==find(n+y)) return 0;
		return 1;
	}
	inline void back(int ti)
	{
		while (!s.empty()&&s.top().ti>ti)
		{
			node x=s.top();s.pop();
			fa[x.fax]=x.fax;sz[x.fay]=x.szy;
		}
		dfn=ti;
	}
}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	n=read();m=read();k=read();
	for (int i=1;i<=n;i++) c[i]=read();
	dsu::init();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		if (c[u]==c[v])
		{
			if (vi[c[u]]) continue;
			if (!dsu::add_edge(u,v)) vi[c[u]]=1;
			continue;
		}
		if (c[u]>c[v]) swap(u,v);
		e[c[u]][c[v]].push_back(m_k(u,v));
	}
	long long ans=0,all=0;
	for (int i=1;i<=k;i++) all+=(!vi[i]);
	for (int i=1;i<=k;i++)
	{
	    
		if (vi[i]) continue;
		all--;
		long long cnt=0;
		for (it=e[i].begin();it!=e[i].end();it++)
		{
			if (vi[it->first]) continue;
			cnt++;
			tmp=it->second;
			int now=dfn;bool bl=1;
			for (int j=0;j<(int)tmp.size();j++)
			{
				int x=tmp[j].first,y=tmp[j].second;
				if (!dsu::add_edge(x,y))
				{
					bl=0;
					break;
				}
			}
			if (bl) ans++;
			dsu::back(now);
		}
		ans+=all-cnt;
	}
	printf("%lld\n",ans);
}