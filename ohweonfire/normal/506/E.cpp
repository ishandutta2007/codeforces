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

const int mod=10007;
int qpow(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1)ret=ret*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ret;
}

namespace Berlekamp_Massey
{
	int n;
	vector<int> calc(const vector<int>&x)
	{
		n=(int)x.size();
		
		vector<int> cur,fix;
		int pos,lastd;
		
		for(int i=0;i<n;i++)
		{
			int delta=(mod-x[i])%mod;
			for(int j=0;j<(int)cur.size();j++)
				delta=(delta+(LL)cur[j]*x[i-j-1])%mod;
			if(delta==0)continue;
			
			if(cur.size()==0)
			{
				cur.resize(i+1);
				pos=i;
				lastd=delta;
				continue;
			}
			
			int coef=(LL)delta*qpow(lastd,mod-2)%mod;
			vector<int> nxt(i-pos-1,0);nxt.pb(coef);
			for(int i=0;i<(int)fix.size();i++)nxt.pb((LL)fix[i]*(mod-coef)%mod);
			if(nxt.size()<cur.size())nxt.resize(cur.size());
			for(int i=0;i<(int)cur.size();i++)
			{
				nxt[i]+=cur[i];
				if(nxt[i]>=mod)nxt[i]-=mod;
			}
			
			pos=i;
			fix=cur;cur=nxt;
			lastd=delta;
			
			// printf("cur ");for(int j=0;j<(int)cur.size();j++)printf("%d ",cur[j]);puts("");
			// printf("fix ");for(int j=0;j<(int)fix.size();j++)printf("%d ",fix[j]);puts("");
		}
		return cur;
	}
};

int tmp[23333];
void poly_mult(int*a,int*b,int*c,int sz)
{
	memset(tmp,0,sizeof(int)*(sz+sz+1));
	for(int i=0;i<sz;i++)for(int j=0;j<sz;j++)tmp[i+j]=(tmp[i+j]+(LL)a[i]*b[j])%mod;
	memcpy(c,tmp,sizeof(int)*(sz+sz+1));
}

void poly_mod(int*a,int*b,int sz)
{
	for(int i=sz+sz-1;i>=sz;i--)if(a[i])
	{
		int tmp=mod-a[i];
		for(int j=0;j<=sz;j++)
			a[i-j]=(a[i-j]+(LL)tmp*b[sz-j])%mod;
	}
}
int ta[23333],tb[23333],tc[23333];
int getkth(vector<int> f,vector<int> rec,int k)//starting from zero
{
	assert(f.size()==rec.size());
	int sz=(int)f.size();
	if(k<sz)return f[k];
	if(sz==1)return (LL)f[0]*qpow(k,rec[0])%mod;
	for(int i=0;i<sz;i++)tb[i]=(mod-rec[sz-i-1])%mod;
	tb[sz]=1;ta[1]=1;tc[0]=1;
	while(k)
	{
		if(k&1)
		{
			poly_mult(tc,ta,tc,sz);
			poly_mod(tc,tb,sz);
		}
		if(k>1)
		{
			poly_mult(ta,ta,ta,sz);
			poly_mod(ta,tb,sz);
		}
		k>>=1;
	}
	int ret=0;
	for(int i=0;i<sz;i++)ret=(ret+(LL)tc[i]*f[i])%mod;
	return ret;
}

const int magic=2000;
const int maxn=211;

char s[maxn];

int seq[magic+500],k,n,dp[maxn][maxn],ndp[maxn][maxn];

int main()
{
	scanf("%s%d",s+1,&k);
	n=strlen(s+1);
	
	dp[0][0]=1;if(n==1)seq[1]=1;
	for(int len=1;len<=magic/2;len++)
	{
		memset(ndp,0,sizeof(ndp));
		for(int l=0;l<=n;l++)for(int r=0;r<=n;r++)if(dp[l][r])
		{
			int vl=-1,vr=-2;
			if(l<n)vl=s[l+1]-'a';if(r<n)vr=s[n-r]-'a';
			if(vl==vr)
			{
				ndp[l+1][r+1]=(ndp[l+1][r+1]+dp[l][r])%mod;
				ndp[l][r]=(ndp[l][r]+dp[l][r]*25)%mod;
			}
			else
			{
				if(vl>=0)ndp[l+1][r]=(ndp[l+1][r]+dp[l][r])%mod;
				if(vr>=0)ndp[l][r+1]=(ndp[l][r+1]+dp[l][r])%mod;
				ndp[l][r]=(ndp[l][r]+dp[l][r]*(26-(vl>=0)-(vr>=0)))%mod;
			}
		}
		memcpy(dp,ndp,sizeof(dp));
		for(int l=0;l<=n;l++)for(int r=0;r<=n;r++)
		{
			if(l+r>=n)
			{
				seq[len*2]=(seq[len*2]+dp[l][r])%mod;
				seq[len*2+1]=(seq[len*2+1]+dp[l][r]*26)%mod;
			}
			else if(l+r==n-1)seq[len*2+1]=(seq[len*2+1]+dp[l][r])%mod;
		}
	}
	if(n+k<=magic)
	{
		printendl(seq[n+k]);
		return 0;
	}
	vector<int> vs,rec;
	for(int i=n;i<=magic;i++)vs.pb(seq[i]);
	rec=Berlekamp_Massey::calc(vs);
	vs.resize(rec.size());
	printf("%d\n",getkth(vs,rec,k));
	return 0;
}