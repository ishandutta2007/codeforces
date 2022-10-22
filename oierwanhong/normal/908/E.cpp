#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned long long ull;
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
const int MAXN = 1011,mod = 1e9+7;
int S[MAXN][MAXN],sum[MAXN];
ull f[MAXN];
char a[MAXN];
bool vis[MAXN];
int main()
{
	int n=read(),m=read();
	S[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)S[i][j]=(S[i-1][j-1]+ll(j)*S[i-1][j])%mod,sum[i]=(sum[i]+S[i][j])%mod;
	for(int x=1;x<=m;++x)
	{
		scanf("%s",a+1);
		for(int i=1;i<=n;++i)
			if(a[i]=='1')f[i]|=1ull<<x;
	}
	int ans=1;
	for(int i=1;i<=n;++i)
		if(!vis[i])
		{
			int cnt=0;
			for(int j=1;j<=n;++j)
				if(f[j]==f[i])vis[j]=1,++cnt;
			ans=ll(ans)*sum[cnt]%mod;
		}
	printf("%d\n",ans);
	return 0;
}