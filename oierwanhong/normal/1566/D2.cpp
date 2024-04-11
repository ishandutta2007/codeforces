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
int a[MAXN],fx[MAXN],diff=0;
std::vector<int>seq[MAXN];
int vis[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),m=read();
		for(int x=1;x<=n*m;++x)vis[x]=0;
		for(int x=1;x<=n*m;++x)a[x]=read(),fx[++diff]=a[x];
		std::sort(fx+1,fx+diff+1),diff=std::unique(fx+1,fx+diff+1)-fx-1;
		for(int x=1;x<=n*m;++x)
		{
			int p=std::lower_bound(fx+1,fx+diff+1,a[x])-fx;
			seq[p].push_back(x);
		}
		int len=0;
		for(int x=1;x<=diff;++x)
		{
			for(int i=0;i<seq[x].size();++i)
			{
				int p=len+i+1;
				vis[p]=seq[x][i];
				if(p%m==0||i+1==seq[x].size())
				{
					int st=max(len+1,((p-1)/m)*m+1);
					std::reverse(vis+st,vis+p+1);
				}
			}
			len+=seq[x].size();
		}
		int ans=0;
		for(int st=1;st<=n*m;st+=m)
		{
			for(int i=1;i<=m;++i)
				for(int j=i+1;j<=m;++j)
					ans+= vis[st+i-1]<vis[st+j-1];
		}
		printf("%d\n",ans);
		for(int x=1;x<=diff;++x)seq[x].clear();
		diff=0;
	}
	return 0;
}