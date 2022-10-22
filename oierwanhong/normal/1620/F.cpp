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
int read()
{
	int f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int abs(int x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 2000011,SINF = 1e9+233;
int a[MAXN],b[MAXN];
struct Line
{
	int l,r,v;
	Line(){}
	Line(int l,int r,int v):l(l),r(r),v(v) {}
};
std::vector<Line>f[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),L=n<<1|1;
		for(int i=1;i<=n;++i)f[i].clear();
		for(int i=1;i<=n;++i)a[i]=read(),b[i]=-a[i],a[i]+=n+1,b[i]+=n+1;
		if(1<b[1])
		{
			f[1].emplace_back(Line(1,b[1]-1,L));
			f[1].emplace_back(Line(b[1],L,0));
		}
		else f[1].emplace_back(Line(1,L,0));
		for(int i=2;i<=n;++i)
		{
			int fa=L,fb=L,sta=L+1,stb=L+1;
			for(auto P:f[i-1])
				if(max(P.l,1)<=min(a[i]-1,P.r))umin(fa,P.v);
			for(auto P:f[i-1])
				if(max(P.l,1)<=min(b[i]-1,P.r))umin(fb,P.v);
			for(auto P:f[i-1])
				if(P.v<a[i])umin(sta,max(a[i]+1,P.l));
			for(auto P:f[i-1])
				if(P.v<b[i])umin(stb,max(b[i]+1,P.l));
			std::vector<pii>now;
			now.emplace_back(pii(a[i],fa)),now.emplace_back(pii(b[i],fb));
			now.emplace_back(pii(sta,a[i])),now.emplace_back(pii(stb,b[i]));
			std::sort(now.begin(),now.end());
			int pref=L,lst=1;
			for(auto P:now)
			{
				if(lst<P.first)f[i].emplace_back(Line(lst,P.first-1,pref)),lst=P.first;
				umin(pref,P.second);
			}
			if(lst<=L)f[i].emplace_back(Line(lst,L,pref));
			//printf("i=%d:",i);
			//for(auto P:f[i])printf("[%d,%d,%d]\n",P.l,P.r,P.v);
		}
		if(f[n].back().v<L)
		{
			puts("YES");
			std::vector<int>res;
			int pos=L,v=f[n].back().v;
			for(int i=n;i>1;--i)
			{
				//printf("i=%d,pos=%d,v=%d\n",i,pos,v);
				bool flag=0;
				if(v==a[i]&&!flag)
				{
					for(auto P:f[i-1])
						if(P.l<=pos&&pos<=P.r&& P.v<a[i]&&a[i]<pos)
						{
							res.emplace_back(a[i]-n-1);
							v=P.v;
							flag=1;break;
						}
				}
				if(v==b[i]&&!flag)
				{
					for(auto P:f[i-1])
						if(P.l<=pos&&pos<=P.r&& P.v<b[i]&&b[i]<pos)
						{
							res.emplace_back(b[i]-n-1);
							v=P.v;
							flag=1;break;
						}
				}
				if(pos>=a[i]&&!flag)
				{
					for(auto P:f[i-1])
						if(P.v==v&&P.l<a[i])
						{
							res.emplace_back(a[i]-n-1);
							pos=P.l;
							flag=1;break;
						}
				}
				if(pos>=b[i]&&!flag)
				{
					for(auto P:f[i-1])
						if(P.v==v&&P.l<b[i])
						{
							res.emplace_back(b[i]-n-1);
							pos=P.l;
							flag=1;break;
						}
				}
				if(!flag)
				{
					fprintf(stderr,"Flag is zero!\n");
					return 0;
				}
			}
			res.emplace_back(pos-n-1);
			std::reverse(res.begin(),res.end());
			for(auto x:res)printf("%d ",x);
			puts("");
		}
		else puts("NO");
	}
	return 0;
}