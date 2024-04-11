#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=55;
const int p=998244353;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int power(int a,int b)
{
	int ret=1;
	for (;b;a=1LL*a*a%p,b/=2) if (b&1) ret=1LL*ret*a%p;
	return ret;
}
int l[N],r[N],b[N*2],dp[N][N*2],C[N*2][N],inv[N];
int calc(int n,int m)
{
	int ret=1;
	for (int i=1;i<=m;i++) ret=1LL*ret*(n-i+1)%p*inv[i]%p;
	return ret;
}
void ysgs(int n,int m)
{
	inv[0]=inv[1]=1;
	for (int i=2;i<=n;i++) inv[i]=1LL*inv[p%i]*(p-p/i)%p;
	for (int i=1;i<m;i++)
	for (int j=1;j<=n;j++)
	C[i][j]=calc(b[i+1]-b[i]+j-1,j);
}

signed main()
{
	int n=read(),cnt=0,iv=1;
	for (int i=1;i<=n;i++) b[++cnt]=l[i]=read(),b[++cnt]=(r[i]=read())+1,iv=1LL*iv*((r[i]-l[i]+1)%p)%p;
	iv=power(iv,p-2);
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<=n;i++) l[i]=lower_bound(b+1,b+1+cnt,l[i])-b;
	for (int i=1;i<=n;i++) r[i]=lower_bound(b+1,b+1+cnt,r[i]+1)-b;
	ysgs(n,cnt);
	for (int i=1;i<=cnt;i++) dp[0][i]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<cnt;j++)
		for (int k=i;k>=1;k--)
		if (l[k]<=j&&j<r[k]) dp[i][j]=(dp[i][j]+1LL*dp[k-1][j+1]*C[j][i-k+1])%p;
						else break;
		for (int j=cnt-1;j>=1;j--) dp[i][j]=(dp[i][j]+dp[i][j+1])%p;
	}
	print(1LL*dp[n][1]*iv%p);
	
	return 0;
}