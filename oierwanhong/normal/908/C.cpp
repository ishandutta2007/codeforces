#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
typedef long long ll;
typedef std::pair<int,int> pii;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN= 5011;
int a[MAXN];
double f[MAXN];
int main()
{
	int n=read(),r=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)
	{
		f[i]=r;
		for(int j=1;j<i;++j)
			if(abs(a[i]-a[j])<=2*r)umax(f[i],f[j]+sqrt(4*r*r-(a[i]-a[j])*(a[i]-a[j])));
		printf("%.8lf ",f[i]);
	}
	puts("");
	return 0;
}