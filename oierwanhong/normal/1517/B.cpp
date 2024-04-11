#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 111,INF=1e9+233;
int a[MAXN][MAXN],b[MAXN][MAXN];
bool used[MAXN][MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),m=read();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)a[i][j]=read(),used[i][j]=0;
		for(int p=1;p<=m;++p)
		{
			int minv=INF,sx=0,sy=0;
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					if(!used[i][j]&&umin(minv,a[i][j]))sx=i,sy=j;
			b[sx][p]=minv;
			used[sx][sy]=1;
			for(int i=1;i<=n;++i)
				if(i!=sx)
				{
					int maxv=0,pos=0;
					for(int j=1;j<=m;++j)
						if(!used[i][j]&&umax(maxv,a[i][j]))pos=j;
					b[i][p]=maxv,used[i][pos]=1;
				}
		}
		for(int i=1;i<=n;++i,puts(""))
			for(int j=1;j<=m;++j)printf("%d ",b[i][j]);
	}
	return 0;
}