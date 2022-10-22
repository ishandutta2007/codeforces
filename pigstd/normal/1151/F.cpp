#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int Mod=1e9+7;
const int M=110;
int dp[M][M],n,k,t,a[M];

struct node
{
	int a[M][M];
}ans,aa,res;

node mul(node a,node b)
{
	node c;memset(c.a,0,sizeof(c.a));
	for (int i=0;i<=t;i++)
		for (int j=0;j<=t;j++)
			for (int k=0;k<=t;k++)
				c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%Mod;
	return c;
}

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

int inv(int a)
{
	return poww(a,Mod-2);
}

node poww2(node a,int b)
{
	while(b)
	{
		if (b&1)res=mul(res,a);
		a=mul(a,a),b>>=1;
	}return res;
}

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),t+=a[i]^1;
	int cnt=0;
	for (int i=1;i<=t;i++)
		cnt+=a[i]^1;
	ans.a[0][cnt]=1;
	for (int i=0;i<=t;i++)res.a[i][i]=1;
	for (int i=0;i<=t;i++)
		aa.a[i-1][i]=(t-i+1)*(t-i+1)%Mod,
		aa.a[i][i]=(t*(t-1)/2+(n-t)*(n-t-1)/2+i*(t-i)+(t-i)*(n-2*t+i))%Mod,
		aa.a[i+1][i]=(i+1)*(n-2*t+(i+1))%Mod;
	aa=poww2(aa,k);ans=mul(ans,aa);
	cout<<ans.a[0][t]*inv(poww(n*(n-1)/2,k))%Mod;
	return 0;
}