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
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=500111;
const int maxm=10000111;
const int mod=1e9+7;

int n,p[maxn],ta[maxm],tb[maxm];
int main()
{
	p[0]=1;for(int i=1;i<maxn;i++)p[i]=p[i-1]*2%mod;
	
	get1(n);
	for(int i=1,x;i<=n;i++)
	{
		get1(x);
		ta[x]++;
	}
	for(int i=1;i<maxm;i++)
	{
		for(int j=i+i;j<maxm;j+=i)ta[i]+=ta[j];
		tb[i]=p[ta[i]]-1;
	}
	for(int i=maxm-1;i>=1;i--)
	{
		for(int j=i+i;j<maxm;j+=i)
		{
			tb[i]-=tb[j];
			if(tb[i]<0)tb[i]+=mod;
		}
	}
	tb[1]=(LL)n*(p[n]-1+mod-tb[1])%mod;
	for(int i=2;i<maxm;i++)tb[i]=(LL)ta[i]*(p[ta[i]]-1)%mod;
	
	for(int i=maxm-1;i>=1;i--)
	{
		for(int j=i+i;j<maxm;j+=i)
		{
			tb[i]-=tb[j];
			if(tb[i]<0)tb[i]+=mod;
		}
	}
	printf("%d\n",tb[1]);
	return 0;
}