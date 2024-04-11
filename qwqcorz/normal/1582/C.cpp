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
int p[N];
char a[N];
int solve(int n)
{
	int ret=N;
	for (char j='a';j<='z';j++)
	{
		int tot=0,l,r,ans=0,flag=1;
		for (int i=1;i<=n;i++) if (a[i]!=j) p[++tot]=i;
		if (!tot) continue;
		if (tot&1) l=r=p[tot/2+1];
			  else ans=(r=p[tot/2+1])-(l=p[tot/2])-1;
		while (l)
		{
			if (a[l--]!=a[r++]){flag=0;break;}
			int tot1=0,tot2=0;
			while (l>=1&&a[l]==j) l--,tot1++;
			while (r<=n&&a[r]==j) r++,tot2++;
			ans+=min(tot1,tot2)*2;
		}
		if (flag) ret=min(ret,n-tot-ans);
	}
	return ret<N?ret:-1;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read();
		scanf("%s",a+1);
		print(solve(n));
	}
	
	return 0;
}
//