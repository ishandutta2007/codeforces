#include<bits/stdc++.h>
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
int a[N],ans[N];

signed main()
{
	memset(ans,-1,sizeof(ans));
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1,j=1;i<=n;i++)
	if (a[i]<a[i-1]) return puts("-1"),0;
	else if (a[i]>a[i-1])
	{
		ans[i]=a[i-1];
		for (int k=a[i-1]+1;k<a[i];k++)
		{
			while (j<=i&&~ans[j]) j++;
			if (j>i) return puts("-1"),0;
			ans[j]=k;
		}
	}
	for (int i=1;i<=n;i++) print(ans[i]<0?1e6:ans[i]," \n"[i==n]);
	
	return 0;
}