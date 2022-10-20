#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int f[2]={-1,1};

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

inline void up(ll &x,ll y){if (x<y) x=y;}
int a[N];
ll dp[N][3][2];

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (n==1) return print(a[1]),0;
	memset(dp,0xc0,sizeof(dp));
	dp[0][0][1]=0;
	for (int i=1;i<=n;i++)
	for (int j=0;j<3;j++)
	for (int k=0;k<=1;k++)
	for (int t=0;t<=1;t++)
	up(dp[i][(j+f[t]+3)%3][k&&(i%2==t)],dp[i-1][j][k]+a[i]*f[t]);
	print(dp[n][1][0]);
	
	return 0;
}