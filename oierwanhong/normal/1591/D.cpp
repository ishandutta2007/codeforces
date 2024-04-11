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
int n;
struct BIT
{
	int t[MAXN];
#define lowb (i&-i)
	void modify(int i,int k)
	{
		while(i<=n)t[i]+=k,i+=lowb;
	}
	int Qsum(int i)
	{
		int res=0;
		while(i)res+=t[i],i-=lowb;
		return res;
	}
}t;
int a[MAXN],b[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		n=read();
		for(int i=1;i<=n;++i)b[i]=a[i]=read();
		std::sort(b+1,b+n+1);
		int nxt=std::unique(b+1,b+n+1)-b-1;
		if(nxt<n){puts("YES");continue;}
		bool f=0;
		for(int i=1;i<=n;++i)
		{
			f^=(i-1-t.Qsum(a[i]-1))&1;
			t.modify(a[i],1);
		}
		puts(f?"NO":"YES");
		for(int i=1;i<=n;++i)t.modify(a[i],-1);
	}
	return 0;
}