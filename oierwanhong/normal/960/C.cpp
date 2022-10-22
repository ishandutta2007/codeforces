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

std::vector<ll>seq;
int main()
{
	ll X=read(),d=read(),cur=1;
	while(X)
	{
		int i=1;
		while(X>=(1<<(i+1))-1)++i;
		X-=(1<<i)-1;
		while(i--)seq.push_back(cur);
		cur+=d+1;
	}
	printf("%d\n",int(seq.size()));
	for(auto x:seq)printf("%lld ",x);
	puts("");
	return 0;
}