#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
#include<queue>
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
int a[MAXN],fx[MAXN],diff=0;
std::vector<int>b[MAXN];
ll ans=0,sum=0;
std::priority_queue<int>q;
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)fx[++diff]=a[i]=read();
	std::sort(fx+1,fx+diff+1),diff=std::unique(fx+1,fx+diff+1)-fx-1;
	for(int i=1;i<=n;++i)b[std::lower_bound(fx+1,fx+diff+1,a[i])-fx].push_back(read());
	for(int i=1;i<=diff;++i)
	{
		for(int x=fx[i-1]+1;x<fx[i];++x)
		{
			if(q.empty())break;
			sum-=q.top();q.pop();
			ans+=sum;
		}
		for(auto w:b[i])sum+=w,q.push(w);
		sum-=q.top(),q.pop();
		ans+=sum;
	}
	while(q.size())sum-=q.top(),q.pop(),ans+=sum;
	printf("%lld\n",ans);
	return 0;
}