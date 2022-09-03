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

const int maxn=200111;

int bit[maxn];
void add(int x,int v)
{
	for(;x<maxn;x+=x&-x)bit[x]+=v;
}
int query(int val)
{
	int x=0;
	for(int i=19;i>=0;i--)if((x|(1<<i))<maxn&&bit[x|(1<<i)]<val)
	{
		x|=(1<<i);
		val-=bit[x];
	}
	return x+1;
}

int n,a[maxn],q,ord[maxn],lv[maxn];
int qk[maxn],ql[maxn],ans[maxn];
vector<int> qs[maxn];
bool cmp(int x,int y){return mp(-a[x],x)<mp(-a[y],y);}

int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get1(a[i]);
		ord[i]=i;
	}
	sort(ord+1,ord+n+1,cmp);
	get1(q);
	for(int i=1;i<=q;i++)
	{
		get2(qk[i],ql[i]);
		qs[qk[i]].pb(i);
	}
	for(int i=1;i<=n;i++)
	{
		add(ord[i],1);
		for(auto id:qs[i])ans[id]=query(ql[id]);
	}
	for(int i=1;i<=q;i++)printf("%d\n",a[ans[i]]);
	return 0;
}