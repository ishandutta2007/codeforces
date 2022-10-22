#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int mod = 998244353;
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
	Mint(ll y){x=(0<=y&&y<mod?y:(y%mod+mod)%mod);}
	void operator+= (Mint a){x+=a.x;if(x>=mod)x-=mod;}
	void operator-= (Mint a){x-=a.x;if(x<0)x+=mod;}
	void operator*= (Mint a){x=ll(x)*a.x%mod;}
};
Mint operator+ (Mint a,Mint b){int t=a.x+b.x;return t<mod?t:t-mod;}
Mint operator- (Mint a,Mint b){int t=a.x-b.x;return t>=0?t:t+mod;}
Mint operator* (Mint a,Mint b){return ll(a.x)*b.x%mod;}
const int MAXN = 400011;
std::vector<pii>factor[MAXN];
int rest[MAXN];
bool vis[MAXN];
void sieve()
{
	for(int i=1;i<MAXN;++i)rest[i]=i;
	for(int i=2;i<MAXN;++i)
		if(!vis[i])
		{
			rest[i]=1,factor[i].emplace_back(pii(i,1));
			for(int j=i<<1;j<MAXN;j+=i)
			{
				int c=0;
				while(rest[j]%i==0)++c,rest[j]/=i;
				factor[j].emplace_back(pii(i,c));
				vis[j]=1;
			}
		}
}
std::vector<int>update;
std::map<int,int>maxf;
std::map<int,int>A,B;
struct edge{int v,x,y,nxt;}e[MAXN<<1|1];
int cnt=1,last[MAXN];
void adde(int u,int v,int x,int y){e[++cnt].v=v,e[cnt].x=x,e[cnt].y=y,e[cnt].nxt=last[u],last[u]=cnt;}
//A[v]=A[u]*x/y
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void dfs1(int u,int fa)
{
	for(int i=last[u];i;i=e[i].nxt)
	{
		int v=e[i].v,x=e[i].x,y=e[i].y;
		if(v==fa)continue;
		int g=gcd(x,y);
		x/=g,y/=g;
		for(auto [p,c]:factor[x])
		{
			A[p]+=c;
			int k=min(A[p],B[p]);
			A[p]-=k,B[p]-=k;
		}
		for(auto [p,c]:factor[y])
		{
			B[p]+=c;
			int k=min(A[p],B[p]);
			A[p]-=k,B[p]-=k;
			umax(maxf[p],B[p]);
		}
		dfs1(v,u);
		for(auto [p,c]:factor[x])
		{
			B[p]+=c;
			int k=min(A[p],B[p]);
			A[p]-=k,B[p]-=k;
			umax(maxf[p],B[p]);
		}
		for(auto [p,c]:factor[y])
		{
			A[p]+=c;
			int k=min(A[p],B[p]);
			A[p]-=k,B[p]-=k;
		}
	}
}
Mint lcm,ans;
void dfs2(int u,int fa,Mint now)
{
	ans+=now;
	for(int i=last[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v!=fa)dfs2(v,u,now*e[i].x*Qpow(e[i].y,mod-2));
	}
}
int main()
{
	sieve();
	int task=read();
	while(task--)
	{
		int n=read();
		cnt=1;
		for(int i=1;i<=n;++i)last[i]=0;
		maxf.clear(),A.clear(),B.clear();
		for(int i=1;i<n;++i){int u=read(),v=read(),y=read(),x=read();adde(u,v,x,y),adde(v,u,y,x);}
		dfs1(1,0);
		lcm=1,ans=0;
		for(auto P:maxf)
		{
			lcm*=Qpow(P.first,P.second);
		}
		dfs2(1,0,lcm);
		printf("%d\n",ans.x);
	}
	return 0;
}