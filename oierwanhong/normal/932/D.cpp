#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
void umin(ll& a,ll t){if(t<a)a=t;}
#define MAXN 400011
ll fa[20][MAXN],w[MAXN], nxt[20][MAXN],sum[20][MAXN],maxw[20][MAXN];
int main()
{
	ll Q=read(),ans=0,cnt=1;
	w[1]=0;
	while(Q--)
	{
		ll op=read();
		if(op==1)
		{
			++cnt;
			fa[0][cnt]=read()^ans,w[cnt]=read()^ans;
			maxw[0][cnt]=w[fa[0][cnt]];
			for(ll i=1;i<=19;++i)
			{
				fa[i][cnt]=fa[i-1][fa[i-1][cnt]];
				maxw[i][cnt]=max(maxw[i-1][cnt],maxw[i-1][fa[i-1][cnt]]);
			}
			ll ed=cnt;
			for(ll i=19;i>=0;--i)
				if(fa[i][ed]&&maxw[i][ed]<w[cnt])ed=fa[i][ed];
			nxt[0][cnt]=fa[0][ed];
			sum[0][cnt]=w[nxt[0][cnt]];
			for(ll i=1;i<=19;++i)
			{
				nxt[i][cnt]=nxt[i-1][nxt[i-1][cnt]];
				sum[i][cnt]=sum[i-1][cnt]+sum[i-1][nxt[i-1][cnt]];
			}
		}
		else
		{
			ll s=read()^ans,limit=read()^ans;
			if(limit<w[s])printf("%lld\n",ans=0 );
			else
			{
				limit-=w[s],ans=1;
				for(ll i=19;i>=0;--i)
					if(nxt[i][s]&&limit>=sum[i][s])
					{
						ans+=(1<<i);
						limit-=sum[i][s],s=nxt[i][s];
					}
				printf("%lld\n",ans );
			}
		}
	}
	return 0;
}