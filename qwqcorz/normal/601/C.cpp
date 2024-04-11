#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int M=1e3+5;

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
long double dp[M*N],sum[M*N];
long double calc(int l,int r)
{
	l=max(l,0);
	if (l>r) return 0;
	return sum[r]-(l?sum[l-1]:0);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read(),summ=0,sumx=0; dp[0]=1;
	for (int i=1;i<=n;i++)
	{
		int x=read(); summ+=m; sumx+=x; sum[0]=dp[0];
		for (int j=1;j<=summ;j++) sum[j]=sum[j-1]+dp[j];
		for (int j=summ;j>=1;j--) dp[j]=(calc(j-m,j-1)-(j-x>=0?dp[j-x]:0))/max(m-1,1);
		dp[0]=0;
	}
	long double ans=0;
	for (int i=0;i<sumx;i++) ans+=dp[i];
	printf("%.15Lf",ans*(m-1)+1);
	
	return 0;
}