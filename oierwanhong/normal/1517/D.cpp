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
const int MAXN = 511,INF=1e9+233;
int f[11][MAXN][MAXN];
int row[MAXN][MAXN],col[MAXN][MAXN];
int main()
{
	int n=read(),m=read(),k=read();
	if(k&1)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)printf("-1%c",j==m?'\n':' ');
		return 0;
	}
	k>>=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<m;++j)row[i][j]=read();
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j)col[i][j]=read();
	memset(f,0x3f,sizeof f);
	for(int x=1;x<=n;++x)
		for(int y=1;y<=m;++y)f[0][x][y]=0;
	for(int t=0;t<k;++t)
	{
		for(int x=1;x<=n;++x)
			for(int y=1;y<=m;++y)
			{
				int cur=f[t][x][y];
				if(x>1)umin(f[t+1][x-1][y],cur+col[x-1][y]);
				if(x<n)umin(f[t+1][x+1][y],cur+col[x][y]);
				if(y>1)umin(f[t+1][x][y-1],cur+row[x][y-1]);
				if(y<m)umin(f[t+1][x][y+1],cur+row[x][y]);
			}
	}
	for(int x=1;x<=n;++x)
		for(int y=1;y<=m;++y)printf("%d%c",f[k][x][y]<<1,y==m?'\n':' ');
	return 0;
}