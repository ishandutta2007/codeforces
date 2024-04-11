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

const int maxn=311;
int n,k,a[maxn],b[maxn];

int query(int l,int r)
{
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int ret;get1(ret);if(ret==-1)for(;;);
	return ret;
}

int main()
{
	get2(n,k);
	
	if(k+k!=n-1&&k+k!=n+1)
	{
		for(int i=1;i<=n;i++)
		{
			int qq;
			while(true)
			{
				query(i,i);
				qq=query(i,i);
				if(qq!=k)break;
			}
			if(qq==n-k-1)a[i]=0;else a[i]=1;
			while(qq!=k)
			{
				query(i,i);
				qq=query(i,i);
			}
		}
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			int qq;
			while(true)
			{
				query(i,i+1);
				qq=query(i,i+1);
				if(qq!=k)break;
			}
			if(qq==n-k)b[i]=1;else b[i]=0;
			while(qq!=k)
			{
				query(i,i+1);
				qq=query(i,i+1);
			}
		}
		int cur=k&1;
		for(int i=1;i<n;i+=2)cur^=b[i];
		a[n]=cur;
		for(int i=n-1;i>=1;i--)a[i]=a[i+1]^b[i];
	}
	printf("! ");for(int i=1;i<=n;i++)printf("%d",a[i]);puts("");
	fflush(stdout);
	return 0;
}