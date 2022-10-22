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
const int MAXN = 200011;
bool vis[MAXN];
pii ed[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),m=read();
		for(int i=1;i<=n;++i)vis[i]=0;
		for(int i=1;i<=m;++i)
		{
			int x=read(),y=read(),z=read();
			vis[y]=1;
		}
		bool flag=0;
		for(int i=1;i<=n;++i)
		{
			if(vis[i])continue;
			for(int j=1;j<=n;++j)
				if(i!=j)printf("%d %d\n",i,j);
			flag=1;break;
		}
	}
	return 0;
}