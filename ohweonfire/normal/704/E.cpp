// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=100111;

struct frac
{
	LL a,b;
	frac(){a=0;b=1;}
	frac(LL k1,LL k2)
	{
		assert(k2>0);
		a=k1;b=k2;
		LL g=__gcd(abs(a),b);
		a/=g;b/=g;
	}
	frac operator +(const frac&t)const
	{
		if(b==t.b)return frac(a+t.a,b);
		else return frac(a*t.b+b*t.a,b*t.b);
	}
	frac operator -(const frac&t)const
	{
		if(b==t.b)return frac(a-t.a,b);
		else return frac(a*t.b-b*t.a,b*t.b);
	}
	frac operator *(const frac&t)const{return frac(a*t.a,b*t.b);}
	frac operator *(const LL&t)const{return frac(a*t,b);}
	frac operator +=(const frac&t){return *this=(*this+t);}
	frac operator /(const LL&t)const
	{
		if(t<0)return frac(-a,-b*t);
		else return frac(a,b*t);
	}
	bool operator <(const frac&t)const{return (LL)a*t.b<(LL)b*t.a;}
	bool operator ==(const frac&t)const{return (LL)a*t.b==(LL)b*t.a;}
	bool operator <=(const frac&t)const{return (LL)a*t.b<=(LL)b*t.a;}
};

vector<int> g[maxn];
int n,m,dep[maxn],fa[maxn],top[maxn],sz[maxn],son[maxn];
void dfs(int x)
{
	sz[x]=1;
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=fa[x])
	{
		fa[g[x][i]]=x;dep[g[x][i]]=dep[x]+1;
		dfs(g[x][i]);
		sz[x]+=sz[g[x][i]];
		if(sz[son[x]]<sz[g[x][i]])son[x]=g[x][i];
	}
}
void dfs2(int x,int tp)
{
	top[x]=tp;
	if(son[x])dfs2(son[x],tp);
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=fa[x]&&g[x][i]!=son[x])dfs2(g[x][i],g[x][i]);
}
void prework()
{
	dfs(1);
	dfs2(1,1);
}

frac piv_t;
struct Seg
{
	frac xl,xr;int yl,speed;
	frac get(const frac&t)const{return frac(yl,1)+(t-xl)*speed;}
	bool operator <(const Seg&b)const{return get(piv_t)<b.get(piv_t);}
};
vector<Seg> qs[maxn];

vector<pair<int,pii> > get_path(int u,int v)
{
	vector<pair<int,pii> > vs,vs2;
	while(true)
	{
		if(top[u]==top[v])
		{
			vs.pb(mp(top[u],mp(dep[u]-dep[top[u]],dep[v]-dep[top[u]])));
			break;
		}
		if(dep[top[u]]>dep[top[v]])
		{
			vs.pb(mp(top[u],mp(dep[u]-dep[top[u]],-1)));
			u=fa[top[u]];
		}
		else
		{
			vs2.pb(mp(top[v],mp(-1,dep[v]-dep[top[v]])));
			v=fa[top[v]];
		}
	}
	for(int i=(int)vs2.size()-1;i>=0;i--)vs.pb(vs2[i]);
	return vs;
}
void add_path(int u,int v,int t,int c)
{
	vector<pair<int,pii> > vs=get_path(u,v);
	frac cur_t(t,1);
	for(int i=0;i<(int)vs.size();i++)
	{
		int len=abs(vs[i].ss.ff-vs[i].ss.ss);
//		printf("top= %d lb= %d rb= %d curt= %d/%d\n",vs[i].ff,vs[i].ss.ff,vs[i].ss.ss,cur_t.a,cur_t.b);
		qs[vs[i].ff].pb(Seg{cur_t,cur_t+frac(len,c),vs[i].ss.ff,vs[i].ss.ff<vs[i].ss.ss?c:-c});
		cur_t+=frac(len,c);
	}
}

set<pair<Seg,int> > st;
frac intersect(const Seg&a,const Seg&b)
{
	if(a.speed==b.speed)
	{
		if(a.get(frac(0,1))==b.get(frac(0,1)))
		{
			if(a.xl<=b.xl&&b.xl<=a.xr)return b.xl;
			else if(b.xl<=a.xl&&a.xl<=b.xr)return a.xl;
		}
		return frac(1000000,1);
	}
	frac ret=(a.get(frac(0,1))-b.get(frac(0,1)))/(b.speed-a.speed);
	if(a.xl<=ret&&ret<=a.xr&&b.xl<=ret&&ret<=b.xr)return ret;
	else return frac(1000000,1);
}
frac do_query(vector<Seg>&v)
{
	/*puts("do");
	for(int i=0;i<(int)v.size();i++)
	{
		printf("lt= %.2lf rt= %.2lf lv= %d speed= %d\n",1.0*v[i].xl.a/v[i].xl.b,1.0*v[i].xr.a/v[i].xr.b,v[i].yl,v[i].speed);
	}*/
	frac now(1000000,1);
	vector<pair<frac,int> >Ev;
//	for(int i=0;i<(int)v.size();i++)for(int j=i+1;j<(int)v.size();j++)now=min(now,intersect(v[i],v[j]));
//	return now;
	st.clear();
	for(int i=0;i<(int)v.size();i++)
	{
		Ev.pb(mp(v[i].xl,i));
		Ev.pb(mp(v[i].xr,i+(int)v.size()));
	}
	sort(Ev.begin(),Ev.end());
	for(int i=0;i<(int)Ev.size()&&Ev[i].ff<now;i++)
	{
		piv_t=Ev[i].ff;
		int id=Ev[i].ss%(int)v.size();
		if(Ev[i].ss<(int)v.size())
		{
//			printf("add %d\n",id);
			st.insert(mp(v[id],id));
			auto it=st.find(mp(v[id],id));
			if(it!=st.begin())
			{
				it--;
//				printf("check %d %d\n",id,it->ss);
				now=min(now,intersect(it->ff,v[id]));
				it++;
			}
			it++;
			if(it!=st.end())
			{
//				printf("check %d %d\n",id,it->ss);
				now=min(now,intersect(it->ff,v[id]));
			}
		}
		else
		{
//			printf("remove %d\n",id);
			auto it=st.find(mp(v[id],id));it++;
			st.erase(mp(v[id],id));
			if(it!=st.end()&&it!=st.begin())
			{
				int id1=it->ss,id2;it--;id2=it->ss;
				now=min(now,intersect(v[id1],v[id2]));
//				printf("check %d %d\n",id1,id2);
			}
		}
	}
//	printf("ret= %.10lf\n",1.0*now.a/now.b);
	return now;
}

int main()
{
	get2(n,m);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	prework();
	
	for(int i=1,t,c,u,v;i<=m;i++)
	{
		get2(t,c);get2(u,v);
		add_path(u,v,t,c);
	}
	
	frac ans(1000000,1);
	for(int i=1;i<=n;i++)if(qs[i].size())ans=min(ans,do_query(qs[i]));
	if(ans==frac(1000000,1))puts("-1");
	else printf("%.10lf\n",ans.a*1.0/ans.b);
	return 0;
}