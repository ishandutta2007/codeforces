#include<bits/stdc++.h>
using namespace std;
const int N=405;
const int p=1e9+7;

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
inline int power(long long a,int b)
{
	long long ret=1;
	while (b)
	{
		if (b&1) ret=ret*a%p;
		a=a*a%p;
		b/=2;
	}
	return ret;
}
int f[N][N],g[N][N],C[N][N],ans[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),m=read();
	for (int i=C[0][0]=1;i<=m*2;i++)
	for (int j=C[i][0]=1;j<=i;j++)
	C[i][j]=(C[i-1][j-1]+C[i-1][j])%p; 
	for (int i=f[0][0]=1;i<=m*2;i++)
	for (int j=f[i][0]=1;j<=m;j++)
	f[i][j]=(f[i-1][j]+1LL*(i-1)*f[i-1][j-1])%p;
	for (int i=g[0][0]=1;i<=m*2;i++)
	for (int j=1;j<=m;j++)
	for (int k=0;k<=i;k++)
	g[i][j]=(g[i][j]+(((i-k)&1)?-1LL:1LL)*C[i][k]*f[k][j]%p+p)%p;
//	for (int i=0;i<=m*2;i++,puts(""))
//	for (int j=0;j<=m*2;j++) print(g[i][j],' ');
	for (int k=ans[0]=1;k<=m;k++)
	for (int i=1,Cni=1;i<=min(n,k*2);i++)
	{
		Cni=1LL*Cni*(n-i+1)%p*power(i,p-2)%p;
		for (int j=1;j<=k;j++)
		if ((k-j)%2==0)
		ans[k]=(ans[k]+1LL*Cni*g[i][j])%p;
	}
	for (int i=1;i<=m;i++) print(ans[i]+=(~i&1),' ');
	
	return 0;
}