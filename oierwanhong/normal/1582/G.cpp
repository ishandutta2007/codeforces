#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<bitset>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 1000011,INF = 1.233e9;
int pri[MAXN],cnt=0;
int minp[MAXN];
bool vis[MAXN];
void sieve(int n)
{
	vis[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!vis[i])pri[++cnt]=i,minp[i]=i;
		for(int j=1;j<=cnt&&i*pri[j]<=n;++j)
		{
			vis[i*pri[j]]=1,minp[i*pri[j]]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
}
int n;
int stk[MAXN],sum[MAXN];
int a[MAXN],f[MAXN];
	struct DSU
	{
		int fa[MAXN],maxp[MAXN];
		void init(int n){for(int i=1;i<=n;++i)fa[i]=-1,maxp[i]=i;}
		int find(int x)
		{
			if(fa[x]<0)return x;
			return fa[x]=find(fa[x]);
		}
		void uni(int x,int y)
		{
			x=find(x),y=find(y);
			if(-fa[x]>-fa[y])std::swap(x,y);
			else if(fa[x]==fa[y])--fa[y];
			fa[x]=y,umax(maxp[y],maxp[x]);
		}
	}dsu;
	std::vector<pii>s[MAXN];
	void Chkmin(int l,int r,int val)
	{
		s[val].emplace_back(pii(l,r));
	}
	void pushall()
	{
		for(int v=0;v<=n;++v)
		{
			for(auto x:s[v])
			{
				int l=dsu.maxp[dsu.find(x.first)];
				while(l<=x.second)f[l]=v,dsu.uni(l,l+1),l=dsu.maxp[dsu.find(l)];
			}
		}
	}
char op[MAXN];
std::vector<pii>seq[MAXN];
int main()
{
	sieve(1e6);
	n=read();
	dsu.init(n+1);
	for(int i=1;i<=n;++i)a[i]=read(),f[i]=n;
	scanf("%s",op+1);
	for(int i=1;i<=cnt;++i)seq[pri[i]].emplace_back(pii(0,0));
	for(int i=1;i<=n;++i)
	{
		int x=a[i],sgn=(op[i]=='*'?1:-1);
		while(x>1)
		{
			int c=0,fir=minp[x];
			while(minp[x]==fir)x/=fir,++c;
			seq[fir].emplace_back(pii(i,c*sgn));
		}
	}
	Chkmin(1,n,n);
	for(int w=1;w<=cnt;++w)
	{
		int p=pri[w];
		if(seq[p].size()==1)continue;
		for(int i=1;i<seq[p].size();++i)
		{
			sum[i]=sum[i-1]+seq[p][i].second;
		}
		int top=0;
		for(int i=int(seq[p].size())-1;i>=0;--i)
		{
			while(top&&sum[stk[top]]>=sum[i])--top;
			if(top)
			{
				Chkmin(seq[p][i].first+1,seq[p][stk[top]].first,seq[p][stk[top]].first-1);
			}
			stk[++top]=i;
		}
	}
	pushall();
	ll ans=0;
	for(int i=1;i<=n;++i)ans+=f[i]-i+1;
	printf("%lld\n",ans);
	return 0;
}