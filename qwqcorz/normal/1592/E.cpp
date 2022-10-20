#include<bits/stdc++.h>
using namespace std;
const int N=(1<<21)+5;

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
int a[N],sum[N],l[2][N];

signed main()
{
	memset(l,-1,sizeof(l));
	int n=read(),ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
	for (int j=0;j<20;j++)
	{
		int lst=0,S=((1<<(20-j))-1)<<j;
		for (int i=1;i<=n;i++)
		if (a[i]>>j&1)
		{
			if (l[~i&1][sum[i-1]&S]<0) l[~i&1][sum[i-1]&S]=i-1;
			if (~l[i&1][sum[i]&S]) ans=max(ans,i-l[i&1][sum[i]&S]);
		}
		else
		{
			for (int k=lst;k<=i;k++) l[~k&1][sum[k-1]&S]=-1;
			lst=i;
		}
		for (int i=lst;i<=n;i++) l[~i&1][sum[i-1]&S]=-1;
	}
	print(ans);
	
	return 0;
}