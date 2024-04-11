#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/
const int MAXN = 51,MAXM = 3000011;
ull LIM;
namespace DSU
{
	int fa[MAXM],size[MAXM];
	void init(int n){for(int i=1;i<=n;++i)fa[i]=i,size[i]=1;}
	int find(int x)
	{
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	void uni(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y)return;
		if(size[x]<size[y])fa[x]=y,size[y]+=size[x];
		else fa[y]=x,size[x]+=size[y];
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
}
std::vector<pii>g[50011];
std::map<ull,int>mp;
struct one{ull x;int v,t;};
int size=0;
namespace sgt
{
	struct node
	{
		int ls,rs;
		std::vector<one>a;
	}t[MAXM];
#define rt t[num]
	int cnt=0;
	void Modify(int& num,ull ql,ull qr,int k,ull l=0,ull r=LIM)
	{
		if(!num)num=++cnt;
		if(ql<=l&&r<=qr)
		{
			//printf("Mark [%llu,%llu] %d,t=%d\n",l,r,size+1,k);
			rt.a.push_back(one{r,++size,k}),mp[r]=size;
			return;
		}
		ull mid=(l+r)>>1;
		if(ql<=mid)Modify(rt.ls,ql,qr,k,l,mid);
		if(qr>mid)Modify(rt.rs,ql,qr,k,mid+1,r);
	}
	std::vector<one> dfs(int num,int bit,ull l=0,ull r=LIM)
	{
		if(!rt.ls&&!rt.rs)return rt.a;
		ull mid=(l+r)>>1;
		std::vector<one>lf=dfs(rt.ls,bit-1,l,mid);
		std::vector<one>rf=dfs(rt.rs,bit-1,mid+1,r);
		{
			std::vector<one> ta,tb;
			ta.swap(t[rt.ls].a);
			tb.swap(t[rt.rs].a);
		}
		int it=0;
		for(int i=0;i<rf.size();++i)
		{
			ull x=rf[i].x-(1ull<<bit);
			int v=rf[i].v;
			while(it<lf.size()&&lf[it].x<x)
			{
				g[min(lf[it].t,rf[i].t)].push_back(pii(lf[it].v,v)),++it;
			}
			if(it<lf.size())
			{
				g[min(lf[it].t,rf[i].t)].push_back(pii(lf[it].v,v));
				if(lf[it].x==x)++it;
			}
		}
		for(auto x:rf)lf.push_back(x);
		return lf;
	}
}
bool type[50011];
std::pair<ull,ull> a[50011];
bool res[50011];
struct edge
{
	ull l,r;int dex;
	bool operator< (const edge& you)const{return l<you.l;}
}b[50011];
char str[11];
int main()
{
	int n=read(),m=read(),c=0;
	LIM=(1ull<<n)-1;
	for(int i=1;i<=m;++i)
	{
		scanf("%s",str);
		if(*str=='b')
		{
			ull l,r;
			scanf("%llu%llu",&l,&r);
			b[++c]=edge{l,r,i};
		}
		else
		{
			type[i]=1;
			scanf("%llu%llu",&a[i].first,&a[i].second);
		}
	}
	ull lst=0;
	int R=0;
	std::sort(b+1,b+c+1);
	for(int i=1;i<=c;++i)
	{
		if(lst<b[i].l)sgt::Modify(R,lst,b[i].l-1,m+1);
		sgt::Modify(R,b[i].l,b[i].r,b[i].dex),lst=b[i].r+1;
	}
	if(lst<(1ull<<n))sgt::Modify(R,lst,(1ull<<n)-1,m+1);
	for(int i=1;i<=m;++i)
		if(type[i])a[i].first=mp.lower_bound(a[i].first)->second,a[i].second=mp.lower_bound(a[i].second)->second;
	mp.clear();
	sgt::dfs(1,n-1);
	DSU::init(size);
	for(int i=m+1;i;--i)
	{
		if(type[i])
		{
			res[i]= DSU::same(a[i].first,a[i].second);
		}
		for(auto x:g[i])DSU::uni(x.first,x.second);
	}
	for(int i=1;i<=m;++i)
		if(type[i])printf("%d\n",int(res[i]));
	return 0;
}