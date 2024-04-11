#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 200011;
pii a[MAXN];
bool used[MAXN];
int main()
{
	std::mt19937 rd(std::chrono::steady_clock::now().time_since_epoch().count());
	int n=read();
	if(n<=4)
	{
		puts("YES");
		return 0;
	}
	for(int i=1;i<=n;++i)a[i].first=read(),a[i].second=read();
	for(int T=1;T*n<=5000000;++T)
	{
		for(int p=1;p<=n;++p)used[p]=0;
		int i=rd()%n+1,j=rd()%n+1;
		while(i==j)i=rd()%n+1,j=rd()%n+1;
		
		ll dx=a[j].first-a[i].first,dy=a[j].second-a[i].second;
		for(int p=1;p<=n;++p)
			if(dy*(a[p].first-a[i].first)==dx*(a[p].second-a[i].second))used[p]=1;
		i=0,j=0;
		bool fail=0;
		for(int p=1;p<=n;++p)
			if(!used[p])
			{
				if(!i)i=p;
				else if(!j)j=p, dx=a[j].first-a[i].first,dy=a[j].second-a[i].second;
				else if(dy*(a[p].first-a[i].first)!=dx*(a[p].second-a[i].second))fail=1;
			}
		if(!fail)
		{
			puts("YES");return 0;
		}
	}
	puts("NO");
	return 0;
}