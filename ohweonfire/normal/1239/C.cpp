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

int bit[maxn];
void add(int x,int v){for(;x<maxn;x+=x&-x)bit[x]+=v;}
int query(int x)
{
	int ret=0;
	for(;x;x-=x&-x)ret+=bit[x];
	return ret;
}

int n;
LL p,t[maxn],ans[maxn];
int main()
{
	get2(n,p);
	for(int i=1;i<=n;i++)get1(t[i]);
	priority_queue<pair<LL,int>,vector<pair<LL,int> >,greater<pair<LL,int> > >boil,star;
	priority_queue<int,vector<int>,greater<int> >wait;
	for(int i=1;i<=n;i++)star.push(mp(t[i],i));
	LL boil_t=0;
	while(!wait.empty()||!boil.empty()||!star.empty())
	{
		LL mnt=Linf;
		if(!boil.empty())mnt=min(mnt,boil.top().ff);
		if(!star.empty())mnt=min(mnt,star.top().ff);
		while(!star.empty()&&mnt==star.top().ff)
		{
			int x=star.top().ss;star.pop();
			wait.push(x);
		}
		while(!boil.empty()&&mnt==boil.top().ff)
		{
			int x=boil.top().ss;ans[x]=boil.top().ff;
			boil.pop();
			add(x,-1);
		}
		if(!wait.empty())
		{
			int x=wait.top();
			if(!query(x))
			{
				boil.push(mp(boil_t=max(mnt,boil_t)+p,x));
				add(x,1);
				wait.pop();
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
	return 0;
}