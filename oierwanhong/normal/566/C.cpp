#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
typedef long long ll;
typedef std::pair<ll,ll> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 200011;
struct edge{int v,w,nxt;}e[MAXN<<1|1];
int cnt=0,last[MAXN];
void adde(int u,int v,int w){e[++cnt].v=v,e[cnt].w=w,e[cnt].nxt=last[u],last[u]=cnt;}

double f1[MAXN],f2[MAXN];
ll s1[MAXN],s2[MAXN],a[MAXN],tot1,tot2;
int size[MAXN],n;
void dfs1(int u,int fa)
{
	size[u]=1,s1[u]=a[u],s2[u]=a[u]*a[u];
	for(int i=last[u];i;i=e[i].nxt)
	{
		int v=e[i].v,w=e[i].w;
		if(v!=fa)
		{
			dfs1(v,u),size[u]+=size[v],s1[u]+=s1[v],s2[u]+=s2[v];
			f1[u]+=f1[v]+double(s1[v])*w,f2[u]+=f2[v]+ 2*f1[v]*w+double(s1[v])*w*w;
		}
	}
}
int dfs2(int u,int fa,double f)
{
	for(int i=last[u];i;i=e[i].nxt)
	{
		int v=e[i].v,w=e[i].w;
		if(v==fa)continue;
		if(f-double(s1[v])*w+double(tot1-s1[v])*w<f)
		{
			return dfs2(v,u,f-double(s1[v])*w+double(tot1-s1[v])*w);
		}
	}
	return u;
}
int dfs3(int u,int fa,double res2,double res1)
{
	for(int i=last[u];i;i=e[i].nxt)
	{
		int v=e[i].v,w=e[i].w;
		if(v==fa)continue;
		double t1=f1[v]+s1[v]*w;
		double nf= res2-2*t1*w +double(s1[v])*w*w +2*(res1-t1)*w+double(tot1-s1[v])*w*w;
		if(nf<res2)
		{
			return dfs3(v,u,nf,res1-double(s1[v])*w+double(tot1-s1[v])*w);
		}
	}
	return u;
}
int pre[MAXN],chain[MAXN];
void dfs4(int u)
{
	for(int i=last[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v!=pre[u])pre[v]=u,dfs4(v);
	}
}
double eval(int u,int dis,int fa)
{
	double res=dis*sqrt(dis)*a[u];
	for(int i=last[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v!=fa)res+=eval(v,dis+e[i].w,u);
	}
	return res;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<n;++i){int u=read(),v=read(),w=read();adde(u,v,w),adde(v,u,w);}
	dfs1(1,0);
	tot1=s1[1],tot2=s2[1];
	int S1=dfs2(1,0,f1[1]);
	int S2=dfs3(1,0,f2[1],f1[1]);
	fprintf(stderr,"%d %d\n",S1,S2);
	if(S1==S2)
	{
		printf("%d %.8lf\n",S1,eval(S1,0,0));
		return 0;
	}
	dfs4(S1);
	int p=S2,len=0;
	while(p!=S1)chain[++len]=p,p=pre[p];
	chain[++len]=p;
	int l=1,r=len;
	double ans=1e30;
	int rp=0;
	while(l+3<r)
	{
		int mid=(l+r)>>1;
		int lm=mid,rm=mid+1;
		double lf=eval(chain[lm],0,0),rf=eval(chain[rm],0,0);
		if(lf>=rf)l=lm;
		else r=rm;
	}
	for(int i=l;i<=r;++i)
		if(umin(ans,eval(chain[i],0,0)))rp=chain[i];
	printf("%d %.8lf\n",rp,ans);
	return 0;
}