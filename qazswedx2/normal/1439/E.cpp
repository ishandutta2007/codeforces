#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
struct pt
{
	int x,y,id;
	ll v;
	pt(int x=0,int y=0,int id=0):x(x),y(y),id(id){v=0;}
	bool operator<(const pt p) const
	{
		if(x!=p.x) return x<p.x;
		return y<p.y;
	}
}a[500005];
struct edge
{
	int v,nxt;
}e[1000005];
int n,at,st[500005],tp,d[500005],e2[100005][2],h[500005],t,ff[500005],g[500005];
int gg[500005];
pt tmp[100005][2];
ll f[105];
map<pt,int> mp;
map<int,int> mp2;
void add(int u,int v)
{
//	if(u<v) printf("add:%d %d\n",u,v);
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
bool cmp(const pt x,const pt y)
{
	return x.v<y.v;
}
ll getdfn(pt p,int k,ll val)
{
	if(!k) return 1;
	int fl=((p.y>>(k-1))&1)*2+((p.x>>(k-1))&1);
	if(fl==0) return getdfn(p,k-1,val+f[k-1]);
	if(fl==1) return getdfn(p,k-1,val)+(1<<(k-1));
	if(fl==2) return getdfn(p,k-1,0)+f[k-1]*2+val;
	return -1;
}
int getps(pt p,int k)
{
	if(!k) return 0;
	int fl=((p.y>>(k-1))&1)*2+((p.x>>(k-1))&1);
	if(fl==0) return getps(p,k-1);
	if(fl==1) return getps(p,k-1)+(1<<(k-1));
	if(fl==2) return 0;
	return -1;
}
int getdep(pt p,int k)
{
	if(!k) return 1;
	int fl=((p.y>>(k-1))&1)*2+((p.x>>(k-1))&1);
	return getdep(p,k-1)+(fl?(1<<(k-1)):0);
}
pt lca(pt u,pt v)
{
//	printf("lca:u=%d,%d,v=%d,%d\n",u.x,u.y,v.x,v.y);
	for(int i=30;i>=0;i--)
	{
		int flu=((u.y>>i)&1)*2+((u.x>>i)&1);
		int flv=((v.y>>i)&1)*2+((v.x>>i)&1);
		if(flu!=flv)
		{
	//		printf("fl=%d,%d,i=%d\n",flu,flv,i);
			if(flu&&flv)
				return pt((u.x>>(i+1))<<(i+1),(u.y>>(i+1))<<(i+1));
			if(flv==0) swap(u,v),swap(flu,flv);
			int ffl=0;
			if(flv==2)
			{
				ffl=1;
				swap(u.x,u.y),swap(v.x,v.y);
			}
			pt ans=pt((u.x>>(i+1))<<(i+1),(u.y>>(i+1))<<(i+1));
			ans.x+=getps(pt(u.x-ans.x,u.y-ans.y),31);
			if(ffl) swap(ans.x,ans.y);
			return ans;
		}
	}
//	printf("lca!!!");
	return u;
}
void ins(pt p)
{
	if(!mp.count(p))
	{
		mp[p]=++at;
		a[at]=p;
		d[at]=getdep(a[at],31);
	}
}
void dfs(int u,int fa)
{
//	printf("dfs:u=%d,fa=%d\n",u,fa);
	ff[u]=fa;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
	}
}
void dfs2(int u,int fa)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u);
		g[u]+=g[v];
		gg[u]+=gg[v]; 
	}
//	printf("u=%d,g=%d,gg=%d,d=%d\n",u,g[u],gg[u],d[u]);
	if(g[u]&&gg[u])
	{
		mp2[d[u]]++;
		mp2[d[fa]]++;
	}
	else if(gg[u])
	{
		mp2[d[u]]++;
		mp2[d[u]-1]++;
	}
}
int main()
{
//	pt qwq=lca(pt(5,0),pt(8,1));
//	printf("%d %d\n",qwq.x,qwq.y);
	f[0]=1;
	for(int i=1;i<=30;i++)
		f[i]=f[i-1]*3;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		pt u,v;
		scanf("%d%d%d%d",&u.x,&u.y,&v.x,&v.y);
		ins(u),ins(v);
		tmp[i][0]=u,tmp[i][1]=v;
	}
	int att=at;
	for(int i=1;i<=at;i++)
		a[i].v=getdfn(a[i],31,0);
	sort(a+1,a+at+1,cmp);
	for(int i=1;i<=at;i++)
	{
		mp[a[i]]=i;
		d[i]=getdep(a[i],31);
	}
	for(int i=1;i<=n;i++)
		e2[i][0]=mp[tmp[i][0]],e2[i][1]=mp[tmp[i][1]];
	ins(pt(0,0));
	st[1]=mp[pt(0,0)];
	tp=1;
	for(int i=1;i<=att;i++)
	{
		if(a[i].x==0&&a[i].y==0)
			continue;
		pt lp=lca(a[st[tp]],a[i]);
		int l;
		ins(lp);
		l=mp[lp];
		/*printf("i=%d,l=%d,lp=%d,%d,tp=%d\n",i,l,lp.x,lp.y,tp);
		for(int j=1;j<=tp;j++)
			printf("%d ",st[j]);
		printf("\n");*/
		while(tp>1&&d[st[tp-1]]>=d[l])
		{
			add(st[tp],st[tp-1]);
			add(st[tp-1],st[tp]);
			tp--;
		}
	/*	printf("d=%d,%d,a=%d,%d,a=%d,%d\n",d[st[tp]],d[l],a[st[tp]].x,a[st[tp]].y,a[l].x,a[l].y);
		for(int j=1;j<=tp;j++)
			printf("%d ",st[j]);
		printf("\n");*/
		if(tp&&d[st[tp]]>d[l])
		{
			add(st[tp],l);
			add(l,st[tp]);
			st[tp]=l;
		}
	/*	for(int j=1;j<=tp;j++)
			printf("%d ",st[j]);
		printf("\n");*/
		st[++tp]=i;
	}
	while(tp>1)
	{
		add(st[tp],st[tp-1]);
		add(st[tp-1],st[tp]);
		tp--;
	}
	dfs(mp[pt(0,0)],0);
	for(int i=1;i<=n;i++)
	{
		int u=e2[i][0],v=e2[i][1];
		int l=mp[lca(a[u],a[v])];
	//	printf("i=%d,u=%d,v=%d,l=%d,ff=%d\n",i,u,v,l,ff[l]);
		g[u]++,g[v]++,g[l]-=2;
		gg[u]++,gg[v]++,gg[l]--,gg[ff[l]]--;
	}
	dfs2(mp[pt(0,0)],0);
	int ans=0;
	for(map<int,int>::iterator it=mp2.begin();it!=mp2.end();it++)
	{
	//	printf("it=%d,%d\n",it->first,it->second);
		if(it->first==0) continue;
		ans+=it->second%2;
	}
	printf("%d\n",ans);
	return 0;
}