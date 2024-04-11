// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")
#endif
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

const int N=20;
int n,dp[1<<N];LL a[N],sum[1<<N];
bool ok[1<<N];
int main()
{
	get1(n);
	int nn=0;
	for(int i=0;i<n;i++)
	{
		get1(a[i]);
		if(!a[i])continue;
		a[nn]=a[i];sum[1<<nn]=a[nn];
		nn++;
	}
	n=nn;
	for(int i=0;i<(1<<n);i++)
	{
		sum[i]=sum[i&i-1]+sum[i&-i];
		int sz=__builtin_popcount(i),msk=i&i-1;
		for(int j=msk;j;j=j-1&msk)if(sum[j]-sum[i^j]<=sz&&sum[j]-sum[i^j]>=-sz&&((sum[j]-sum[i^j]+sz-1)&1)==0)
		{
			ok[i]=1;
			break;
		}
	}
	for(int i=0;i<(1<<n);i++)if(ok[i])
	{
		int nmsk=((1<<n)-1)^i;
		for(int j=nmsk;j;j=j-1&nmsk)dp[i^j]=max(dp[i^j],dp[j]+1);
		dp[i]=max(dp[i],1);
	}
	printf("%d\n",n-dp[(1<<n)-1]);
	return 0;
}