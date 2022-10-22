#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;
typedef unsigned un;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=i;++j)putchar('(');
			for(int j=1;j<=i;++j)putchar(')');
			for(int j=i+1;j<=n;++j)printf("()");
			puts("");
		}
	}
	return 0;
}