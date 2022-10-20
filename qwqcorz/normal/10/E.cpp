#include<bits/stdc++.h>
using namespace std;
const int N=4e2+5;
const int inf=2147483647;

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N];

signed main()
{
	int n=read(),ans=inf;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++)
	for (int j=i+1;j<=n;j++)
	{
		int cnt1=1,cnt2=0,w=a[i]-1,tmp;
		for (int k=i;k<=j;k++)
		{
			cnt1+=w/a[k];
			w%=a[k];
		}
		tmp=w=a[i]-1-w+a[j];
		for (int k=1;k<=n;k++)
		{
			cnt2+=w/a[k];
			w%=a[k];
		}
		if (cnt1<cnt2) ans=min(ans,tmp);
	}
	if (ans<inf) print(ans);
			else puts("-1");

	return 0;
}
// D
//......