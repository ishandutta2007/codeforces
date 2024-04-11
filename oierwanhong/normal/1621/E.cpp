#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
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
const int MAXN = 400011;
int n;
struct BIT
{
#define lowb (i&-i)
	int t[MAXN];
	void modify(int i,int k)
	{
		while(i<=n)t[i]+=k,i+=lowb;
	}
	int Qsum(int i)
	{
		int res=0;
		while(i)res+=t[i],i-=lowb;
		return res;
	}
}bt;
int a[MAXN];
int type[MAXN],ord[MAXN];
std::vector<int>b[MAXN],res[MAXN];
ll sumb[MAXN];
bool cmp(int x,int y){return sumb[x]*b[y].size()<sumb[y]*b[x].size();}
bool leq(ll a,ll b,ll c,ll d)
{
	return a*d<=c*b;
}
int main()
{
	int task=read();
	while(task--)
	{
		int c=read();
		n=read();
		for(int i=1;i<=c;++i)a[i]=read();
		std::sort(a+1,a+c+1);
		for(int i=1;i<=n;++i)a[i]=a[i+(c-n)];
		for(int i=1;i<=n;++i)
		{
			int k=read();
			b[i].resize(k);
			sumb[i]=0;
			for(int j=0;j<k;++j)b[i][j]=read(),sumb[i]+=b[i][j];
			ord[i]=i;
			res[i].clear();
		}
		std::sort(ord+1,ord+n+1,cmp);
		bool fail=0;
		for(int w=1;w<=n;++w)
		{
			int x=ord[w];
			if(!leq(sumb[x],b[x].size(),a[w],1))fail=1;
			if(leq(sumb[x],b[x].size(),a[w-1],1))bt.modify(w,1);
		}
		if(!fail)
		{
			//fprintf(stderr,"success at first!\n");
			for(int w=1;w<=n;++w)
			{
				int x=ord[w];
				int l=w,r=n;
				while(l<r)
				{
					int mid=(l+r+1)>>1;
					if(bt.Qsum(mid)-bt.Qsum(w)==mid-w)l=mid;
					else r=mid-1;
				}
				// (sum[x]-k)/(c-1) <= a[l]
				// sum[x]-a[l]*(c-1)<= k
				ll lim = sumb[x]-ll(a[l])*(int(b[x].size())-1);
				res[x].clear();
				for(auto v:b[x])
					if(v>=lim)res[x].emplace_back(1);
					else res[x].emplace_back(0);
			}
			for(int x=1;x<=n;++x)
				for(auto v:res[x])putchar('0'+v);
			puts("");
		}
		else
		{
			//fprintf(stderr,"fail at first!\n");
			bool two=0;
			for(int w=1;w<n;++w)
			{
				int x=ord[w];
				if(!leq(sumb[x],b[x].size(),a[w+1],1)){two=1;break;}
			}
			if(two)
			{
				//fprintf(stderr,"fail for two!\n");
				for(int x=1;x<=n;++x)
					for(auto v:b[x])putchar('0');
				puts("");
			}
			else
			{
				int minp=0,maxp=0;
				for(int w=1;w<=n;++w)
				{
					int x=ord[w];
					if(!leq(sumb[x],b[x].size(),a[w],1))
					{
						if(!minp)minp=w;
						maxp=w;
					}
				}
				//printf("Minp=%d\n",minp);
				for(int w=1;w<maxp;++w)res[ord[w]].resize(b[ord[w]].size());
				for(int w=maxp;w<=n;++w)
				{
					// (sum-k)/(c-1)<=a[minp]
					// sum[x]-a[minp]*(c-1)<= k
					int x=ord[w];
					ll lim=sumb[x]-ll(a[minp])*(int(b[x].size())-1);
					//printf("sum=%lld,lim=%lld\n",sumb[x],lim);
					//for(auto v:b[x])printf("%d ",v);
					//puts("");
					res[x].clear();
					for(auto v:b[x])
						if(v>=lim)res[x].emplace_back(1);
						else res[x].emplace_back(0);
				}
			for(int x=1;x<=n;++x)
				for(auto v:res[x])putchar('0'+v);
			puts("");
			}
		}
		for(int w=1;w<=n;++w)
		{
			int x=ord[w];
			if(!leq(sumb[x],b[x].size(),a[w],1))fail=1;
			if(leq(sumb[x],b[x].size(),a[w-1],1))bt.modify(w,-1);
		}
	}
	return 0;
}