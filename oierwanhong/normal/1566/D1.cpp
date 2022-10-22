#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
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
const int MAXN = 200011;
int a[MAXN],fx[MAXN],cnt[MAXN],diff=0;
bool vis[311][311];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),m=read();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)vis[i][j]=0;
		for(int x=1;x<=n*m;++x)a[x]=read(),fx[++diff]=a[x];
		std::sort(fx+1,fx+diff+1),diff=std::unique(fx+1,fx+diff+1)-fx-1;
		for(int x=1;x<=n*m;++x)
		{
			int p=std::lower_bound(fx+1,fx+diff+1,a[x])-fx;
			++cnt[p],a[x]=p;
		}
		for(int x=1;x<=diff;++x)cnt[x]+=cnt[x-1];
		int ans=0;
		for(int x=1;x<=n*m;++x)
		{
			int pos=cnt[a[x]];
			int i=(pos-1)/m+1,j=(pos-1)%m+1;
			for(int k=1;k<=j;++k)ans+=vis[i][k];
			vis[i][j]=1;
			--cnt[a[x]];
		}
		printf("%d\n",ans);
		for(int x=1;x<=diff;++x)cnt[x]=0;
		diff=0;
	}
	return 0;
}