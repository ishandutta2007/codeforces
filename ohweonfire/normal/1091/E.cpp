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

int n,a[maxn],pos[maxn],cnt[maxn];
LL sum[maxn];

bool check_k(int k,int pr)
{
	if(pr+sum[n]&1)return false;
	LL val=sum[k]-min(k,pr)-(LL)k*(k-1);
	int p=max(pos[k],k);
	val-=(LL)k*(p-k)+sum[n]-sum[p];
	val+=max(0,pr-p);
	return (val<=0);
}

int main()
{
	get1(n);
	for(int i=1,x;i<=n;i++)
	{
		get1(x);
		if(x>n)
		{
			puts("-1");
			return 0;
		}
		cnt[x]++;
	}
	int nn=0;
	for(int i=n;i>=1;i--)while(cnt[i]--)a[++nn]=i;
	n=nn;
	
	if(n==0)
	{
		puts("0");
		return 0;
	}
	
	pos[0]=n;
	for(int i=1;i<=n;i++)
	{
		pos[i]=pos[i-1];
		while(pos[i]&&a[pos[i]]<=i)pos[i]--;
	}
	
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	
	int lb=0,rb=n;
	for(int i=1;i<=n;i++)
	{
		while(lb<=rb&&!check_k(i,lb))lb++;
		while(lb<=rb&&!check_k(i,rb))rb--;
	}
	
	if(lb>rb)puts("-1");
	else for(int i=lb;i<=rb;i+=2)printf("%d ",i);
	return 0;
}