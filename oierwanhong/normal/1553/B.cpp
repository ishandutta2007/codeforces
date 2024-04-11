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

const int MAXN = 2011;
char s[MAXN],t[MAXN];
int n,m;
bool eq(int x,int y)
{
	for(int k=0;k<y-x+1;++k)
		if(s[x+k]!=t[1+k])return 0;
	return 1;
}
bool eqR(int x,int y)
{
	for(int k=0;k<y-x+1;++k)
		if(s[x+k]!=t[m-k])return 0;
	return 1;
}
int main()
{
	int task=read();
	while(task--)
	{
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1),m=strlen(t+1);
		bool res=0;
		for(int i=1;i<=n;++i)
			for(int j=i;j<=n&&j-i+1<=m;++j)
			{
				int pos=j-(m-(j-i+1));
				//printf("(%d,%d),pos=%d\n",i,j,pos);
				if(pos>=1&&eq(i,j)&&eqR(pos,j-1)){res=1;goto Print;}
			}
		Print:puts(res?"YES":"NO");
	}
	return 0;
}