#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=405;

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
int sum[N],f[N][N],C[N][N];

signed main()
{
	int n=read(),p=read();
	sum[1]=1;
	for (int i=2;i<=n;i++) sum[i]=sum[i-1]*2%p;
	for (int i=C[0][0]=1;i<=n;i++)
	for (int j=C[i][0]=1;j<=n;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	f[1][1]=1;
	for (int i=2;i<=n;i++)
	{
		f[i][i]=sum[i];
		for (int j=1;j<=i-1;j++)
		for (int k=1;k<=min(i-2,j-1);k++)
		f[i][j]=(f[i][j]+f[i-k-1][j-k]*C[j][k]%p*sum[k])%p;
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans=(ans+f[n][i])%p;
	print(ans);

	return 0;
}