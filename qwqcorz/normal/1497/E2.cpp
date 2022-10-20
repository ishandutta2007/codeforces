#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int K=25;
const int V=1e7+5;
const int inf=1e9+7;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N],l[N][K],dp[N][K],tot[V],cnt;
void add(int x) {tot[x]++;cnt+=tot[x]>1;}
void del(int x) {cnt-=tot[x]>1;tot[x]--;}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int T=read();
	while (T--)
	{
		int n=read(),m=read();
		for (int i=1;i<=n;i++)
		{
			a[i]=1;
			int x=read();
			for (int j=2;j*j<=x;j++)
			if (x%j==0)
			{
				int cnt=0;
				while (x%j==0) x/=j,cnt^=1;
				if (cnt) a[i]*=j;
			}
			if (x>1) a[i]*=x;
		}
		for (int i=0;i<=m;i++) dp[0][i]=0;
		for (int i=1;i<=n;i++)
		for (int j=0;j<=m;j++) dp[i][j]=inf;
		for (int k=0;k<=m;k++)
		{
			cnt=0;
			for (int i=1;i<=n;i++) tot[a[i]]=0;
			for (int i=1,j=1;i<=n;i++)
			{
				add(a[i]);
				while (cnt>k) del(a[j++]);
				l[i][k]=j;
			}
		}
		for (int i=1;i<=n;i++)
		for (int j=0;j<=m;j++)
		for (int k=0;k<=j;k++)
		dp[i][j]=min(dp[i][j],dp[l[i][k]-1][j-k]+1);
		print(dp[n][m]);
	}
	
	return 0;
}