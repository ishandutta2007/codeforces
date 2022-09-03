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
int n,k,p,h[maxn],a[maxn];

LL cur[maxn],m;

bool check(LL val)
{
//	printf("val= %lld\n",val);
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	for(int i=1;i<=n;i++)
	{
		cur[i]=val;
		if(cur[i]-m*a[i]<0)pq.push(mp(int(cur[i]/a[i]),i));
	}
	LL need=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(pq.empty())
			{
				need++;
				continue;
			}
			if(pq.top().ff<i)return false;
			int x=pq.top().ss;pq.pop();
			cur[x]+=p;
			if(cur[x]-m*a[x]<0)pq.push(mp(int(cur[x]/a[x]),x));
		}
	}
	if(!pq.empty())return false;
	for(int i=1;i<=n;i++)
	{
		if(cur[i]-m*a[i]>=h[i])continue;
		need-=(h[i]-cur[i]+m*a[i]+p-1)/p;
		if(need<0)return false;
	}
	return true;
}

int main()
{
	get3(n,m,k);get1(p);
	for(int i=1;i<=n;i++)get2(h[i],a[i]);
	
	LL lb=0,rb=100000000000000ll,mid;
	while(lb<rb-1)
	{
		mid=(lb+rb)>>1;
		if(check(mid))rb=mid;
		else lb=mid;
	}
	printendl(rb);
	return 0;
}