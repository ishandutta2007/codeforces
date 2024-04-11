#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=1e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
ll ans=0,dp[N];
int a[N],Log[N];
pair<int,int>st[N][20];
pair<int,int>query(int l,int r)
{
	int k=Log[r-l+1];
	return max(st[l][k],st[r-(1<<k)+1][k]);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read();
	st[n][0]=mk(a[n]=n,n);
	for (int i=1;i<n;i++) st[i][0]=mk(a[i]=read(),i);
	for (int j=1;j<17;j++)
	for (int i=1;i+(1<<j)-1<=n;i++)
	st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for (int i=2;i<=n;i++) Log[i]=Log[i/2]+1;
	for (int i=n-1;i>=1;i--)
	{
		int j=query(i,a[i]).se;
		ans+=dp[i]=dp[j]+(n-i)-(a[i]-j);
	}
	print(ans);
	
	return 0;
}