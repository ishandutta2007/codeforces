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

const int MAXN = 1011;
char s[MAXN][MAXN];
int sum1[MAXN][MAXN],sum2[MAXN][MAXN];
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(int r=2;r<=n;++r)
		for(int c=1;c<=m;++c)sum1[r][c]= s[r][c]=='.'&&s[r-1][c]=='.';
	for(int r=1;r<=n;++r)
		for(int c=2;c<=m;++c)sum2[r][c]= s[r][c]=='.'&&s[r][c-1]=='.';
	for(int r=1;r<=n;++r)
		for(int c=1;c<=m;++c)sum1[r][c]+=sum1[r-1][c]+sum1[r][c-1]-sum1[r-1][c-1],
							sum2[r][c]+=sum2[r-1][c]+sum2[r][c-1]-sum2[r-1][c-1];
	int q=read();
	while(q--)
	{
		int x1=read(),y1=read(),x2=read(),y2=read();
		printf("%d\n",sum1[x2][y2]-sum1[x1][y2]-sum1[x2][y1-1]+sum1[x1][y1-1]
					+sum2[x2][y2]-sum2[x1-1][y2]-sum2[x2][y1]+sum2[x1-1][y1]);
	}
	return 0;
}