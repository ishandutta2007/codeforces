#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
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
inline int max(int x,int y)
{
	return x>y?x:y;
}
int a[N],n,m;
namespace smallc
{
	int dp[N][1<<10];
	void solve()
	{
		dp[0][0]=1;
		int Max=0,full=(1<<m)-1,nxt;
		for (int i=1;i<=n;i++)
		for (int j=Max;j>=0;j--)
		for (int k=full-1;k>=0;k--)
		if (dp[j][k])
		{
			nxt=k|(1<<a[i]);
			if (nxt==full) Max=max(Max,j+1),add(dp[j+1][0],dp[j][k]);
					  else add(dp[j][nxt],dp[j][k]);
		}
		for (int i=0;i<=n;i++)
		{
			int sum=0;
			for (int j=0;j<full;j++) add(sum,dp[i][j]);
			print(sum-!i,' ');
		}
	}
}
namespace bigc
{
	inline int power(int a,int b)
	{
		int ret=1;
		while (b)
		{
			if (b&1) ret=1LL*ret*a%p;
			a=1LL*a*a%p;
			b/=2;
		}
		return ret;
	}
	int f[N][N],g[N][N],Max[N],tot[N],inv[N],Pow[N],sum[N];
	void solve()
	{
		for (int i=Pow[0]=1;i<=n;i++) Pow[i]=Pow[i-1]*2%p;
		for (int i=inv[0]=1;i<=n;i++) inv[i]=max(power(Pow[i]-1,p-2),1);
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<m;j++) tot[j]=0;
			int cnt=1,sum=1;
			for (int j=i+1;j<=n;j++)
			if (a[i]==a[j]) add(sum,sum);
			else
			{
				cnt+=!tot[a[j]];
				tot[a[j]]++;
				sum=1LL*sum*inv[tot[a[j]]-1]%p*(Pow[tot[a[j]]]-1)%p;
				if (cnt==m) g[i][j]=1LL*sum*inv[tot[a[j]]]%p;
			}
		}
		f[n+1][0]=1;
		for (int i=n;i>=1;i--)
		{
			for (int j=i;j<=n;j++)
			if (g[i][j])
			{
				Max[i]=max(Max[i],Max[j+1]+1);
				for (int k=0;k<=Max[j+1];k++)
				add(f[i][k+1],1LL*f[j+1][k]*g[i][j]%p);
			}
			f[i][0]=Pow[n-i];
			for (int j=0;j<=n/m;j++) add(f[i][j],f[i+1][j]);
		}
		for (int i=0;i<=n;i++) print((1LL*f[1][i]-f[1][i+1]-!i+p)%p,' ');
	}
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read()-1;
	if (m<=10) smallc::solve();
		  else bigc::solve();
	
	return 0;
}