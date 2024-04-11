#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 600011;
int a[10],b[10];
int main()
{
	int n=read(),k=read();
	int mul=1;
	for(int x=1;;++x)
	{
		mul*=k;
		if(mul>=n)
		{
			printf("%d\n",x);
			for(int i=0;i<n;++i)
				for(int j=i;j<n;++j)
				{
					int ta=i,tb=j;
					for(int w=0;w<x;++w)a[w]=ta%k,ta/=k;
					for(int w=0;w<x;++w)b[w]=tb%k,tb/=k;
					for(int w=x-1;w>=0;--w)
						if(a[w]!=b[w])
						{
							printf("%d ",w+1);
							break;
						}
				}
			puts("");
			return 0;
		}
	}
	return 0;
}