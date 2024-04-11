#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
int abs(int x){return x>0?x:-x;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
int f[111][10011];
int main()
{
	int n=read(),tot=0;
	memset(f,0xcf,sizeof f);
	f[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		int a=read(),b=read();
		tot+=b;
		for(int j=i;j;--j)
			for(int k=10000;k>=a;--k)umax(f[j][k],f[j-1][k-a]+b);
	}
	for(int j=1;j<=n;++j)
	{
		int res=0;
		for(int k=0;k<=10000;++k)umax(res,min(2*k,f[j][k]*2+(tot-f[j][k])));
		if(res&1)printf("%d.50000000000 ",res>>1);
		else printf("%d.00000000 ",res>>1);
	}
	puts("");
	return 0;
}