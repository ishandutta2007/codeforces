#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=55;

inline int read()
{
	register int s=0;
	register char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(register int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
inline void print(const register int x,const register char c='\n')
{
	write(x);
	putchar(c);
}
int n,k,ans=0,a[N];
bool can[N][N];
bitset<N>dp[N];
bool check(int ans)
{
	for (int i=0;i<=n;i++) dp[i].reset();
	for (int i=1;i<=n;i++)
	for (int j=i,sum=a[i];j<=n;sum+=a[++j]) can[i][j]=(sum&ans)==ans;
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
	for (int j=0;j<i;j++)
	if (can[j+1][i])
	dp[i]|=dp[j]<<1;
	return dp[n][k];
}

signed main()
{
	n=read();
	k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=60;i>=0;i--)
	if (check(ans|(1ll<<i)))
	ans|=1ll<<i;
	print(ans);

	return 0;
}