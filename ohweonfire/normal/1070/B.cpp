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
const int maxn=200111*33;
int n;
bool OK=1;
int tot=1;
int cnt[maxn][2];
int sum[maxn][2];
int go[maxn][2];
void adds(ll x,int l,bool ty)
{
//	cerr<<"adds:"<<x<<" "<<l<<" "<<ty<<endl;
	int p=1;
	for(int i=0;i<l;i++)
	{
		int c=(x>>(31-i))&1;
		int &nxt=go[p][c];
		if(nxt==0)nxt=++tot;
		p=nxt;
	}
	cnt[p][ty]++;
}
void pdfs(int x,int cnt0=0,int cnt1=0)
{
	if(cnt0>0&&cnt1>0)
	{
		OK=0;
	}
	sum[x][0]=cnt[x][0];
	sum[x][1]=cnt[x][1];
	for(int i=0;i<2;i++)
	{
		if(go[x][i])
		{
			int u=go[x][i];
			pdfs(u,cnt0+cnt[u][0],cnt1+cnt[u][1]);
			sum[x][0]+=sum[u][0];
			sum[x][1]+=sum[u][1];
		}
	}
//	cerr<<x<<":"<<sum[x][0]<<" , "<<sum[x][1]<<endl;
}
vector<pair<ll,int> > v;
void dfs(int x,int lv=0,ll msk=0)
{
//	cerr<<x<<":"<<sum[x][0]<<" "<<sum[x][1]<<endl;
	if(sum[x][1]==0)
	{
		v.PB(MP(msk,lv));
		return;
	}
	for(int i=0;i<2;i++)
	{
		if(go[x][i])
		{
			int u=go[x][i];
			dfs(u,lv+1,msk|((1ll*i)<<(31-lv)));
		}
	}
}
void output(ll msk,int l)
{
	int x=(msk>>24)&255;
	int y=(msk>>16)&255;
	int z=(msk>>8)&255;
	int w=(msk>>0)&255;
	printf("%d.%d.%d.%d/%d\n",x,y,z,w,l);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char s[40];
		scanf("%s",s);
		int l=strlen(s);
		bool is_sub=0;
		for(int j=0;j<l;j++)
		{
			if(s[j]=='/')
			{
				is_sub=1;
			}
		}
		bool add=s[0]=='+';
		ll id=0;
		int a[4],b;
		if(!is_sub)s[l++]='/';
		vector<int>p;
		for(int i=0;i<l;i++)if(s[i]=='.'||s[i]=='/')p.PB(i);
		if(!is_sub)
		{
			for(int t=0;t<4;t++)sscanf(s+(t==0?1:p[t-1]+1),"%d",&a[t]);
			b=32;
		}
		else
		{
			for(int t=0;t<4;t++)sscanf(s+(t==0?1:p[t-1]+1),"%d",&a[t]);
			sscanf(s+p[3]+1,"%d",&b);
		}
//		cout<<a[0]<<","<<a[1]<<","<<a[2]<<","<<a[3]<<endl;
		id=id<<8|a[0];
		id=id<<8|a[1];
		id=id<<8|a[2];
		id=id<<8|a[3];
		adds(id,b,add);
	}
	pdfs(1,cnt[1][0],cnt[1][1]);
	if(!OK)puts("-1");
	else
	{
		dfs(1);
		putsi(v.size());
		for(int i=0;i<v.size();i++)
		{
			output(v[i].FF,v[i].SS);
		}
	}
	return 0;
}