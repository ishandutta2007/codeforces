//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int Tn,n,m;
bitset<2012> a[2011];
vector<int> con[2011];
bool used[2011];
void out()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cerr<<a[i][j];
		}
		cerr<<endl;
	}
	cerr<<endl;
}
int main()
{
	geti(Tn);
	while(Tn--)
	{
		getii(n,m);
		for(int i=1;i<=n;i++)for(int j=1;j<=n+1;j++)a[i][j]=0;
		for(int i=1;i<=n;i++)con[i].clear(),used[i]=0;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			getii(x,y);
			con[x].PB(y);
			con[y].PB(x);
		}
		bool ok=1;
		for(int i=1;i<=n;i++)ok&=(con[i].size()%2==0);
		if(ok)
		{
			puts("1");
			for(int i=1;i<=n;i++)puti(1);
			puts("");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<con[i].size();j++)
			{
				a[i].flip(i);
				a[i].flip(con[i][j]);
				a[i].flip(n+1);
			}
		}
		for(int i=1;i<n;i++)
		{
//			out();
			bool ok=0;
			for(int j=1;j<=n;j++)
			{
				if(!used[j]&&a[j][i])
				{
					ok=1;
					swap(a[j],a[i]);
					break;
				}
			}
			if(!ok)continue;
			used[i]=1;
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				if(a[j][i])
				{
					a[j]^=a[i];
				}
			}
		}
		puts("2");
		for(int i=1;i<=n;i++)puti(int(a[i][n+1])+1);
	}
	return 0;
}