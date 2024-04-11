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

vector<int> g[maxn],ops;
int n,p[maxn],dep[maxn],ed[maxn],nxt[maxn],tp[maxn];

void dfs(int x)
{
	int st1=-1,ed1=-1;
	for(auto v:g[x])
	{
		dep[v]=dep[x]+1;
		dfs(v);
		int st2=v,ed2=ed[v];
		if(st1==-1)
		{
			st1=st2;
			ed1=ed2;
		}
		else
		{
			if(dep[ed1]>dep[ed2])
			{
				swap(st1,st2);
				swap(ed1,ed2);
			}
			nxt[ed1]=st2;
			tp[st2]=dep[ed1]-dep[x];
			ed1=ed2;
		}
	}
//	printf("dfs %d st= %d ed= %d\n",x,st1,ed1);
	if(ed1==-1)ed1=x;
	nxt[x]=st1;
	ed[x]=ed1;
}

int main()
{
	get1(n);
	for(int i=1;i<n;i++)
	{
		get1(p[i]);
		g[p[i]].pb(i);
	}
	
	memset(nxt,-1,sizeof(nxt));
	dfs(0);
//	for(int i=0;i<n;i++)printf("i= %d nxt= %d\n",i,nxt[i]);
	int tmp=0;
	while(tmp!=-1)
	{
		printf("%d ",tmp);
		while(tp[tmp]--)ops.pb(tmp);
		tmp=nxt[tmp];
	}
	puts("");
	printf("%d\n",(int)ops.size());
	for(int i=0;i<(int)ops.size();i++)printf("%d ",ops[i]);
	return 0;
}