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

const int maxn=500111;

vector<int> vs[maxn];
int f[maxn],T[maxn];
LL val[maxn],val2[maxn];

void pushdown(int t,int time)
{
	for(auto v:vs[t])
	{
		if(T[v]<val[t])val2[v]=val[t];
		T[v]=time;
	}
}
void merge(int t1,int t2,int time)
{
//	printf("merge %d %d\n",t1,t2);
	if((int)vs[t1].size()<(int)vs[t2].size())swap(t1,t2);
	pushdown(t2,time);
	for(auto v:vs[t2])
	{
		vs[t1].pb(v);
		f[v]=t1;
	}
	vs[t2].clear();
}
void merge2(int t1,int t2)
{
	if((int)vs[t1].size()<(int)vs[t2].size())swap(t1,t2);
	LL dlt=val[t2]-val[t1];
	for(auto v:vs[t2])
	{
		vs[t1].pb(v);
		f[v]=t1;
		val2[v]+=dlt;
	}
	vs[t2].clear();
}

int n,m,tp[maxn],a[maxn],b[maxn];
LL ans[maxn];
vector<int> sub[maxn];

int main()
{
	get2(n,m);
	
	char op[5];
	for(int i=1;i<=m;i++)
	{
		scanf("%s",op);
		if(op[0]=='U')
		{
			tp[i]=0;
			get2(a[i],b[i]);
		}
		else if(op[0]=='M')
		{
			tp[i]=1;
			get2(a[i],b[i]);
		}
		else if(op[0]=='A')
		{
			tp[i]=2;
			get1(a[i]);
		}
		else if(op[0]=='Z')
		{
			tp[i]=3;
			get1(a[i]);
		}
		else
		{
			tp[i]=4;
			get1(a[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		vs[i].pb(i);
	}
	
	for(int i=1;i<=m;i++)
	{
		if(tp[i]==1)merge(f[a[i]],f[b[i]],i);
		else if(tp[i]==3)val[f[a[i]]]=i;
		else if(tp[i]==4)
		{
			int last;
			if(T[a[i]]<val[f[a[i]]])last=val[f[a[i]]];
			else last=val2[a[i]];
//			printf("i= %d a= %d f= %d last= %d\n",i,a[i],f[a[i]],last);
			sub[last].pb(i);
		}
	}
	memset(val,0,sizeof(val));
	memset(val2,0,sizeof(val2));
	for(int i=1;i<=n;i++)
	{
		vs[i].clear();vs[i].pb(i);
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		for(auto v:sub[i])ans[v]-=val[f[a[v]]]+val2[a[v]];
		if(tp[i]==0)merge2(f[a[i]],f[b[i]]);
		else if(tp[i]==2)
		{
			int sz=(int)vs[f[a[i]]].size();
			val[f[a[i]]]+=sz;
		}
		else if(tp[i]==4)printf("%lld\n",ans[i]+val[f[a[i]]]+val2[a[i]]);
//		for(int j=1;j<=n;j++)printf("%4d ",val[f[j]]+val2[j]);puts("");
	}
	
	return 0;
}