#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::vector<int> P;
typedef unsigned un;
ll read()
{
    ll x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x;
}
using std::min;
using std::max;
template<typename T>bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T>bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}

const int MAXN = 1000011;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int a[MAXN];
std::vector<ll>seq[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),m=read(),g=0;
		for(int i=0;i<n;++i)seq[i].clear();
		ll sum=0;
		for(int i=0;i<n;++i)a[i]=read(),sum+=a[i];
		for(int i=1;i<=m;++i)g=gcd(g,read());
		for(int i=0;i<n;++i)seq[i%g].emplace_back(a[i]);
		ll f0=0,f1=0;
		for(int r=0;r<g;++r)
		{
			std::sort(seq[r].begin(),seq[r].end());
			for(int i=0;i+1<seq[r].size();i+=2)f0+=max(0ll,-2*(seq[r][i]+seq[r][i+1]));
			f1+=-2*seq[r][0];
			for(int i=1;i+1<seq[r].size();i+=2)f1+=max(0ll,-2*(seq[r][i]+seq[r][i+1]));
		}
		printf("%lld\n",sum+max(f0,f1));
	}
	return 0;
}