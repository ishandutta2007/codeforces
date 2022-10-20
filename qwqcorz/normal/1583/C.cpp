#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int get()
{
	char c=getchar();
	while (c!='.'&&c!='X') c=getchar();
	return c=='X';
}
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
vector<int>a[N];
int sum1[N],sum2[N],sum[N]; 

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read();
	for (int i=1;i<=n;i++) a[i].resize(m+1);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=get();
	for (int i=1;i<n;i++)
	for (int j=2;j<=m;j++)
	if (a[i][j]&&a[i+1][j-1]) sum[j]++;
	for (int j=2;j<=m;j++) sum[j]+=sum[j-1];
	int Q=read();
	while (Q--)
	{
		int l=read(),r=read();
		int ans=sum[r]-sum[l];
		puts(ans?"NO":"YES");
	}
	
	return 0;
}