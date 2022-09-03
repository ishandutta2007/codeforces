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

bitset<1250011> dp[25];
int n,a[55];
bool choose[55];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n+n;i++)scanf("%d",a+i);
	sort(a+1,a+n+n+1);reverse(a+1,a+n+n+1);
	
	int sum=0,mn=inf,mnv,mnt;
	for(int i=1;i<n+n;i++)sum+=a[i];dp[0].set(0);
	for(int i=1;i<n+n;i++)
	{
		for(int j=0;j<=1250000;j++)if(dp[n-1].test(j))
		{
			int cur=max(j,sum-a[i]-j)+a[n+n]+a[i];
			if(cur<mn)
			{
				mn=cur;
				mnv=i;
				mnt=j;
			}
		}
		for(int j=min(i,n-1);j>=1;j--)dp[j]|=(dp[j-1]<<a[i]);
	}
	
	choose[mnv]=1;
	for(int t=n-1;t>=1;t--)
	{
		for(int i=0;i<n;i++)dp[i].reset();
		dp[0].set(0);
		for(int i=1;i<mnv;i++)
		{
			for(int j=min(i,n-1);j>=1;j--)dp[j]|=(dp[j-1]<<a[i]);
			if(dp[t].test(mnt))
			{
				choose[i]=1;
				mnt-=a[i];
				break;
			}
		}
	}
	for(int i=n+n;i>=1;i--)if(!choose[i])printf("%d ",a[i]);puts("");
	for(int i=1;i<=n+n;i++)if(choose[i])printf("%d ",a[i]);puts("");
	return 0;
}