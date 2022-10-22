#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
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
const int MAXN = 211;
char a[5][MAXN][MAXN],b[MAXN][MAXN];
int p[5];
int calc(int n)
{
	int f1=0,f2=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(b[i][j]!='0'+((i+j)&1))++f1;
			else ++f2;
	return min(f1,f2);
}
int main()
{
	int n=read();
	for(int w=1;w<=4;++w)
		for(int i=1;i<=n;++i)scanf("%s",a[w][i]+1);
	for(int w=1;w<=4;++w)p[w]=w;
	int ans=1e9;
	do
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				b[i][j]=a[p[1]][i][j];
				b[i][n+j]=a[p[2]][i][j];
				b[n+i][j]=a[p[3]][i][j];
				b[n+i][n+j]=a[p[4]][i][j];
			}
		umin(ans,calc(n+n));
	}while(std::next_permutation(p+1,p+5));
	printf("%d\n",ans);
	return 0;
}