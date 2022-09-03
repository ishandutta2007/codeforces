// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
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

const int sigma=27;
const int maxn=200111;

#define ls a[t].ch[0]
#define rs a[t].ch[1]
namespace SGT
{
	struct node
	{
		int ch[2];
		pii mx;
		node(){ch[0]=ch[1]=0;mx=mp(0,-inf);}
	};
	node a[10000111];
	int tot;
	
	void add(int p,int v,int tl,int tr,int t)
	{
		if(tl==tr)
		{
			a[t].mx=mp(a[t].mx.ff+v,-p);
			return;
		}
		int mid=(tl+tr)>>1;
		if(p<=mid)
		{
			if(!ls)ls=++tot;
			add(p,v,tl,mid,ls);
		}
		else
		{
			if(!rs)rs=++tot;
			add(p,v,mid+1,tr,rs);
		}
		a[t].mx=max(a[ls].mx,a[rs].mx);
	}
	int merge(int x,int y,int tl,int tr)
	{
		if(!x||!y)return x|y;
		int t=++tot;
		if(tl==tr)
		{
			a[t].mx=mp(a[x].mx.ff+a[y].mx.ff,-tl);
			return t;
		}
		int mid=(tl+tr)>>1;
		if(!a[x].ch[0]||!a[y].ch[0])ls=a[x].ch[0]|a[y].ch[0];
		else ls=merge(a[x].ch[0],a[y].ch[0],tl,mid);
		if(!a[x].ch[1]||!a[y].ch[1])rs=a[x].ch[1]|a[y].ch[1];
		else rs=merge(a[x].ch[1],a[y].ch[1],mid+1,tr);
		a[t].mx=max(a[ls].mx,a[rs].mx);
		return t;
	}
	pii query(int l,int r,int tl,int tr,int t)
	{
		if(l<=tl&&tr<=r)return a[t].mx;
		int mid=(tl+tr)>>1;pii ret=mp(0,-l);
		
		if(l<=mid&&ls)ret=max(ret,query(l,r,tl,mid,ls));
		if(r>mid&&rs)ret=max(ret,query(l,r,mid+1,tr,rs));
		return ret;
	}
	void debug(int tl,int tr,int t)
	{
		if(!t)return;
		printf("t= %d tl= %d tr= %d mx= %d %d\n",t,tl,tr,a[t].mx.ff,-a[t].mx.ss);
		int mid=(tl+tr)>>1;
		debug(tl,mid,ls);
		debug(mid+1,tr,rs);
	}
};

struct sam
{
	int go[sigma];
	int val,fa,belong;
	sam(int val=0){fa=belong=0;this->val=val;memset(go,0,sizeof(go));}
};
sam a[maxn];

int tot,root,last;
int newnode(int v){a[++tot]=sam(v);return tot;}
void append(int ch,int id)
{
	int p=last,np=newnode(a[p].val+1);a[np].belong=id;
//	printf("append %d %d np= %d\n",ch,id,np);
	while(p&&!a[p].go[ch])
	{
		a[p].go[ch]=np;
		p=a[p].fa;
	}
	if(!p)a[np].fa=root;
	else
	{
		int q=a[p].go[ch];
		if(a[p].val+1==a[q].val)a[np].fa=q;
		else
		{
			int nq=newnode(a[p].val+1);
			memcpy(a[nq].go,a[q].go,sizeof(a[q].go));
			a[nq].fa=a[q].fa;
			a[np].fa=a[q].fa=nq;
			while(p&&a[p].go[ch]==q)
			{
				a[p].go[ch]=nq;
				p=a[p].fa;
			}
		}
	}
	last=np;
}


char s[500111],t[50111];
int n,m,f[20][maxn],sgt[maxn];

vector<int> g[maxn];
void dfs(int x)
{
	sgt[x]=++SGT::tot;
	if(a[x].belong)SGT::add(a[x].belong,1,1,m,sgt[x]);
	for(auto v:g[x])
	{
		dfs(v);
		sgt[x]=SGT::merge(sgt[x],sgt[v],1,m);
	}
//	printf("x= %d fa= %d belong = %d\n",x,a[x].fa,a[x].belong);
//	SGT::debug(1,m,sgt[x]);
//	puts("");
}

int match[500111],len[500111];
void prework()
{
	root=last=newnode(0);
	get1(m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",t+1);int l=strlen(t+1);
		for(int j=1;j<=l;j++)
			append(t[j]-'a',i);
		append(26,0);
	}
	for(int i=1;i<=tot;i++)
	{
		f[0][i]=a[i].fa;
		if(a[i].fa)g[a[i].fa].pb(i);
//		for(int j=0;j<sigma;j++)if(a[i].go[j])
//			printf("%d %d %c\n",i,a[i].go[j],j+'a');
	}
	for(int i=1;i<20;i++)for(int j=1;j<=tot;j++)f[i][j]=f[i-1][f[i-1][j]];
	
	int p=root,cur=0;
	for(int i=1;i<=n;i++)
	{
		int ch=s[i]-'a';
		if(a[p].go[ch])
		{
			cur++;
			p=a[p].go[ch];
		}
		else
		{
			while(p&&!a[p].go[ch])p=a[p].fa;
			if(!p)p=root,cur=0;
			else cur=a[p].val+1,p=a[p].go[ch];
		}
		match[i]=p;len[i]=cur;
	}
	dfs(root);
}

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	
	prework();
	int q,l,r,pl,pr;get1(q);
	while(q--)
	{
		get2(l,r);get2(pl,pr);pl=pr-pl+1;
		if(len[pr]<pl)printf("%d 0\n",l);
		else
		{
			int tmp=match[pr];
			for(int i=19;i>=0;i--)if(a[f[i][tmp]].val>=pl)
				tmp=f[i][tmp];
//			printf("tmp= %d\n",tmp);
			pii ans=SGT::query(l,r,1,m,sgt[tmp]);
			printf("%d %d\n",-ans.ss,ans.ff);
		}
	}
	return 0;
}