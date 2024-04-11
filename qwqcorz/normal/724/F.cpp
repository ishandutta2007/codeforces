#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int f[N][13],inv[13];
int C(int n,int m,int p)
{
	if (n<m||m<0) return 0;
	int ret=1;
	for (int i=1;i<=m;i++) ret=1LL*ret*(n-i+1)%p*inv[i]%p;
	return ret;
}

signed main()
{
	int n=read(),d=read(),p=read(),inv2=(p+1)/2;
	if (n==1) return puts("1"),0;
	inv[0]=inv[1]=1;
	for (int i=2;i<=d;i++) inv[i]=1LL*inv[p%i]*(p-p/i)%p;
	f[1][0]=1;
	for (int j=1;j<=n/2;j++)
	for (int i=n-j;i>=0;i--)
	for (int k=d-1;k>=0;k--)
	for (int t=1;k+t<=d&&i+j*t<=n;t++)
	f[i+j*t][k+t]=(f[i+j*t][k+t]+1LL*f[i][k]*C(f[j][0]+f[j][d-1]+t-1,t,p))%p;
	int ans=(f[n][d]+f[n][1])%p;
	if (n%2==0) ans=(ans-C(f[n/2][d-1],2,p)+p)%p;
	print(ans);
	
	return 0;
}