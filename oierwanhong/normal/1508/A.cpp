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
char a[MAXN],b[MAXN],c[MAXN];
char res[MAXN];
void work1(char* a,char* b,int n)
{
	int it=1,L=0;
	for(int i=1;i<=n+n;++i)
	{
		if(a[i]=='0'){res[++L]='0';continue;}
		while(it<=n+n&&b[it]=='0')res[++L]='0',++it;
		res[++L]='1',++it;
	}
	while(it<=n+n)res[++L]=b[it],++it;
	res[L+1]=0;
	puts(res+1);
}
void work0(char* a,char* b,int n)
{
	int it=1,L=0;
	for(int i=1;i<=n+n;++i)
	{
		if(a[i]=='1'){res[++L]='1';continue;}
		while(it<=n+n&&b[it]=='1')res[++L]='1',++it;
		res[++L]='0',++it;
	}
	while(it<=n+n)res[++L]=b[it],++it;
	res[L+1]=0;
	puts(res+1);
}
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		scanf("%s%s%s",a+1,b+1,c+1);
		int ca=0,cb=0,cc=0;
		for(int i=1;i<=n+n;++i)ca+=(a[i]=='1');
		for(int i=1;i<=n+n;++i)cb+=(b[i]=='1');
		for(int i=1;i<=n+n;++i)cc+=(c[i]=='1');
		if(ca>=n&&cb>=n)
		{
			if(ca>=cb)work1(a,b,n);
			else work1(b,a,n);
		}
		else if(ca>=n&&cc>=n)
		{
			if(ca>=cc)work1(a,c,n);
			else work1(c,a,n);
		}
		else if(cb>=n&&cc>=n)
		{
			if(cb>=cc)work1(b,c,n);
			else work1(c,b,n);
		}
		else if(ca<=n&&cb<=n)
		{
			if(ca<cb)work0(a,b,n);
			else work0(b,a,n);
		}
		else if(ca<=n&&cc<=n)
		{
			if(ca<cc)work0(a,c,n);
			else work0(c,a,n);
		}
		else
		{
			if(cb<cc)work0(b,c,n);
			else work0(c,b,n);
		}
	}
	return 0;
}