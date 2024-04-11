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
int x[N],l[N],r[N];

signed main()
{
	int n=read(),k=read(),ans=0;
	for (int i=1;i<=k;i++) x[i]=read();
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	for (int i=1;i<=k;i++) r[x[i]]=i;
	for (int i=k;i>=1;i--) l[x[i]]=i;
	for (int i=1;i<=n;i++)
	{
		if (l[i]==0) ans++;
		if (i>1) if (l[i]==0||l[i]>=r[i-1]) ans++;
		if (i<n) if (l[i]==0||l[i]>=r[i+1]) ans++;
	}
	print(ans);

	return 0;
}