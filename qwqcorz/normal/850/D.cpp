#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=35;
const int M=65;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int dp[N][M][N*M],a[N],b[M],u[M];
bool e[M][M];

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	int m=61;
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	for (int k=max(a[i],j*(j-1)/2);k<=j*30;k++)
	{
		if (~dp[i-1][j-1][k-a[i]]) dp[i][j][k]=1;
		if (~dp[i][j-1][k-a[i]]) dp[i][j][k]=0;
	}
	int t=0;
	for (int i=1;i<=m;i++)
	if (~dp[n][i][i*(i-1)/2]){t=i;break;}
	if (!t) return puts("=("),0;
	
	int tmp=t,now=t*(t-1)/2,kkk=n;
	while (tmp)
	{
		b[tmp]=a[kkk];
		kkk-=dp[kkk][tmp][now];
		now-=b[tmp--];
	}
	for (int i=1;i<=t;i++)
	for (int j=1;j<i;j++) e[i][j]=1,u[i]++;
	while (1)
	{
		bool flag=0;
		for (int i=1;i<=t;i++) if (u[i]>b[i])
		for (int j=1;j<=t;j++) if (u[j]==b[j])
		for (int k=1;k<=t;k++) if (u[k]<b[k])
		if (e[i][j]&&e[j][k])
		{
			e[i][j]=e[j][k]=0;
			e[k][j]=e[j][i]=1;
			u[i]--,u[k]++;
			flag=1;
		}
		if (!flag) break;
	}
	print(t);
	for (int i=1;i<=t;i++,puts(""))
	for (int j=1;j<=t;j++) putchar(e[i][j]+'0');
	
	return 0;
}