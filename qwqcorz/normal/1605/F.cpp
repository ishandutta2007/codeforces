#include<bits/stdc++.h>
using namespace std;
const int N=85;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int C[N][N],pw[N*N],A[N][N];
void ysgs(int n,int p)
{
	for (int i=C[0][0]=1;i<=n;i++)
	for (int j=C[i][0]=1;j<=i;j++)
	C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	for (int i=pw[0]=1;i<=n*n;i++) pw[i]=pw[i-1]*2%p;
	for (int i=0;i<=n;i++)
	for (int j=A[i][0]=1,w=pw[i]-1;j<=n&&w;j++)
	A[i][j]=1LL*A[i][j-1]*w--%p;
}
int dp[N][N];
void ThePolice()
{
	int n=read(),k=read(),p=read();
	ysgs(N-1,p);
	for (int i=0;i<=n;i++) dp[i][0]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=k;j++)
	{
		dp[i][j]=pw[i*j];
		for (int ip=0;ip<=i;ip++)
		for (int jp=0;jp<j;jp++)
		dp[i][j]=(dp[i][j]-1LL*dp[ip][jp]*C[i][ip]%p*C[j][jp]%p*pw[(i-ip)*jp]%p*A[j-jp][i-ip]%p+p)%p;
	}
	int ans=pw[n*k];
	for (int ip=0;ip<n-n%2;ip++)
	for (int jp=0;jp<k;jp++)
	ans=(ans-1LL*dp[ip][jp]*C[n][ip]%p*C[k][jp]%p*pw[(n-ip)*jp]%p*A[k-jp][n-ip]%p+p)%p;
	print(ans);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) ThePolice();
	
	return 0;
}