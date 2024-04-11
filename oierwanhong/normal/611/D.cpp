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
const int MAXN = 5011,mod = 1e9+7;
int lcp[MAXN][MAXN],f[MAXN][MAXN];
char a[MAXN];
int main()
{
	int n=read();
	scanf("%s",a+1);
	for(int i=n;i;--i)
		for(int j=n;j;--j)
			lcp[i][j]= a[i]==a[j]?lcp[i+1][j+1]+1:0;
	for(int i=1;i<=n;++i)
	{
		f[i][1]=1;
		for(int j=2;j<=i;++j)
		{
			if(a[j]=='0')continue;
			int len=i-j+1;
			if(j<=len)
			{
				f[i][j]=f[j-1][1];
				continue;
			}
			int k=lcp[j-len][j];
			bool type= k<len&&a[j-len+k]<a[j+k];
			if(type)f[i][j]=f[j-1][j-len];
			else f[i][j]=f[j-1][j-len+1];
		}
		for(int j=i;j;--j)f[i][j]=(f[i][j]+f[i][j+1])%mod;
	}
	printf("%d\n",f[n][1]);
	return 0;
}