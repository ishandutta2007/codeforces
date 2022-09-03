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

#define ls a[o].ch[0]
#define rs a[o].ch[1]
struct node
{
	int ch[2],fa;
	
	int sz,vsz,val,lazy;
	LL sum,cnt;
	
	void clear(){ch[2]=fa=0;sz=vsz=sum=lazy=val=cnt=0;}
	node(){clear();}
	void add(int size)
	{
		sz+=size;
		cnt+=2ll*vsz*size;
		lazy+=size;
	}
}a[50111];

inline int gettp(const int&o){int&f=a[o].fa;return a[f].ch[0]==o?0:(a[f].ch[1]==o?1:-1);}

void pushdown(int o)
{
	if(a[o].lazy)
	{
		if(ls)a[ls].add(a[o].lazy);
		if(rs)a[rs].add(a[o].lazy);
		a[o].lazy=0;
	}
}
void pushup(int o){if(gettp(o)!=-1)pushup(a[o].fa);pushdown(o);}
void pull(int o){a[o].sum=a[ls].sum+a[rs].sum+1ll*a[o].vsz*a[o].val;}

void rotate(int o,int d)
{
	int k1=a[o].ch[d],k2=a[k1].ch[d^1];
	if(gettp(o)!=-1)a[a[o].fa].ch[gettp(o)]=k1;
	a[o].ch[d]=k2;a[k1].ch[d^1]=o;
	a[k1].fa=a[o].fa;a[o].fa=k1;a[k2].fa=o;
	pull(o);
}
void splay(int o)
{
	pushup(o);
	while(gettp(o)!=-1)
	{
		int f1=a[o].fa,f2=a[f1].fa,t1=gettp(o),t2=gettp(f1);
		if(t2==-1||f2==0)rotate(f1,t1);
		else if(t1==t2){rotate(f2,t2);rotate(f1,t1);}
		else{rotate(f1,t1);rotate(f2,t2);}
	}
	pull(o);
}
int access(int o)
{
	int k=0,tmp=o;
	while(o)
	{
//		printf("o= %d\n",o);
		if(k)
		{
			while(a[k].ch[0])k=a[k].ch[0];
			splay(k);
		}
		
		splay(o);
		a[o].vsz=a[o].sz-a[k].sz;
		rs=k;
		pull(o);
		
		k=o;o=a[o].fa;
	}
	splay(tmp);
}

LL ans;

bool anc(int u,int v)
{
	access(v);
	splay(u);
	return a[v].fa>0;
}
void link(int u,int v)
{
	access(u);
	access(v);
	ans+=2*a[u].sum*a[v].sz;
	a[u].add(a[v].sz);
	pull(u);
	a[v].fa=u;
}
void cut(int o)
{
	access(o);
	ans-=2*a[ls].sum*a[o].sz;
	if(ls)a[ls].add(-a[o].sz);
	a[ls].fa=0;ls=0;
	pull(o);
}
void modify(int o,int v)
{
	access(o);
	ans+=a[o].cnt*(v-a[o].val);
	a[o].val=v;
	pull(o);
}

int n,q;
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)a[i].sz=a[i].vsz=a[i].cnt=1;
	for(int i=2,p;i<=n;i++)
	{
		get1(p);
		link(p,i);
	}
	for(int i=1,v;i<=n;i++)
	{
		get1(v);
		modify(i,v);
	}
	get1(q);
	printf("%.10lf\n",1.0*ans/n/n);
	char op[5];
	for(int i=1,u,v;i<=q;i++)
	{
		scanf("%s%d%d",op,&u,&v);
		if(op[0]=='P')
		{
			if(anc(u,v))swap(u,v);
			cut(u);
			link(v,u);
		}
		else modify(u,v);
		printf("%.10lf\n",1.0*ans/n/n);
	}
	return 0;
}