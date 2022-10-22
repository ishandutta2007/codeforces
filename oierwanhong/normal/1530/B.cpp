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
const int MAXN = 35;
bool a[MAXN][MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		memset(a,0,sizeof a);
		int n=read(),m=read();
		bool cur=1;
		for(int i=1;i<=m;++i)a[1][i]=a[n][i]=cur,cur^=1;
		for(int i=3;i<n-1;i+=2)a[i][1]=a[i][m]=1;
		for(int i=1;i<=n;++i,puts(""))
			for(int j=1;j<=m;++j)putchar(a[i][j]+'0');
		puts("");
	}
	return 0;
}