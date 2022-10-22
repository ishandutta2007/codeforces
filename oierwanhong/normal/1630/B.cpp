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

const int MAXN = 200011;
int a[MAXN],cnt[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),k=read();
		for(int i=1;i<=n;++i)cnt[i]=0;
		for(int i=1;i<=n;++i)++cnt[a[i]=read()];
		int res=n+1,fl=0,fr=0;
		int l=1,r=1,sum=0;
		while(l<=n)
		{
			while(r<=n&&sum-(n-sum)<k)sum+=cnt[r++];
			if(sum-(n-sum)<k)break;
			if(umin(res,r-l))fl=l,fr=r;
			sum-=cnt[l++];
		}
		printf("%d %d\n",fl,fr-1);
		int now=1,lst=1;
		sum=0;
		for(int i=1;i<=n;++i)
		{
			if(fl<=a[i]&&a[i]<fr)++sum;
			else --sum;
			if(sum>0&&now<k)printf("%d %d\n",lst,i),lst=i+1,++now,sum=0;
		}
		printf("%d %d\n",lst,n);
	}
	return 0;
}