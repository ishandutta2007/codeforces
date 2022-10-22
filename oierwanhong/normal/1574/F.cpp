#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::pair<int,int> pii;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 525011,mod = 998244353;
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
struct Mint
{
	int x;
	Mint(){x=0;}
	Mint(int x):x(x) {}
	void operator+= (Mint you){x+=you.x;if(x>=mod)x-=mod;}
	void operator-= (Mint you){x-=you.x;if(x<0)x+=mod;}
	void operator*= (Mint you){x=ll(x)*you.x%mod;}
	void operator/= (Mint you){x=ll(x)*Qpow(you.x,mod-2)%mod;}
	Mint Inv(){return Qpow(x,mod-2);}
};
Mint operator+ (Mint a,Mint b){int t=a.x+b.x;return t>=mod?t-mod:t;}
Mint operator- (Mint a,Mint b){int t=a.x-b.x;return t<0?t+mod:t;}
Mint operator* (Mint a,Mint b){return ll(a.x)*b.x%mod;}
Mint operator/ (Mint a,Mint b){return ll(a.x)*Qpow(b.x,mod-2)%mod;}
Mint operator++ (Mint& a){return a=a+1;}
Mint operator-- (Mint& a){return a=a-1;}
Mint operator- (Mint a){return 0-a;}
typedef std::vector<Mint> P;
Mint RT[MAXN],inv[MAXN],inv2=(mod+1)>>1;
void init(int n)
{
	int len=1;
	while(len<=n)len<<=1;
	inv[1]=1;
	for(int i=1;i<len;i<<=1)
	{
		Mint R=Qpow(3,(mod-1)/(i<<1));
		RT[i]=1;
		for(int j=1;j<i;++j)RT[i+j]=RT[i+j-1]*R;
		inv[i<<1]=inv[i]*inv2;
	}
}
int status[MAXN];
void DFT(Mint* a,int len)
{
	for(int i=0;i<len;++i)
		if(status[i]>i)std::swap(a[i],a[status[i]]);
	for(int cur=1;cur<len;cur<<=1)
		if(cur<4)
			for(int j=0;j<len;j+=cur<<1)
				for(int k=0;k<cur;++k)
				{
					Mint x=a[j+k],y=RT[cur+k]*a[j+cur+k];
					a[j+k]=x+y,a[j+cur+k]=x-y;
				}
		else
			for(int j=0;j<len;j+=cur<<1)
				for(int k=0;k<cur;k+=4)
				{
					Mint x=a[j+k],y=RT[cur+k]*a[j+cur+k];
					a[j+k]=x+y,a[j+cur+k]=x-y;
					x=a[j+k+1],y=RT[cur+k+1]*a[j+cur+k+1];
					a[j+k+1]=x+y,a[j+cur+k+1]=x-y;
					x=a[j+k+2],y=RT[cur+k+2]*a[j+cur+k+2];
					a[j+k+2]=x+y,a[j+cur+k+2]=x-y;
					x=a[j+k+3],y=RT[cur+k+3]*a[j+cur+k+3];
					a[j+k+3]=x+y,a[j+cur+k+3]=x-y;
				}
}
void IDFT(Mint* a,int len)
{
	std::reverse(a+1,a+len);
	DFT(a,len);
	for(int i=0;i<len;++i)a[i]=a[i]*inv[len];
}

std::vector<int>nxt[MAXN],pre[MAXN];
bool fail[MAXN];
void mark(int u)
{
	if(fail[u])return;
	fail[u]=1;
	for(auto x:nxt[u])mark(x);
	for(auto x:pre[u])mark(x);
}
int vis[MAXN],T,cur=0;
void dfs(int u)
{
	vis[u]=T,++cur;
	std::sort(nxt[u].begin(),nxt[u].end()),nxt[u].resize(std::unique(nxt[u].begin(),nxt[u].end())-nxt[u].begin());
	std::sort(pre[u].begin(),pre[u].end()),pre[u].resize(std::unique(pre[u].begin(),pre[u].end())-pre[u].begin());
	if(nxt[u].size()>1)
	{
		mark(u);return;
	}
	if(nxt[u].size())
	{
		if(vis[nxt[u][0]]==T){mark(u);return;}
		dfs(nxt[u][0]);
	}
	if(pre[u].size()>1)
	{
		mark(u);return;
	}
}
Mint f[MAXN],g[MAXN],tf[MAXN],tg[MAXN],th[MAXN];
void poly_inv(int n)
{
	f[0]=Mint(1)/g[0];
	for(int len=2;len<=n;len<<=1)
	{
		for(int i=0;i<len;++i)status[i]=(status[i>>1]>>1)|(i&1?len>>1:0);
		for(int i=0;i<len;++i)tf[i]=f[i],tg[i]=g[i];
		DFT(tf,len),DFT(tg,len);
		for(int i=0;i<len;++i)th[i]=tf[i]*tg[i];
		IDFT(th,len);
		for(int i=1;i<(len>>1);++i)th[i]=0;
		th[0]=1;
		DFT(th,len);
		for(int i=0;i<len;++i)th[i]=-th[i]*tf[i];
		IDFT(th,len);
		for(int i=(len>>1);i<len;++i)f[i]=th[i];
	}
}
int main()
{
	init(3e5);
	int n=read(),m=read(),k=read();
	for(int i=1;i<=n;++i)
	{
		int l=read(),lst=read();
		for(int j=2;j<=l;++j)
		{
			int x=read();
			nxt[lst].push_back(x),pre[x].push_back(lst);
			lst=x;
		}
	}
	int all=0;
	for(int i=1;i<=k;++i)
		if(!vis[i]&&!fail[i]&&pre[i].empty())
		{
			++T,cur=0;
			dfs(i);
			if(!fail[i])--g[cur];
		}
	++g[0];
	int len=1;
	while(len<=m)len<<=1;
	poly_inv(len);
	printf("%d\n",f[m].x);
	return 0;
}