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
 
const int maxn=1000111;
int n,a[maxn],cnt[maxn],m;
 
bool check(int x,int y)//O(maxn/y) time
{
	LL sum=0;
	for(int i=y;i<=m;i+=y)sum+=(LL)(cnt[i+y-1]-cnt[i-1])*(i/y);
	sum-=x/y*2;
	if(sum<x)return false;
	int s1=0,s2=0,q=x%y;
	for(int i=0;i<=m;i+=y)
	{
		if(i<=x-y)continue;
		if(i>=x)
		{
			s1+=cnt[i+y-1]-cnt[i+q-1];
			s2+=cnt[i+q-1]-cnt[i-1];
		}
		else
		{
			s1+=cnt[i+y-1]-cnt[max(i+q-1,x-1)];
			s2+=cnt[max(i+q-1,x-1)]-cnt[x-1];
		}
	}
	if(s1>=2)return true;
	if(s1+s2>=2&&sum-(2-s1)>=x)return true;
	sum+=x/y*2;sum-=(x+x)/y;
	if(sum<x)return false;
	s1=s2=0;q=(x+x)%y;
	for(int i=0;i<=m;i+=y)
	{
		if(i<=x+x-y)continue;
		if(i>=x+x)
		{
			s1+=cnt[i+y-1]-cnt[i+q-1];
			s2+=cnt[i+q-1]-cnt[i-1];
		}
		else
		{
			s1+=cnt[i+y-1]-cnt[max(i+q-1,x+x-1)];
			s2+=cnt[max(i+q-1,x+x-1)]-cnt[x+x-1];
		}
	}
	if(s1)return true;
	if(s2&&sum>x)return true;
	return false;
}
 
int ord[maxn];
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get1(a[i]);
		cnt[a[i]]++;
	}
	for(int i=1;i<maxn;i++)cnt[i]+=cnt[i-1];
	
	m=*max_element(a+1,a+n+1);
	LL ans=0;
	for(int i=2;i<=m;i++)ord[i]=i;
	random_shuffle(ord+2,ord+m+1);
	for(int _=2;_<=m;_++)
	{
		int y=ord[_];
		LL tmp=(ans+y-1)/y;
		if(tmp<=m&&check(max((int)tmp,2),y))
		{
			int lb=1,rb=m+1,mid;
			while(lb<rb-1)
			{
				mid=(lb+rb)>>1;
				if(check(mid,y))lb=mid;
				else rb=mid;
			}
			if(lb>1)ans=max(ans,(LL)y*lb);
		}
	}
	printf("%lld\n",ans);
	return 0;
}