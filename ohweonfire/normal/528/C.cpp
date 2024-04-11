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

const int maxn=100111;
const int maxm=300111;

int head[maxn],nxt[maxm<<1],to[maxm<<1],etot=1;
void addedge(int u,int v)
{
//	printf("edge %d %d\n",u,v);
	nxt[++etot]=head[u];head[u]=etot;to[etot]=v;
	nxt[++etot]=head[v];head[v]=etot;to[etot]=u;
}

int n,m,dgr[maxn];

int iter[maxn];
bool use[maxm];

vector<int> vs;
void dfs(int x)
{
	for(int&i=iter[x];i;i=nxt[i])if(!use[i>>1])
	{
		use[i>>1]=1;
		dfs(to[i]);
	}
	vs.pb(x);
}

int main()
{
	get2(n,m);
	for(int i=1,u,v;i<=m;i++)
	{
		get2(u,v);addedge(u,v);
		dgr[u]++;dgr[v]++;
	}
	
	int tmp=0;
	for(int i=1;i<=n;i++)if(dgr[i]%2==1)
	{
		if(tmp)
		{
			addedge(i,tmp);
			tmp=0;
		}
		else tmp=i;
	}
	
	if(etot%4==3)addedge(1,1);
	memcpy(iter,head,sizeof(head));
	
	dfs(1);
	printf("%d\n",etot/2);
	for(int i=1;i<(int)vs.size();i+=2)
	{
		printf("%d %d\n",vs[i],vs[i-1]);
		printf("%d %d\n",vs[i],vs[i+1]);
	}
	
	return 0;
}