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

const int MAXN = 500011;
ll pw[65];
int res[MAXN];
int main()
{
	pw[0]=1;
	for(int i=1;i<=62;++i)pw[i]=pw[i-1]*2;
	int task=read();
	while(task--)
	{
		int n=read();
		ll k=read();
		/*
		if(n<=62)
		{
			if(k>pw[n-1]){puts("-1");continue;}
			int l=0;
			for(int i=1;i<=n;)
			{
				int j=i;
				while(k>(j==n?1:pw[n-j-1]))k-=(j==n?1:pw[n-j-1]),++j;
				int nxt=j+1;
				while(j>=i)res[++l]=j,--j;
				i=nxt;
			}
			for(int i=1;i<=n;++i)printf("%d ",res[i]);
			puts("");
		}
		else
		{
		*/
			if(n<=62&&k>pw[n-1]){puts("-1");continue;}
			for(int i=1;i<=n-62;++i)printf("%d ",i);
			int l=0;
			for(int i=max(1,n-61);i<=n;)
			{
				int j=i;
				while(k>(j==n?1:pw[n-j-1]))k-=(j==n?1:pw[n-j-1]),++j;
				int nxt=j+1;
				while(j>=i)res[++l]=j,--j;
				i=nxt;
			}
			for(int i=1;i<=l;++i)printf("%d ",res[i]);
			puts("");
	}
	return 0;
}