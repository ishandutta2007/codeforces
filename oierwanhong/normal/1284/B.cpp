#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
typedef unsigned un;
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0;bool f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f?-x:x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/
const int MAXN = 200011;
int a[MAXN],cnt[10000011],las[MAXN];

int main()
{
	int n=read(),nxt=0;
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		int l=read(),fir, pre=read(),fail=0;
		fir=pre;
		for(int j=2;j<=l;++j)
		{
			int x=read();
			if(x>pre)fail=1;
			pre=x;
		}
		if(!fail)las[++nxt]=pre,++cnt[fir];
	}
	for(int i=1;i<=1000000;++i)cnt[i]+=cnt[i-1];
	for(int i=1;i<=nxt;++i)ans+=cnt[las[i]];
	printf("%lld\n",ll(n)*n-ans);
	return 0;
}