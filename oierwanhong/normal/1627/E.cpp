#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
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
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 800011;
const ll LINF = 1e18+233;
struct ladder{int a,b,c,d,val;}a[MAXN];
std::vector<pll>b[MAXN];
ll c[MAXN],f[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),m=read(),k=read();
		for(int i=1;i<=n;++i)c[i]=read(),b[i].clear();
		for(int i=1;i<=k;++i)f[i]=LINF;
		for(int i=1;i<=k;++i)
		{
			a[i].a=read(),a[i].b=read(),a[i].c=read(),a[i].d=read(),a[i].val=read();
			b[a[i].a].emplace_back(pll(a[i].b,i));
			b[a[i].c].emplace_back(pll(a[i].d,-i));
		}
		for(int r=1;r<=n;++r)
		{
			std::sort(b[r].begin(),b[r].end());
			ll pref= r==1?-c[r]:LINF;
			for(int i=0;i<b[r].size();++i)
			{
				int p=b[r][i].second;
				if(p<0)p=-p,umin(pref,f[p]-a[p].val-b[r][i].first*c[r]);
				else umin(f[p],pref+b[r][i].first*c[r]);
			}
			if(r==n)
			{
				if(pref>ll(1e17))puts("NO ESCAPE");
				else printf("%lld\n",pref+m*c[r]);
				break;
			}
			pref=LINF;
			for(int i=int(b[r].size())-1;i>=0;--i)
			{
				int p=b[r][i].second;
				if(p<0)p=-p,umin(pref,f[p]-a[p].val+b[r][i].first*c[r]);
				else umin(f[p],pref-b[r][i].first*c[r]);
			}
		}
	}
	return 0;
}