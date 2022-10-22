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
const int MAXN = 400011,V = 200000;
ll calc(std::vector<int> *pos,int n)
{
	ll res=0;
	for(int x=1;x<=V;++x)
	{
		if(pos[x].empty())continue;
		std::sort(pos[x].begin(),pos[x].end());
		int lc=0,rc=pos[x].size();
		int lst=0;
		for(auto p:pos[x])
		{
			if(lst<p)res+=ll(p-lst)*lc*rc;
			lst=p;
			++lc,--rc;
		}
	}
	return res;
}
std::vector<int>pos1[MAXN],pos2[MAXN];
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			int x=read();
			pos1[x].emplace_back(i);
			pos2[x].emplace_back(j);
		}
	printf("%lld\n",calc(pos1,n)+calc(pos2,m));
	return 0;
}