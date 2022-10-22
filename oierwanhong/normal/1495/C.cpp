#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/
const int MAXN = 511;
char a[MAXN][MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),m=read();
		for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
		for(int i=1;i<=n;i+=3)
			for(int j=1;j<=m;++j)a[i][j]='X';
		for(int i=2;i+1<=n;i+=3)
		{
			bool flag=0;
			for(int j=1;j<=m&&(!flag||i+2>n);++j)
				if(a[i][j]=='X')a[i+1][j]='X',flag=1;
				else if(a[i+1][j]=='X')a[i][j]='X',flag=1;
			if(!flag)a[i][1]=a[i+1][1]='X';
		}
		for(int i=1;i<=n;++i)puts(a[i]+1);
	}
	return 0;
}