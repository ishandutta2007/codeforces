#include<bits/stdc++.h>
using namespace std;
const int N=4096;
const int p=998244353;

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
inline void add(int &x,int y)
{
	x+=y;
	if (x>=p) x-=p;
}
int C[N][N],sum[N],ans=0;

signed main()
{
	for (int i=C[0][0]=1;i<=4044;i++)
	for (int j=C[i][0]=1;j<=i;j++)
	C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	int n=read(),m=read();
	for (int t=1;t<m;t++)
	{
		for (int j=1;j<n;j++) sum[j]=(sum[j-1]+1LL*C[m-t+j-1][m-t]*C[m-t-1+n-j][m-t-1]%p)%p;
		for (int i=2;i<=n;i++) add(ans,1LL*C[t-1+i-1][t-1]*C[t+n-i][t]%p*sum[i-1]%p);
	}
	swap(n,m);
	for (int t=1;t<m;t++)
	{
		for (int j=1;j<n-1;j++) sum[j]=(sum[j-1]+1LL*C[m-t+j-1][m-t]*C[m-t-1+n-j][m-t-1]%p)%p;
		for (int i=3;i<=n;i++) add(ans,1LL*C[t-1+i-1][t-1]*C[t+n-i][t]%p*sum[i-2]%p);
	}
	add(ans,ans);
	print(ans);

	return 0;
}