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
const int MAXN = 1000011;
int sum[MAXN];
char a[MAXN];
int n,m;
int num(int x,int y){return (x-1)*m+y;}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)scanf("%s",a+(i-1)*m+1);
	for(int i=2;i<=n;++i)
		for(int j=2;j<=m;++j)
			if(a[num(i-1,j)]=='X'&&a[num(i,j-1)]=='X')++sum[num(i,j)];
	for(int i=2;i<=n;++i)
		for(int j=2;j<=m;++j)sum[num(i,j)]+=sum[num(i-1,j)]+sum[num(i,j-1)]-sum[num(i-1,j-1)];
	int q=read();
	while(q--)
	{
		int x1=read(),x2=read();
		if(x1==x2){puts("YES");continue;}
		puts(sum[num(n,x2)]-sum[num(n,x1)]?"NO":"YES");
	}
	return 0;
}