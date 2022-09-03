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
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxl=600111;
const int maxn=300111;

namespace suffix
{
	int sa[maxl],t[maxl],t2[maxl],c[maxl],n;
	int rk[maxl],v[20][maxl],lg[maxl];
	void construct_sa(char*s)
	{
		int *x=t,*y=t2,m=256;
		for(int i=0;i<m;i++)c[i]=0;
		for(int i=0;i<n;i++)c[x[i]=s[i]]++;
		for(int i=1;i<m;i++)c[i]+=c[i-1];
		for(int i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
		
		for(int k=1;k<=n;k<<=1)
		{
			int p=0;
			for(int i=n-k;i<n;i++)y[p++]=i;
			for(int i=0;i<n;i++)if(sa[i]>=k)y[p++]=sa[i]-k;
			for(int i=0;i<m;i++)c[i]=0;
			for(int i=0;i<n;i++)c[x[y[i]]]++;
			for(int i=1;i<m;i++)c[i]+=c[i-1];
			for(int i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
			swap(x,y);
			x[sa[0]]=0;p=1;
			for(int i=1;i<n;i++)x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?p-1:p++;
			if(p>=n)break;
			m=p;
		}
	}
	void construct_lcp(char*s)
	{
		int k=0;
		for(int i=0;i<n;i++)rk[sa[i]]=i;
		for(int i=0;i<n-1;i++)
		{
			if(k)k--;
			int j=sa[rk[i]-1];
			while(s[i+k]==s[j+k])k++;
			v[0][rk[i]]=k;
		}
		for(int i=2;i<n;i++)lg[i]=lg[i>>1]+1;
		for(int i=1;i<20;i++)
		{
			for(int j=2;j<n;j++)
			{
				int nxt=j+(1<<i-1);
				if(nxt>=n)v[i][j]=v[i-1][j];
				else v[i][j]=min(v[i-1][j],v[i-1][nxt]);
			}
		}
	}
	int qlcp(int l,int r)
	{
		if(l==r)return n-l;
		l=rk[l];
		r=rk[r];
		if(l>r)swap(l,r);l++;
		int t=lg[r-l+1];
		return min(v[t][l],v[t][r-(1<<t)+1]);
	}
};
char s[maxn],S[maxl];

int n,q,head[maxn],nxt[maxn<<1],to[maxn<<1],etot;
void addedge(int u,int v)
{
	nxt[++etot]=head[u];head[u]=etot;to[etot]=v;
	nxt[++etot]=head[v];head[v]=etot;to[etot]=u;
}
int dfn[maxn],top[maxn],timer,sz[maxn],dep[maxn],fa[maxn],son[maxn],seq[maxn];
void dfs(int x,int f,int d)
{
	dep[x]=d;fa[x]=f;sz[x]=1;
	for(int i=head[x];i;i=nxt[i])if(to[i]!=f)
	{
		dfs(to[i],x,d+1);
		sz[x]+=sz[to[i]];
		if(sz[son[x]]<sz[to[i]])son[x]=to[i];
	}
}
void dfs2(int x,int tp)
{
	top[x]=tp;dfn[x]=++timer;S[dfn[x]-1]=S[n+n-dfn[x]]=s[x];seq[timer]=x;
	if(son[x])dfs2(son[x],tp);
	for(int i=head[x];i;i=nxt[i])if(to[i]!=fa[x]&&to[i]!=son[x])dfs2(to[i],to[i]);
}

vector<pii> calc_path(int u,int v)
{
	vector<pii> pre,suf;
//	printf("path %d %d\n",u,v);
	while(true)
	{
		if(top[u]==top[v])
		{
			if(dfn[u]<=dfn[v])pre.pb(mp(dfn[u]-1,dfn[v]-1));
			else suf.pb(mp(n+n-dfn[u],n+n-dfn[v]));
			break;
		}
		if(dep[top[u]]>dep[top[v]])
		{
			pre.pb(mp(n+n-dfn[u],n+n-dfn[top[u]]));
			u=fa[top[u]];
		}
		else
		{
			suf.pb(mp(dfn[top[v]]-1,dfn[v]-1));
			v=fa[top[v]];
		}
	}
	for(int i=(int)suf.size()-1;i>=0;i--)pre.pb(suf[i]);
//	for(auto v:pre)printf("%d %d\n",v.ff+1,v.ss+1);
	return pre;
}

int main()
{
	get1(n);scanf("%s",s+1);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		addedge(u,v);
	}
	dfs(1,0,0);
	dfs2(1,1);
	suffix::n=n+n+1;
	suffix::construct_sa(S);
	suffix::construct_lcp(S);
//	for(int i=1;i<=n;i++)printf("%d ",seq[i]);for(int i=n;i>=1;i--)printf("%d ",seq[i]);puts("");
	get1(q);
	for(int i=1,a,b,c,d;i<=q;i++)
	{
		get2(a,b);get2(c,d);
		vector<pii> v1=calc_path(a,b),v2=calc_path(c,d);
		int s1=0,s2=0,len=0,it1=0,it2=0;
		while(true)
		{
			while(it1<(int)v1.size()&&s1+v1[it1].ss-v1[it1].ff+1<=len)
			{
				s1+=v1[it1].ss-v1[it1].ff+1;
				it1++;
			}
			if(it1==(int)v1.size())break;
			while(it2<(int)v2.size()&&s2+v2[it2].ss-v2[it2].ff+1<=len)
			{
				s2+=v2[it2].ss-v2[it2].ff+1;
				it2++;
			}
			if(it2==(int)v2.size())break;
			int st1=v1[it1].ff+len-s1,st2=v2[it2].ff+len-s2,nl=min(v1[it1].ss-st1+1,v2[it2].ss-st2+1),lcp=min(nl,suffix::qlcp(st1,st2));
//			printf("st1= %d st2= %d\n",st1+1,st2+1);
			len+=lcp;
			if(lcp!=nl)break;
		}
		printf("%d\n",len);
	}
	
	return 0;
}