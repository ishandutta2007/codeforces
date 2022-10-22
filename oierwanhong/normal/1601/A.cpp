#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read()
{
	 ll x=0;bool f=0;char c=getchar();
	 while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
	 while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	 return f?-x:x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/
int f[200011];
int cnt[30];
int main()
{
	int task=read();
	while(task--)
	{
		memset(cnt,0,sizeof cnt);
		int n=read(),all=0;
		for(int i=1;i<=n;++i)
		{
			f[i]=0;
			int x=read();
			for(int k=0;k<30;++k)
				if(x&(1<<k))++cnt[k];
		}
		for(int k=0;k<30;++k)
			for(int d=1;d<=n;++d)
			{
				if(cnt[k]%d==0)++f[d];
			}
		for(int i=1;i<=n;++i)
			if(f[i]==30)printf("%d ",i);
		puts("");
	}
	return 0;
}