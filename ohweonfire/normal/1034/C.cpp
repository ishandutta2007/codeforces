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
const int mod=1e9+7;

int n,a[maxn],p[maxn],dp[maxn];
LL s[maxn];

int cnt[maxn];
void prework()
{
	for(int i=1;i<=n;i++)
	{
		LL tmp=s[1]/__gcd(s[1],s[i]);
		if(tmp<=n)cnt[tmp]++;
	}
	for(int i=n;i>=1;i--)for(int j=i+i;j<=n;j+=i)cnt[j]+=cnt[i];
}

int main()
{
	get1(n);
	for(int i=1;i<=n;i++)get1(a[i]);
	for(int i=2;i<=n;i++)get1(p[i]);
	for(int i=n;i>=1;i--)
	{
		s[i]+=a[i];
		s[p[i]]+=s[i];
	}
	
	prework();
	
	int ans=0;
	dp[1]=1;
	for(int i=1;i<=n;i++)if(cnt[i]==i)
	{
		for(int j=i+i;j<=n;j+=i)
		{
			dp[j]+=dp[i];
			if(dp[j]>=mod)dp[j]-=mod;
		}
		ans+=dp[i];
		if(ans>=mod)ans-=mod;
	}
	printendl(ans);
	return 0;
}