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

const int mod=1e9+7;
const int maxn=100111;
int qpow(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1)ret=(LL)ret*x%mod;
		x=(LL)x*x%mod;
		y>>=1;
	}
	return ret;
}

int n,k,p[maxn];
LL cnt[maxn];

vector<int> divs[maxn*2];

int main()
{
	get2(n,k);
	k=qpow(k,mod-2);
	p[0]=1;for(int i=1;i<=n;i++)p[i]=(LL)p[i-1]*k%mod;
	
	/*int ans=0;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(i+j-__gcd(i,j)<=n)ans+=p[n-__gcd(i,j)];
			else ans+=p[n-(i+j-n)];
			if(ans>=mod)ans-=mod;
		}
	}*/
	
	for(int i=1;i<n;i++)for(int j=i;j<n*2;j+=i)divs[j].pb(i);
	
	for(int s=1;s<n+n;s++)
	{
		reverse(divs[s].begin(),divs[s].end());
		vector<int> ansv;
		for(auto g:divs[s])
		{
			int lb=g,rb=(n-1)/g*g;
			lb=max(lb,s-rb);
			rb=min(rb,s-lb);
			if(lb>rb)ansv.pb(0);
			else ansv.pb((rb-lb)/g+1);
		}
		for(int i=0;i<(int)divs[s].size();i++)
		{
			for(int j=0;j<i;j++)if(divs[s][j]%divs[s][i]==0)ansv[i]-=ansv[j];
			int g=divs[s][i];
			if(s-g<=n)cnt[n-g]+=ansv[i];
			else cnt[n+n-s]+=ansv[i];
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)ans=(ans+cnt[i]%mod*p[i])%mod;
	
	printf("%d\n",ans);
	return 0;
}