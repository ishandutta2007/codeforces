#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cassert>
typedef long long ll;
typedef std::pair<int,int> pii;
typedef unsigned un;
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
const double INF = 1e18+233;
typedef std::pair<double,int> pv;
int n,p[MAXN],a[MAXN],cur[MAXN];
struct sgt_max
{
	pv t[MAXN<<2|1];
	pv merge(pv a,pv b){return a.first>b.first?a:b;}
#define rt t[num]
	void modify(un pos,double val,un l=1,un r=n,un num=1)
	{
		if(l==r){rt=pv(val,l);return;}
		un mid=(l+r)>>1;
		if(pos<=mid)modify(pos,val,l,mid,num<<1);
		else modify(pos,val,mid+1,r,num<<1|1);
		rt=merge(t[num<<1],t[num<<1|1]);
	}
	pv Qmax(){return t[1];}
}Tmax;
struct sgt_min
{
	pv t[MAXN<<2|1];
	pv merge(pv a,pv b){return a.first<b.first?a:b;}
#define rt t[num]
	void modify(un pos,double val,un l=1,un r=n,un num=1)
	{
		if(l==r){rt=pv(val,l);return;}
		un mid=(l+r)>>1;
		if(pos<=mid)modify(pos,val,l,mid,num<<1);
		else modify(pos,val,mid+1,r,num<<1|1);
		rt=merge(t[num<<1],t[num<<1|1]);
	}
	pv Qmin(){return t[1];}
}Tmin;

double eval(int i,int k)
{
	if(k>a[i])return -INF;
	if(k)return double(p[i])*k/(a[i]+k)-double(p[i])*(k-1)/(a[i]+k-1);
	else return 0;
}
int sum=0;
void update(int i,int k)
{
	Tmax.modify(i,eval(i,k+1)),Tmin.modify(i,k==0?INF:eval(i,k));
	sum+=k-cur[i],cur[i]=k;
}
int main()
{
	n=read();
	int t=read(),q=read();
	for(int i=1;i<=n;++i)p[i]=read();
	for(int i=1;i<=n;++i)a[i]=read(),Tmax.modify(i,eval(i,1)),Tmin.modify(i,INF);
	double ans=0;
	sum=0;
	while(sum<t&&Tmax.Qmax().first>0)
	{
		pv x=Tmax.Qmax();
		int i=x.second;
		ans+=x.first,update(i,cur[i]+1);
	}
	while(q--)
	{
		int op=read(),pos=read();
		int nxt=a[pos]+ (op==1?1:-1);
		ans+=double(p[pos])*cur[pos]/(nxt+cur[pos])-double(p[pos])*cur[pos]/(a[pos]+cur[pos]);
		a[pos]=nxt;
		if(cur[pos]>a[pos])ans-=double(p[pos])*cur[pos]/(a[pos]+cur[pos])-double(p[pos])*(cur[pos]-1)/(a[pos]+cur[pos]-1),update(pos,cur[pos]-1);
		else update(pos,cur[pos]);
	while(sum<t&&Tmax.Qmax().first-1e-8>0)
	{
		pv x=Tmax.Qmax();
		int i=x.second;
		ans+=x.first,update(i,cur[i]+1);
	}
	int cnt=0;
		while(Tmax.Qmax().first-1e-8>Tmin.Qmin().first)
		{
			++cnt;
			pv x=Tmax.Qmax();
			int i=x.second;
			ans+=x.first,update(i,cur[i]+1);
			x=Tmin.Qmin();
			i=x.second;
			ans-=x.first,update(i,cur[i]-1);
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}