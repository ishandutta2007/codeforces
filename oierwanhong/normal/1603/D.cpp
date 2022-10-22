#pragma GCC optimize("Ofast")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cassert>
typedef unsigned un;
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0;bool f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f?-x:x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool uminle(T& a,T b){if(b<=a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/
const int MAXN = 200011;
struct node
{
	int t[8];
	ll sum[8];
}t[MAXN*51];
#define rt t[num]
int root[MAXN],cnt=0;
int cpynode(int x)
{
	t[++cnt]=t[x];return cnt;
}
void insert(int& num,un pos,ll val)
{
	t[++cnt]=t[num],num=cnt;
	int u=num;
	for(int k=5;k;--k)
	{
		int c=pos>>(3*k)&7;
		t[u].t[c]=cpynode(t[u].t[c]);
		for(int w=c;w<8;++w)t[u].sum[w]+=val;
		u=t[u].t[c];
	}
	int c=pos&7;
	for(int w=c;w<8;++w)t[u].sum[w]+=val;
}
ll sum=0;
void Qsum(int u,un pos)
{
	for(int k=5;k;--k)
	{
		int c=pos>>(3*k)&7;
		if(c)sum+=t[u].sum[c-1];
		u=t[u].t[c];
	}
	sum+=t[u].sum[pos&7];
}
std::vector<int>d[MAXN];
int phi[MAXN];
ll s2[MAXN];
bool vis[MAXN];
void prework(int n)
{
	vis[1]=1;
	for(int i=1;i<=n;++i)phi[i]=i;
	for(int i=2;i<=n;++i)
		if(!vis[i])
			for(int j=i;j<=n;j+=i)phi[j]=phi[j]/i*(i-1),vis[j]=1;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;j+=i)d[j].emplace_back(i);
	for(int i=1;i<=n;++i)
	{
		root[i]=root[i-1];
		for(auto x:d[i])
		{
			insert(root[i],x,i==x?1:2*phi[i/x]);
		}
		s2[i]=s2[i-1]+2*i-1;
	}
	fprintf(stderr,"cnt=%d\n",cnt);
}
ll calc(int l,int r)
{
	ll res=s2[r]+r-l+1;
	sum=0,Qsum(root[r],l-1);
	return (res-sum)>>1;
}
void solve(ll* pre,ll* f,int l,int r,int kl,int kr)
{
	int mid=(l+r)>>1,best=kl;
	for(int p=kl;p<=kr&&p<mid;++p)
		if(umin(f[mid],pre[p]+calc(p+1,mid)))best=p;
	if(l<mid)solve(pre,f,l,mid-1,kl,best);
	if(mid<r)solve(pre,f,mid+1,r,best,kr);
}
ll f[18][MAXN];
int main()
{
	prework(100000);
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	for(int i=1;i<17;++i)
	{
		solve(f[i-1],f[i],0,100000,0,100000);
	}
	int task=read();
	while(task--)
	{
		int k=read(),n=read();
		if(n>=17)printf("%d\n",k);
		else printf("%lld\n",f[n][k]);
	}
	return 0;
}