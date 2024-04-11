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
int a[MAXN];
int main()
{
	int n=read();
	//get p1,p2
	for(int i=1;i<n;++i)
	{
		printf("?");
		for(int j=1;j<n;++j)printf(" 1");
		printf(" %d\n",i+1);fflush(stdout);
		int x=read();
		if(!x)
		{
			//fprintf(stderr,"An=%d\n",n-i+1);
			a[n]=n-i+1;break;
		}
	}
	if(!a[n])a[n]=1;
	for(int x=1;x<a[n];++x)
	{
		printf("?");
		for(int i=1;i<n;++i)printf(" %d",1+a[n]-x);
		printf(" 1\n"),fflush(stdout);
		int p=read();
		if(!p){fprintf(stderr,"ERR!\n");return -233;}
		a[p]=x;
	}
	for(int x=a[n]+1;x<=n;++x)
	{
		printf("?");
		for(int i=1;i<n;++i)printf(" 1");
		printf(" %d\n",x-a[n]+1),fflush(stdout);
		int p=read();
		if(!p){fprintf(stderr,"ERR!\n");return -233;}
		a[p]=x;
	}
	printf("!");
	for(int i=1;i<=n;++i)printf(" %d",a[i]);
	puts(""),fflush(stdout);
	return 0;
}